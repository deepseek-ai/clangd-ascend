// SPDX-License-Identifier: MIT
// Copyright (c) 2026 DeepSeek
//

// Provides proper function signatures for CCE aicore intrinsics.
// This file is included before the runtime wrapper and loads types and enums
// from the local CANN headers below.
//
// Strategy:
//   - CCE_AICORE_INTRINSICS_ALIAS is defined here before loading the SDK
//     headers, so cce_aicore_intrinsics.h skips its (...) declarations.

#ifndef __CCE_INTRINSIC_STUBS_H__
#define __CCE_INTRINSIC_STUBS_H__

// Skip the (...) declarations in cce_aicore_intrinsics.h
#define CCE_AICORE_INTRINSICS_ALIAS

// Use the same target-aware integer definitions as the main shim.
#include "stdint_stubs.h"
#include <stddef.h>

// Pull in types: half, bfloat16_t, float8_e4m3_t, etc.
#include "__clang_cce_types.h"

// Pull in pipe_t and other enums from the TYPES section
// (ALIAS section is skipped because we pre-defined CCE_AICORE_INTRINSICS_ALIAS)
#include "cce_aicore_intrinsics.h"

#define __cce_stub_attribute(v) __attribute__((clang_builtin_alias(v)))

// --- Typed declarations ---
namespace __cce_scalar {
// PIPE_S, ASM: DFX_REGION.pipe 	xt
__cce_stub_attribute(__builtin_cce___dfx_region) void __dfx_region(uint32_t xt, pipe_t pipe);
// PIPE_S, ASM: SBCNT0.b64  	ret, in
__cce_stub_attribute(__builtin_cce_bcnt0) int64_t bcnt0(uint64_t in);
// PIPE_S, ASM: SBCNT1.b64  	ret, in
__cce_stub_attribute(__builtin_cce_bcnt1) int64_t bcnt1(uint64_t in);
// PIPE_S, ASM: CLZ.b64  	ret, in
__cce_stub_attribute(__builtin_cce_clz) int64_t clz(uint64_t in);
// PIPE_S, ASM: CONV.f322f16o 	ret, in
__cce_stub_attribute(__builtin_cce_conv_f322f16o) half conv_f322f16o(float in);
// PIPE_S, ASM: CONV.f322s32a 	ret, in
__cce_stub_attribute(__builtin_cce_conv_f322s32a) int64_t conv_f322s32a(float in);
// PIPE_S, ASM: CONV.f322s32c 	ret, in
__cce_stub_attribute(__builtin_cce_conv_f322s32c) int64_t conv_f322s32c(float in);
// PIPE_S, ASM: CONV.f322s32f 	ret, in
__cce_stub_attribute(__builtin_cce_conv_f322s32f) int64_t conv_f322s32f(float in);
// PIPE_S, ASM: CONV.f322s32r 	ret, in
__cce_stub_attribute(__builtin_cce_conv_f322s32r) int64_t conv_f322s32r(float in);
// PIPE_MTE1, ASM: MOV_L1_TO_BT.bf16 	[dst], [src], config
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_bt) void copy_cbuf_to_bt(uint64_t dst, __cbuf__ bfloat16_t *src, uint64_t config);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_bt) void copy_cbuf_to_bt(uint64_t dst, __cbuf__ bfloat16_t *src, bool convControl, uint16_t nBurst, uint16_t lenBurst, uint16_t sourceGap, uint16_t dstGap);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_bt) void copy_cbuf_to_bt(uint64_t dst, __cbuf__ half *src, uint64_t config);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_bt) void copy_cbuf_to_bt(uint64_t dst, __cbuf__ half *src, bool convControl, uint16_t nBurst, uint16_t lenBurst, uint16_t sourceGap, uint16_t dstGap);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_bt) void copy_cbuf_to_bt(uint64_t dst, __cbuf__ float *src, uint64_t config);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_bt) void copy_cbuf_to_bt(uint64_t dst, __cbuf__ float *src, bool convControl, uint16_t nBurst, uint16_t lenBurst, uint16_t sourceGap, uint16_t dstGap);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_bt) void copy_cbuf_to_bt(uint64_t dst, __cbuf__ int32_t *src, uint64_t config);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_bt) void copy_cbuf_to_bt(uint64_t dst, __cbuf__ int32_t *src, bool convControl, uint16_t nBurst, uint16_t lenBurst, uint16_t sourceGap, uint16_t dstGap);
// PIPE_FIX, ASM: MOV_L1_TO_FB 		[dst], [src], config
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_fbuf) void copy_cbuf_to_fbuf(__fbuf__ void *dst, __cbuf__ void *src, uint64_t config);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_fbuf) void copy_cbuf_to_fbuf(__fbuf__ void *dst, __cbuf__ void *src, uint16_t burstNum, uint16_t burstLen, uint16_t srcGapSize, uint16_t dstGapSize);
// PIPE_MTE1, ASM: MOV_L1_TO_FB_V2 		[dst], [src], config
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_fbuf_v2) void copy_cbuf_to_fbuf_v2(__fbuf__ void *dst, __cbuf__ void *src, uint64_t config);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_fbuf_v2) void copy_cbuf_to_fbuf_v2(__fbuf__ void *dst, __cbuf__ void *src, uint16_t burst_num, uint16_t burst_len, uint16_t src_stride, uint16_t dst_stride);
// PIPE_MTE1, ASM: MOV_L1_TO_UB 	[dst_addr], [src_addr], config
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_ubuf) void copy_cbuf_to_ubuf(__ubuf__ void *dst_addr, __cbuf__ void *src_addr, uint64_t config);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_ubuf) void copy_cbuf_to_ubuf(__ubuf__ void *dst_addr, __cbuf__ void *src_addr, bool sub_blockid, uint16_t burst_num, uint16_t burst_len, uint16_t src_gap, uint16_t dst_gap);
// PIPE_MTE2, ASM: MOV_OUT_TO_L1_ALIGN_V2.b16	[dst_addr], [src_addr], config0, config1
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ bfloat16_t *dst_addr, __gm__ bfloat16_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ bfloat16_t *dst_addr, __gm__ bfloat16_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ float8_e4m3_t *dst_addr, __gm__ float8_e4m3_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ float8_e4m3_t *dst_addr, __gm__ float8_e4m3_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ float8_e5m2_t *dst_addr, __gm__ float8_e5m2_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ float8_e5m2_t *dst_addr, __gm__ float8_e5m2_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ float8_e8m0_t *dst_addr, __gm__ float8_e8m0_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ float8_e8m0_t *dst_addr, __gm__ float8_e8m0_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ half *dst_addr, __gm__ half *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ half *dst_addr, __gm__ half *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ float *dst_addr, __gm__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ float *dst_addr, __gm__ float *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ hifloat8_t *dst_addr, __gm__ hifloat8_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ hifloat8_t *dst_addr, __gm__ hifloat8_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ int16_t *dst_addr, __gm__ int16_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ int16_t *dst_addr, __gm__ int16_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ int32_t *dst_addr, __gm__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ int32_t *dst_addr, __gm__ int32_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ int8_t *dst_addr, __gm__ int8_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ int8_t *dst_addr, __gm__ int8_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ uint16_t *dst_addr, __gm__ uint16_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ uint16_t *dst_addr, __gm__ uint16_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ uint32_t *dst_addr, __gm__ uint32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ uint32_t *dst_addr, __gm__ uint32_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ uint8_t *dst_addr, __gm__ uint8_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(__cbuf__ uint8_t *dst_addr, __gm__ uint8_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
// PIPE_MTE2, ASM: MOV_OUT_TO_L1_MULTI_DN2NZ.b16 	[dst_addr], [src_addr], config0, config1
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ bfloat16_t *dst_addr, __gm__ bfloat16_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ bfloat16_t *dst_addr, __gm__ bfloat16_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctl, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ float8_e4m3_t *dst_addr, __gm__ float8_e4m3_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ float8_e4m3_t *dst_addr, __gm__ float8_e4m3_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctl, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ float8_e5m2_t *dst_addr, __gm__ float8_e5m2_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ float8_e5m2_t *dst_addr, __gm__ float8_e5m2_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctl, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ float8_e8m0_t *dst_addr, __gm__ float8_e8m0_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ float8_e8m0_t *dst_addr, __gm__ float8_e8m0_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctl, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ half *dst_addr, __gm__ half *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ half *dst_addr, __gm__ half *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctl, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ float *dst_addr, __gm__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ float *dst_addr, __gm__ float *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctl, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ hifloat8_t *dst_addr, __gm__ hifloat8_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ hifloat8_t *dst_addr, __gm__ hifloat8_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctl, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ int16_t *dst_addr, __gm__ int16_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ int16_t *dst_addr, __gm__ int16_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctl, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ int32_t *dst_addr, __gm__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ int32_t *dst_addr, __gm__ int32_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctl, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ int8_t *dst_addr, __gm__ int8_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ int8_t *dst_addr, __gm__ int8_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctl, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ uint16_t *dst_addr, __gm__ uint16_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ uint16_t *dst_addr, __gm__ uint16_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctl, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ uint32_t *dst_addr, __gm__ uint32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ uint32_t *dst_addr, __gm__ uint32_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctl, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ uint8_t *dst_addr, __gm__ uint8_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(__cbuf__ uint8_t *dst_addr, __gm__ uint8_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctl, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
// PIPE_MTE2, ASM: MOV_OUT_TO_L1_MULTI_ND2NZ.b16 	[dst], [src], config0, config1
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ bfloat16_t *dst, __gm__ bfloat16_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ bfloat16_t *dst_addr, __gm__ bfloat16_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctrl_mode, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ float8_e4m3_t *dst, __gm__ float8_e4m3_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ float8_e4m3_t *dst_addr, __gm__ float8_e4m3_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctrl_mode, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ float8_e5m2_t *dst, __gm__ float8_e5m2_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ float8_e5m2_t *dst_addr, __gm__ float8_e5m2_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctrl_mode, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ float8_e8m0_t *dst, __gm__ float8_e8m0_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ float8_e8m0_t *dst_addr, __gm__ float8_e8m0_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctrl_mode, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ half *dst, __gm__ half *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ half *dst_addr, __gm__ half *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctrl_mode, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ float *dst, __gm__ float *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ float *dst_addr, __gm__ float *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctrl_mode, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ hifloat8_t *dst, __gm__ hifloat8_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ hifloat8_t *dst_addr, __gm__ hifloat8_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctrl_mode, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ int16_t *dst, __gm__ int16_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ int16_t *dst_addr, __gm__ int16_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctrl_mode, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ int32_t *dst, __gm__ int32_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ int32_t *dst_addr, __gm__ int32_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctrl_mode, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ int8_t *dst, __gm__ int8_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ int8_t *dst_addr, __gm__ int8_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctrl_mode, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ uint16_t *dst, __gm__ uint16_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ uint16_t *dst_addr, __gm__ uint16_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctrl_mode, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ uint32_t *dst, __gm__ uint32_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ uint32_t *dst_addr, __gm__ uint32_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctrl_mode, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ uint8_t *dst, __gm__ uint8_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(__cbuf__ uint8_t *dst_addr, __gm__ uint8_t *src_addr, uint8_t sid, uint64_t loop1_src_stride, uint8_t l2_cache_ctrl_mode, uint16_t n_value, uint32_t d_value, uint64_t loop4_src_stride, bool smallc0_en);
// PIPE_MTE2, ASM: MOV_OUT_TO_L1_V2 	[dst], [src], config0, config1
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_v2) void copy_gm_to_cbuf_v2(__cbuf__ void *dst, __gm__ void *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_v2) void copy_gm_to_cbuf_v2(__cbuf__ void *dst, __gm__ void *src, uint8_t sid, uint32_t nBurst, uint32_t lenBurst, uint8_t padFUncMode, uint8_t l2Ctrl, uint64_t srcStride, uint32_t dstStride);
// PIPE_MTE2, ASM: MOV_OUT_TO_UB_ALIGN_V2.b16	[dst_addr], [src_addr], config0, config1
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ bfloat16_t *dst_addr, __gm__ bfloat16_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ bfloat16_t *dst_addr, __gm__ bfloat16_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ float8_e4m3_t *dst_addr, __gm__ float8_e4m3_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ float8_e4m3_t *dst_addr, __gm__ float8_e4m3_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ float8_e5m2_t *dst_addr, __gm__ float8_e5m2_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ float8_e5m2_t *dst_addr, __gm__ float8_e5m2_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ float8_e8m0_t *dst_addr, __gm__ float8_e8m0_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ float8_e8m0_t *dst_addr, __gm__ float8_e8m0_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ half *dst_addr, __gm__ half *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ half *dst_addr, __gm__ half *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ float *dst_addr, __gm__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ float *dst_addr, __gm__ float *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ hifloat8_t *dst_addr, __gm__ hifloat8_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ hifloat8_t *dst_addr, __gm__ hifloat8_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ int16_t *dst_addr, __gm__ int16_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ int16_t *dst_addr, __gm__ int16_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ int32_t *dst_addr, __gm__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ int32_t *dst_addr, __gm__ int32_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ int8_t *dst_addr, __gm__ int8_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ int8_t *dst_addr, __gm__ int8_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ uint16_t *dst_addr, __gm__ uint16_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ uint16_t *dst_addr, __gm__ uint16_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ uint32_t *dst_addr, __gm__ uint32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ uint32_t *dst_addr, __gm__ uint32_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ uint8_t *dst_addr, __gm__ uint8_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(__ubuf__ uint8_t *dst_addr, __gm__ uint8_t *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t left_padding_count, uint8_t right_padding_count, bool data_select_bit, uint8_t l2_cache_ctl, uint64_t burst_src_stride, uint32_t burst_dst_stride);
// PIPE_FIX, ASM: FIX_L0C_TO_L1.f32 	[dst_addr], [src_addr], config0, config1
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ bfloat16_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ bfloat16_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ half *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ half *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ float8_e4m3_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ float8_e4m3_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ float8_e5m2_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ float8_e5m2_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ hifloat8_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ hifloat8_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ int8_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ int8_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ uint8_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ uint8_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ float *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ float *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ bfloat16_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ bfloat16_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ half *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ half *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ float8_e4m3_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ float8_e4m3_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ float8_e5m2_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ float8_e5m2_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ hifloat8_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ hifloat8_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ int8_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ int8_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ uint8_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ uint8_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ int32_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(__cbuf__ int32_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
// PIPE_FIX, ASM: FIX_L0C_TO_L1.f32 	[dst_addr], [src_addr], config0, config1
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf_s4) void copy_matrix_cc_to_cbuf_s4(__cbuf__ void *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf_s4) void copy_matrix_cc_to_cbuf_s4(__cbuf__ void *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf_s4) void copy_matrix_cc_to_cbuf_s4(__cbuf__ void *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf_s4) void copy_matrix_cc_to_cbuf_s4(__cbuf__ void *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
// PIPE_FIX, ASM: FIX_L0C_TO_OUT.f32 	[dst_addr], [src_addr], config0, config1
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ bfloat16_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ bfloat16_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ half *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ half *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ float8_e4m3_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ float8_e4m3_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ float8_e5m2_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ float8_e5m2_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ hifloat8_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ hifloat8_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ int8_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ int8_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ uint8_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ uint8_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ float *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ float *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ bfloat16_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ bfloat16_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ half *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ half *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ float8_e4m3_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ float8_e4m3_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ float8_e5m2_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ float8_e5m2_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ hifloat8_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ hifloat8_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ int8_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ int8_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ uint8_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ uint8_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ int32_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(__gm__ int32_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
// PIPE_FIX, ASM: FIX_L0C_TO_OUT.f32 	[dst_addr], [src_addr], config0, config1
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm_s4) void copy_matrix_cc_to_gm_s4(__gm__ void *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm_s4) void copy_matrix_cc_to_gm_s4(__gm__ void *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm_s4) void copy_matrix_cc_to_gm_s4(__gm__ void *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm_s4) void copy_matrix_cc_to_gm_s4(__gm__ void *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t l2_cache_ctl, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
// PIPE_FIX, ASM: FIX_L0C_TO_UB.f32 	[dst_addr], [src_addr], config0, config1
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ bfloat16_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ bfloat16_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ half *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ half *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ float8_e4m3_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ float8_e4m3_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ float8_e5m2_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ float8_e5m2_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ hifloat8_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ hifloat8_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ int8_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ int8_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ uint8_t *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ uint8_t *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ float *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ float *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ bfloat16_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ bfloat16_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ half *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ half *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ float8_e4m3_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ float8_e4m3_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ float8_e5m2_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ float8_e5m2_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ hifloat8_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ hifloat8_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ int8_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ int8_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ uint8_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ uint8_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ int32_t *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(__ubuf__ int32_t *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
// PIPE_FIX, ASM: FIX_L0C_TO_UB.f32 	[dst_addr], [src_addr], config0, config1
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub_s4) void copy_matrix_cc_to_ub_s4(__ubuf__ void *dst_addr, __cc__ float *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub_s4) void copy_matrix_cc_to_ub_s4(__ubuf__ void *dst_addr, __cc__ float *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub_s4) void copy_matrix_cc_to_ub_s4(__ubuf__ void *dst_addr, __cc__ int32_t *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub_s4) void copy_matrix_cc_to_ub_s4(__ubuf__ void *dst_addr, __cc__ int32_t *src_addr, uint8_t sid, uint16_t n_size, uint16_t m_size, uint32_t loop_dst_stride, uint16_t loop_src_stride, uint8_t dual_dst_ctl, bool sub_blockid, uint8_t clip_relu_pre, uint8_t unit_flag_ctl, uint64_t quant_pre, uint8_t relu_pre, bool split_en, bool NZ2ND_en, uint64_t quant_post, uint8_t relu_post, bool clip_relu_post, bool loop_enhance_en, uint8_t eltwise_op, bool eltwise_antq_en, bool loop_enhance_merge_en, bool C0_pad_en, bool wino_post_en, bool broadcast_en, bool NZ2DN_en);
// PIPE_MTE3, ASM: MOV_UB_TO_L1 	[dst_addr], [src_addr], config
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_cbuf) void copy_ubuf_to_cbuf(__cbuf__ void *dst_addr, __ubuf__ void *src_addr, uint64_t config);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_cbuf) void copy_ubuf_to_cbuf(__cbuf__ void *dst_addr, __ubuf__ void *src_addr, bool sub_blockid, uint16_t burst_num, uint16_t burst_len, uint16_t src_gap, uint16_t dst_gap);
// PIPE_MTE3, ASM: MOV_UB_TO_OUT_ALIGN_V2	[dst_addr], [src_addr], config0, config1
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_gm_align_v2) void copy_ubuf_to_gm_align_v2(__gm__ void *dst_addr, __ubuf__ void *src_addr, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_gm_align_v2) void copy_ubuf_to_gm_align_v2(__gm__ void *dst_addr, __ubuf__ void *src_addr, uint8_t sid, uint32_t burst_num, uint32_t burst_len, uint8_t l2_cache_ctl, uint64_t burst_dst_stride, uint32_t burst_src_stride);
// PIPE_V
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_ubuf) void copy_ubuf_to_ubuf(__ubuf__ void *dst, __ubuf__ void *src, uint16_t nBurst, uint16_t lenBurst, uint16_t srcGap, uint16_t dstGap);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_ubuf) void copy_ubuf_to_ubuf(__ubuf__ void *dst, __ubuf__ void *src, uint64_t config);
// PIPE_MTE1, ASM: SET_L1_2D.b16 	[dst], repeat
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix) void create_cbuf_matrix(__cbuf__ half *dst, int64_t repeat, uint32_t value);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix) void create_cbuf_matrix(__cbuf__ half *dst, int64_t repeat, half value);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix) void create_cbuf_matrix(__cbuf__ float *dst, int64_t repeat, uint32_t value);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix) void create_cbuf_matrix(__cbuf__ float *dst, int64_t repeat, half value);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix) void create_cbuf_matrix(__cbuf__ int16_t *dst, int64_t repeat, uint32_t value);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix) void create_cbuf_matrix(__cbuf__ int16_t *dst, int64_t repeat, half value);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix) void create_cbuf_matrix(__cbuf__ int32_t *dst, int64_t repeat, uint32_t value);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix) void create_cbuf_matrix(__cbuf__ int32_t *dst, int64_t repeat, half value);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix) void create_cbuf_matrix(__cbuf__ uint16_t *dst, int64_t repeat, uint32_t value);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix) void create_cbuf_matrix(__cbuf__ uint16_t *dst, int64_t repeat, half value);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix) void create_cbuf_matrix(__cbuf__ uint32_t *dst, int64_t repeat, uint32_t value);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix) void create_cbuf_matrix(__cbuf__ uint32_t *dst, int64_t repeat, half value);
// PIPE_MTE1, ASM: SET_L1_2D.b16 	[dst], repeat
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix_bf16) void create_cbuf_matrix_bf16(__cbuf__ bfloat16_t *dst, int64_t repeat, bfloat16_t value);
// PIPE_MTE1, ASM: SET_L1_2D.b16 	[dst], repeat
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix_h) void create_cbuf_matrix_h(__cbuf__ bfloat16_t *dst, int64_t repeat, half value);
// PIPE_MTE1, ASM: SET_L1_2D.b16 	[dst], repeat
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix_ui) void create_cbuf_matrix_ui(__cbuf__ bfloat16_t *dst, int64_t repeat, uint32_t value);
// PIPE_S, ASM: {DC_PRELOAD|DC_PRELOADI}	[address], #offset
__cce_stub_attribute(__builtin_cce_dc_preload) void dc_preload(__gm__ uint64_t *address, int16_t offset);
__cce_stub_attribute(__builtin_cce_dc_preload) void dc_preload(uint64_t *address, int16_t offset);
__cce_stub_attribute(__builtin_cce_dc_preload) void dc_preload(__gm__ uint64_t *address, int64_t offset);
__cce_stub_attribute(__builtin_cce_dc_preload) void dc_preload(uint64_t *address, int64_t offset);
// PIPE_S, ASM: DCI
__cce_stub_attribute(__builtin_cce_dci) void dci();
// PIPE_S, ASM: DSB 		#arg0
__cce_stub_attribute(__builtin_cce_dsb) void dsb(mem_dsb_t arg0);
// PIPE_S, ASM: FAKE_OVERFLOW_STATUS_1
__cce_stub_attribute(__builtin_cce_fake_overflow_status_1) uint64_t fake_overflow_status_1();
// PIPE_S, ASM: FAKE_OVERFLOW_STATUS_2
__cce_stub_attribute(__builtin_cce_fake_overflow_status_2) uint64_t fake_overflow_status_2();
// PIPE_S, ASM: SET_CROSS_CORE.pipe  	config
__cce_stub_attribute(__builtin_cce_ffts_cross_core_sync) void ffts_cross_core_sync(pipe_t pipe, uint64_t config);
// PIPE_S, ASM: MOV		ret, AR
__cce_stub_attribute(__builtin_cce_get_ar) int64_t get_ar();
// PIPE_S, ASM: MOV		ret, ARCH_VER
__cce_stub_attribute(__builtin_cce_get_arch_ver) int64_t get_arch_ver();
// PIPE_S, ASM: GET_BUFI.pipe 	#buf_ID, #mode
__cce_stub_attribute(__builtin_cce_get_buf) void get_buf(pipe_t pipe, uint8_t buf_ID, bool mode);
__cce_stub_attribute(__builtin_cce_get_buf) void get_buf(pipe_t pipe, uint64_t buf_ID, bool mode);
// PIPE_S, ASM: MOV		ret, CONDITION_FLAG
__cce_stub_attribute(__builtin_cce_get_condition_flag) int64_t get_condition_flag();
// PIPE_S, ASM: MOV		ret, COREID
__cce_stub_attribute(__builtin_cce_get_coreid) int64_t get_coreid();
// PIPE_S, ASM: MOV		ret, CTRL
__cce_stub_attribute(__builtin_cce_get_ctrl) int64_t get_ctrl();
// PIPE_S, ASM: MOV		ret, DATA_MAIN_BASE
__cce_stub_attribute(__builtin_cce_get_data_main_base) int64_t get_data_main_base();
// PIPE_S, ASM: MOV		ret, DATA_SIZE
__cce_stub_attribute(__builtin_cce_get_data_size) int64_t get_data_size();
// PIPE_S, ASM: MOV		ret, DATA_UB_BASE
__cce_stub_attribute(__builtin_cce_get_data_ub_base) int64_t get_data_ub_base();
// PIPE_S, ASM: MOV		ret, FFTS_BASE_ADDR
__cce_stub_attribute(__builtin_cce_get_ffts_base_addr) int64_t get_ffts_base_addr();
// PIPE_S, ASM: MOV		ret, GROUPBLOCKDIM
__cce_stub_attribute(__builtin_cce_get_groupblockdim) int64_t get_groupblockdim();
// PIPE_S, ASM: MOV		ret, GROUPBLOCKID
__cce_stub_attribute(__builtin_cce_get_groupblockid) int64_t get_groupblockid();
// PIPE_S, ASM: MOV		ret, GROUPDIM
__cce_stub_attribute(__builtin_cce_get_groupdim) int64_t get_groupdim();
// PIPE_S, ASM: MOV		ret, GROUPID
__cce_stub_attribute(__builtin_cce_get_groupid) int64_t get_groupid();
// PIPE_S, ASM: MOV		ret, ICACHE_PRL_ST
__cce_stub_attribute(__builtin_cce_get_icache_prl_st) int64_t get_icache_prl_st();
// PIPE_S, ASM: MOV 	ret, #imm0_15
__cce_stub_attribute(__builtin_cce_get_imm) uint64_t get_imm(uint64_t imm0_15);
__cce_stub_attribute(__builtin_cce_get_imm) uint64_t get_imm(uint64_t imm0_15, uint64_t imm16_31);
__cce_stub_attribute(__builtin_cce_get_imm) uint64_t get_imm(uint64_t imm0_15, uint64_t imm16_31, uint64_t imm32_47);
__cce_stub_attribute(__builtin_cce_get_imm) uint64_t get_imm(uint64_t imm0_15, uint64_t imm16_31, uint64_t imm32_47, uint64_t imm48_63);
// PIPE_S, ASM: GET_IQENT.pipe 	ret
__cce_stub_attribute(__builtin_cce_get_iqent) int64_t get_iqent(pipe_t pipe);
// PIPE_S, ASM: MOV		ret, L2_IN_MAIN
__cce_stub_attribute(__builtin_cce_get_l2_in_main) int64_t get_l2_in_main();
// PIPE_S, ASM: MOV		ret, L2_VADDR_BASE
__cce_stub_attribute(__builtin_cce_get_l2_vaddr_base) int64_t get_l2_vaddr_base();
// PIPE_S, ASM: MOV		ret, ONLY_COREID
__cce_stub_attribute(__builtin_cce_get_only_coreid) int64_t get_only_coreid();
// PIPE_S, ASM: GET_OVERFLOW_STATUS 	ret
__cce_stub_attribute(__builtin_cce_get_overflow_status) uint64_t get_overflow_status();
// PIPE_S, ASM: MOV		ret, PARA_BASE
__cce_stub_attribute(__builtin_cce_get_para_base) int64_t get_para_base();
// PIPE_S, ASM: MOV		ret, PC
__cce_stub_attribute(__builtin_cce_get_pc) int64_t get_pc();
// PIPE_S, ASM: MOV		ret, RPN_COR_IR
__cce_stub_attribute(__builtin_cce_get_rpn_cor_ir) int64_t get_rpn_cor_ir();
// PIPE_S, ASM: MOV		ret, SHMEM_SZ
__cce_stub_attribute(__builtin_cce_get_shmem_sz) int64_t get_shmem_sz();
// PIPE_S, ASM: MOV		ret, SMMU_TAG_VER
__cce_stub_attribute(__builtin_cce_get_smmu_tag_ver) int64_t get_smmu_tag_ver();
// PIPE_S, ASM: MOV		ret, ST_ATOMIC_CFG
__cce_stub_attribute(__builtin_cce_get_st_atomic_cfg) int64_t get_st_atomic_cfg();
// PIPE_S, ASM: MOV		ret, STACK_PHY_BASE
__cce_stub_attribute(__builtin_cce_get_stack_phy_base) int64_t get_stack_phy_base();
// PIPE_S, ASM: MOV		ret, STATUS
__cce_stub_attribute(__builtin_cce_get_status) int64_t get_status();
// PIPE_S, ASM: MOV		ret, SUBBLOCKDIM
__cce_stub_attribute(__builtin_cce_get_subblockdim) int64_t get_subblockdim();
// PIPE_S, ASM: MOV		ret, SUBBLOCKID
__cce_stub_attribute(__builtin_cce_get_subblockid) int64_t get_subblockid();
// PIPE_S, ASM: MOV		ret, SYS_CNT
__cce_stub_attribute(__builtin_cce_get_sys_cnt) int64_t get_sys_cnt();
// PIPE_S, ASM: MOV		ret, SYS_VA_BASE
__cce_stub_attribute(__builtin_cce_get_sys_va_base) int64_t get_sys_va_base();
// PIPE_S, ASM: MOV		ret, THREAD_DIM
__cce_stub_attribute(__builtin_cce_get_thread_dim) int64_t get_thread_dim();
// PIPE_S, ASM: MOV		ret, THREAD_ID
__cce_stub_attribute(__builtin_cce_get_thread_id) int64_t get_thread_id();
// PIPE_S, ASM: MOV		ret, VL
__cce_stub_attribute(__builtin_cce_get_vl) int64_t get_vl();
// PIPE_S, ASM: MOV		ret, VMS4_SR
__cce_stub_attribute(__builtin_cce_get_vms4_sr) int64_t get_vms4_sr();
// PIPE_S, ASM: {HSET_FLAG|HSET_FLAGI}.pipe.tpipe  	#eventID, #memory, #v
__cce_stub_attribute(__builtin_cce_hset_flag) void hset_flag(pipe_t pipe, pipe_t tpipe, event_t eventID, mem_t memory, bool v);
__cce_stub_attribute(__builtin_cce_hset_flag) void hset_flag(pipe_t pipe, pipe_t tpipe, uint64_t eventID, mem_t memory, bool v);
// PIPE_S, ASM: {HWAIT_FLAG|HWAIT_FLAGI}.pipe.tpipe  	#eventID, #memory, #v
__cce_stub_attribute(__builtin_cce_hwait_flag) void hwait_flag(pipe_t pipe, pipe_t tpipe, event_t eventID, mem_t memory, bool v);
__cce_stub_attribute(__builtin_cce_hwait_flag) void hwait_flag(pipe_t pipe, pipe_t tpipe, uint64_t eventID, mem_t memory, bool v);
// PIPE_MTE1, ASM: LOAD_L1_TO_L0A_3DV2.b16 [dst], [src], config0, config1, #0
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint64_t config0, uint64_t config1, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ float8_e4m3_t *dst, __cbuf__ float8_e4m3_t *src, uint64_t config0, uint64_t config1, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ float8_e4m3_t *dst, __cbuf__ float8_e4m3_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ float8_e4m3_t *dst, __cbuf__ float8_e4m3_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ float8_e4m3_t *dst, __cbuf__ float8_e4m3_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ float8_e5m2_t *dst, __cbuf__ float8_e5m2_t *src, uint64_t config0, uint64_t config1, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ float8_e5m2_t *dst, __cbuf__ float8_e5m2_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ float8_e5m2_t *dst, __cbuf__ float8_e5m2_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ float8_e5m2_t *dst, __cbuf__ float8_e5m2_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ half *dst, __cbuf__ half *src, uint64_t config0, uint64_t config1, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ half *dst, __cbuf__ half *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ half *dst, __cbuf__ half *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ half *dst, __cbuf__ half *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ float *dst, __cbuf__ float *src, uint64_t config0, uint64_t config1, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ float *dst, __cbuf__ float *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ float *dst, __cbuf__ float *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ float *dst, __cbuf__ float *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint64_t config0, uint64_t config1, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ int16_t *dst, __cbuf__ int16_t *src, uint64_t config0, uint64_t config1, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ int16_t *dst, __cbuf__ int16_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ int16_t *dst, __cbuf__ int16_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ int16_t *dst, __cbuf__ int16_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ int32_t *dst, __cbuf__ int32_t *src, uint64_t config0, uint64_t config1, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ int32_t *dst, __cbuf__ int32_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ int32_t *dst, __cbuf__ int32_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ int32_t *dst, __cbuf__ int32_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ int8_t *dst, __cbuf__ int8_t *src, uint64_t config0, uint64_t config1, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ int8_t *dst, __cbuf__ int8_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ int8_t *dst, __cbuf__ int8_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ int8_t *dst, __cbuf__ int8_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ uint16_t *dst, __cbuf__ uint16_t *src, uint64_t config0, uint64_t config1, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ uint16_t *dst, __cbuf__ uint16_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ uint16_t *dst, __cbuf__ uint16_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ uint16_t *dst, __cbuf__ uint16_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ uint32_t *dst, __cbuf__ uint32_t *src, uint64_t config0, uint64_t config1, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ uint32_t *dst, __cbuf__ uint32_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ uint32_t *dst, __cbuf__ uint32_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ uint32_t *dst, __cbuf__ uint32_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ uint8_t *dst, __cbuf__ uint8_t *src, uint64_t config0, uint64_t config1, bm_t enDualSrc);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ uint8_t *dst, __cbuf__ uint8_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ uint8_t *dst, __cbuf__ uint8_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(__ca__ uint8_t *dst, __cbuf__ uint8_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel, bm_t enDualSrc);
// PIPE_MTE1, ASM: LOAD_L1_TO_L0B_3DV2.b16 [dst], [src], config0, config1
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ float8_e4m3_t *dst, __cbuf__ float8_e4m3_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ float8_e4m3_t *dst, __cbuf__ float8_e4m3_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ float8_e5m2_t *dst, __cbuf__ float8_e5m2_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ float8_e5m2_t *dst, __cbuf__ float8_e5m2_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ half *dst, __cbuf__ half *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ half *dst, __cbuf__ half *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ float *dst, __cbuf__ float *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ float *dst, __cbuf__ float *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ int16_t *dst, __cbuf__ int16_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ int16_t *dst, __cbuf__ int16_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ int32_t *dst, __cbuf__ int32_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ int32_t *dst, __cbuf__ int32_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ int8_t *dst, __cbuf__ int8_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ int8_t *dst, __cbuf__ int8_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ uint16_t *dst, __cbuf__ uint16_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ uint16_t *dst, __cbuf__ uint16_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ uint32_t *dst, __cbuf__ uint32_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ uint32_t *dst, __cbuf__ uint32_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ uint8_t *dst, __cbuf__ uint8_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(__cb__ uint8_t *dst, __cbuf__ uint8_t *src, uint16_t stepK, uint16_t stepM, uint16_t posK, uint16_t posM, uint8_t strideW, uint8_t strideH, uint8_t Wk, uint8_t Hk, uint8_t dilationW, uint8_t dilationH, bool filterW, bool filterH, bool transpose, bool fmatrixCtrl, uint16_t sizeChannel);
// PIPE_S, ASM: {INSERT|INSERTI} 		dst, #uimm8, #pos, #ext
__cce_stub_attribute(__builtin_cce_insert_imm) uint64_t insert_imm(uint64_t dst, uint8_t uimm8, uint8_t pos, bool ext);
// PIPE_S, ASM: INSERT 		dst, src, #k, #n
__cce_stub_attribute(__builtin_cce_insert_reg) uint64_t insert_reg(uint64_t dst, uint64_t src, uint8_t k, uint8_t n);
// PIPE_S, ASM: LD_DEV.b16	ret, [src], #offset
__cce_stub_attribute(__builtin_cce_ld_dev) uint64_t ld_dev(half *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) uint64_t ld_dev(__gm__ half *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) int64_t ld_dev(int16_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) int64_t ld_dev(__gm__ int16_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) int64_t ld_dev(int32_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) int64_t ld_dev(__gm__ int32_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) int64_t ld_dev(int64_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) int64_t ld_dev(__gm__ int64_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) int64_t ld_dev(int8_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) int64_t ld_dev(__gm__ int8_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) uint64_t ld_dev(uint16_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) uint64_t ld_dev(__gm__ uint16_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) uint64_t ld_dev(uint32_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) uint64_t ld_dev(__gm__ uint32_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) uint64_t ld_dev(uint64_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) uint64_t ld_dev(__gm__ uint64_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) uint64_t ld_dev(uint8_t *src, int16_t offset);
__cce_stub_attribute(__builtin_cce_ld_dev) uint64_t ld_dev(__gm__ uint8_t *src, int16_t offset);
// PIPE_V, ASM: LDVA 		dst, [src], #h
__cce_stub_attribute(__builtin_cce_ldva) void ldva(ub_addr8_t dst, uint64_t src, bool h);
// PIPE_MTE1, ASM: LOAD_L1_TO_L0A_2DV2.b16 	[dst], [src], config0, config1, #transpose
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ float8_e4m3_t *dst, __cbuf__ float8_e4m3_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ float8_e4m3_t *dst, __cbuf__ float8_e4m3_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ float8_e5m2_t *dst, __cbuf__ float8_e5m2_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ float8_e5m2_t *dst, __cbuf__ float8_e5m2_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ half *dst, __cbuf__ half *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ half *dst, __cbuf__ half *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ float *dst, __cbuf__ float *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ float *dst, __cbuf__ float *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ int16_t *dst, __cbuf__ int16_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ int16_t *dst, __cbuf__ int16_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ int32_t *dst, __cbuf__ int32_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ int32_t *dst, __cbuf__ int32_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ int8_t *dst, __cbuf__ int8_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ int8_t *dst, __cbuf__ int8_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ uint16_t *dst, __cbuf__ uint16_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ uint16_t *dst, __cbuf__ uint16_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ uint32_t *dst, __cbuf__ uint32_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ uint32_t *dst, __cbuf__ uint32_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ uint8_t *dst, __cbuf__ uint8_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(__ca__ uint8_t *dst, __cbuf__ uint8_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
// PIPE_MTE1, ASM: LOAD_L1_TO_L0A_MX_2DV2 	[dst], [src], config0, config1
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca_mx) void load_cbuf_to_ca_mx(uint64_t dst, __cbuf__ void *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca_mx) void load_cbuf_to_ca_mx(uint64_t dst, __cbuf__ void *src, uint16_t xStartPosition, uint16_t yStartPosition, uint8_t xStep, uint8_t yStep, uint16_t srcStride, uint16_t dstStride);
// PIPE_MTE1, ASM: LOAD_L1_TO_L0A_2DV2.b4 	[dst], [src], config0, config1, #transpose
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca_s4) void load_cbuf_to_ca_s4(__ca__ float4_e1m2x2_t *dst, __cbuf__ float4_e1m2x2_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca_s4) void load_cbuf_to_ca_s4(__ca__ float4_e1m2x2_t *dst, __cbuf__ float4_e1m2x2_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca_s4) void load_cbuf_to_ca_s4(__ca__ float4_e2m1x2_t *dst, __cbuf__ float4_e2m1x2_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca_s4) void load_cbuf_to_ca_s4(__ca__ float4_e2m1x2_t *dst, __cbuf__ float4_e2m1x2_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca_s4) void load_cbuf_to_ca_s4(__ca__ void *dst, __cbuf__ void *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca_s4) void load_cbuf_to_ca_s4(__ca__ void *dst, __cbuf__ void *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
// PIPE_MTE1, ASM: LOAD_L1_TO_L0B_2DV2.b16 	[dst], [src], config0, config1, #transpose
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ float8_e4m3_t *dst, __cbuf__ float8_e4m3_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ float8_e4m3_t *dst, __cbuf__ float8_e4m3_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ float8_e5m2_t *dst, __cbuf__ float8_e5m2_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ float8_e5m2_t *dst, __cbuf__ float8_e5m2_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ half *dst, __cbuf__ half *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ half *dst, __cbuf__ half *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ float *dst, __cbuf__ float *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ float *dst, __cbuf__ float *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ int16_t *dst, __cbuf__ int16_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ int16_t *dst, __cbuf__ int16_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ int32_t *dst, __cbuf__ int32_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ int32_t *dst, __cbuf__ int32_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ int8_t *dst, __cbuf__ int8_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ int8_t *dst, __cbuf__ int8_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ uint16_t *dst, __cbuf__ uint16_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ uint16_t *dst, __cbuf__ uint16_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ uint32_t *dst, __cbuf__ uint32_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ uint32_t *dst, __cbuf__ uint32_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ uint8_t *dst, __cbuf__ uint8_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(__cb__ uint8_t *dst, __cbuf__ uint8_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
// PIPE_MTE1, ASM: LOAD_L1_TO_L0B_MX_2DV2 	[dst], [src], config0, config1
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_mx) void load_cbuf_to_cb_mx(uint64_t dst, __cbuf__ void *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_mx) void load_cbuf_to_cb_mx(uint64_t dst, __cbuf__ void *src, uint16_t xStartPosition, uint16_t yStartPosition, uint8_t xStep, uint8_t yStep, uint16_t srcStride, uint16_t dstStride);
// PIPE_MTE1, ASM: LOAD_L1_TO_L0B_2DV2.b4 	[dst], [src], config0, config1, #transpose
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_s4) void load_cbuf_to_cb_s4(__cb__ float4_e1m2x2_t *dst, __cbuf__ float4_e1m2x2_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_s4) void load_cbuf_to_cb_s4(__cb__ float4_e1m2x2_t *dst, __cbuf__ float4_e1m2x2_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_s4) void load_cbuf_to_cb_s4(__cb__ float4_e2m1x2_t *dst, __cbuf__ float4_e2m1x2_t *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_s4) void load_cbuf_to_cb_s4(__cb__ float4_e2m1x2_t *dst, __cbuf__ float4_e2m1x2_t *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_s4) void load_cbuf_to_cb_s4(__cb__ void *dst, __cbuf__ void *src, uint64_t config0, uint64_t config1, bool transpose);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_s4) void load_cbuf_to_cb_s4(__cb__ void *dst, __cbuf__ void *src, uint16_t mStartPosition, uint16_t kStartPosition, uint8_t mStep, uint8_t kStep, int16_t srcStride, uint16_t dstStride, bool transpose);
// PIPE_MTE1, ASM: LOAD_L1_TO_L0B_2D_SP.b16 	[dst], [src], config
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_sp) void load_cbuf_to_cb_sp(__cb__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint64_t config);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_sp) void load_cbuf_to_cb_sp(__cb__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint16_t startID, uint8_t repeatTime);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_sp) void load_cbuf_to_cb_sp(__cb__ half *dst, __cbuf__ half *src, uint64_t config);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_sp) void load_cbuf_to_cb_sp(__cb__ half *dst, __cbuf__ half *src, uint16_t startID, uint8_t repeatTime);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_sp) void load_cbuf_to_cb_sp(__cb__ float *dst, __cbuf__ float *src, uint64_t config);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_sp) void load_cbuf_to_cb_sp(__cb__ float *dst, __cbuf__ float *src, uint16_t startID, uint8_t repeatTime);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_sp) void load_cbuf_to_cb_sp(__cb__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint64_t config);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_sp) void load_cbuf_to_cb_sp(__cb__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint16_t startID, uint8_t repeatTime);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_sp) void load_cbuf_to_cb_sp(__cb__ int8_t *dst, __cbuf__ int8_t *src, uint64_t config);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_sp) void load_cbuf_to_cb_sp(__cb__ int8_t *dst, __cbuf__ int8_t *src, uint16_t startID, uint8_t repeatTime);
// PIPE_MTE1, ASM: LOAD_L1_TO_L0B_2D_TRANSPOSE.b16 	[dst], [src], config, fracStride
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint64_t config, uint64_t fracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ bfloat16_t *dst, __cbuf__ bfloat16_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride, uint16_t srcFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__ca__ float8_e4m3_t *dst, __cbuf__ float8_e4m3_t *src, uint64_t config, uint64_t fracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__ca__ float8_e4m3_t *dst, __cbuf__ float8_e4m3_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__ca__ float8_e4m3_t *dst, __cbuf__ float8_e4m3_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride, uint16_t srcFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__ca__ float8_e5m2_t *dst, __cbuf__ float8_e5m2_t *src, uint64_t config, uint64_t fracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__ca__ float8_e5m2_t *dst, __cbuf__ float8_e5m2_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__ca__ float8_e5m2_t *dst, __cbuf__ float8_e5m2_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride, uint16_t srcFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ half *dst, __cbuf__ half *src, uint64_t config, uint64_t fracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ half *dst, __cbuf__ half *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride, uint16_t srcFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ float *dst, __cbuf__ float *src, uint64_t config, uint64_t fracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ float *dst, __cbuf__ float *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride, uint16_t srcFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__ca__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint64_t config, uint64_t fracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__ca__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__ca__ hifloat8_t *dst, __cbuf__ hifloat8_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride, uint16_t srcFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ int32_t *dst, __cbuf__ int32_t *src, uint64_t config, uint64_t fracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ int32_t *dst, __cbuf__ int32_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride, uint16_t srcFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ int8_t *dst, __cbuf__ int8_t *src, uint64_t config, uint64_t fracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ int8_t *dst, __cbuf__ int8_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride, uint16_t srcFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ uint32_t *dst, __cbuf__ uint32_t *src, uint64_t config, uint64_t fracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ uint32_t *dst, __cbuf__ uint32_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride, uint16_t srcFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ uint8_t *dst, __cbuf__ uint8_t *src, uint64_t config, uint64_t fracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(__cb__ uint8_t *dst, __cbuf__ uint8_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride, uint16_t srcFracStride);
// PIPE_MTE1, ASM: LOAD_L1_TO_L0B_2D_TRANSPOSE.b4 	[dst], [src], config, fracStride
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose_s4) void load_cbuf_to_cb_transpose_s4(__ca__ float4_e1m2x2_t *dst, __cbuf__ float4_e1m2x2_t *src, uint64_t config, uint64_t fracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose_s4) void load_cbuf_to_cb_transpose_s4(__ca__ float4_e1m2x2_t *dst, __cbuf__ float4_e1m2x2_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose_s4) void load_cbuf_to_cb_transpose_s4(__ca__ float4_e1m2x2_t *dst, __cbuf__ float4_e1m2x2_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride, uint16_t srcFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose_s4) void load_cbuf_to_cb_transpose_s4(__ca__ float4_e2m1x2_t *dst, __cbuf__ float4_e2m1x2_t *src, uint64_t config, uint64_t fracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose_s4) void load_cbuf_to_cb_transpose_s4(__ca__ float4_e2m1x2_t *dst, __cbuf__ float4_e2m1x2_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose_s4) void load_cbuf_to_cb_transpose_s4(__ca__ float4_e2m1x2_t *dst, __cbuf__ float4_e2m1x2_t *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride, uint16_t srcFracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose_s4) void load_cbuf_to_cb_transpose_s4(__cb__ void *dst, __cbuf__ void *src, uint64_t config, uint64_t fracStride);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose_s4) void load_cbuf_to_cb_transpose_s4(__cb__ void *dst, __cbuf__ void *src, uint16_t indexID, uint8_t repeat, uint16_t srcStride, uint16_t dstStride, bool addrmode, uint16_t dstFracStride, uint16_t srcFracStride);
// PIPE_MTE2, ASM: LOAD_OUT_TO_L1_2DV2 	[dst], [src], config0, config1
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ bfloat16_t *dst, __gm__ bfloat16_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ bfloat16_t *dst, __gm__ bfloat16_t *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ float8_e4m3_t *dst, __gm__ float8_e4m3_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ float8_e4m3_t *dst, __gm__ float8_e4m3_t *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ float8_e5m2_t *dst, __gm__ float8_e5m2_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ float8_e5m2_t *dst, __gm__ float8_e5m2_t *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ float8_e8m0_t *dst, __gm__ float8_e8m0_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ float8_e8m0_t *dst, __gm__ float8_e8m0_t *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ half *dst, __gm__ half *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ half *dst, __gm__ half *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ float *dst, __gm__ float *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ float *dst, __gm__ float *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ hifloat8_t *dst, __gm__ hifloat8_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ hifloat8_t *dst, __gm__ hifloat8_t *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ int16_t *dst, __gm__ int16_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ int16_t *dst, __gm__ int16_t *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ int32_t *dst, __gm__ int32_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ int32_t *dst, __gm__ int32_t *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ int8_t *dst, __gm__ int8_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ int8_t *dst, __gm__ int8_t *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ uint16_t *dst, __gm__ uint16_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ uint16_t *dst, __gm__ uint16_t *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ uint32_t *dst, __gm__ uint32_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ uint32_t *dst, __gm__ uint32_t *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ uint8_t *dst, __gm__ uint8_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(__cbuf__ uint8_t *dst, __gm__ uint8_t *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
// PIPE_MTE2, ASM: LOAD_OUT_TO_L1_2DV2 	[dst], [src], config0, config1
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2_s4) void load_gm_to_cbuf_2dv2_s4(__cbuf__ float4_e1m2x2_t *dst, __gm__ float4_e1m2x2_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2_s4) void load_gm_to_cbuf_2dv2_s4(__cbuf__ float4_e1m2x2_t *dst, __gm__ float4_e1m2x2_t *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2_s4) void load_gm_to_cbuf_2dv2_s4(__cbuf__ float4_e2m1x2_t *dst, __gm__ float4_e2m1x2_t *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2_s4) void load_gm_to_cbuf_2dv2_s4(__cbuf__ float4_e2m1x2_t *dst, __gm__ float4_e2m1x2_t *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2_s4) void load_gm_to_cbuf_2dv2_s4(__cbuf__ void *dst, __gm__ void *src, uint64_t config0, uint64_t config1);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2_s4) void load_gm_to_cbuf_2dv2_s4(__cbuf__ void *dst, __gm__ void *src, uint32_t mStartPosition, uint32_t kStartPosition, uint16_t dstStride, uint16_t mStep, uint16_t kStep, uint8_t sid, uint8_t decompMode, uint8_t l2CacheCtl);
// PIPE_M, ASM: MMAD.bf162f32	[c], [a], [b], config
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ bfloat16_t *a, __cb__ bfloat16_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ bfloat16_t *a, __cb__ bfloat16_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ float8_e4m3_t *a, __cb__ float8_e4m3_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ float8_e4m3_t *a, __cb__ float8_e4m3_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ float8_e4m3_t *a, __cb__ float8_e5m2_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ float8_e4m3_t *a, __cb__ float8_e5m2_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ float8_e5m2_t *a, __cb__ float8_e4m3_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ float8_e5m2_t *a, __cb__ float8_e4m3_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ float8_e5m2_t *a, __cb__ float8_e5m2_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ float8_e5m2_t *a, __cb__ float8_e5m2_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ half *a, __cb__ half *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ half *a, __cb__ half *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ float *a, __cb__ float *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ float *c, __ca__ float *a, __cb__ float *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ int32_t *c, __ca__ int8_t *a, __cb__ int8_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad) void mad(__cc__ int32_t *c, __ca__ int8_t *a, __cb__ int8_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
// PIPE_M, ASM: MMAD_MX.e1m2e1m2	[c], [a], [b], config
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float4_e1m2x2_t *a, __cb__ float4_e1m2x2_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float4_e1m2x2_t *a, __cb__ float4_e1m2x2_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float4_e1m2x2_t *a, __cb__ float4_e2m1x2_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float4_e1m2x2_t *a, __cb__ float4_e2m1x2_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float4_e2m1x2_t *a, __cb__ float4_e1m2x2_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float4_e2m1x2_t *a, __cb__ float4_e1m2x2_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float4_e2m1x2_t *a, __cb__ float4_e2m1x2_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float4_e2m1x2_t *a, __cb__ float4_e2m1x2_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float8_e4m3_t *a, __cb__ float8_e4m3_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float8_e4m3_t *a, __cb__ float8_e4m3_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float8_e4m3_t *a, __cb__ float8_e5m2_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float8_e4m3_t *a, __cb__ float8_e5m2_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float8_e5m2_t *a, __cb__ float8_e4m3_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float8_e5m2_t *a, __cb__ float8_e4m3_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float8_e5m2_t *a, __cb__ float8_e5m2_t *b, uint64_t config);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(__cc__ float *c, __ca__ float8_e5m2_t *a, __cb__ float8_e5m2_t *b, uint16_t m, uint16_t k, uint16_t n, uint8_t unit_Flag_ctrl, bool gemv_ctrl, bool BTbuf_ctrl, bool zero_Cmatrix_ctrl);
// PIPE_V, ASM: MOV_VSPR 	#spr_id, config
__cce_stub_attribute(__builtin_cce_mov_vspr) void mov_vspr(VSPR_t spr_id, uint64_t config);
// PIPE_S
__cce_stub_attribute(__builtin_cce_mte4_mte5_off) void mte4_mte5_off();
// PIPE_S
__cce_stub_attribute(__builtin_cce_mte4_mte5_on) void mte4_mte5_on();
// PIPE_S, ASM: ND_DMA_DCI
__cce_stub_attribute(__builtin_cce_nd_dma_dci) void nd_dma_dci();
// PIPE_MTE2, ASM: ND_DMA_OUT_TO_UB.b16 	[dst], [src], config, secConfig
__cce_stub_attribute(__builtin_cce_nddma_out_to_ub_b16) void nddma_out_to_ub_b16(__ubuf__ void *dst, __gm__ void *src, uint64_t config, uint64_t secConfig);
__cce_stub_attribute(__builtin_cce_nddma_out_to_ub_b16) void nddma_out_to_ub_b16(__ubuf__ void *dst, __gm__ void *src, uint8_t sid, uint32_t loop0_size, uint32_t loop1_size, uint32_t loop2_size, uint32_t loop3_size, uint32_t loop4_size, uint8_t loop0_lp_size, uint8_t loop0_rp_size, bool constant_padding_ctl, uint8_t l2_cache_ctl);
// PIPE_MTE2, ASM: ND_DMA_OUT_TO_UB.b32 	[dst], [src], config, secConfig
__cce_stub_attribute(__builtin_cce_nddma_out_to_ub_b32) void nddma_out_to_ub_b32(__ubuf__ void *dst, __gm__ void *src, uint64_t config, uint64_t secConfig);
__cce_stub_attribute(__builtin_cce_nddma_out_to_ub_b32) void nddma_out_to_ub_b32(__ubuf__ void *dst, __gm__ void *src, uint8_t sid, uint32_t loop0_size, uint32_t loop1_size, uint32_t loop2_size, uint32_t loop3_size, uint32_t loop4_size, uint8_t loop0_lp_size, uint8_t loop0_rp_size, bool constant_padding_ctl, uint8_t l2_cache_ctl);
// PIPE_MTE2, ASM: ND_DMA_OUT_TO_UB.b8 	[dst], [src], config, secConfig
__cce_stub_attribute(__builtin_cce_nddma_out_to_ub_b8) void nddma_out_to_ub_b8(__ubuf__ void *dst, __gm__ void *src, uint64_t config, uint64_t secConfig);
__cce_stub_attribute(__builtin_cce_nddma_out_to_ub_b8) void nddma_out_to_ub_b8(__ubuf__ void *dst, __gm__ void *src, uint8_t sid, uint32_t loop0_size, uint32_t loop1_size, uint32_t loop2_size, uint32_t loop3_size, uint32_t loop4_size, uint8_t loop0_lp_size, uint8_t loop0_rp_size, bool constant_padding_ctl, uint8_t l2_cache_ctl);
// PIPE_MTE2, ASM: ND_DMA_UB_TO_UB.b16 	[dst], [src], config, secConfig
__cce_stub_attribute(__builtin_cce_nddma_ub_to_ub_b16) void nddma_ub_to_ub_b16(__ubuf__ void *dst, __ubuf__ void *src, uint64_t config, uint64_t secConfig);
// PIPE_MTE2, ASM: ND_DMA_UB_TO_UB.b32 	[dst], [src], config, secConfig
__cce_stub_attribute(__builtin_cce_nddma_ub_to_ub_b32) void nddma_ub_to_ub_b32(__ubuf__ void *dst, __ubuf__ void *src, uint64_t config, uint64_t secConfig);
// PIPE_MTE2, ASM: ND_DMA_UB_TO_UB.b8 	[dst], [src], config, secConfig
__cce_stub_attribute(__builtin_cce_nddma_ub_to_ub_b8) void nddma_ub_to_ub_b8(__ubuf__ void *dst, __ubuf__ void *src, uint64_t config, uint64_t secConfig);
// PIPE_S
__cce_stub_attribute(__builtin_cce_pc_trace_off) void pc_trace_off();
// PIPE_S
__cce_stub_attribute(__builtin_cce_pc_trace_on) void pc_trace_on();
// PIPE_S, ASM: BAR.pipe
__cce_stub_attribute(__builtin_cce_pipe_barrier) void pipe_barrier(pipe_t pipe);
// PIPE_V, ASM: RELEASE_PBID 		src
__cce_stub_attribute(__builtin_cce_release_pbid) void release_pbid(uint64_t src);
// PIPE_S, ASM: RLS_BUFI.pipe 	#buf_ID, #mode
__cce_stub_attribute(__builtin_cce_rls_buf) void rls_buf(pipe_t pipe, uint8_t buf_ID, bool mode);
__cce_stub_attribute(__builtin_cce_rls_buf) void rls_buf(pipe_t pipe, uint64_t buf_ID, bool mode);
// PIPE_S, ASM: SBITSET0.b64  	x, idx
__cce_stub_attribute(__builtin_cce_sbitset0) uint64_t sbitset0(uint64_t x, int64_t idx);
// PIPE_S, ASM: SBITSET1.b64  	x, idx
__cce_stub_attribute(__builtin_cce_sbitset1) uint64_t sbitset1(uint64_t x, int64_t idx);
// PIPE_V, ASM: VNCHWCONV.b16 	[dst], [src], config, #0, #0 // VA reg version
__cce_stub_attribute(__builtin_cce_scatter_vnchwconv_b16) void scatter_vnchwconv_b16(ub_addr8_t dst, ub_addr8_t src, uint64_t config);
__cce_stub_attribute(__builtin_cce_scatter_vnchwconv_b16) void scatter_vnchwconv_b16(ub_addr8_t dst, ub_addr8_t src, uint8_t repeat, uint16_t dstStride, uint16_t srcStride);
// PIPE_V, ASM: VNCHWCONV.b32 	[dst], [src], config, #0, #0 // VA reg version
__cce_stub_attribute(__builtin_cce_scatter_vnchwconv_b32) void scatter_vnchwconv_b32(ub_addr8_t dst, ub_addr8_t src, uint64_t config);
__cce_stub_attribute(__builtin_cce_scatter_vnchwconv_b32) void scatter_vnchwconv_b32(ub_addr8_t dst, ub_addr8_t src, uint8_t repeat, uint16_t dstStride, uint16_t srcStride);
// PIPE_V, ASM: VNCHWCONV.b8 	[dst], [src], config, #dstHighHalf, #srcHighHalf // VA reg version
__cce_stub_attribute(__builtin_cce_scatter_vnchwconv_b8) void scatter_vnchwconv_b8(ub_addr8_t dst, ub_addr8_t src, uint64_t config, bool dstHighHalf, bool srcHighHalf);
__cce_stub_attribute(__builtin_cce_scatter_vnchwconv_b8) void scatter_vnchwconv_b8(ub_addr8_t dst, ub_addr8_t src, uint8_t repeat, uint16_t dstStride, uint16_t srcStride, bool dstHighHalf, bool srcHighHalf);
// PIPE_S, ASM: MOV		AIPP_SPR_0, config
__cce_stub_attribute(__builtin_cce_set_aipp_spr_0) void set_aipp_spr_0(uint64_t config);
// PIPE_S, ASM: MOV		AIPP_SPR_1, config
__cce_stub_attribute(__builtin_cce_set_aipp_spr_1) void set_aipp_spr_1(uint64_t config);
// PIPE_S, ASM: MOV		AIPP_SPR_18, config
__cce_stub_attribute(__builtin_cce_set_aipp_spr_18) void set_aipp_spr_18(uint64_t config);
// PIPE_S, ASM: MOV		AIPP_SPR_19, config
__cce_stub_attribute(__builtin_cce_set_aipp_spr_19) void set_aipp_spr_19(uint64_t config);
// PIPE_S, ASM: MOV		AIPP_SPR_2, config
__cce_stub_attribute(__builtin_cce_set_aipp_spr_2) void set_aipp_spr_2(uint64_t config);
// PIPE_S, ASM: MOV		AIPP_SPR_20, config
__cce_stub_attribute(__builtin_cce_set_aipp_spr_20) void set_aipp_spr_20(uint64_t config);
// PIPE_S, ASM: MOV		AIPP_SPR_21, config
__cce_stub_attribute(__builtin_cce_set_aipp_spr_21) void set_aipp_spr_21(uint64_t config);
// PIPE_S, ASM: MOV		AIPP_SPR_3, config
__cce_stub_attribute(__builtin_cce_set_aipp_spr_3) void set_aipp_spr_3(uint64_t config);
// PIPE_S, ASM: MOV		AIPP_SPR_4, config
__cce_stub_attribute(__builtin_cce_set_aipp_spr_4) void set_aipp_spr_4(uint64_t config);
// PIPE_S, ASM: MOV		AIPP_SPR_8, config
__cce_stub_attribute(__builtin_cce_set_aipp_spr_8) void set_aipp_spr_8(uint64_t config);
// PIPE_S, ASM: MOV		AIPP_SPR_9, config
__cce_stub_attribute(__builtin_cce_set_aipp_spr_9) void set_aipp_spr_9(uint64_t config);
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_atomic_add) void set_atomic_add();
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_atomic_bf16) void set_atomic_bf16();
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_atomic_f16) void set_atomic_f16();
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_atomic_f32) void set_atomic_f32();
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_atomic_max) void set_atomic_max();
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_atomic_min) void set_atomic_min();
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_atomic_none) void set_atomic_none();
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_atomic_s16) void set_atomic_s16();
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_atomic_s32) void set_atomic_s32();
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_atomic_s8) void set_atomic_s8();
// PIPE_S, ASM: MOV		CHANNEL_PARA, config
__cce_stub_attribute(__builtin_cce_set_channel_para) void set_channel_para(uint64_t config);
// PIPE_S, ASM: MOV		COND, config
__cce_stub_attribute(__builtin_cce_set_cond) void set_cond(uint64_t config);
// PIPE_S, ASM: MOV		CONDITION_FLAG, config
__cce_stub_attribute(__builtin_cce_set_condition_flag) void set_condition_flag(uint64_t config);
// PIPE_S, ASM: MOV		CTRL, config
__cce_stub_attribute(__builtin_cce_set_ctrl) void set_ctrl(uint64_t config);
// PIPE_V
__cce_stub_attribute(__builtin_cce_set_data_exp_0) void set_data_exp_0(uint64_t config);
// PIPE_V
__cce_stub_attribute(__builtin_cce_set_data_exp_1) void set_data_exp_1(uint64_t config);
// PIPE_V
__cce_stub_attribute(__builtin_cce_set_data_exp_2) void set_data_exp_2(uint64_t config);
// PIPE_V
__cce_stub_attribute(__builtin_cce_set_data_exp_3) void set_data_exp_3(uint64_t config);
// PIPE_S, ASM: MOV		ELT_ANTIQ_PARA, config
__cce_stub_attribute(__builtin_cce_set_elt_antiq_para) void set_elt_antiq_para(uint64_t config);
// PIPE_S, ASM: MOV		ELT_SRC_PARA, config
__cce_stub_attribute(__builtin_cce_set_elt_src_para) void set_elt_src_para(uint64_t config);
// PIPE_S, ASM: MOV		FFTS_BASE_ADDR, config
__cce_stub_attribute(__builtin_cce_set_ffts_base_addr) void set_ffts_base_addr(uint64_t config);
// PIPE_S, ASM: MOV		FIX_CLIP_RELU, config
__cce_stub_attribute(__builtin_cce_set_fix_clip_relu) void set_fix_clip_relu(uint64_t config);
// PIPE_S, ASM: MOV		FIXP_ADDR, config
__cce_stub_attribute(__builtin_cce_set_fixp_addr) void set_fixp_addr(uint64_t config);
// PIPE_S, ASM: {SET_FLAG|SET_FLAGI}.pipe.tpipe  	#pipeID
__cce_stub_attribute(__builtin_cce_set_flag) void set_flag(pipe_t pipe, pipe_t tpipe, event_t pipeID);
__cce_stub_attribute(__builtin_cce_set_flag) void set_flag(pipe_t pipe, pipe_t tpipe, uint64_t pipeID);
// PIPE_S, ASM: MOV		FMATRIX, config
__cce_stub_attribute(__builtin_cce_set_fmatrix) void set_fmatrix(uint64_t config);
// PIPE_S, ASM: MOV		FMATRIX_B, config
__cce_stub_attribute(__builtin_cce_set_fmatrix_b) void set_fmatrix_b(uint64_t config);
// PIPE_S, ASM: MOV		FPC, config
__cce_stub_attribute(__builtin_cce_set_fpc) void set_fpc(uint64_t config);
// PIPE_S, ASM: SET_INTRA_BLOCKI.pipe 	#sync_id
__cce_stub_attribute(__builtin_cce_set_intra_block) void set_intra_block(pipe_t pipe, uint8_t sync_id);
__cce_stub_attribute(__builtin_cce_set_intra_block) void set_intra_block(pipe_t pipe, uint64_t sync_id);
// PIPE_S, ASM: MOV		L0_SET_VALUE, config
__cce_stub_attribute(__builtin_cce_set_l0_set_value_bf16) void set_l0_set_value_bf16(bfloat16_t config);
// PIPE_S, ASM: MOV		L0_SET_VALUE, config
__cce_stub_attribute(__builtin_cce_set_l0_set_value_h) void set_l0_set_value_h(half config);
// PIPE_S, ASM: MOV		L0_SET_VALUE, config
__cce_stub_attribute(__builtin_cce_set_l0_set_value_ui) void set_l0_set_value_ui(uint32_t config);
// PIPE_MTE2, ASM: SET_L1_2D.b16 	[dst], config
__cce_stub_attribute(__builtin_cce_set_l1_2d) void set_l1_2d(__cbuf__ bfloat16_t *dst, int64_t config);
__cce_stub_attribute(__builtin_cce_set_l1_2d) void set_l1_2d(__cbuf__ half *dst, int64_t config);
__cce_stub_attribute(__builtin_cce_set_l1_2d) void set_l1_2d(__cbuf__ float *dst, int64_t config);
__cce_stub_attribute(__builtin_cce_set_l1_2d) void set_l1_2d(__cbuf__ int16_t *dst, int64_t config);
__cce_stub_attribute(__builtin_cce_set_l1_2d) void set_l1_2d(__cbuf__ int32_t *dst, int64_t config);
__cce_stub_attribute(__builtin_cce_set_l1_2d) void set_l1_2d(__cbuf__ uint16_t *dst, int64_t config);
__cce_stub_attribute(__builtin_cce_set_l1_2d) void set_l1_2d(__cbuf__ uint32_t *dst, int64_t config);
// PIPE_S, ASM: MOV		L3D_RPT, config
__cce_stub_attribute(__builtin_cce_set_l3d_rpt) void set_l3d_rpt(uint64_t config);
// PIPE_S, ASM: MOV		L3D_RPT_B, config
__cce_stub_attribute(__builtin_cce_set_l3d_rpt_b) void set_l3d_rpt_b(uint64_t config);
// PIPE_S, ASM: MOV		LOOP0_STRIDE_NDDMA, config
__cce_stub_attribute(__builtin_cce_set_loop0_stride_nddma) void set_loop0_stride_nddma(uint64_t config);
// PIPE_S, ASM: MOV		LOOP1_STRIDE_L1TOOUT, config
__cce_stub_attribute(__builtin_cce_set_loop1_stride_l1toout) void set_loop1_stride_l1toout(uint64_t config);
// PIPE_S, ASM: MOV		LOOP1_STRIDE_NDDMA, config
__cce_stub_attribute(__builtin_cce_set_loop1_stride_nddma) void set_loop1_stride_nddma(uint64_t config);
// PIPE_S, ASM: MOV		LOOP1_STRIDE_OUTTOL1, config
__cce_stub_attribute(__builtin_cce_set_loop1_stride_outtol1) void set_loop1_stride_outtol1(uint64_t config);
// PIPE_S, ASM: MOV		LOOP1_STRIDE_OUTTOUB, config
__cce_stub_attribute(__builtin_cce_set_loop1_stride_outtoub) void set_loop1_stride_outtoub(uint64_t config);
// PIPE_S, ASM: MOV		LOOP1_STRIDE_UBTOOUT, config
__cce_stub_attribute(__builtin_cce_set_loop1_stride_ubtoout) void set_loop1_stride_ubtoout(uint64_t config);
// PIPE_S, ASM: MOV		LOOP2_STRIDE_L1TOOUT, config
__cce_stub_attribute(__builtin_cce_set_loop2_stride_l1toout) void set_loop2_stride_l1toout(uint64_t config);
// PIPE_S, ASM: MOV		LOOP2_STRIDE_NDDMA, config
__cce_stub_attribute(__builtin_cce_set_loop2_stride_nddma) void set_loop2_stride_nddma(uint64_t config);
// PIPE_S, ASM: MOV		LOOP2_STRIDE_OUTTOL1, config
__cce_stub_attribute(__builtin_cce_set_loop2_stride_outtol1) void set_loop2_stride_outtol1(uint64_t config);
// PIPE_S, ASM: MOV		LOOP2_STRIDE_OUTTOUB, config
__cce_stub_attribute(__builtin_cce_set_loop2_stride_outtoub) void set_loop2_stride_outtoub(uint64_t config);
// PIPE_S, ASM: MOV		LOOP2_STRIDE_UBTOOUT, config
__cce_stub_attribute(__builtin_cce_set_loop2_stride_ubtoout) void set_loop2_stride_ubtoout(uint64_t config);
// PIPE_S, ASM: MOV		LOOP3_PARA, config
__cce_stub_attribute(__builtin_cce_set_loop3_para) void set_loop3_para(uint64_t config);
// PIPE_S, ASM: MOV		LOOP3_STRIDE_NDDMA, config
__cce_stub_attribute(__builtin_cce_set_loop3_stride_nddma) void set_loop3_stride_nddma(uint64_t config);
// PIPE_S, ASM: MOV		LOOP4_PARA, config
__cce_stub_attribute(__builtin_cce_set_loop4_para) void set_loop4_para(uint64_t config);
// PIPE_S, ASM: MOV		LOOP4_STRIDE_NDDMA, config
__cce_stub_attribute(__builtin_cce_set_loop4_stride_nddma) void set_loop4_stride_nddma(uint64_t config);
// PIPE_S, ASM: MOV		LOOP_SIZE_L1TOOUT, config
__cce_stub_attribute(__builtin_cce_set_loop_size_l1toout) void set_loop_size_l1toout(uint64_t config);
// PIPE_S, ASM: MOV		LOOP_SIZE_OUTTOL1, config
__cce_stub_attribute(__builtin_cce_set_loop_size_outtol1) void set_loop_size_outtol1(uint64_t config);
// PIPE_S, ASM: MOV		LOOP_SIZE_OUTTOUB, config
__cce_stub_attribute(__builtin_cce_set_loop_size_outtoub) void set_loop_size_outtoub(uint64_t config);
// PIPE_S, ASM: MOV		LOOP_SIZE_UBTOOUT, config
__cce_stub_attribute(__builtin_cce_set_loop_size_ubtoout) void set_loop_size_ubtoout(uint64_t config);
// PIPE_S, ASM: MOV		LRELU_ALPHA, config
__cce_stub_attribute(__builtin_cce_set_lrelu_alpha) void set_lrelu_alpha(half config);
__cce_stub_attribute(__builtin_cce_set_lrelu_alpha) void set_lrelu_alpha(float config);
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_mask_count) void set_mask_count();
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_mask_norm) void set_mask_norm();
// PIPE_S, ASM: MOV		MOV_PAD_VAL, config
__cce_stub_attribute(__builtin_cce_set_mov_pad_val) void set_mov_pad_val(uint64_t config);
// PIPE_S, ASM: MOV		MTE2_ANTIQ_PARA, config
__cce_stub_attribute(__builtin_cce_set_mte2_antiq_para) void set_mte2_antiq_para(uint64_t config);
// PIPE_S, ASM: MOV		MTE2_NZ_PARA, config
__cce_stub_attribute(__builtin_cce_set_mte2_nz_para) void set_mte2_nz_para(uint64_t config);
// PIPE_S, ASM: MOV		MTE2_SRC_PARA, config
__cce_stub_attribute(__builtin_cce_set_mte2_src_para) void set_mte2_src_para(uint64_t config);
// PIPE_S, ASM: MOV		ND_PARA, config
__cce_stub_attribute(__builtin_cce_set_nd_para) void set_nd_para(uint64_t config);
// PIPE_S, ASM: MOV		PAD_CNT_NDDMA, config
__cce_stub_attribute(__builtin_cce_set_pad_cnt_nddma) void set_pad_cnt_nddma(uint64_t config);
// PIPE_S, ASM: MOV		PAD_VAL_NDDMA, config
__cce_stub_attribute(__builtin_cce_set_pad_val_nddma) void set_pad_val_nddma(uint64_t config);
// PIPE_S, ASM: MOV		PAD_VAL_OUTTOL1, config
__cce_stub_attribute(__builtin_cce_set_pad_val_outtol1) void set_pad_val_outtol1(uint64_t config);
// PIPE_S, ASM: MOV		PAD_VAL_OUTTOUB, config
__cce_stub_attribute(__builtin_cce_set_pad_val_outtoub) void set_pad_val_outtoub(uint64_t config);
// PIPE_S, ASM: MOV		PADDING, config
__cce_stub_attribute(__builtin_cce_set_padding) void set_padding(uint64_t config);
__cce_stub_attribute(__builtin_cce_set_padding) void set_padding(half config);
__cce_stub_attribute(__builtin_cce_set_padding) void set_padding(int16_t config);
__cce_stub_attribute(__builtin_cce_set_padding) void set_padding(uint16_t config);
// PIPE_S, ASM: MOV		PADDING_B, config
__cce_stub_attribute(__builtin_cce_set_padding_b) void set_padding_b(uint64_t config);
// PIPE_S, ASM: MOV		PCIE_RD_CTRL, config
__cce_stub_attribute(__builtin_cce_set_pcie_rd_ctrl) void set_pcie_rd_ctrl(uint64_t config);
// PIPE_S, ASM: MOV		PCIE_WR_CTRL, config
__cce_stub_attribute(__builtin_cce_set_pcie_wr_ctrl) void set_pcie_wr_ctrl(uint64_t config);
// PIPE_S, ASM: MOV		QUANT_POST, config
__cce_stub_attribute(__builtin_cce_set_quant_post) void set_quant_post(uint64_t config);
// PIPE_S, ASM: MOV		QUANT_PRE, config
__cce_stub_attribute(__builtin_cce_set_quant_pre) void set_quant_pre(uint64_t config);
// PIPE_S, ASM: MOV		RELU_ALPHA, config
__cce_stub_attribute(__builtin_cce_set_relu_alpha) void set_relu_alpha(uint64_t config);
// PIPE_V
__cce_stub_attribute(__builtin_cce_set_rpn_cor_ir) void set_rpn_cor_ir(uint64_t config);
// PIPE_S, ASM: MOV		ST_ATOMIC_CFG, config
__cce_stub_attribute(__builtin_cce_set_st_atomic_cfg) void set_st_atomic_cfg(uint64_t config);
__cce_stub_attribute(__builtin_cce_set_st_atomic_cfg) void set_st_atomic_cfg(atomic_type_t type, atomic_op_t op);
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_vector_mask) void set_vector_mask(uint64_t mask1, uint64_t mask0);
// PIPE_S
__cce_stub_attribute(__builtin_cce_set_vector_mask_dup) void set_vector_mask_dup(uint64_t mask);
// PIPE_S, ASM: SFF0.b64  	ret, in
__cce_stub_attribute(__builtin_cce_sff0) int64_t sff0(uint64_t in);
// PIPE_S, ASM: SFF1.b64  	ret, in
__cce_stub_attribute(__builtin_cce_sff1) int64_t sff1(uint64_t in);
// PIPE_S, ASM: SFLBITS.s64  	ret, in
__cce_stub_attribute(__builtin_cce_sflbits) int64_t sflbits(int64_t in);
// PIPE_S, ASM: ST_DEV.b16	src, [dst], #offset
__cce_stub_attribute(__builtin_cce_st_dev) void st_dev(half src, __gm__ half *dst, int16_t offset);
__cce_stub_attribute(__builtin_cce_st_dev) void st_dev(float src, __gm__ float *dst, int16_t offset);
__cce_stub_attribute(__builtin_cce_st_dev) void st_dev(int16_t src, __gm__ int16_t *dst, int16_t offset);
__cce_stub_attribute(__builtin_cce_st_dev) void st_dev(int32_t src, __gm__ int32_t *dst, int16_t offset);
__cce_stub_attribute(__builtin_cce_st_dev) void st_dev(int64_t src, __gm__ int64_t *dst, int16_t offset);
__cce_stub_attribute(__builtin_cce_st_dev) void st_dev(int8_t src, __gm__ int8_t *dst, int16_t offset);
__cce_stub_attribute(__builtin_cce_st_dev) void st_dev(uint16_t src, __gm__ uint16_t *dst, int16_t offset);
__cce_stub_attribute(__builtin_cce_st_dev) void st_dev(uint32_t src, __gm__ uint32_t *dst, int16_t offset);
__cce_stub_attribute(__builtin_cce_st_dev) void st_dev(uint64_t src, __gm__ uint64_t *dst, int16_t offset);
__cce_stub_attribute(__builtin_cce_st_dev) void st_dev(uint8_t src, __gm__ uint8_t *dst, int16_t offset);
// PIPE_S, ASM: TRAP
__cce_stub_attribute(__builtin_cce_trap) void trap();
// PIPE_S, ASM: TRY_WAITI 	ret, #id, #sync_mode
__cce_stub_attribute(__builtin_cce_try_wait) int64_t try_wait(uint8_t id, sync_mode_t sync_mode);
__cce_stub_attribute(__builtin_cce_try_wait) int64_t try_wait(uint64_t xt, sync_mode_t sync_mode);
// PIPE_V
__cce_stub_attribute(__builtin_cce_vabs) void vabs(__ubuf__ int16_t *dst, __ubuf__ int16_t *src, uint8_t repeat, uint16_t dstBlockStride, uint16_t srcBlockStride, uint16_t dstRepeatStride, uint16_t srcRepeatStride);
// PIPE_V
__cce_stub_attribute(__builtin_cce_vaddreluconv_vdeqs162b8) void vaddreluconv_vdeqs162b8(__ubuf__ uint8_t *dst, __ubuf__ int16_t *src0, __ubuf__ int16_t *src1, uint8_t repeat, uint8_t dstBlockStride, uint8_t src0BlockStride, uint8_t src1BlockStride, uint8_t dstRepeatStride, uint8_t src0RepeatStride, uint8_t src1RepeatStride, bool h);
__cce_stub_attribute(__builtin_cce_vaddreluconv_vdeqs162b8) void vaddreluconv_vdeqs162b8(__ubuf__ int8_t *dst, __ubuf__ int16_t *src0, __ubuf__ int16_t *src1, uint8_t repeat, uint8_t dstBlockStride, uint8_t src0BlockStride, uint8_t src1BlockStride, uint8_t dstRepeatStride, uint8_t src0RepeatStride, uint8_t src1RepeatStride, bool h);
// PIPE_V, ASM: VBS32.f16	[dst], [src0], [src1], config
__cce_stub_attribute(__builtin_cce_vbs) void vbs(__ubuf__ half *dst, __ubuf__ half *src0, __ubuf__ uint32_t *src1, uint64_t config);
__cce_stub_attribute(__builtin_cce_vbs) void vbs(__ubuf__ half *dst, __ubuf__ half *src0, __ubuf__ uint32_t *src1, uint8_t repeat, uint8_t dstBlockStride, uint8_t src0BlockStride, uint8_t src1BlockStride, uint8_t dstRepeatStride, uint8_t src0RepeatStride, uint8_t src1RepeatStride, bool repeatStrideMode, bool strideSizeMode);
__cce_stub_attribute(__builtin_cce_vbs) void vbs(__ubuf__ float *dst, __ubuf__ float *src0, __ubuf__ uint32_t *src1, uint64_t config);
__cce_stub_attribute(__builtin_cce_vbs) void vbs(__ubuf__ float *dst, __ubuf__ float *src0, __ubuf__ uint32_t *src1, uint8_t repeat, uint8_t dstBlockStride, uint8_t src0BlockStride, uint8_t src1BlockStride, uint8_t dstRepeatStride, uint8_t src0RepeatStride, uint8_t src1RepeatStride, bool repeatStrideMode, bool strideSizeMode);
// PIPE_V, ASM: VMS4V2.f16	[dst], [src0], src1, config
__cce_stub_attribute(__builtin_cce_vmrgsort4) void vmrgsort4(__ubuf__ half *dst, __ubuf__ half *src0, uint64_t src1, uint64_t config);
__cce_stub_attribute(__builtin_cce_vmrgsort4) void vmrgsort4(__ubuf__ half *dst, __ubuf__ half *src, uint8_t repeat, uint16_t regionProposalLi0, uint16_t regionProposalLi1, uint16_t regionProposalLi2, uint16_t regionProposalLi3, bool isAllStored, uint8_t maskSignal);
__cce_stub_attribute(__builtin_cce_vmrgsort4) void vmrgsort4(__ubuf__ float *dst, __ubuf__ float *src0, uint64_t src1, uint64_t config);
__cce_stub_attribute(__builtin_cce_vmrgsort4) void vmrgsort4(__ubuf__ float *dst, __ubuf__ float *src, uint8_t repeat, uint16_t regionProposalLi0, uint16_t regionProposalLi1, uint16_t regionProposalLi2, uint16_t regionProposalLi3, bool isAllStored, uint8_t maskSignal);
// PIPE_V
__cce_stub_attribute(__builtin_cce_vsubreluconv_vdeqs162b8) void vsubreluconv_vdeqs162b8(__ubuf__ uint8_t *dst, __ubuf__ int16_t *src0, __ubuf__ int16_t *src1, uint8_t repeat, uint8_t dstBlockStride, uint8_t src0BlockStride, uint8_t src1BlockStride, uint8_t dstRepeatStride, uint8_t src0RepeatStride, uint8_t src1RepeatStride, bool h);
__cce_stub_attribute(__builtin_cce_vsubreluconv_vdeqs162b8) void vsubreluconv_vdeqs162b8(__ubuf__ int8_t *dst, __ubuf__ int16_t *src0, __ubuf__ int16_t *src1, uint8_t repeat, uint8_t dstBlockStride, uint8_t src0BlockStride, uint8_t src1BlockStride, uint8_t dstRepeatStride, uint8_t src0RepeatStride, uint8_t src1RepeatStride, bool h);
// PIPE_V, ASM: VTRANSPOSE.b16	[dst], [src]
__cce_stub_attribute(__builtin_cce_vtranspose) void vtranspose(__ubuf__ int16_t *dst, __ubuf__ int16_t *src);
__cce_stub_attribute(__builtin_cce_vtranspose) void vtranspose(__ubuf__ uint16_t *dst, __ubuf__ uint16_t *src);
// PIPE_S, ASM: {WAIT_FLAG|WAIT_FLAGI}.pipe.tpipe  	#pipeID
__cce_stub_attribute(__builtin_cce_wait_flag) void wait_flag(pipe_t pipe, pipe_t tpipe, event_t pipeID);
__cce_stub_attribute(__builtin_cce_wait_flag) void wait_flag(pipe_t pipe, pipe_t tpipe, uint64_t pipeID);
// PIPE_S, ASM: WAIT_FLAG_DEVI.pipe 	#flagID
__cce_stub_attribute(__builtin_cce_wait_flag_dev) void wait_flag_dev(pipe_t pipe, uint8_t flagID);
__cce_stub_attribute(__builtin_cce_wait_flag_dev) void wait_flag_dev(pipe_t pipe, int64_t flagID);
// PIPE_S, ASM: WAIT_INTRA_BLOCKI.pipe 	#sync_id
__cce_stub_attribute(__builtin_cce_wait_intra_block) void wait_intra_block(pipe_t pipe, uint8_t sync_id);
__cce_stub_attribute(__builtin_cce_wait_intra_block) void wait_intra_block(pipe_t pipe, uint64_t sync_id);
} // namespace __cce_scalar

