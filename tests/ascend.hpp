#include <kernel_operator.h>

using namespace AscendC;

namespace deep_gemm {

// TODO: @zhean, SFPtrDiv
// TODO: move this to a common header to be included by host code
inline constexpr uint32_t C0 = 16;
inline constexpr uint32_t L1SizeBytes = 512 * 1024;
inline constexpr uint32_t L0ASizeBytes = 64 * 1024;
inline constexpr uint32_t L0BSizeBytes = 64 * 1024;
inline constexpr uint32_t L0CSizeBytes = 256 * 1024;
inline constexpr uint32_t UBSizeBytes = 248 * 1024;

template<typename T1, typename T2>
__aicore__ inline constexpr auto ceildiv(T1 a, T2 b) -> decltype(a + b) { return (a + b - 1) / b; }
template<typename T1, typename T2>
__aicore__ inline constexpr auto aligned(T1 a, T2 b) -> decltype(a + b) { return ceildiv(a, b) * b; }

__aicore__ inline void set_mte2_nz(uint16_t num_batch, uint16_t dst_nz_n_stride, uint16_t dst_nz_c0_stride) {
    set_mte2_nz_para(uint64_t(num_batch) | (uint64_t(dst_nz_n_stride) << 16) | (uint64_t(dst_nz_c0_stride) << 32));
}

// ------- Ascend Convention -------
//
// 1. All shape  MUST be multiples of C0
// 2. All index  MUST be multiples of C0
// 3. All stride MUST have suffix of `_bytes` or `_elems`
// 4. All index  MUST be at the origial [M, N] domain, SHOULD NOT be converted to [M // C0, N // C0]
//
// 5. The layout in L1 is ALWAYS NZ
// 6. All matrix in L0A/L0B/L0C are ALWAYS tightly packed [M, N] without stride

enum BufLayout  {
    // for a [N, K] matrix
    ND, // (N, K) : (K, 1)
    DN, // (N, K) : (1, N)
    NZ, // ((N/16, 16), (K/16, 16)) : ((256, 16), (16*N, 1)), "DNZ" in fact
    // DZ, ((N/16, 16), (K/16, 16)) : ((16*N, 1), (256, 16)), "NDZ" in fact, not commonly used and not optimized for now
};

// see also unit_flag_t
enum UnitFlag : uint8_t {
    UF_DISABLE = 0,
    UF_ENABLE = 2,
    UF_LAST = 3,
};

enum DualDst: uint8_t {
    DUAL_NONE = 0,
    DUAL_M = 1,
    DUAL_N = 2
};

// same encoding as the LD_L2CacheType
enum L2Ctrl : uint8_t {
    L2_NORMAL_FV = 0,      // normal first victim
    L2_NORMAL_LV = 1,      // normal last victim
    L2_NORMAL_PERS = 2,    // normal persistent
    L2_NORMAL_PREF = 3,    // normal prefetch
    L2_NOTALLOC_KEEP = 4,  // not-alloc keep
    L2_NOTALLOC_CLEAN = 5, // not-alloc clean
    L2_NOTALLOC_DROP = 6,  // not-alloc drop
    L2_IDS_FV = 8,         // inter domain share first victim
    L2_IDS_LV = 9,         // inter domain share last victim
    L2_IDS_PERS = 10,      // inter domain share persistent
    L2_IDS_PREF = 11,      // inter domain share prefetch
    L2_EXCLUSIV_FV = 12,   // exclusive first victim
    L2_EXCLUSIV_LV = 13,   // exclusive last victim
    L2_EXCLUSIV_PERS = 14, // exclusive persistent
    L2_EXCLUSIV_PREF = 15, // exclusive prefetch
    L2_INVALID = 16,
};

// ------- human friendly copy wrapper -------

template<typename dtype_t>
__aicore__ inline void copy_gm_to_l1(
    __cbuf__ dtype_t *dst_ptr, __gm__ dtype_t *src_ptr,
    uint64_t shape_m, uint64_t shape_n,
    uint64_t src_stride_bytes,
    BufLayout src_layout = ND,
    // uint64_t dst_layout = NZ
    L2Ctrl   l2ctrl=L2_NORMAL_FV,
    uint16_t num_batch=1, uint64_t batch_stride_bytes=0
) {
    // ascendc_assert(shape_m % C0 == 0, "shape_m must be multiples of C0");
    // ascendc_assert(shape_n % C0 == 0, "shape_n must be multiples of C0");
    switch(src_layout) {
        case ND:
            set_mte2_nz(num_batch, 1, shape_m);
            copy_gm_to_cbuf_multi_nd2nz(dst_ptr, src_ptr, 0, src_stride_bytes, l2ctrl, shape_m, shape_n, batch_stride_bytes, false);
            break;
        case DN:
            set_mte2_nz(num_batch, 1, shape_m);
            copy_gm_to_cbuf_multi_dn2nz(dst_ptr, src_ptr, 0, src_stride_bytes, l2ctrl, shape_m, shape_n, batch_stride_bytes, false);
            break;
        case NZ:
            set_mte2_nz(num_batch, shape_n / C0, 1);
            copy_gm_to_cbuf_multi_nd2nz(dst_ptr, src_ptr, 0, src_stride_bytes, l2ctrl, shape_m, shape_n, batch_stride_bytes, false);
            break;
    }
}

template<typename dtype_t>
__aicore__ inline void copy_l1_to_l0a(
    __ca__ dtype_t * dst_ptr, __cbuf__ dtype_t * src_ptr,
    uint64_t m_idx, uint64_t n_idx,
    uint64_t shape_m, uint64_t shape_n,
    uint64_t src_stride_elems,
    bool transpose = false
) {
    // ascendc_assert(m_idx % C0 == 0, "m_idx must be multiples of C0");
    // ascendc_assert(n_idx % C0 == 0, "n_idx must be multiples of C0");
    // ascendc_assert(dst_shape_m % C0 == 0, "dst_shape_m must be multiples of C0");
    // ascendc_assert(dst_shape_n % C0 == 0, "dst_shape_n must be multiples of C0");
    // ascendc_assert(src_shape_n % C0 == 0, "src_shape_n must be multiples of C0");
    if(transpose) {
        load_cbuf_to_ca(
            dst_ptr, src_ptr,
            m_idx / C0, n_idx / C0,
            shape_m / C0, shape_n / C0,
            src_stride_elems / C0, shape_m / C0,
            true
        );
    } else {
        load_cbuf_to_ca(
            dst_ptr, src_ptr,
            m_idx / C0, n_idx / C0,
            shape_m / C0, shape_n / C0,
            src_stride_elems / C0, shape_m / C0,
            false
        );
    }
}

template<typename dtype_t>
__aicore__ inline void copy_l1_to_l0a_sf(
    __ca__ dtype_t * dst_ptr, __cbuf__ dtype_t * src_ptr,
    uint64_t m_idx, uint64_t n_idx,
    uint64_t shape_m, uint64_t shape_n,
    uint64_t src_stride_elems,
    bool transpose = false
) {
}

template<typename dtype_t>
__aicore__ inline void copy_l1_to_l0b(
    __cb__ dtype_t * dst_ptr, __cbuf__ dtype_t * src_ptr,
    uint64_t m_idx, uint64_t n_idx,
    uint64_t shape_m, uint64_t shape_n,
    uint64_t src_stride_elems,
    bool transpose = false
) {
    // ascendc_assert(m_idx % C0 == 0, "m_idx must be multiples of C0");
    // ascendc_assert(n_idx % C0 == 0, "n_idx must be multiples of C0");
    // ascendc_assert(dst_shape_m % C0 == 0, "dst_shape_m must be multiples of C0");
    // ascendc_assert(dst_shape_n % C0 == 0, "dst_shape_n must be multiples of C0");
    // ascendc_assert(src_shape_n % C0 == 0, "src_shape_n must be multiples of C0");
    if(transpose) {
        load_cbuf_to_cb(
            dst_ptr, src_ptr,
            m_idx / C0, n_idx / C0,
            shape_m / C0, shape_n / C0,
            src_stride_elems / C0, shape_m / C0,
            true
        );
    } else {
        load_cbuf_to_cb(
            dst_ptr, src_ptr,
            m_idx / C0, n_idx / C0,
            shape_m / C0, shape_n / C0,
            src_stride_elems / C0, shape_m / C0,
            false
        );
    }
}

template<typename dtype_t>
__aicore__ inline void copy_l0c_to_ub(
    __ubuf__ dtype_t * dst_ptr, __cc__ dtype_t * src_ptr,
    uint64_t shape_m, uint64_t shape_n,
    uint64_t dst_stride_elems,
    UnitFlag unit_flag,
    DualDst dual_dst_ctrl,
    QuantMode_t quant_mode = NoQuant,
    BufLayout dst_layout = ND,
    uint32_t dst_subblock_id = 0,
    bool relu=false
) {
    set_loop3_para(1ul);
    copy_matrix_cc_to_ub(
        dst_ptr, src_ptr,           // dst_ptr, src_ptr
        0,                          // sid
        shape_n, shape_m,           // n size, m size
        dst_stride_elems, shape_m,  // dst stride, src stride
        (uint32_t) dual_dst_ctrl,   // dual dst ctrl
        dst_subblock_id,            // subblock_id
        0,                          // clip_relu_pre (not supported by 3510)
        (uint32_t) unit_flag,       // unit_flag_ctrl
        (uint32_t) quant_mode,      // quant_pre     (not supported by 3510)
        relu,                       // relu_pre
        false,                      // split_en      (not supported by 3510)
        dst_layout == ND,           // NZ2ND_en
        0,                          // quant_post
        0,                          // relu_post     (not supported by 3510)
        false, false, 0, false, false, false, false, false, // not supported by 3510
        dst_layout == DN            // NZ2DN_en      (may not supported by 3510)
    );
}

template<typename dtype_t>
__aicore__ inline void copy_l0c_to_gm(
    __gm__ dtype_t * dst_ptr, __cc__ dtype_t * src_ptr,
    uint64_t shape_m, uint64_t shape_n,
    uint64_t dst_stride_elems,
    UnitFlag unit_flag,
    L2Ctrl l2ctrl = L2_NORMAL_FV,
    QuantMode_t quant_mode = NoQuant,
    BufLayout dst_layout = ND,
    bool relu = false
) {
    set_loop3_para(1ul);
    copy_matrix_cc_to_gm(
        dst_ptr, src_ptr,           // dst_ptr, src_ptr
        0,                          // sid
        shape_n, shape_m,           // n size, m size
        dst_stride_elems, shape_m,  // dst stride, src stride
        (uint32_t) l2ctrl,          // l2_cache_ctl
        0,                          // clip_relu_pre (not supported by 3510)
        (uint32_t) unit_flag,       // unit_flag_ctrl
        (uint32_t) quant_mode,      // quant_pre
        relu,                       // relu_pre
        false,                      // split_en      (not supported by 3510)
        dst_layout == ND,           // NZ2ND_en
        0,                          // quant_post
        0,                          // relu_post     (not supported by 3510)
        false, false, 0, false, false, false, false, false, // not supported by 3510
        dst_layout == DN            // NZ2DN_en      (may not supported by 3510)
    );
}

template<typename DstT, typename SrcT>
__aicore__ inline void copy_l0c_to_l1(
    __cbuf__ DstT * dst_ptr, __cc__ SrcT * src_ptr,
    uint64_t shape_m, uint64_t shape_n,
    uint64_t dst_stride_elems,
    UnitFlag unit_flag,
    QuantMode_t quant_mode = NoQuant,
    BufLayout dst_layout = ND,
    bool relu = false
) {
    // void copy_matrix_cc_to_cbuf(__cbuf__ bfloat16_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
    copy_matrix_cc_to_cbuf(
        dst_ptr, src_ptr,           // dst_ptr, src_ptr
        0,                          // sid
        shape_n, shape_m,           // n size, m size
        dst_stride_elems, shape_m,  // dst stride, src stride
        0,                          // l2_cache_ctl  (may not supported by 3510)
        0,                          // clip_relu_pre (not supported by 3510)
        (uint32_t) unit_flag,       // unit_flag_ctrl
        (uint32_t) quant_mode,      // quant_pre
        relu,                       // relu_pre      (not supported by 3510)
        false,                      // split_en      (not supported by 3510)
        dst_layout == ND,           // NZ2ND_en
        0,                          // quant_post
        0,                          // relu_post     (not supported by 3510)
        false, false, 0, false, false, false, false, false, // not supported by 3510
        dst_layout == DN            // NZ2DN_en      (may not supported by 3510)
    );
}

template<typename dtype_t>
__aicore__ inline void copy_ub_to_gm(
    __gm__ dtype_t * dst_ptr, __ubuf__ dtype_t * src_ptr,
    uint64_t shape_m, uint64_t shape_n,
    uint64_t dst_stride_bytes,
    L2Ctrl l2ctrl = L2_NORMAL_FV
) {
    copy_ubuf_to_gm_align_v2(
        dst_ptr, src_ptr,
        /* sid */ 0,
        /* burst_num */ shape_m,
        /* burst_len */ shape_n * sizeof(dtype_t),
        l2ctrl,
        /* burst_dst_stride */ dst_stride_bytes,
        /* burst_src_stride */ shape_n * sizeof(dtype_t)
    );
}

template<typename dtype_t>
__aicore__ inline void copy_gm_to_ub(
    __ubuf__ dtype_t * dst_ptr, __gm__ dtype_t * src_ptr,
    uint64_t shape_m, uint64_t shape_n,
    uint64_t src_stride_bytes,
    L2Ctrl l2ctrl = L2_NORMAL_FV
) {
    copy_gm_to_ubuf_align_v2(
        dst_ptr, src_ptr,
        /* sid */ 0,
        /* burst_num */ shape_m,
        /* burst_len */ shape_n * sizeof(dtype_t),
        /* left_padding_count */ 0,
        /* right_padding_count */ 0,
        /* data_select_bit */ false,
        /* l2_cache_ctl */ (uint8_t) l2ctrl,
        /* burst_src_stride */ src_stride_bytes,
        /* burst_dst_stride */ (uint32_t)(shape_n * sizeof(dtype_t))
    );
}

// ------- pointer with shape wrapper -------

template<typename T>
struct l1_ptr {
    __cbuf__ T * ptr;
    const uint64_t shape_m, shape_n;

    constexpr __aicore__ inline l1_ptr(uint64_t address, uint64_t shape_m, uint64_t shape_n):
        ptr(reinterpret_cast<__cbuf__ T *>(address)), shape_m(shape_m), shape_n(shape_n) {}
    constexpr __aicore__ inline operator __cbuf__ T *() const { return ptr; }
};

template<typename T>
struct l0a_ptr {
    __ca__ T * ptr;
    const uint64_t shape_m, shape_n;

    constexpr __aicore__ inline l0a_ptr(uint64_t address, uint64_t shape_m, uint64_t shape_n):
        ptr(reinterpret_cast<__ca__ T *>(address)), shape_m(shape_m), shape_n(shape_n) {}
    constexpr __aicore__ inline operator __ca__ T *() const { return ptr; }
};

template<typename T>
struct l0b_ptr {
    __cb__ T * ptr;
    const uint64_t shape_m, shape_n;

    constexpr __aicore__ inline l0b_ptr(uint64_t address, uint64_t shape_m, uint64_t shape_n):
        ptr(reinterpret_cast<__cb__ T *>(address)), shape_m(shape_m), shape_n(shape_n) {}
    constexpr __aicore__ inline operator __cb__ T *() const { return ptr; }
};

template<typename T>
struct l0c_ptr {
    __cc__ T * ptr;
    const uint64_t shape_m, shape_n;