// --- Variadic fallback declarations ---
namespace __cce_scalar {
__cce_stub_attribute(__builtin_cce___atom_add_hscb) int32_t __atom_add_hscb(...);
__cce_stub_attribute(__builtin_cce___atom_cas_hscb) int32_t __atom_cas_hscb(...);
__cce_stub_attribute(__builtin_cce___atom_exch_hscb) int32_t __atom_exch_hscb(...);
__cce_stub_attribute(__builtin_cce___atom_max_hscb) int32_t __atom_max_hscb(...);
__cce_stub_attribute(__builtin_cce___atom_min_hscb) int32_t __atom_min_hscb(...);
__cce_stub_attribute(__builtin_cce___bt_alloc) uint64_t __bt_alloc(...);
__cce_stub_attribute(__builtin_cce___bt_alloci) uint64_t __bt_alloci(...);
__cce_stub_attribute(__builtin_cce___bt_free) void __bt_free(...);
__cce_stub_attribute(__builtin_cce___bt_freei) void __bt_freei(...);
__cce_stub_attribute(__builtin_cce___ca_alloc) __ca__ void * __ca_alloc(...);
__cce_stub_attribute(__builtin_cce___ca_alloci) __ca__ void * __ca_alloci(...);
__cce_stub_attribute(__builtin_cce___ca_free) void __ca_free(...);
__cce_stub_attribute(__builtin_cce___ca_freei) void __ca_freei(...);
__cce_stub_attribute(__builtin_cce___cb_alloc) __cb__ void * __cb_alloc(...);
__cce_stub_attribute(__builtin_cce___cb_alloci) __cb__ void * __cb_alloci(...);
__cce_stub_attribute(__builtin_cce___cb_free) void __cb_free(...);
__cce_stub_attribute(__builtin_cce___cb_freei) void __cb_freei(...);
__cce_stub_attribute(__builtin_cce___cbuf_alloc) __cbuf__ void * __cbuf_alloc(...);
__cce_stub_attribute(__builtin_cce___cbuf_alloci) __cbuf__ void * __cbuf_alloci(...);
__cce_stub_attribute(__builtin_cce___cbuf_free) void __cbuf_free(...);
__cce_stub_attribute(__builtin_cce___cbuf_freei) void __cbuf_freei(...);
__cce_stub_attribute(__builtin_cce___cc_alloc) __cc__ void * __cc_alloc(...);
__cce_stub_attribute(__builtin_cce___cc_alloci) __cc__ void * __cc_alloci(...);
__cce_stub_attribute(__builtin_cce___cc_free) void __cc_free(...);
__cce_stub_attribute(__builtin_cce___cc_freei) void __cc_freei(...);
__cce_stub_attribute(__builtin_cce___cce_ldva) void __cce_ldva(...);
__cce_stub_attribute(__builtin_cce___cce_scatter_vnchwconv_b16) void __cce_scatter_vnchwconv_b16(...);
__cce_stub_attribute(__builtin_cce___cce_scatter_vnchwconv_b8) void __cce_scatter_vnchwconv_b8(...);
__cce_stub_attribute(__builtin_cce___dfx_region) void __dfx_region(...);
__cce_stub_attribute(__builtin_cce___fbuf_alloc) __fbuf__ void * __fbuf_alloc(...);
__cce_stub_attribute(__builtin_cce___fbuf_alloci) __fbuf__ void * __fbuf_alloci(...);
__cce_stub_attribute(__builtin_cce___fbuf_free) void __fbuf_free(...);
__cce_stub_attribute(__builtin_cce___fbuf_freei) void __fbuf_freei(...);
__cce_stub_attribute(__builtin_cce___gqm) uint64_t __gqm(...);
__cce_stub_attribute(__builtin_cce___ib_set_stub) void __ib_set_stub(...);
__cce_stub_attribute(__builtin_cce___ib_wait_stub) void __ib_wait_stub(...);
__cce_stub_attribute(__builtin_cce___ld_hscb_f16) half __ld_hscb_f16(...);
__cce_stub_attribute(__builtin_cce___ld_hscb_f32) float __ld_hscb_f32(...);
__cce_stub_attribute(__builtin_cce___ld_hscb_s16) int16_t __ld_hscb_s16(...);
__cce_stub_attribute(__builtin_cce___ld_hscb_s32) int32_t __ld_hscb_s32(...);
__cce_stub_attribute(__builtin_cce___ld_hscb_s64) int64_t __ld_hscb_s64(...);
__cce_stub_attribute(__builtin_cce___ld_hscb_s8) int8_t __ld_hscb_s8(...);
__cce_stub_attribute(__builtin_cce___ld_hscb_u16) uint64_t __ld_hscb_u16(...);
__cce_stub_attribute(__builtin_cce___ld_hscb_u32) uint64_t __ld_hscb_u32(...);
__cce_stub_attribute(__builtin_cce___ld_hscb_u64) uint64_t __ld_hscb_u64(...);
__cce_stub_attribute(__builtin_cce___ld_hscb_u8) uint64_t __ld_hscb_u8(...);
__cce_stub_attribute(__builtin_cce___mad) void __mad(...);
__cce_stub_attribute(__builtin_cce___mad_s4) void __mad_s4(...);
__cce_stub_attribute(__builtin_cce___mad_tf322f32) void __mad_tf322f32(...);
__cce_stub_attribute(__builtin_cce___memcpy) void __memcpy(...);
__cce_stub_attribute(__builtin_cce___mstx_dfx_report_stub) void __mstx_dfx_report_stub(...);
__cce_stub_attribute(__builtin_cce___prefetch_stop) void __prefetch_stop(...);
__cce_stub_attribute(__builtin_cce___red_add_hscb) void __red_add_hscb(...);
__cce_stub_attribute(__builtin_cce___red_max_hscb) void __red_max_hscb(...);
__cce_stub_attribute(__builtin_cce___red_min_hscb) void __red_min_hscb(...);
__cce_stub_attribute(__builtin_cce___sev) void __sev(...);
__cce_stub_attribute(__builtin_cce___sevl) void __sevl(...);
__cce_stub_attribute(__builtin_cce___st_hscb) void __st_hscb(...);
__cce_stub_attribute(__builtin_cce___sync_all_stub) void __sync_all_stub(...);
__cce_stub_attribute(__builtin_cce___sync_hscb) void __sync_hscb(...);
__cce_stub_attribute(__builtin_cce___ubuf_alloc) __ubuf__ void * __ubuf_alloc(...);
__cce_stub_attribute(__builtin_cce___ubuf_alloci) __ubuf__ void * __ubuf_alloci(...);
__cce_stub_attribute(__builtin_cce___ubuf_free) void __ubuf_free(...);
__cce_stub_attribute(__builtin_cce___ubuf_freei) void __ubuf_freei(...);
__cce_stub_attribute(__builtin_cce___vabs) void __vabs(...);
__cce_stub_attribute(__builtin_cce___vadd) void __vadd(...);
__cce_stub_attribute(__builtin_cce___vaddrelu) void __vaddrelu(...);
__cce_stub_attribute(__builtin_cce___vaddreluconv_f162s8) void __vaddreluconv_f162s8(...);
__cce_stub_attribute(__builtin_cce___vaddreluconv_f322f16) void __vaddreluconv_f322f16(...);
__cce_stub_attribute(__builtin_cce___vaddreluconv_s162s8) void __vaddreluconv_s162s8(...);
__cce_stub_attribute(__builtin_cce___vadds) void __vadds(...);
__cce_stub_attribute(__builtin_cce___vand) void __vand(...);
__cce_stub_attribute(__builtin_cce___vaxpy) void __vaxpy(...);
__cce_stub_attribute(__builtin_cce___vcgadd) void __vcgadd(...);
__cce_stub_attribute(__builtin_cce___vcgmax) void __vcgmax(...);
__cce_stub_attribute(__builtin_cce___vcgmin) void __vcgmin(...);
__cce_stub_attribute(__builtin_cce___vcmax) void __vcmax(...);
__cce_stub_attribute(__builtin_cce___vcmin) void __vcmin(...);
__cce_stub_attribute(__builtin_cce___vconv_bf162s32a) void __vconv_bf162s32a(...);
__cce_stub_attribute(__builtin_cce___vconv_bf162s32c) void __vconv_bf162s32c(...);
__cce_stub_attribute(__builtin_cce___vconv_bf162s32f) void __vconv_bf162s32f(...);
__cce_stub_attribute(__builtin_cce___vconv_bf162s32r) void __vconv_bf162s32r(...);
__cce_stub_attribute(__builtin_cce___vconv_bf162s32z) void __vconv_bf162s32z(...);
__cce_stub_attribute(__builtin_cce___vconv_deqs162b8h) void __vconv_deqs162b8h(...);
__cce_stub_attribute(__builtin_cce___vconv_deqs162b8l) void __vconv_deqs162b8l(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s16a) void __vconv_f162s16a(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s16c) void __vconv_f162s16c(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s16f) void __vconv_f162s16f(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s16r) void __vconv_f162s16r(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s16z) void __vconv_f162s16z(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s32a) void __vconv_f162s32a(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s32c) void __vconv_f162s32c(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s32f) void __vconv_f162s32f(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s32r) void __vconv_f162s32r(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s32z) void __vconv_f162s32z(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s4) void __vconv_f162s4(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s4a) void __vconv_f162s4a(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s4c) void __vconv_f162s4c(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s4f) void __vconv_f162s4f(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s4r) void __vconv_f162s4r(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s4z) void __vconv_f162s4z(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s8) void __vconv_f162s8(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s8a) void __vconv_f162s8a(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s8c) void __vconv_f162s8c(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s8f) void __vconv_f162s8f(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s8r) void __vconv_f162s8r(...);
__cce_stub_attribute(__builtin_cce___vconv_f162s8z) void __vconv_f162s8z(...);
__cce_stub_attribute(__builtin_cce___vconv_f162u8) void __vconv_f162u8(...);
__cce_stub_attribute(__builtin_cce___vconv_f162u8a) void __vconv_f162u8a(...);
__cce_stub_attribute(__builtin_cce___vconv_f162u8c) void __vconv_f162u8c(...);
__cce_stub_attribute(__builtin_cce___vconv_f162u8f) void __vconv_f162u8f(...);
__cce_stub_attribute(__builtin_cce___vconv_f162u8r) void __vconv_f162u8r(...);
__cce_stub_attribute(__builtin_cce___vconv_f162u8z) void __vconv_f162u8z(...);
__cce_stub_attribute(__builtin_cce___vconv_f322bf16a) void __vconv_f322bf16a(...);
__cce_stub_attribute(__builtin_cce___vconv_f322bf16c) void __vconv_f322bf16c(...);
__cce_stub_attribute(__builtin_cce___vconv_f322bf16f) void __vconv_f322bf16f(...);
__cce_stub_attribute(__builtin_cce___vconv_f322bf16r) void __vconv_f322bf16r(...);
__cce_stub_attribute(__builtin_cce___vconv_f322bf16z) void __vconv_f322bf16z(...);
__cce_stub_attribute(__builtin_cce___vconv_f322f16) void __vconv_f322f16(...);
__cce_stub_attribute(__builtin_cce___vconv_f322f16a) void __vconv_f322f16a(...);
__cce_stub_attribute(__builtin_cce___vconv_f322f16c) void __vconv_f322f16c(...);
__cce_stub_attribute(__builtin_cce___vconv_f322f16f) void __vconv_f322f16f(...);
__cce_stub_attribute(__builtin_cce___vconv_f322f16o) void __vconv_f322f16o(...);
__cce_stub_attribute(__builtin_cce___vconv_f322f16r) void __vconv_f322f16r(...);
__cce_stub_attribute(__builtin_cce___vconv_f322f16z) void __vconv_f322f16z(...);
__cce_stub_attribute(__builtin_cce___vconv_f322f32a) void __vconv_f322f32a(...);
__cce_stub_attribute(__builtin_cce___vconv_f322f32c) void __vconv_f322f32c(...);
__cce_stub_attribute(__builtin_cce___vconv_f322f32f) void __vconv_f322f32f(...);
__cce_stub_attribute(__builtin_cce___vconv_f322f32r) void __vconv_f322f32r(...);
__cce_stub_attribute(__builtin_cce___vconv_f322f32z) void __vconv_f322f32z(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s16a) void __vconv_f322s16a(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s16c) void __vconv_f322s16c(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s16f) void __vconv_f322s16f(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s16r) void __vconv_f322s16r(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s16z) void __vconv_f322s16z(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s32a) void __vconv_f322s32a(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s32c) void __vconv_f322s32c(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s32f) void __vconv_f322s32f(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s32r) void __vconv_f322s32r(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s32z) void __vconv_f322s32z(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s64a) void __vconv_f322s64a(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s64c) void __vconv_f322s64c(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s64f) void __vconv_f322s64f(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s64r) void __vconv_f322s64r(...);
__cce_stub_attribute(__builtin_cce___vconv_f322s64z) void __vconv_f322s64z(...);
__cce_stub_attribute(__builtin_cce___vconv_s162f16) void __vconv_s162f16(...);
__cce_stub_attribute(__builtin_cce___vconv_s162f16a) void __vconv_s162f16a(...);
__cce_stub_attribute(__builtin_cce___vconv_s162f16c) void __vconv_s162f16c(...);
__cce_stub_attribute(__builtin_cce___vconv_s162f16f) void __vconv_s162f16f(...);
__cce_stub_attribute(__builtin_cce___vconv_s162f16r) void __vconv_s162f16r(...);
__cce_stub_attribute(__builtin_cce___vconv_s162f16z) void __vconv_s162f16z(...);
__cce_stub_attribute(__builtin_cce___vconv_s322f32) void __vconv_s322f32(...);
__cce_stub_attribute(__builtin_cce___vconv_s322f32a) void __vconv_s322f32a(...);
__cce_stub_attribute(__builtin_cce___vconv_s322f32c) void __vconv_s322f32c(...);
__cce_stub_attribute(__builtin_cce___vconv_s322f32f) void __vconv_s322f32f(...);
__cce_stub_attribute(__builtin_cce___vconv_s322f32r) void __vconv_s322f32r(...);
__cce_stub_attribute(__builtin_cce___vconv_s322f32z) void __vconv_s322f32z(...);
__cce_stub_attribute(__builtin_cce___vconv_s642f32a) void __vconv_s642f32a(...);
__cce_stub_attribute(__builtin_cce___vconv_s642f32c) void __vconv_s642f32c(...);
__cce_stub_attribute(__builtin_cce___vconv_s642f32f) void __vconv_s642f32f(...);
__cce_stub_attribute(__builtin_cce___vconv_s642f32r) void __vconv_s642f32r(...);
__cce_stub_attribute(__builtin_cce___vconv_s642f32z) void __vconv_s642f32z(...);
__cce_stub_attribute(__builtin_cce___vconv_vdeqs162b8h) void __vconv_vdeqs162b8h(...);
__cce_stub_attribute(__builtin_cce___vconv_vdeqs162b8l) void __vconv_vdeqs162b8l(...);
__cce_stub_attribute(__builtin_cce___vcpadd) void __vcpadd(...);
__cce_stub_attribute(__builtin_cce___vdiv) void __vdiv(...);
__cce_stub_attribute(__builtin_cce___vector_dup) void __vector_dup(...);
__cce_stub_attribute(__builtin_cce___vexp) void __vexp(...);
__cce_stub_attribute(__builtin_cce___vgather) void __vgather(...);
__cce_stub_attribute(__builtin_cce___vln) void __vln(...);
__cce_stub_attribute(__builtin_cce___vlrelu) void __vlrelu(...);
__cce_stub_attribute(__builtin_cce___vmadd) void __vmadd(...);
__cce_stub_attribute(__builtin_cce___vmaddrelu) void __vmaddrelu(...);
__cce_stub_attribute(__builtin_cce___vmax) void __vmax(...);
__cce_stub_attribute(__builtin_cce___vmaxs) void __vmaxs(...);
__cce_stub_attribute(__builtin_cce___vmin) void __vmin(...);
__cce_stub_attribute(__builtin_cce___vmins) void __vmins(...);
__cce_stub_attribute(__builtin_cce___vmla) void __vmla(...);
__cce_stub_attribute(__builtin_cce___vmul) void __vmul(...);
__cce_stub_attribute(__builtin_cce___vmulconv_f162s8) void __vmulconv_f162s8(...);
__cce_stub_attribute(__builtin_cce___vmulconv_f162u8) void __vmulconv_f162u8(...);
__cce_stub_attribute(__builtin_cce___vmuls) void __vmuls(...);
__cce_stub_attribute(__builtin_cce___vnot) void __vnot(...);
__cce_stub_attribute(__builtin_cce___vor) void __vor(...);
__cce_stub_attribute(__builtin_cce___vrec) void __vrec(...);
__cce_stub_attribute(__builtin_cce___vrelu) void __vrelu(...);
__cce_stub_attribute(__builtin_cce___vrsqrt) void __vrsqrt(...);
__cce_stub_attribute(__builtin_cce___vsel) void __vsel(...);
__cce_stub_attribute(__builtin_cce___vshl) void __vshl(...);
__cce_stub_attribute(__builtin_cce___vshr) void __vshr(...);
__cce_stub_attribute(__builtin_cce___vsqrt) void __vsqrt(...);
__cce_stub_attribute(__builtin_cce___vsub) void __vsub(...);
__cce_stub_attribute(__builtin_cce___vsubrelu) void __vsubrelu(...);
__cce_stub_attribute(__builtin_cce___vsubreluconv_f162s8) void __vsubreluconv_f162s8(...);
__cce_stub_attribute(__builtin_cce___vsubreluconv_f322f16) void __vsubreluconv_f322f16(...);
__cce_stub_attribute(__builtin_cce___vsubreluconv_s162s8) void __vsubreluconv_s162s8(...);
__cce_stub_attribute(__builtin_cce___wait_ast_scb) void __wait_ast_scb(...);
__cce_stub_attribute(__builtin_cce___wait_prev_task) void __wait_prev_task(...);
__cce_stub_attribute(__builtin_cce___wfe) void __wfe(...);
__cce_stub_attribute(__builtin_cce_bcnt0) int64_t bcnt0(...);
__cce_stub_attribute(__builtin_cce_bcnt1) int64_t bcnt1(...);
__cce_stub_attribute(__builtin_cce_broadcast_ub_to_cc) void broadcast_ub_to_cc(...);
__cce_stub_attribute(__builtin_cce_clz) int64_t clz(...);
__cce_stub_attribute(__builtin_cce_col2img) void col2img(...);
__cce_stub_attribute(__builtin_cce_compress_ub_to_gm) void compress_ub_to_gm(...);
__cce_stub_attribute(__builtin_cce_conv_f322f16o) half conv_f322f16o(...);
__cce_stub_attribute(__builtin_cce_conv_f322s32a) int64_t conv_f322s32a(...);
__cce_stub_attribute(__builtin_cce_conv_f322s32c) int64_t conv_f322s32c(...);
__cce_stub_attribute(__builtin_cce_conv_f322s32f) int64_t conv_f322s32f(...);
__cce_stub_attribute(__builtin_cce_conv_f322s32r) int64_t conv_f322s32r(...);
__cce_stub_attribute(__builtin_cce_conv_to_l1_e4m3e4m3) void conv_to_l1_e4m3e4m3(...);
__cce_stub_attribute(__builtin_cce_conv_to_l1_e4m3s4) void conv_to_l1_e4m3s4(...);
__cce_stub_attribute(__builtin_cce_conv_to_l1_e4m3s8) void conv_to_l1_e4m3s8(...);
__cce_stub_attribute(__builtin_cce_conv_to_l1_f16f16) void conv_to_l1_f16f16(...);
__cce_stub_attribute(__builtin_cce_conv_to_l1_s16s8) void conv_to_l1_s16s8(...);
__cce_stub_attribute(__builtin_cce_conv_to_l1_s4s4) void conv_to_l1_s4s4(...);
__cce_stub_attribute(__builtin_cce_conv_to_l1_s8s4) void conv_to_l1_s8s4(...);
__cce_stub_attribute(__builtin_cce_conv_to_l1_s8s8) void conv_to_l1_s8s8(...);
__cce_stub_attribute(__builtin_cce_conv_ub_to_ub_s16s8) void conv_ub_to_ub_s16s8(...);
__cce_stub_attribute(__builtin_cce_conv_ub_to_ub_s8s4) void conv_ub_to_ub_s8s4(...);
__cce_stub_attribute(__builtin_cce_conv_ub_to_ub_s8s8) void conv_ub_to_ub_s8s8(...);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_bt) void copy_cbuf_to_bt(...);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_cbuf_loopenhance) void copy_cbuf_to_cbuf_loopenhance(...);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_fbuf) void copy_cbuf_to_fbuf(...);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_fbuf_v2) void copy_cbuf_to_fbuf_v2(...);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_gm) void copy_cbuf_to_gm(...);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_gm_align) void copy_cbuf_to_gm_align(...);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_gm_align_no_padding) void copy_cbuf_to_gm_align_no_padding(...);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_gm_align_v2) void copy_cbuf_to_gm_align_v2(...);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_gm_multi_nz2dn) void copy_cbuf_to_gm_multi_nz2dn(...);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_gm_multi_nz2nd) void copy_cbuf_to_gm_multi_nz2nd(...);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_pt) void copy_cbuf_to_pt(...);
__cce_stub_attribute(__builtin_cce_copy_cbuf_to_ubuf) void copy_cbuf_to_ubuf(...);
__cce_stub_attribute(__builtin_cce_copy_depthwise_cc_to_ubuf) void copy_depthwise_cc_to_ubuf(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf) void copy_gm_to_cbuf(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align) void copy_gm_to_cbuf_align(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_align_v2) void copy_gm_to_cbuf_align_v2(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_dn2nz) void copy_gm_to_cbuf_multi_dn2nz(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz) void copy_gm_to_cbuf_multi_nd2nz(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz_b16) void copy_gm_to_cbuf_multi_nd2nz_b16(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz_b32s) void copy_gm_to_cbuf_multi_nd2nz_b32s(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_multi_nd2nz_b8) void copy_gm_to_cbuf_multi_nd2nz_b8(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_cbuf_v2) void copy_gm_to_cbuf_v2(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf) void copy_gm_to_ubuf(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align) void copy_gm_to_ubuf_align(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_b16) void copy_gm_to_ubuf_align_b16(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_b32) void copy_gm_to_ubuf_align_b32(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_b8) void copy_gm_to_ubuf_align_b8(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_no_padding) void copy_gm_to_ubuf_align_no_padding(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_align_v2) void copy_gm_to_ubuf_align_v2(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_pad_b16) void copy_gm_to_ubuf_pad_b16(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_pad_b32) void copy_gm_to_ubuf_pad_b32(...);
__cce_stub_attribute(__builtin_cce_copy_gm_to_ubuf_pad_b8) void copy_gm_to_ubuf_pad_b8(...);
__cce_stub_attribute(__builtin_cce_copy_matrix_cbuf_to_cc) void copy_matrix_cbuf_to_cc(...);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf) void copy_matrix_cc_to_cbuf(...);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf_b4) void copy_matrix_cc_to_cbuf_b4(...);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_cbuf_s4) void copy_matrix_cc_to_cbuf_s4(...);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm) void copy_matrix_cc_to_gm(...);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm_b4) void copy_matrix_cc_to_gm_b4(...);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_gm_s4) void copy_matrix_cc_to_gm_s4(...);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub) void copy_matrix_cc_to_ub(...);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ub_s4) void copy_matrix_cc_to_ub_s4(...);
__cce_stub_attribute(__builtin_cce_copy_matrix_cc_to_ubuf) void copy_matrix_cc_to_ubuf(...);
__cce_stub_attribute(__builtin_cce_copy_matrix_ubuf_to_cc) void copy_matrix_ubuf_to_cc(...);
__cce_stub_attribute(__builtin_cce_copy_small_matrix_cc_to_ubuf) void copy_small_matrix_cc_to_ubuf(...);
__cce_stub_attribute(__builtin_cce_copy_small_matrix_ubuf_to_cc) void copy_small_matrix_ubuf_to_cc(...);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_cbuf) void copy_ubuf_to_cbuf(...);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_fbuf) void copy_ubuf_to_fbuf(...);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_gm) void copy_ubuf_to_gm(...);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_gm_align) void copy_ubuf_to_gm_align(...);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_gm_align_b16) void copy_ubuf_to_gm_align_b16(...);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_gm_align_b32) void copy_ubuf_to_gm_align_b32(...);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_gm_align_b8) void copy_ubuf_to_gm_align_b8(...);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_gm_align_no_padding) void copy_ubuf_to_gm_align_no_padding(...);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_gm_align_v2) void copy_ubuf_to_gm_align_v2(...);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_gm_pad_b16) void copy_ubuf_to_gm_pad_b16(...);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_gm_pad_b32) void copy_ubuf_to_gm_pad_b32(...);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_gm_pad_b8) void copy_ubuf_to_gm_pad_b8(...);
__cce_stub_attribute(__builtin_cce_copy_ubuf_to_ubuf) void copy_ubuf_to_ubuf(...);
__cce_stub_attribute(__builtin_cce_copy_vector_cc_to_ubuf) void copy_vector_cc_to_ubuf(...);
__cce_stub_attribute(__builtin_cce_copy_vector_ubuf_to_cc) void copy_vector_ubuf_to_cc(...);
__cce_stub_attribute(__builtin_cce_create_ca_matrix) void create_ca_matrix(...);
__cce_stub_attribute(__builtin_cce_create_ca_matrix_bf16) void create_ca_matrix_bf16(...);
__cce_stub_attribute(__builtin_cce_create_ca_matrix_h) void create_ca_matrix_h(...);
__cce_stub_attribute(__builtin_cce_create_ca_matrix_ui) void create_ca_matrix_ui(...);
__cce_stub_attribute(__builtin_cce_create_cb_matrix) void create_cb_matrix(...);
__cce_stub_attribute(__builtin_cce_create_cb_matrix_bf16) void create_cb_matrix_bf16(...);
__cce_stub_attribute(__builtin_cce_create_cb_matrix_h) void create_cb_matrix_h(...);
__cce_stub_attribute(__builtin_cce_create_cb_matrix_ui) void create_cb_matrix_ui(...);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix) void create_cbuf_matrix(...);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix_bf16) void create_cbuf_matrix_bf16(...);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix_h) void create_cbuf_matrix_h(...);
__cce_stub_attribute(__builtin_cce_create_cbuf_matrix_ui) void create_cbuf_matrix_ui(...);
__cce_stub_attribute(__builtin_cce_dc_preload) void dc_preload(...);
__cce_stub_attribute(__builtin_cce_decompress_gm_to_cbuf) void decompress_gm_to_cbuf(...);
__cce_stub_attribute(__builtin_cce_decompress_gm_to_ub) void decompress_gm_to_ub(...);
__cce_stub_attribute(__builtin_cce_depthwise_conv) void depthwise_conv(...);
__cce_stub_attribute(__builtin_cce_depthwise_conv_v2) void depthwise_conv_v2(...);
__cce_stub_attribute(__builtin_cce_dsb) void dsb(...);
__cce_stub_attribute(__builtin_cce_fake_isa) void fake_isa(...);
__cce_stub_attribute(__builtin_cce_fake_isa_ret) uint64_t fake_isa_ret(...);
__cce_stub_attribute(__builtin_cce_ffts_cross_core_sync) void ffts_cross_core_sync(...);
__cce_stub_attribute(__builtin_cce_fifr1) void fifr1(...);
__cce_stub_attribute(__builtin_cce_fix_cbuf_to_cbuf_inner) void fix_cbuf_to_cbuf_inner(...);
__cce_stub_attribute(__builtin_cce_fix_cbuf_to_gm_inner) void fix_cbuf_to_gm_inner(...);
__cce_stub_attribute(__builtin_cce_fix_cbuf_to_ub_inner) void fix_cbuf_to_ub_inner(...);
__cce_stub_attribute(__builtin_cce_fix_depthwisein_cc_to_cbuf) void fix_depthwisein_cc_to_cbuf(...);
__cce_stub_attribute(__builtin_cce_fix_depthwisein_cc_to_ubuf) void fix_depthwisein_cc_to_ubuf(...);
__cce_stub_attribute(__builtin_cce_fix_depthwiseout_cc_to_cbuf) void fix_depthwiseout_cc_to_cbuf(...);
__cce_stub_attribute(__builtin_cce_fix_matrix_cc_to_cbuf) void fix_matrix_cc_to_cbuf(...);
__cce_stub_attribute(__builtin_cce_fix_matrix_cc_to_cbufubuf) void fix_matrix_cc_to_cbufubuf(...);
__cce_stub_attribute(__builtin_cce_fix_matrix_cc_to_ubuf) void fix_matrix_cc_to_ubuf(...);
__cce_stub_attribute(__builtin_cce_fix_winograd_cc_to_cbuf) void fix_winograd_cc_to_cbuf(...);
__cce_stub_attribute(__builtin_cce_fix_winograd_cc_to_ubuf) void fix_winograd_cc_to_ubuf(...);
__cce_stub_attribute(__builtin_cce_gather_gm_to_ubuf_u16) void gather_gm_to_ubuf_u16(...);
__cce_stub_attribute(__builtin_cce_gather_gm_to_ubuf_u32) void gather_gm_to_ubuf_u32(...);
__cce_stub_attribute(__builtin_cce_gather_gm_to_ubuf_u64) void gather_gm_to_ubuf_u64(...);
__cce_stub_attribute(__builtin_cce_gather_gm_to_ubuf_u8) void gather_gm_to_ubuf_u8(...);
__cce_stub_attribute(__builtin_cce_get_acc_val) int64_t get_acc_val(...);
__cce_stub_attribute(__builtin_cce_get_acsqid) int64_t get_acsqid(...);
__cce_stub_attribute(__builtin_cce_get_ast_reg_0) int64_t get_ast_reg_0(...);
__cce_stub_attribute(__builtin_cce_get_ast_reg_1) int64_t get_ast_reg_1(...);
__cce_stub_attribute(__builtin_cce_get_ast_reg_2) int64_t get_ast_reg_2(...);
__cce_stub_attribute(__builtin_cce_get_ast_reg_3) int64_t get_ast_reg_3(...);
__cce_stub_attribute(__builtin_cce_get_ast_scb_0) int64_t get_ast_scb_0(...);
__cce_stub_attribute(__builtin_cce_get_ast_scb_1) int64_t get_ast_scb_1(...);
__cce_stub_attribute(__builtin_cce_get_ast_scb_2) int64_t get_ast_scb_2(...);
__cce_stub_attribute(__builtin_cce_get_ast_scb_3) int64_t get_ast_scb_3(...);
__cce_stub_attribute(__builtin_cce_get_block_idx) int32_t get_block_idx(...);
__cce_stub_attribute(__builtin_cce_get_block_num) int32_t get_block_num(...);
__cce_stub_attribute(__builtin_cce_get_blockdim) int64_t get_blockdim(...);
__cce_stub_attribute(__builtin_cce_get_blockid) int64_t get_blockid(...);
__cce_stub_attribute(__builtin_cce_get_bmu_segm_bt) int64_t get_bmu_segm_bt(...);
__cce_stub_attribute(__builtin_cce_get_bmu_segm_fb) int64_t get_bmu_segm_fb(...);
__cce_stub_attribute(__builtin_cce_get_bmu_segm_l0a) int64_t get_bmu_segm_l0a(...);
__cce_stub_attribute(__builtin_cce_get_bmu_segm_l0b) int64_t get_bmu_segm_l0b(...);
__cce_stub_attribute(__builtin_cce_get_bmu_segm_l0c) int64_t get_bmu_segm_l0c(...);
__cce_stub_attribute(__builtin_cce_get_bmu_segm_l1) int64_t get_bmu_segm_l1(...);
__cce_stub_attribute(__builtin_cce_get_bmu_segm_ub) int64_t get_bmu_segm_ub(...);
__cce_stub_attribute(__builtin_cce_get_buf) void get_buf(...);
__cce_stub_attribute(__builtin_cce_get_cmpmask) void get_cmpmask(...);
__cce_stub_attribute(__builtin_cce_get_cond) int64_t get_cond(...);
__cce_stub_attribute(__builtin_cce_get_cond_taskid) int64_t get_cond_taskid(...);
__cce_stub_attribute(__builtin_cce_get_fpc) int64_t get_fpc(...);
__cce_stub_attribute(__builtin_cce_get_imm) uint64_t get_imm(...);
__cce_stub_attribute(__builtin_cce_get_ioa_base) int64_t get_ioa_base(...);
__cce_stub_attribute(__builtin_cce_get_ipc_reg_0) int64_t get_ipc_reg_0(...);
__cce_stub_attribute(__builtin_cce_get_ipc_reg_1) int64_t get_ipc_reg_1(...);
__cce_stub_attribute(__builtin_cce_get_ipc_reg_2) int64_t get_ipc_reg_2(...);
__cce_stub_attribute(__builtin_cce_get_ipc_reg_3) int64_t get_ipc_reg_3(...);
__cce_stub_attribute(__builtin_cce_get_ipc_reg_4) int64_t get_ipc_reg_4(...);
__cce_stub_attribute(__builtin_cce_get_ipc_reg_5) int64_t get_ipc_reg_5(...);
__cce_stub_attribute(__builtin_cce_get_ipc_reg_6) int64_t get_ipc_reg_6(...);
__cce_stub_attribute(__builtin_cce_get_ipc_reg_7) int64_t get_ipc_reg_7(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_0) int64_t get_ipc_scb_0(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_1) int64_t get_ipc_scb_1(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_10) int64_t get_ipc_scb_10(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_11) int64_t get_ipc_scb_11(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_12) int64_t get_ipc_scb_12(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_13) int64_t get_ipc_scb_13(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_14) int64_t get_ipc_scb_14(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_15) int64_t get_ipc_scb_15(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_2) int64_t get_ipc_scb_2(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_3) int64_t get_ipc_scb_3(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_4) int64_t get_ipc_scb_4(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_5) int64_t get_ipc_scb_5(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_6) int64_t get_ipc_scb_6(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_7) int64_t get_ipc_scb_7(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_8) int64_t get_ipc_scb_8(...);
__cce_stub_attribute(__builtin_cce_get_ipc_scb_9) int64_t get_ipc_scb_9(...);
__cce_stub_attribute(__builtin_cce_get_iqent) int64_t get_iqent(...);
__cce_stub_attribute(__builtin_cce_get_k_num) int64_t get_k_num(...);
__cce_stub_attribute(__builtin_cce_get_lpcnt) int64_t get_lpcnt(...);
__cce_stub_attribute(__builtin_cce_get_max_min_cnt) int64_t get_max_min_cnt(...);
__cce_stub_attribute(__builtin_cce_get_next_task) void get_next_task(...);
__cce_stub_attribute(__builtin_cce_get_rsvd_cnt) int64_t get_rsvd_cnt(...);
__cce_stub_attribute(__builtin_cce_get_safety_crc_data) int64_t get_safety_crc_data(...);
__cce_stub_attribute(__builtin_cce_get_safety_crc_en) int64_t get_safety_crc_en(...);
__cce_stub_attribute(__builtin_cce_get_stackid) int64_t get_stackid(...);
__cce_stub_attribute(__builtin_cce_get_tilingdata_base) int64_t get_tilingdata_base(...);
__cce_stub_attribute(__builtin_cce_get_weight_base) int64_t get_weight_base(...);
__cce_stub_attribute(__builtin_cce_get_workspace_base) int64_t get_workspace_base(...);
__cce_stub_attribute(__builtin_cce_group_conv) void group_conv(...);
__cce_stub_attribute(__builtin_cce_hebcd_out_to_ub) void hebcd_out_to_ub(...);
__cce_stub_attribute(__builtin_cce_hebce_l1_to_out) void hebce_l1_to_out(...);
__cce_stub_attribute(__builtin_cce_hebce_ub_to_out) void hebce_ub_to_out(...);
__cce_stub_attribute(__builtin_cce_hset_flag) void hset_flag(...);
__cce_stub_attribute(__builtin_cce_hwait_flag) void hwait_flag(...);
__cce_stub_attribute(__builtin_cce_img2col_cbuf_to_ca) void img2col_cbuf_to_ca(...);
__cce_stub_attribute(__builtin_cce_img2col_cbuf_to_cb) void img2col_cbuf_to_cb(...);
__cce_stub_attribute(__builtin_cce_img2col_cbuf_to_ub) void img2col_cbuf_to_ub(...);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca) void img2colv2_cbuf_to_ca(...);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ca_s4) void img2colv2_cbuf_to_ca_s4(...);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb) void img2colv2_cbuf_to_cb(...);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_cb_s4) void img2colv2_cbuf_to_cb_s4(...);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ub) void img2colv2_cbuf_to_ub(...);
__cce_stub_attribute(__builtin_cce_img2colv2_cbuf_to_ub_s4) void img2colv2_cbuf_to_ub_s4(...);
__cce_stub_attribute(__builtin_cce_insert_imm) uint64_t insert_imm(...);
__cce_stub_attribute(__builtin_cce_insert_reg) uint64_t insert_reg(...);
__cce_stub_attribute(__builtin_cce_insert_reg_f32) half insert_reg_f32(...);
__cce_stub_attribute(__builtin_cce_itm_cbuf_to_cbuf_inner) void itm_cbuf_to_cbuf_inner(...);
__cce_stub_attribute(__builtin_cce_ld_dev) uint64_t ld_dev(...);
__cce_stub_attribute(__builtin_cce_ldva) void ldva(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca) void load_cbuf_to_ca(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca_mx) void load_cbuf_to_ca_mx(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca_s4) void load_cbuf_to_ca_s4(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca_transpose) void load_cbuf_to_ca_transpose(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca_winograd) void load_cbuf_to_ca_winograd(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_ca_winograd_v2) void load_cbuf_to_ca_winograd_v2(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb) void load_cbuf_to_cb(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_b2) void load_cbuf_to_cb_b2(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_mx) void load_cbuf_to_cb_mx(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_s4) void load_cbuf_to_cb_s4(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_sp) void load_cbuf_to_cb_sp(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose) void load_cbuf_to_cb_transpose(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_transpose_s4) void load_cbuf_to_cb_transpose_s4(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_winograd) void load_cbuf_to_cb_winograd(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cb_winograd_v2) void load_cbuf_to_cb_winograd_v2(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cbuf) void load_cbuf_to_cbuf(...);
__cce_stub_attribute(__builtin_cce_load_cbuf_to_cbuf_s4) void load_cbuf_to_cbuf_s4(...);
__cce_stub_attribute(__builtin_cce_load_decompress_header_from_gm) void load_decompress_header_from_gm(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_ca) void load_gm_to_ca(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_ca_2dv2) void load_gm_to_ca_2dv2(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_ca_2dv2_s4) void load_gm_to_ca_2dv2_s4(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_ca_s4) void load_gm_to_ca_s4(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_ca_unzip) void load_gm_to_ca_unzip(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_cb) void load_gm_to_cb(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_cb_2dv2) void load_gm_to_cb_2dv2(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_cb_2dv2_s4) void load_gm_to_cb_2dv2_s4(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_cb_s4) void load_gm_to_cb_s4(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_cb_unzip) void load_gm_to_cb_unzip(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf) void load_gm_to_cbuf(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2) void load_gm_to_cbuf_2dv2(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_2dv2_s4) void load_gm_to_cbuf_2dv2_s4(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_s4) void load_gm_to_cbuf_s4(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_unzip) void load_gm_to_cbuf_unzip(...);
__cce_stub_attribute(__builtin_cce_load_gm_to_cbuf_xgamma) void load_gm_to_cbuf_xgamma(...);
__cce_stub_attribute(__builtin_cce_load_image_to_cbuf) void load_image_to_cbuf(...);
__cce_stub_attribute(__builtin_cce_load_smask_table_from_cbuf) void load_smask_table_from_cbuf(...);
__cce_stub_attribute(__builtin_cce_load_smask_table_from_gm) void load_smask_table_from_gm(...);
__cce_stub_attribute(__builtin_cce_load_smask_table_from_ub) void load_smask_table_from_ub(...);
__cce_stub_attribute(__builtin_cce_load_unzip_index_from_gm) void load_unzip_index_from_gm(...);
__cce_stub_attribute(__builtin_cce_mad) void mad(...);
__cce_stub_attribute(__builtin_cce_mad_b8u2) void mad_b8u2(...);
__cce_stub_attribute(__builtin_cce_mad_bf16s4) void mad_bf16s4(...);
__cce_stub_attribute(__builtin_cce_mad_e4m3s4) void mad_e4m3s4(...);
__cce_stub_attribute(__builtin_cce_mad_f16s4) void mad_f16s4(...);
__cce_stub_attribute(__builtin_cce_mad_f16u2) void mad_f16u2(...);
__cce_stub_attribute(__builtin_cce_mad_inner) void mad_inner(...);
__cce_stub_attribute(__builtin_cce_mad_mx) void mad_mx(...);
__cce_stub_attribute(__builtin_cce_mad_s4) void mad_s4(...);
__cce_stub_attribute(__builtin_cce_mad_s4_inner) void mad_s4_inner(...);
__cce_stub_attribute(__builtin_cce_mad_s8s4) void mad_s8s4(...);
__cce_stub_attribute(__builtin_cce_mad_sp) void mad_sp(...);
__cce_stub_attribute(__builtin_cce_mad_tf322f32) void mad_tf322f32(...);
__cce_stub_attribute(__builtin_cce_matmul_mx_to_l1_e4m3e4m3) void matmul_mx_to_l1_e4m3e4m3(...);
__cce_stub_attribute(__builtin_cce_matmul_mx_to_l1_e4m3s4) void matmul_mx_to_l1_e4m3s4(...);
__cce_stub_attribute(__builtin_cce_matmul_mx_to_l1_f16e4m3) void matmul_mx_to_l1_f16e4m3(...);
__cce_stub_attribute(__builtin_cce_matmul_mx_to_l1_hif4s4) void matmul_mx_to_l1_hif4s4(...);
__cce_stub_attribute(__builtin_cce_matmul_to_l1_e4m3e4m3) void matmul_to_l1_e4m3e4m3(...);
__cce_stub_attribute(__builtin_cce_matmul_to_l1_e4m3s4) void matmul_to_l1_e4m3s4(...);
__cce_stub_attribute(__builtin_cce_matmul_to_l1_e4m3s8) void matmul_to_l1_e4m3s8(...);
__cce_stub_attribute(__builtin_cce_matmul_to_l1_f16f16) void matmul_to_l1_f16f16(...);
__cce_stub_attribute(__builtin_cce_matmul_to_l1_s16s8) void matmul_to_l1_s16s8(...);
__cce_stub_attribute(__builtin_cce_matmul_to_l1_s4s4) void matmul_to_l1_s4s4(...);
__cce_stub_attribute(__builtin_cce_matmul_to_l1_s8s4) void matmul_to_l1_s8s4(...);
__cce_stub_attribute(__builtin_cce_matmul_to_l1_s8s8) void matmul_to_l1_s8s8(...);
__cce_stub_attribute(__builtin_cce_matmul_ub_to_ub_s16s8) void matmul_ub_to_ub_s16s8(...);
__cce_stub_attribute(__builtin_cce_matmul_ub_to_ub_s8s4) void matmul_ub_to_ub_s8s4(...);
__cce_stub_attribute(__builtin_cce_matmul_ub_to_ub_s8s8) void matmul_ub_to_ub_s8s8(...);
__cce_stub_attribute(__builtin_cce_maxfilter) void maxfilter(...);
__cce_stub_attribute(__builtin_cce_minfilter) void minfilter(...);
__cce_stub_attribute(__builtin_cce_mov_vspr) void mov_vspr(...);
__cce_stub_attribute(__builtin_cce_mvf_dci) void mvf_dci(...);
__cce_stub_attribute(__builtin_cce_mvf_gm_to_ub_b128_u16) void mvf_gm_to_ub_b128_u16(...);
__cce_stub_attribute(__builtin_cce_mvf_gm_to_ub_b128_u32) void mvf_gm_to_ub_b128_u32(...);
__cce_stub_attribute(__builtin_cce_mvf_gm_to_ub_b256_u16) void mvf_gm_to_ub_b256_u16(...);
__cce_stub_attribute(__builtin_cce_mvf_gm_to_ub_b256_u32) void mvf_gm_to_ub_b256_u32(...);
__cce_stub_attribute(__builtin_cce_mvf_gm_to_ub_b32_u16) void mvf_gm_to_ub_b32_u16(...);
__cce_stub_attribute(__builtin_cce_mvf_gm_to_ub_b32_u32) void mvf_gm_to_ub_b32_u32(...);
__cce_stub_attribute(__builtin_cce_mvf_gm_to_ub_b512_u16) void mvf_gm_to_ub_b512_u16(...);
__cce_stub_attribute(__builtin_cce_mvf_gm_to_ub_b512_u32) void mvf_gm_to_ub_b512_u32(...);
__cce_stub_attribute(__builtin_cce_mvf_gm_to_ub_b64_u16) void mvf_gm_to_ub_b64_u16(...);
__cce_stub_attribute(__builtin_cce_mvf_gm_to_ub_b64_u32) void mvf_gm_to_ub_b64_u32(...);
__cce_stub_attribute(__builtin_cce_nddma_out_to_ub_b16) void nddma_out_to_ub_b16(...);
__cce_stub_attribute(__builtin_cce_nddma_out_to_ub_b32) void nddma_out_to_ub_b32(...);
__cce_stub_attribute(__builtin_cce_nddma_out_to_ub_b8) void nddma_out_to_ub_b8(...);
__cce_stub_attribute(__builtin_cce_nddma_ub_to_ub_b16) void nddma_ub_to_ub_b16(...);
__cce_stub_attribute(__builtin_cce_nddma_ub_to_ub_b32) void nddma_ub_to_ub_b32(...);
__cce_stub_attribute(__builtin_cce_nddma_ub_to_ub_b8) void nddma_ub_to_ub_b8(...);
__cce_stub_attribute(__builtin_cce_pipe_barrier) void pipe_barrier(...);
__cce_stub_attribute(__builtin_cce_postproc_to_l1_inner) void postproc_to_l1_inner(...);
__cce_stub_attribute(__builtin_cce_preload) void preload(...);
__cce_stub_attribute(__builtin_cce_release_pbid) void release_pbid(...);
__cce_stub_attribute(__builtin_cce_rls_buf) void rls_buf(...);
__cce_stub_attribute(__builtin_cce_rpn_cor) void rpn_cor(...);
__cce_stub_attribute(__builtin_cce_rpn_cor_diag) void rpn_cor_diag(...);
__cce_stub_attribute(__builtin_cce_rpn_cor_diag2) void rpn_cor_diag2(...);
__cce_stub_attribute(__builtin_cce_sbitset0) uint64_t sbitset0(...);
__cce_stub_attribute(__builtin_cce_sbitset1) uint64_t sbitset1(...);
__cce_stub_attribute(__builtin_cce_scatter_ubuf_to_gm_u16) void scatter_ubuf_to_gm_u16(...);
__cce_stub_attribute(__builtin_cce_scatter_ubuf_to_gm_u32) void scatter_ubuf_to_gm_u32(...);
__cce_stub_attribute(__builtin_cce_scatter_ubuf_to_gm_u64) void scatter_ubuf_to_gm_u64(...);
__cce_stub_attribute(__builtin_cce_scatter_ubuf_to_gm_u8) void scatter_ubuf_to_gm_u8(...);
__cce_stub_attribute(__builtin_cce_scatter_vabs) void scatter_vabs(...);
__cce_stub_attribute(__builtin_cce_scatter_vabs_f16) void scatter_vabs_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vabs_f32) void scatter_vabs_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vabs_s16) void scatter_vabs_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vadd) void scatter_vadd(...);
__cce_stub_attribute(__builtin_cce_scatter_vadd_f16) void scatter_vadd_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vadd_f32) void scatter_vadd_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vadd_s16) void scatter_vadd_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vadd_s32) void scatter_vadd_s32(...);
__cce_stub_attribute(__builtin_cce_scatter_vadds) void scatter_vadds(...);
__cce_stub_attribute(__builtin_cce_scatter_vadds_f16) void scatter_vadds_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vadds_f32) void scatter_vadds_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vadds_s16) void scatter_vadds_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vadds_s32) void scatter_vadds_s32(...);
__cce_stub_attribute(__builtin_cce_scatter_vaxpy) void scatter_vaxpy(...);
__cce_stub_attribute(__builtin_cce_scatter_vaxpy_f16) void scatter_vaxpy_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vaxpy_f32) void scatter_vaxpy_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vaxpy_fmix) void scatter_vaxpy_fmix(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_eq) void scatter_vcmp_eq(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_eq_f16) void scatter_vcmp_eq_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_eq_f32) void scatter_vcmp_eq_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_eq_s16) void scatter_vcmp_eq_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_ge) void scatter_vcmp_ge(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_ge_f16) void scatter_vcmp_ge_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_ge_f32) void scatter_vcmp_ge_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_ge_s16) void scatter_vcmp_ge_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_gt) void scatter_vcmp_gt(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_gt_f16) void scatter_vcmp_gt_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_gt_f32) void scatter_vcmp_gt_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_gt_s16) void scatter_vcmp_gt_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_le) void scatter_vcmp_le(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_le_f16) void scatter_vcmp_le_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_le_f32) void scatter_vcmp_le_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_le_s16) void scatter_vcmp_le_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_lt) void scatter_vcmp_lt(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_lt_f16) void scatter_vcmp_lt_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_lt_f32) void scatter_vcmp_lt_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_lt_s16) void scatter_vcmp_lt_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_ne) void scatter_vcmp_ne(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_ne_f16) void scatter_vcmp_ne_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_ne_f32) void scatter_vcmp_ne_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vcmp_ne_s16) void scatter_vcmp_ne_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vconcat_f16) void scatter_vconcat_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vconcat_f32) void scatter_vconcat_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_deq) void scatter_vconv_deq(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162f32) void scatter_vconv_f162f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162s32a) void scatter_vconv_f162s32a(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162s32c) void scatter_vconv_f162s32c(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162s32f) void scatter_vconv_f162s32f(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162s32r) void scatter_vconv_f162s32r(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162s32z) void scatter_vconv_f162s32z(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162s8) void scatter_vconv_f162s8(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162s8a) void scatter_vconv_f162s8a(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162s8c) void scatter_vconv_f162s8c(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162s8f) void scatter_vconv_f162s8f(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162s8z) void scatter_vconv_f162s8z(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162u8) void scatter_vconv_f162u8(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162u8a) void scatter_vconv_f162u8a(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162u8c) void scatter_vconv_f162u8c(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162u8f) void scatter_vconv_f162u8f(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f162u8z) void scatter_vconv_f162u8z(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f322f16) void scatter_vconv_f322f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f322f16o) void scatter_vconv_f322f16o(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f322s32a) void scatter_vconv_f322s32a(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f322s32c) void scatter_vconv_f322s32c(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f322s32f) void scatter_vconv_f322s32f(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f322s32r) void scatter_vconv_f322s32r(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_f322s32z) void scatter_vconv_f322s32z(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_s322f32) void scatter_vconv_s322f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_s82f16) void scatter_vconv_s82f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vconv_u82f16) void scatter_vconv_u82f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vcshuffle_b16) void scatter_vcshuffle_b16(...);
__cce_stub_attribute(__builtin_cce_scatter_vcshuffle_b32) void scatter_vcshuffle_b32(...);
__cce_stub_attribute(__builtin_cce_scatter_vcshuffle_b8) void scatter_vcshuffle_b8(...);
__cce_stub_attribute(__builtin_cce_scatter_vdiv) void scatter_vdiv(...);
__cce_stub_attribute(__builtin_cce_scatter_vdiv_f16) void scatter_vdiv_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vdiv_f32) void scatter_vdiv_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vector_mov) void scatter_vector_mov(...);
__cce_stub_attribute(__builtin_cce_scatter_vector_mov_f16) void scatter_vector_mov_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vector_mov_s16) void scatter_vector_mov_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vector_mov_u16) void scatter_vector_mov_u16(...);
__cce_stub_attribute(__builtin_cce_scatter_vexp) void scatter_vexp(...);
__cce_stub_attribute(__builtin_cce_scatter_vexp_f16) void scatter_vexp_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vexp_f32) void scatter_vexp_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vextract_f16) void scatter_vextract_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vextract_f32) void scatter_vextract_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vln) void scatter_vln(...);
__cce_stub_attribute(__builtin_cce_scatter_vln_f16) void scatter_vln_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vln_f32) void scatter_vln_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmadd) void scatter_vmadd(...);
__cce_stub_attribute(__builtin_cce_scatter_vmadd_f16) void scatter_vmadd_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmadd_f32) void scatter_vmadd_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmaddrelu) void scatter_vmaddrelu(...);
__cce_stub_attribute(__builtin_cce_scatter_vmaddrelu_f16) void scatter_vmaddrelu_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmaddrelu_f32) void scatter_vmaddrelu_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmax) void scatter_vmax(...);
__cce_stub_attribute(__builtin_cce_scatter_vmax_f16) void scatter_vmax_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmax_f32) void scatter_vmax_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmax_s16) void scatter_vmax_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmax_s32) void scatter_vmax_s32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmaxs_f16) void scatter_vmaxs_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmaxs_f32) void scatter_vmaxs_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmaxs_s16) void scatter_vmaxs_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmaxs_s32) void scatter_vmaxs_s32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmin) void scatter_vmin(...);
__cce_stub_attribute(__builtin_cce_scatter_vmin_f16) void scatter_vmin_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmin_f32) void scatter_vmin_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmin_s16) void scatter_vmin_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmin_s32) void scatter_vmin_s32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmins_f16) void scatter_vmins_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmins_f32) void scatter_vmins_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmins_s16) void scatter_vmins_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmins_s32) void scatter_vmins_s32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmla) void scatter_vmla(...);
__cce_stub_attribute(__builtin_cce_scatter_vmla_f16) void scatter_vmla_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmla_f32) void scatter_vmla_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmla_fmix) void scatter_vmla_fmix(...);
__cce_stub_attribute(__builtin_cce_scatter_vmul) void scatter_vmul(...);
__cce_stub_attribute(__builtin_cce_scatter_vmul_f16) void scatter_vmul_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmul_f32) void scatter_vmul_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmul_s16) void scatter_vmul_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmul_s32) void scatter_vmul_s32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmulconv_f162s8) void scatter_vmulconv_f162s8(...);
__cce_stub_attribute(__builtin_cce_scatter_vmulconv_f162u8) void scatter_vmulconv_f162u8(...);
__cce_stub_attribute(__builtin_cce_scatter_vmuls) void scatter_vmuls(...);
__cce_stub_attribute(__builtin_cce_scatter_vmuls_f16) void scatter_vmuls_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmuls_f32) void scatter_vmuls_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vmuls_s16) void scatter_vmuls_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vmuls_s32) void scatter_vmuls_s32(...);
__cce_stub_attribute(__builtin_cce_scatter_vnchwconv_b16) void scatter_vnchwconv_b16(...);
__cce_stub_attribute(__builtin_cce_scatter_vnchwconv_b32) void scatter_vnchwconv_b32(...);
__cce_stub_attribute(__builtin_cce_scatter_vnchwconv_b8) void scatter_vnchwconv_b8(...);
__cce_stub_attribute(__builtin_cce_scatter_vrec) void scatter_vrec(...);
__cce_stub_attribute(__builtin_cce_scatter_vrec_f16) void scatter_vrec_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vrec_f32) void scatter_vrec_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vrelu) void scatter_vrelu(...);
__cce_stub_attribute(__builtin_cce_scatter_vrelu_f16) void scatter_vrelu_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vrelu_f32) void scatter_vrelu_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vrelu_s32) void scatter_vrelu_s32(...);
__cce_stub_attribute(__builtin_cce_scatter_vrsqrt) void scatter_vrsqrt(...);
__cce_stub_attribute(__builtin_cce_scatter_vrsqrt_f16) void scatter_vrsqrt_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vrsqrt_f32) void scatter_vrsqrt_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vscmerge) void scatter_vscmerge(...);
__cce_stub_attribute(__builtin_cce_scatter_vscmerge_b16) void scatter_vscmerge_b16(...);
__cce_stub_attribute(__builtin_cce_scatter_vscmerge_b8) void scatter_vscmerge_b8(...);
__cce_stub_attribute(__builtin_cce_scatter_vscmerge_f16) void scatter_vscmerge_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vscsplit) void scatter_vscsplit(...);
__cce_stub_attribute(__builtin_cce_scatter_vscsplit_b16) void scatter_vscsplit_b16(...);
__cce_stub_attribute(__builtin_cce_scatter_vscsplit_b8) void scatter_vscsplit_b8(...);
__cce_stub_attribute(__builtin_cce_scatter_vscsplit_f16) void scatter_vscsplit_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vsel) void scatter_vsel(...);
__cce_stub_attribute(__builtin_cce_scatter_vsel_f16) void scatter_vsel_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vsel_f32) void scatter_vsel_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vsqrt) void scatter_vsqrt(...);
__cce_stub_attribute(__builtin_cce_scatter_vsqrt_f16) void scatter_vsqrt_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vsqrt_f32) void scatter_vsqrt_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vsub) void scatter_vsub(...);
__cce_stub_attribute(__builtin_cce_scatter_vsub_f16) void scatter_vsub_f16(...);
__cce_stub_attribute(__builtin_cce_scatter_vsub_f32) void scatter_vsub_f32(...);
__cce_stub_attribute(__builtin_cce_scatter_vsub_s16) void scatter_vsub_s16(...);
__cce_stub_attribute(__builtin_cce_scatter_vsub_s32) void scatter_vsub_s32(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_0) void set_aipp_spr_0(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_1) void set_aipp_spr_1(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_10) void set_aipp_spr_10(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_11) void set_aipp_spr_11(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_12) void set_aipp_spr_12(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_13) void set_aipp_spr_13(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_14) void set_aipp_spr_14(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_15) void set_aipp_spr_15(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_16) void set_aipp_spr_16(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_17) void set_aipp_spr_17(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_18) void set_aipp_spr_18(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_19) void set_aipp_spr_19(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_2) void set_aipp_spr_2(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_20) void set_aipp_spr_20(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_21) void set_aipp_spr_21(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_22) void set_aipp_spr_22(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_23) void set_aipp_spr_23(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_24) void set_aipp_spr_24(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_25) void set_aipp_spr_25(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_26) void set_aipp_spr_26(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_27) void set_aipp_spr_27(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_28) void set_aipp_spr_28(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_29) void set_aipp_spr_29(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_3) void set_aipp_spr_3(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_30) void set_aipp_spr_30(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_31) void set_aipp_spr_31(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_4) void set_aipp_spr_4(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_5) void set_aipp_spr_5(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_6) void set_aipp_spr_6(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_7) void set_aipp_spr_7(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_8) void set_aipp_spr_8(...);
__cce_stub_attribute(__builtin_cce_set_aipp_spr_9) void set_aipp_spr_9(...);
__cce_stub_attribute(__builtin_cce_set_ast_reg_0) void set_ast_reg_0(...);
__cce_stub_attribute(__builtin_cce_set_ast_reg_1) void set_ast_reg_1(...);
__cce_stub_attribute(__builtin_cce_set_ast_reg_2) void set_ast_reg_2(...);
__cce_stub_attribute(__builtin_cce_set_ast_reg_3) void set_ast_reg_3(...);
__cce_stub_attribute(__builtin_cce_set_ast_scb_0) void set_ast_scb_0(...);
__cce_stub_attribute(__builtin_cce_set_ast_scb_1) void set_ast_scb_1(...);
__cce_stub_attribute(__builtin_cce_set_ast_scb_2) void set_ast_scb_2(...);
__cce_stub_attribute(__builtin_cce_set_ast_scb_3) void set_ast_scb_3(...);
__cce_stub_attribute(__builtin_cce_set_atom_load_para) void set_atom_load_para(...);
__cce_stub_attribute(__builtin_cce_set_bmu_segm_bt) void set_bmu_segm_bt(...);
__cce_stub_attribute(__builtin_cce_set_bmu_segm_fb) void set_bmu_segm_fb(...);
__cce_stub_attribute(__builtin_cce_set_bmu_segm_l0a) void set_bmu_segm_l0a(...);
__cce_stub_attribute(__builtin_cce_set_bmu_segm_l0b) void set_bmu_segm_l0b(...);
__cce_stub_attribute(__builtin_cce_set_bmu_segm_l0c) void set_bmu_segm_l0c(...);
__cce_stub_attribute(__builtin_cce_set_bmu_segm_l1) void set_bmu_segm_l1(...);
__cce_stub_attribute(__builtin_cce_set_bmu_segm_ub) void set_bmu_segm_ub(...);
__cce_stub_attribute(__builtin_cce_set_cache_normread) void set_cache_normread(...);
__cce_stub_attribute(__builtin_cce_set_cache_notwriteback) void set_cache_notwriteback(...);
__cce_stub_attribute(__builtin_cce_set_cache_readinv) void set_cache_readinv(...);
__cce_stub_attribute(__builtin_cce_set_cache_readlast) void set_cache_readlast(...);
__cce_stub_attribute(__builtin_cce_set_channel_para) void set_channel_para(...);
__cce_stub_attribute(__builtin_cce_set_channel_stride) void set_channel_stride(...);
__cce_stub_attribute(__builtin_cce_set_cmpmask) void set_cmpmask(...);
__cce_stub_attribute(__builtin_cce_set_cond) void set_cond(...);
__cce_stub_attribute(__builtin_cce_set_cond_taskid) void set_cond_taskid(...);
__cce_stub_attribute(__builtin_cce_set_condition_flag) void set_condition_flag(...);
__cce_stub_attribute(__builtin_cce_set_ctrl) void set_ctrl(...);
__cce_stub_attribute(__builtin_cce_set_cube_stride_para) void set_cube_stride_para(...);
__cce_stub_attribute(__builtin_cce_set_data_exp_0) void set_data_exp_0(...);
__cce_stub_attribute(__builtin_cce_set_data_exp_1) void set_data_exp_1(...);
__cce_stub_attribute(__builtin_cce_set_data_exp_2) void set_data_exp_2(...);
__cce_stub_attribute(__builtin_cce_set_data_exp_3) void set_data_exp_3(...);
__cce_stub_attribute(__builtin_cce_set_deqscale) void set_deqscale(...);
__cce_stub_attribute(__builtin_cce_set_dtc_para) void set_dtc_para(...);
__cce_stub_attribute(__builtin_cce_set_elt_antiq_para) void set_elt_antiq_para(...);
__cce_stub_attribute(__builtin_cce_set_elt_src_para) void set_elt_src_para(...);
__cce_stub_attribute(__builtin_cce_set_fcol2img) void set_fcol2img(...);
__cce_stub_attribute(__builtin_cce_set_ffts_base_addr) void set_ffts_base_addr(...);
__cce_stub_attribute(__builtin_cce_set_fix_clip_relu) void set_fix_clip_relu(...);
__cce_stub_attribute(__builtin_cce_set_fixp_addr) void set_fixp_addr(...);
__cce_stub_attribute(__builtin_cce_set_fixp_max_cfg) void set_fixp_max_cfg(...);
__cce_stub_attribute(__builtin_cce_set_fixp_nz_para) void set_fixp_nz_para(...);
__cce_stub_attribute(__builtin_cce_set_flag) void set_flag(...);
__cce_stub_attribute(__builtin_cce_set_fm_step_pos) void set_fm_step_pos(...);
__cce_stub_attribute(__builtin_cce_set_fmatrix) void set_fmatrix(...);
__cce_stub_attribute(__builtin_cce_set_fmatrix_b) void set_fmatrix_b(...);
__cce_stub_attribute(__builtin_cce_set_fmatrix_dual_0) void set_fmatrix_dual_0(...);
__cce_stub_attribute(__builtin_cce_set_fmatrix_dual_1) void set_fmatrix_dual_1(...);
__cce_stub_attribute(__builtin_cce_set_fp_para) void set_fp_para(...);
__cce_stub_attribute(__builtin_cce_set_fp_para_post) void set_fp_para_post(...);
__cce_stub_attribute(__builtin_cce_set_fp_post_cfg) void set_fp_post_cfg(...);
__cce_stub_attribute(__builtin_cce_set_fpc) void set_fpc(...);
__cce_stub_attribute(__builtin_cce_set_fpdeq) void set_fpdeq(...);
__cce_stub_attribute(__builtin_cce_set_intra_block) void set_intra_block(...);
__cce_stub_attribute(__builtin_cce_set_ipc_reg_0) void set_ipc_reg_0(...);
__cce_stub_attribute(__builtin_cce_set_ipc_reg_1) void set_ipc_reg_1(...);
__cce_stub_attribute(__builtin_cce_set_ipc_reg_2) void set_ipc_reg_2(...);
__cce_stub_attribute(__builtin_cce_set_ipc_reg_3) void set_ipc_reg_3(...);
__cce_stub_attribute(__builtin_cce_set_ipc_reg_4) void set_ipc_reg_4(...);
__cce_stub_attribute(__builtin_cce_set_ipc_reg_5) void set_ipc_reg_5(...);
__cce_stub_attribute(__builtin_cce_set_ipc_reg_6) void set_ipc_reg_6(...);
__cce_stub_attribute(__builtin_cce_set_ipc_reg_7) void set_ipc_reg_7(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_0) void set_ipc_scb_0(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_1) void set_ipc_scb_1(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_10) void set_ipc_scb_10(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_11) void set_ipc_scb_11(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_12) void set_ipc_scb_12(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_13) void set_ipc_scb_13(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_14) void set_ipc_scb_14(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_15) void set_ipc_scb_15(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_2) void set_ipc_scb_2(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_3) void set_ipc_scb_3(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_4) void set_ipc_scb_4(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_5) void set_ipc_scb_5(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_6) void set_ipc_scb_6(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_7) void set_ipc_scb_7(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_8) void set_ipc_scb_8(...);
__cce_stub_attribute(__builtin_cce_set_ipc_scb_9) void set_ipc_scb_9(...);
__cce_stub_attribute(__builtin_cce_set_ita_max_addr) void set_ita_max_addr(...);
__cce_stub_attribute(__builtin_cce_set_itm_anchor0) void set_itm_anchor0(...);
__cce_stub_attribute(__builtin_cce_set_itm_anchor1) void set_itm_anchor1(...);
__cce_stub_attribute(__builtin_cce_set_itm_image_para) void set_itm_image_para(...);
__cce_stub_attribute(__builtin_cce_set_kernel) void set_kernel(...);
__cce_stub_attribute(__builtin_cce_set_l0_set_value_bf16) void set_l0_set_value_bf16(...);
__cce_stub_attribute(__builtin_cce_set_l0_set_value_h) void set_l0_set_value_h(...);
__cce_stub_attribute(__builtin_cce_set_l0_set_value_ui) void set_l0_set_value_ui(...);
__cce_stub_attribute(__builtin_cce_set_l0a_2d) void set_l0a_2d(...);
__cce_stub_attribute(__builtin_cce_set_l0b_2d) void set_l0b_2d(...);
__cce_stub_attribute(__builtin_cce_set_l1_2d) void set_l1_2d(...);
__cce_stub_attribute(__builtin_cce_set_l1_3d_size) void set_l1_3d_size(...);
__cce_stub_attribute(__builtin_cce_set_l3d_rpt) void set_l3d_rpt(...);
__cce_stub_attribute(__builtin_cce_set_l3d_rpt_b) void set_l3d_rpt_b(...);
__cce_stub_attribute(__builtin_cce_set_loop0_stride_nddma) void set_loop0_stride_nddma(...);
__cce_stub_attribute(__builtin_cce_set_loop1_stride_l1toout) void set_loop1_stride_l1toout(...);
__cce_stub_attribute(__builtin_cce_set_loop1_stride_nddma) void set_loop1_stride_nddma(...);
__cce_stub_attribute(__builtin_cce_set_loop1_stride_outtol1) void set_loop1_stride_outtol1(...);
__cce_stub_attribute(__builtin_cce_set_loop1_stride_outtoub) void set_loop1_stride_outtoub(...);
__cce_stub_attribute(__builtin_cce_set_loop1_stride_ubtoout) void set_loop1_stride_ubtoout(...);
__cce_stub_attribute(__builtin_cce_set_loop2_stride_l1toout) void set_loop2_stride_l1toout(...);
__cce_stub_attribute(__builtin_cce_set_loop2_stride_nddma) void set_loop2_stride_nddma(...);
__cce_stub_attribute(__builtin_cce_set_loop2_stride_outtol1) void set_loop2_stride_outtol1(...);
__cce_stub_attribute(__builtin_cce_set_loop2_stride_outtoub) void set_loop2_stride_outtoub(...);
__cce_stub_attribute(__builtin_cce_set_loop2_stride_ubtoout) void set_loop2_stride_ubtoout(...);
__cce_stub_attribute(__builtin_cce_set_loop3_para) void set_loop3_para(...);
__cce_stub_attribute(__builtin_cce_set_loop3_stride_nddma) void set_loop3_stride_nddma(...);
__cce_stub_attribute(__builtin_cce_set_loop4_para) void set_loop4_para(...);
__cce_stub_attribute(__builtin_cce_set_loop4_stride_nddma) void set_loop4_stride_nddma(...);
__cce_stub_attribute(__builtin_cce_set_loop_size_l1toout) void set_loop_size_l1toout(...);
__cce_stub_attribute(__builtin_cce_set_loop_size_outtol1) void set_loop_size_outtol1(...);
__cce_stub_attribute(__builtin_cce_set_loop_size_outtoub) void set_loop_size_outtoub(...);
__cce_stub_attribute(__builtin_cce_set_loop_size_ubtoout) void set_loop_size_ubtoout(...);
__cce_stub_attribute(__builtin_cce_set_loopenhance_para) void set_loopenhance_para(...);
__cce_stub_attribute(__builtin_cce_set_low_pre_tbl) void set_low_pre_tbl(...);
__cce_stub_attribute(__builtin_cce_set_lpcnt) void set_lpcnt(...);
__cce_stub_attribute(__builtin_cce_set_lrelu_alpha) void set_lrelu_alpha(...);
__cce_stub_attribute(__builtin_cce_set_m_clip_relu) void set_m_clip_relu(...);
__cce_stub_attribute(__builtin_cce_set_m_elt_antiq_para) void set_m_elt_antiq_para(...);
__cce_stub_attribute(__builtin_cce_set_m_elt_src_para) void set_m_elt_src_para(...);
__cce_stub_attribute(__builtin_cce_set_m_fmatrix) void set_m_fmatrix(...);
__cce_stub_attribute(__builtin_cce_set_m_fmatrix_dual_0) void set_m_fmatrix_dual_0(...);
__cce_stub_attribute(__builtin_cce_set_m_fmatrix_dual_1) void set_m_fmatrix_dual_1(...);
__cce_stub_attribute(__builtin_cce_set_m_fpc) void set_m_fpc(...);
__cce_stub_attribute(__builtin_cce_set_m_padding) void set_m_padding(...);
__cce_stub_attribute(__builtin_cce_set_m_quant_post) void set_m_quant_post(...);
__cce_stub_attribute(__builtin_cce_set_m_quant_pre) void set_m_quant_pre(...);
__cce_stub_attribute(__builtin_cce_set_m_relu_alpha) void set_m_relu_alpha(...);
__cce_stub_attribute(__builtin_cce_set_matrix_para) void set_matrix_para(...);
__cce_stub_attribute(__builtin_cce_set_mov_pad_val) void set_mov_pad_val(...);
__cce_stub_attribute(__builtin_cce_set_mte2_antiq_para) void set_mte2_antiq_para(...);
__cce_stub_attribute(__builtin_cce_set_mte2_nz_para) void set_mte2_nz_para(...);
__cce_stub_attribute(__builtin_cce_set_mte2_qtable0) void set_mte2_qtable0(...);
__cce_stub_attribute(__builtin_cce_set_mte2_qtable1) void set_mte2_qtable1(...);
__cce_stub_attribute(__builtin_cce_set_mte2_qtable2) void set_mte2_qtable2(...);
__cce_stub_attribute(__builtin_cce_set_mte2_qtable3) void set_mte2_qtable3(...);
__cce_stub_attribute(__builtin_cce_set_mte2_src_para) void set_mte2_src_para(...);
__cce_stub_attribute(__builtin_cce_set_mte3_nz_para) void set_mte3_nz_para(...);
__cce_stub_attribute(__builtin_cce_set_mx_buf_addr) void set_mx_buf_addr(...);
__cce_stub_attribute(__builtin_cce_set_nd_para) void set_nd_para(...);
__cce_stub_attribute(__builtin_cce_set_pad_cnt_nddma) void set_pad_cnt_nddma(...);
__cce_stub_attribute(__builtin_cce_set_pad_val_nddma) void set_pad_val_nddma(...);
__cce_stub_attribute(__builtin_cce_set_pad_val_outtol1) void set_pad_val_outtol1(...);
__cce_stub_attribute(__builtin_cce_set_pad_val_outtoub) void set_pad_val_outtoub(...);
__cce_stub_attribute(__builtin_cce_set_padding) void set_padding(...);
__cce_stub_attribute(__builtin_cce_set_padding_b) void set_padding_b(...);
__cce_stub_attribute(__builtin_cce_set_pcie_rd_ctrl) void set_pcie_rd_ctrl(...);
__cce_stub_attribute(__builtin_cce_set_pcie_wr_ctrl) void set_pcie_wr_ctrl(...);
__cce_stub_attribute(__builtin_cce_set_pnt_coe) void set_pnt_coe(...);
__cce_stub_attribute(__builtin_cce_set_quant_post) void set_quant_post(...);
__cce_stub_attribute(__builtin_cce_set_quant_pre) void set_quant_pre(...);
__cce_stub_attribute(__builtin_cce_set_rawheader_to_gm) void set_rawheader_to_gm(...);
__cce_stub_attribute(__builtin_cce_set_relu_alpha) void set_relu_alpha(...);
__cce_stub_attribute(__builtin_cce_set_reqscale) void set_reqscale(...);
__cce_stub_attribute(__builtin_cce_set_rpn_cor_ir) void set_rpn_cor_ir(...);
__cce_stub_attribute(__builtin_cce_set_rpn_offset) void set_rpn_offset(...);
__cce_stub_attribute(__builtin_cce_set_rpn_offset_f32) void set_rpn_offset_f32(...);
__cce_stub_attribute(__builtin_cce_set_safety_crc_en) void set_safety_crc_en(...);
__cce_stub_attribute(__builtin_cce_set_safety_crc_excp) void set_safety_crc_excp(...);
__cce_stub_attribute(__builtin_cce_set_smask_index) void set_smask_index(...);
__cce_stub_attribute(__builtin_cce_set_st_atomic_cfg) void set_st_atomic_cfg(...);
__cce_stub_attribute(__builtin_cce_set_ub_2d) void set_ub_2d(...);
__cce_stub_attribute(__builtin_cce_set_upscale_para) void set_upscale_para(...);
__cce_stub_attribute(__builtin_cce_set_vector_mask) void set_vector_mask(...);
__cce_stub_attribute(__builtin_cce_set_vector_mask_dup) void set_vector_mask_dup(...);
__cce_stub_attribute(__builtin_cce_set_vpipe) void set_vpipe(...);
__cce_stub_attribute(__builtin_cce_set_vsp) void set_vsp(...);
__cce_stub_attribute(__builtin_cce_sff0) int64_t sff0(...);
__cce_stub_attribute(__builtin_cce_sff1) int64_t sff1(...);
__cce_stub_attribute(__builtin_cce_sflbits) int64_t sflbits(...);
__cce_stub_attribute(__builtin_cce_shl_imm_f32) float shl_imm_f32(...);
__cce_stub_attribute(__builtin_cce_st_dev) void st_dev(...);
__cce_stub_attribute(__builtin_cce_store_l1_to_out_image) void store_l1_to_out_image(...);
__cce_stub_attribute(__builtin_cce_try_wait) int64_t try_wait(...);
__cce_stub_attribute(__builtin_cce_use_pipe_v) void use_pipe_v(...);
__cce_stub_attribute(__builtin_cce_use_pipe_v2) void use_pipe_v2(...);
__cce_stub_attribute(__builtin_cce_v4dtrans) void v4dtrans(...);
__cce_stub_attribute(__builtin_cce_vabs) void vabs(...);
__cce_stub_attribute(__builtin_cce_vadd) void vadd(...);
__cce_stub_attribute(__builtin_cce_vadd_masked) void vadd_masked(...);
__cce_stub_attribute(__builtin_cce_vadddeqrelu) void vadddeqrelu(...);
__cce_stub_attribute(__builtin_cce_vaddrelu) void vaddrelu(...);
__cce_stub_attribute(__builtin_cce_vaddreluconv_f162s8) void vaddreluconv_f162s8(...);
__cce_stub_attribute(__builtin_cce_vaddreluconv_f322f16) void vaddreluconv_f322f16(...);
__cce_stub_attribute(__builtin_cce_vaddreluconv_s162s8) void vaddreluconv_s162s8(...);
__cce_stub_attribute(__builtin_cce_vaddreluconv_vdeqs162b8) void vaddreluconv_vdeqs162b8(...);
__cce_stub_attribute(__builtin_cce_vadds) void vadds(...);
__cce_stub_attribute(__builtin_cce_vand) void vand(...);
__cce_stub_attribute(__builtin_cce_vaxpy) void vaxpy(...);
__cce_stub_attribute(__builtin_cce_vbi) void vbi(...);
__cce_stub_attribute(__builtin_cce_vbrcb) void vbrcb(...);
__cce_stub_attribute(__builtin_cce_vbs) void vbs(...);
__cce_stub_attribute(__builtin_cce_vcadd) void vcadd(...);
__cce_stub_attribute(__builtin_cce_vcbd_s162s32) void vcbd_s162s32(...);
__cce_stub_attribute(__builtin_cce_vcbd_s162u32) void vcbd_s162u32(...);
__cce_stub_attribute(__builtin_cce_vcbd_s162u8) void vcbd_s162u8(...);
__cce_stub_attribute(__builtin_cce_vcbd_s322s16) void vcbd_s322s16(...);
__cce_stub_attribute(__builtin_cce_vcbd_s322u16) void vcbd_s322u16(...);
__cce_stub_attribute(__builtin_cce_vcbd_s322u8) void vcbd_s322u8(...);
__cce_stub_attribute(__builtin_cce_vcbd_u162s32) void vcbd_u162s32(...);
__cce_stub_attribute(__builtin_cce_vcbd_u162u32) void vcbd_u162u32(...);
__cce_stub_attribute(__builtin_cce_vcbd_u162u8) void vcbd_u162u8(...);
__cce_stub_attribute(__builtin_cce_vcbd_u322s16) void vcbd_u322s16(...);
__cce_stub_attribute(__builtin_cce_vcbd_u322u16) void vcbd_u322u16(...);
__cce_stub_attribute(__builtin_cce_vcbd_u322u8) void vcbd_u322u8(...);
__cce_stub_attribute(__builtin_cce_vcbd_u82s16) void vcbd_u82s16(...);
__cce_stub_attribute(__builtin_cce_vcbd_u82s32) void vcbd_u82s32(...);
__cce_stub_attribute(__builtin_cce_vcbd_u82u16) void vcbd_u82u16(...);
__cce_stub_attribute(__builtin_cce_vcbd_u82u32) void vcbd_u82u32(...);
__cce_stub_attribute(__builtin_cce_vcgadd) void vcgadd(...);
__cce_stub_attribute(__builtin_cce_vcgmax) void vcgmax(...);
__cce_stub_attribute(__builtin_cce_vcgmin) void vcgmin(...);
__cce_stub_attribute(__builtin_cce_vci) void vci(...);
__cce_stub_attribute(__builtin_cce_vcmax) void vcmax(...);
__cce_stub_attribute(__builtin_cce_vcmin) void vcmin(...);
__cce_stub_attribute(__builtin_cce_vcmp_eq) void vcmp_eq(...);
__cce_stub_attribute(__builtin_cce_vcmp_ge) void vcmp_ge(...);
__cce_stub_attribute(__builtin_cce_vcmp_gt) void vcmp_gt(...);
__cce_stub_attribute(__builtin_cce_vcmp_le) void vcmp_le(...);
__cce_stub_attribute(__builtin_cce_vcmp_lt) void vcmp_lt(...);
__cce_stub_attribute(__builtin_cce_vcmp_ne) void vcmp_ne(...);
__cce_stub_attribute(__builtin_cce_vcmpv_eq) void vcmpv_eq(...);
__cce_stub_attribute(__builtin_cce_vcmpv_ge) void vcmpv_ge(...);
__cce_stub_attribute(__builtin_cce_vcmpv_gt) void vcmpv_gt(...);
__cce_stub_attribute(__builtin_cce_vcmpv_le) void vcmpv_le(...);
__cce_stub_attribute(__builtin_cce_vcmpv_lt) void vcmpv_lt(...);
__cce_stub_attribute(__builtin_cce_vcmpv_ne) void vcmpv_ne(...);
__cce_stub_attribute(__builtin_cce_vcmpvs_eq) void vcmpvs_eq(...);
__cce_stub_attribute(__builtin_cce_vcmpvs_ge) void vcmpvs_ge(...);
__cce_stub_attribute(__builtin_cce_vcmpvs_gt) void vcmpvs_gt(...);
__cce_stub_attribute(__builtin_cce_vcmpvs_le) void vcmpvs_le(...);
__cce_stub_attribute(__builtin_cce_vcmpvs_lt) void vcmpvs_lt(...);
__cce_stub_attribute(__builtin_cce_vcmpvs_ne) void vcmpvs_ne(...);
__cce_stub_attribute(__builtin_cce_vconcat) void vconcat(...);
__cce_stub_attribute(__builtin_cce_vconv_bf162f32) void vconv_bf162f32(...);
__cce_stub_attribute(__builtin_cce_vconv_bf162s32a) void vconv_bf162s32a(...);
__cce_stub_attribute(__builtin_cce_vconv_bf162s32c) void vconv_bf162s32c(...);
__cce_stub_attribute(__builtin_cce_vconv_bf162s32f) void vconv_bf162s32f(...);
__cce_stub_attribute(__builtin_cce_vconv_bf162s32r) void vconv_bf162s32r(...);
__cce_stub_attribute(__builtin_cce_vconv_bf162s32z) void vconv_bf162s32z(...);
__cce_stub_attribute(__builtin_cce_vconv_deq) void vconv_deq(...);
__cce_stub_attribute(__builtin_cce_vconv_deqs162b8) void vconv_deqs162b8(...);
__cce_stub_attribute(__builtin_cce_vconv_deqs162b8h) void vconv_deqs162b8h(...);
__cce_stub_attribute(__builtin_cce_vconv_deqs162b8l) void vconv_deqs162b8l(...);
__cce_stub_attribute(__builtin_cce_vconv_deqs322f16) void vconv_deqs322f16(...);
__cce_stub_attribute(__builtin_cce_vconv_f162f32) void vconv_f162f32(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s16a) void vconv_f162s16a(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s16c) void vconv_f162s16c(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s16f) void vconv_f162s16f(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s16r) void vconv_f162s16r(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s16z) void vconv_f162s16z(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s32a) void vconv_f162s32a(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s32c) void vconv_f162s32c(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s32f) void vconv_f162s32f(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s32r) void vconv_f162s32r(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s32z) void vconv_f162s32z(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s4) void vconv_f162s4(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s4a) void vconv_f162s4a(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s4c) void vconv_f162s4c(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s4f) void vconv_f162s4f(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s4r) void vconv_f162s4r(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s4z) void vconv_f162s4z(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s8) void vconv_f162s8(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s8a) void vconv_f162s8a(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s8c) void vconv_f162s8c(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s8f) void vconv_f162s8f(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s8r) void vconv_f162s8r(...);
__cce_stub_attribute(__builtin_cce_vconv_f162s8z) void vconv_f162s8z(...);
__cce_stub_attribute(__builtin_cce_vconv_f162u8) void vconv_f162u8(...);
__cce_stub_attribute(__builtin_cce_vconv_f162u8a) void vconv_f162u8a(...);
__cce_stub_attribute(__builtin_cce_vconv_f162u8c) void vconv_f162u8c(...);
__cce_stub_attribute(__builtin_cce_vconv_f162u8f) void vconv_f162u8f(...);
__cce_stub_attribute(__builtin_cce_vconv_f162u8r) void vconv_f162u8r(...);
__cce_stub_attribute(__builtin_cce_vconv_f162u8z) void vconv_f162u8z(...);
__cce_stub_attribute(__builtin_cce_vconv_f322bf16a) void vconv_f322bf16a(...);
__cce_stub_attribute(__builtin_cce_vconv_f322bf16c) void vconv_f322bf16c(...);
__cce_stub_attribute(__builtin_cce_vconv_f322bf16f) void vconv_f322bf16f(...);
__cce_stub_attribute(__builtin_cce_vconv_f322bf16r) void vconv_f322bf16r(...);
__cce_stub_attribute(__builtin_cce_vconv_f322bf16z) void vconv_f322bf16z(...);
__cce_stub_attribute(__builtin_cce_vconv_f322f16) void vconv_f322f16(...);
__cce_stub_attribute(__builtin_cce_vconv_f322f16a) void vconv_f322f16a(...);
__cce_stub_attribute(__builtin_cce_vconv_f322f16c) void vconv_f322f16c(...);
__cce_stub_attribute(__builtin_cce_vconv_f322f16f) void vconv_f322f16f(...);
__cce_stub_attribute(__builtin_cce_vconv_f322f16o) void vconv_f322f16o(...);
__cce_stub_attribute(__builtin_cce_vconv_f322f16r) void vconv_f322f16r(...);
__cce_stub_attribute(__builtin_cce_vconv_f322f16z) void vconv_f322f16z(...);
__cce_stub_attribute(__builtin_cce_vconv_f322f32a) void vconv_f322f32a(...);
__cce_stub_attribute(__builtin_cce_vconv_f322f32c) void vconv_f322f32c(...);
__cce_stub_attribute(__builtin_cce_vconv_f322f32f) void vconv_f322f32f(...);
__cce_stub_attribute(__builtin_cce_vconv_f322f32r) void vconv_f322f32r(...);
__cce_stub_attribute(__builtin_cce_vconv_f322f32z) void vconv_f322f32z(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s16a) void vconv_f322s16a(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s16c) void vconv_f322s16c(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s16f) void vconv_f322s16f(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s16r) void vconv_f322s16r(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s16z) void vconv_f322s16z(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s32a) void vconv_f322s32a(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s32c) void vconv_f322s32c(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s32f) void vconv_f322s32f(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s32r) void vconv_f322s32r(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s32z) void vconv_f322s32z(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s64a) void vconv_f322s64a(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s64c) void vconv_f322s64c(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s64f) void vconv_f322s64f(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s64r) void vconv_f322s64r(...);
__cce_stub_attribute(__builtin_cce_vconv_f322s64z) void vconv_f322s64z(...);
__cce_stub_attribute(__builtin_cce_vconv_s162f16) void vconv_s162f16(...);
__cce_stub_attribute(__builtin_cce_vconv_s162f16a) void vconv_s162f16a(...);
__cce_stub_attribute(__builtin_cce_vconv_s162f16c) void vconv_s162f16c(...);
__cce_stub_attribute(__builtin_cce_vconv_s162f16f) void vconv_s162f16f(...);
__cce_stub_attribute(__builtin_cce_vconv_s162f16r) void vconv_s162f16r(...);
__cce_stub_attribute(__builtin_cce_vconv_s162f16z) void vconv_s162f16z(...);
__cce_stub_attribute(__builtin_cce_vconv_s162f32) void vconv_s162f32(...);
__cce_stub_attribute(__builtin_cce_vconv_s322f32) void vconv_s322f32(...);
__cce_stub_attribute(__builtin_cce_vconv_s322f32a) void vconv_s322f32a(...);
__cce_stub_attribute(__builtin_cce_vconv_s322f32c) void vconv_s322f32c(...);
__cce_stub_attribute(__builtin_cce_vconv_s322f32f) void vconv_s322f32f(...);
__cce_stub_attribute(__builtin_cce_vconv_s322f32r) void vconv_s322f32r(...);
__cce_stub_attribute(__builtin_cce_vconv_s322f32z) void vconv_s322f32z(...);
__cce_stub_attribute(__builtin_cce_vconv_s322s16) void vconv_s322s16(...);
__cce_stub_attribute(__builtin_cce_vconv_s322s64) void vconv_s322s64(...);
__cce_stub_attribute(__builtin_cce_vconv_s42f16) void vconv_s42f16(...);
__cce_stub_attribute(__builtin_cce_vconv_s642f32a) void vconv_s642f32a(...);
__cce_stub_attribute(__builtin_cce_vconv_s642f32c) void vconv_s642f32c(...);
__cce_stub_attribute(__builtin_cce_vconv_s642f32f) void vconv_s642f32f(...);
__cce_stub_attribute(__builtin_cce_vconv_s642f32r) void vconv_s642f32r(...);
__cce_stub_attribute(__builtin_cce_vconv_s642f32z) void vconv_s642f32z(...);
__cce_stub_attribute(__builtin_cce_vconv_s642s32) void vconv_s642s32(...);
__cce_stub_attribute(__builtin_cce_vconv_s82f16) void vconv_s82f16(...);
__cce_stub_attribute(__builtin_cce_vconv_u82f16) void vconv_u82f16(...);
__cce_stub_attribute(__builtin_cce_vconv_vdeqs162b8) void vconv_vdeqs162b8(...);
__cce_stub_attribute(__builtin_cce_vconv_vdeqs162b8h) void vconv_vdeqs162b8h(...);
__cce_stub_attribute(__builtin_cce_vconv_vdeqs162b8l) void vconv_vdeqs162b8l(...);
__cce_stub_attribute(__builtin_cce_vcopy) void vcopy(...);
__cce_stub_attribute(__builtin_cce_vcpadd) void vcpadd(...);
__cce_stub_attribute(__builtin_cce_vdiv) void vdiv(...);
__cce_stub_attribute(__builtin_cce_vdp) void vdp(...);
__cce_stub_attribute(__builtin_cce_vector_dup) void vector_dup(...);
__cce_stub_attribute(__builtin_cce_velu) void velu(...);
__cce_stub_attribute(__builtin_cce_vexp) void vexp(...);
__cce_stub_attribute(__builtin_cce_vextract) void vextract(...);
__cce_stub_attribute(__builtin_cce_vgather) void vgather(...);
__cce_stub_attribute(__builtin_cce_vgatherb) void vgatherb(...);
__cce_stub_attribute(__builtin_cce_vld_va_reg) void vld_va_reg(...);
__cce_stub_attribute(__builtin_cce_vln) void vln(...);
__cce_stub_attribute(__builtin_cce_vlrelu) void vlrelu(...);
__cce_stub_attribute(__builtin_cce_vmadd) void vmadd(...);
__cce_stub_attribute(__builtin_cce_vmaddrelu) void vmaddrelu(...);
__cce_stub_attribute(__builtin_cce_vmax) void vmax(...);
__cce_stub_attribute(__builtin_cce_vmaxs) void vmaxs(...);
__cce_stub_attribute(__builtin_cce_vmin) void vmin(...);
__cce_stub_attribute(__builtin_cce_vmins) void vmins(...);
__cce_stub_attribute(__builtin_cce_vmla) void vmla(...);
__cce_stub_attribute(__builtin_cce_vmrgsort4) void vmrgsort4(...);
__cce_stub_attribute(__builtin_cce_vmul) void vmul(...);
__cce_stub_attribute(__builtin_cce_vmulconv_f162s8) void vmulconv_f162s8(...);
__cce_stub_attribute(__builtin_cce_vmulconv_f162u8) void vmulconv_f162u8(...);
__cce_stub_attribute(__builtin_cce_vmuls) void vmuls(...);
__cce_stub_attribute(__builtin_cce_vnot) void vnot(...);
__cce_stub_attribute(__builtin_cce_vor) void vor(...);
__cce_stub_attribute(__builtin_cce_vpadding) void vpadding(...);
__cce_stub_attribute(__builtin_cce_vrec) void vrec(...);
__cce_stub_attribute(__builtin_cce_vreduce) void vreduce(...);
__cce_stub_attribute(__builtin_cce_vreducev2) void vreducev2(...);
__cce_stub_attribute(__builtin_cce_vrelu) void vrelu(...);
__cce_stub_attribute(__builtin_cce_vrsqrt) void vrsqrt(...);
__cce_stub_attribute(__builtin_cce_vscatter) void vscatter(...);
__cce_stub_attribute(__builtin_cce_vsel) void vsel(...);
__cce_stub_attribute(__builtin_cce_vshl) void vshl(...);
__cce_stub_attribute(__builtin_cce_vshr) void vshr(...);
__cce_stub_attribute(__builtin_cce_vsigmoid) void vsigmoid(...);
__cce_stub_attribute(__builtin_cce_vsort) void vsort(...);
__cce_stub_attribute(__builtin_cce_vsqrt) void vsqrt(...);
__cce_stub_attribute(__builtin_cce_vsub) void vsub(...);
__cce_stub_attribute(__builtin_cce_vsubrelu) void vsubrelu(...);
__cce_stub_attribute(__builtin_cce_vsubreluconv_f162s8) void vsubreluconv_f162s8(...);
__cce_stub_attribute(__builtin_cce_vsubreluconv_f322f16) void vsubreluconv_f322f16(...);
__cce_stub_attribute(__builtin_cce_vsubreluconv_s162s8) void vsubreluconv_s162s8(...);
__cce_stub_attribute(__builtin_cce_vsubreluconv_vdeqs162b8) void vsubreluconv_vdeqs162b8(...);
__cce_stub_attribute(__builtin_cce_vtanh) void vtanh(...);
__cce_stub_attribute(__builtin_cce_vtranspose) void vtranspose(...);
__cce_stub_attribute(__builtin_cce_wait_flag) void wait_flag(...);
__cce_stub_attribute(__builtin_cce_wait_flag_dev) void wait_flag_dev(...);
__cce_stub_attribute(__builtin_cce_wait_intra_block) void wait_intra_block(...);
__cce_stub_attribute(__builtin_cce_wait_spr) void wait_spr(...);
__cce_stub_attribute(__builtin_cce_winograd_conv) void winograd_conv(...);
__cce_stub_attribute(__builtin_cce_winograd_to_l1_s16s8) void winograd_to_l1_s16s8(...);
__cce_stub_attribute(__builtin_cce_winograd_to_l1_s8s8) void winograd_to_l1_s8s8(...);
} // namespace __cce_scalar

// --- Global scope intrinsics ---
// PIPE_S, ASM: DCCI 		dst, #entire
// __cce_stub_attribute(__builtin_cce_dcci) void dcci(__gm__ void *dst, uint64_t entire); // this func is conflict with simt's dcci
__cce_stub_attribute(__builtin_cce_dcci) void dcci(__gm__ void *dst, uint64_t entire, uint64_t type);
__cce_stub_attribute(__builtin_cce_dcci) void dcci(__ubuf__ void *dst, uint64_t entire, uint64_t type);
__cce_stub_attribute(__builtin_cce_dcci) void dcci(__ubuf__ void *dst, uint64_t entire);
__cce_stub_attribute(__builtin_cce_dcci) void dcci(...);

#endif // __CCE_INTRINSIC_STUBS_H__