    constexpr __aicore__ inline l0c_ptr(uint64_t address, uint64_t shape_m, uint64_t shape_n):
        ptr(reinterpret_cast<__cc__ T *>(address)), shape_m(shape_m), shape_n(shape_n) {}
    constexpr __aicore__ inline operator __cc__ T *() const { return ptr; }
};

template<typename T>
struct ub_ptr {
    __ubuf__ T * ptr;
    const uint64_t shape_m, shape_n;

    constexpr __aicore__ inline ub_ptr(uint64_t address, uint64_t shape_m, uint64_t shape_n):
        ptr(reinterpret_cast<__ubuf__ T *>(address)), shape_m(shape_m), shape_n(shape_n) {}
    constexpr __aicore__ inline operator __ubuf__ T *() const { return ptr; }
};

template<typename T>
__aicore__ inline void copy_gm_to_l1(
    l1_ptr<T> dst, __gm__ T * src,
    uint64_t src_stride_bytes,
    BufLayout src_layout = ND,
    L2Ctrl l2ctrl = L2_NORMAL_FV,
    uint16_t num_batch=1, uint64_t batch_stride_bytes=0
) {
    copy_gm_to_l1(dst.ptr, src, dst.shape_m, dst.shape_n, src_stride_bytes, src_layout, l2ctrl, num_batch, batch_stride_bytes);
}

template<typename T>
__aicore__ inline void copy_l1_to_l0a(
    l0a_ptr<T> dst, l1_ptr<T> src,
    uint64_t m_idx, uint64_t n_idx,
    bool transpose = false
) {
    copy_l1_to_l0a(dst.ptr, src.ptr, m_idx, n_idx, dst.shape_m, dst.shape_n, src.shape_m, transpose);
}

template<typename T>
__aicore__ inline void copy_l1_to_l0b(
    l0b_ptr<T> dst, l1_ptr<T> src,
    uint64_t m_idx, uint64_t n_idx,
    bool transpose = false
) {
    copy_l1_to_l0b(dst.ptr, src.ptr, m_idx, n_idx, dst.shape_m, dst.shape_n, src.shape_m, transpose);
}

template<typename T>
__aicore__ inline void copy_l0c_to_ub(
    ub_ptr<T> dst, l0c_ptr<T> src,
    UnitFlag unit_flag,
    DualDst dual_dst_ctrl,
    QuantMode_t quant_mode = NoQuant,
    BufLayout dst_layout = ND,
    uint32_t dst_subblock_id = 0,
    bool relu=false
) {
    copy_l0c_to_ub(dst.ptr, src.ptr, src.shape_m, src.shape_n, src.shape_n, unit_flag, dual_dst_ctrl, quant_mode, dst_layout, dst_subblock_id, relu);
}

template<typename T>
__aicore__ inline void copy_l0c_to_gm(
    __gm__ T * dst, l0c_ptr<T> src,
    uint64_t dst_stride_elems,
    UnitFlag unit_flag,
    L2Ctrl l2ctrl = L2_NORMAL_FV,
    QuantMode_t quant_mode = NoQuant,
    BufLayout dst_layout = ND,
    bool relu = false
) {
    copy_l0c_to_gm(dst, src.ptr, src.shape_m, src.shape_n, dst_stride_elems, unit_flag, l2ctrl, quant_mode, dst_layout, relu);
}

template<typename DstT, typename SrcT>
__aicore__ inline void copy_l0c_to_l1(
    l1_ptr<DstT> dst, l0c_ptr<SrcT> src,
    UnitFlag unit_flag,
    QuantMode_t quant_mode = NoQuant,
    BufLayout dst_layout = ND,
    bool relu = false
) {
    copy_l0c_to_l1(dst.ptr, src.ptr, src.shape_m, src.shape_n, dst.shape_m, unit_flag, quant_mode, dst_layout, relu);
}

template<typename T>
__aicore__ inline void copy_ub_to_gm(
    __gm__ T * dst, ub_ptr<T> src,
    uint64_t dst_stride_bytes,
    L2Ctrl l2ctrl = L2_NORMAL_FV
) {
    copy_ub_to_gm(dst, src.ptr, src.shape_m, src.shape_n, dst_stride_bytes, l2ctrl);
}

template<typename TA, typename TB, typename TC>
__aicore__ inline void mad(l0c_ptr<TC> l0c, l0a_ptr<TA> l0a, l0b_ptr<TB> l0b, UnitFlag unit_flag, bool clear_C = false) {
    __cce_scalar::mad(l0c.ptr, l0a.ptr, l0b.ptr, l0c.shape_m, l0a.shape_n, l0c.shape_n, unit_flag, false, false, clear_C);
}

// ------- utilities wrapper -------

__aicore__ inline constexpr bool is_vec_pipe(pipe_t pipe) {
    return pipe == PIPE_ALL || pipe == PIPE_S || pipe == PIPE_V || pipe == PIPE_MTE2 || pipe == PIPE_MTE3;
}

__aicore__ inline constexpr bool is_cube_pipe(pipe_t pipe) {
    return pipe == PIPE_ALL || pipe == PIPE_S || pipe == PIPE_MTE1 || pipe == PIPE_MTE2 || pipe == PIPE_FIX || pipe == PIPE_M ;
}

// bisheng requires pipe_t to be a compile-time literal (encoded into the instruction).
// pipe_cases expands to switch cases with literal pipes for the current compilation pass.
// PIPE_ALL is not included (not valid for all intrinsics); add it yourself where needed.
#if defined(SPLIT_CORE_VEC)
#define pipe_cases(func, ...) \
    case PIPE_MTE2: func(PIPE_MTE2, ##__VA_ARGS__); break; \
    case PIPE_MTE3: func(PIPE_MTE3, ##__VA_ARGS__); break; \
    case PIPE_V:    func(PIPE_V,    ##__VA_ARGS__); break;
#elif defined(SPLIT_CORE_CUBE)
#define pipe_cases(func, ...) \
    case PIPE_MTE2: func(PIPE_MTE2, ##__VA_ARGS__); break; \
    case PIPE_MTE3: func(PIPE_MTE3, ##__VA_ARGS__); break; \
    case PIPE_M:    func(PIPE_M,    ##__VA_ARGS__); break; \
    case PIPE_MTE1: func(PIPE_MTE1, ##__VA_ARGS__); break; \
    case PIPE_FIX:  func(PIPE_FIX,  ##__VA_ARGS__); break;
#else
#define pipe_cases(func, ...)
#endif

__aicore__ inline void set_intra_block(pipe_t pipe, uint8_t subblock_id, uint8_t flag_id) {
    uint64_t flag = ((subblock_id & 1) << 4) | (flag_id & 0xf);
    switch(pipe) {
        pipe_cases(__cce_scalar::set_intra_block, flag)
        default: ascendc_assert(false, "set_intra_block: invalid pipe %d", (int)pipe);
    }
}
__aicore__ inline void wait_intra_block(pipe_t pipe, uint8_t subblock_id, uint8_t flag_id) {
    uint64_t flag;
    // AIV ignores subblock_id for intra-block waiting
    if ASCEND_IS_AIV {
        flag = flag_id & 0xf;
    } else {
        flag = ((subblock_id & 1) << 4) | (flag_id & 0xf);
    }
    switch(pipe) {
        pipe_cases(__cce_scalar::wait_intra_block, flag)
        default: ascendc_assert(false, "cross_core_wait: invalid pipe %d", (int)pipe);
    }
}

// typedef enum {
//   CROSS_CORE = 0,
//   INTRA_BLOCK,
//   BUFFER_ID,
//   RESERVED,
// } sync_mode_t;
__aicore__ inline void ffts_sync(pipe_t pipe, sync_mode_t mode, uint8_t flag_id) {
    uint64_t config = 0x1u | ((mode & 0x3u) << 4) | ((flag_id & 0xfu) << 8);
    switch(pipe) {
        pipe_cases(ffts_cross_core_sync, config)
        default: ascendc_assert(false, "ffts_sync: invalid pipe %d", (int)pipe);
    }
}

__aicore__ inline void ffts_wait(pipe_t pipe, uint8_t flag_id) {
    switch(pipe) {
        pipe_cases(wait_flag_dev, flag_id)
        case PIPE_S:   wait_flag_dev(PIPE_S, flag_id); break;
        default: ascendc_assert(false, "ffts_wait: invalid pipe %d", (int)pipe);
    }
}

template<pipe_t pipe, pipe_t tpipe, uint32_t size, uint32_t offset=0>
__aicore__ inline void set_flags() {
    for(uint32_t i = 0; i < size; i++)
        set_flag(pipe, tpipe, offset + i);
}

template<pipe_t pipe, pipe_t tpipe, uint32_t size, uint32_t offset=0>
__aicore__ inline void wait_flags() {
    for(uint32_t i = 0; i < size; i++)
        wait_flag(pipe, tpipe, offset + i);
}

template<pipe_t pipe, uint32_t size, uint32_t offset=0>
__aicore__ inline void set_intra_blocks(uint8_t subblock_id) {
    for(uint32_t i = 0; i < size; i++)
        set_intra_block(pipe, subblock_id, offset + i);
}

template<pipe_t pipe, uint32_t size, uint32_t offset=0>
__aicore__ inline void wait_intra_blocks(uint8_t subblock_id) {
    for(uint32_t i = 0; i < size; i++)
        wait_intra_block(pipe, subblock_id, offset + i);
}

}