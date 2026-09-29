// SPDX-License-Identifier: MIT
// Copyright (c) 2026 DeepSeek
//
// clangd shim header for Ascend CCE (include/cce_stubs/cce_stubs.h).
// Provides builtin type stubs, includes the bisheng runtime wrapper,
// and makes Ascend CCE headers parseable by our custom clangd.

#ifndef __CCE_STUBS_H__
#define __CCE_STUBS_H__

// CCE target configuration
#define __CCE__ 1
#define __BISHENG_CCEC__ 1
#define __CCE_AICORE__ 310
#define __CCE_ARCH__ 100
#define __NPU_ARCH__   3510
#define __CCE_VF_VEC_LEN__ 256
#define __CCE_IS_AICORE__ 1
#define __CCE_AICORE_ENABLE_MIX__ 1
#define __CCE_AICORE_SUPPORT_SIMT__ 1
#define __DAV_C310__ 1
#define __DAV_C310_CUBE__ 1
#define __DAV_C310_VEC__ 1
#define __DAV_CUBE__ 1
#define __DAV_VEC__ 1
#define __VEC_SCOPE__ if ASCEND_IS_AIC

// RT_CONFIGURE_CALL is normally provided by the build system to declare the
// runtime kernel launch function. We stub it and __CCE_RT_CONFIGURE_FUNC_NAME__.
#define RT_CONFIGURE_CALL
static inline unsigned int __CCE_RT_CONFIGURE_FUNC_NAME__(unsigned int, void*, void*) { return 0; }



// CCE builtin types (__hif8, __fp8e4m3, etc.) are now implemented as
// genuine clang built-in types in our custom clangd build.

// Pre-empt __clang_cce_defines.h — provide our own definitions that map
// CCE address space qualifiers to clang's __attribute__((address_space(N)))
// so that differently-qualified types are treated as distinct types.
#define __CCE_DEFINES_H__

#define __no_return__ __attribute__((noreturn))
#define __sync_noalias__
#define __sync_alias__
#define __check_sync_alias__
#define __sync_in__
#define __sync_out__
#define __in_pipe__(...)
#define __out_pipe__(...)
#define __inout_pipe__(...)
#define __forceinline__ __inline__ __attribute__((always_inline))
#define __align__(n) __attribute__((aligned(n)))

#define __global__
#define __simt_callee__
#define __simt_vf__ __attribute__((noinline))
#define __aicpu__
#define __disable_kernel_type_autoinfer__
#define LAUNCH_BOUND(N)
#define __launch_bounds__(N)
#define __schedmode__(N)
#define __maxnreg__(N)

#define __simd_vf__
#define __simd_callee__
#define __no_simd_vf_fusion__
#define __callee__

#define __cube__
#define __vector__
#define __mix__(cube, vec)

// Address space qualifiers — use distinct address_space IDs to make types differ
#ifdef __CCE_STUB_DISABLE_ADDRESS_SPACE_QUALIFIERS__

#define __gm__
#define __ca__
#define __cb__
#define __cc__
#define __ubuf__
#define __cbuf__
#define __fbuf__
#define __biasbuf__
#define __private__
#define __ssbuf__

#else

#define __gm__    __attribute__((address_space(1)))
#define __ca__    __attribute__((address_space(2)))
#define __cb__    __attribute__((address_space(3)))
#define __cc__    __attribute__((address_space(4)))
#define __ubuf__  __attribute__((address_space(5)))
#define __cbuf__  __attribute__((address_space(6)))
#define __fbuf__  __attribute__((address_space(7)))
#define __biasbuf__ __attribute__((address_space(8)))
#define __private__
#define __ssbuf__ __attribute__((address_space(9)))

#endif

#define __copyval__
#define __no_specialization__
#define __device_immutable__
#define __device_builtin__
#define __early_read_before_pre_task_done__
#define __kfc_workspace__
#define __sk__
#define __aicore__
#define __host__

// Provide integer types before the CANN runtime headers are parsed.
#include "stdint_stubs.h"
#include <stddef.h>

// ---------- CCE compiler builtin stubs ----------
// bisheng has ~3000 __builtin_cce_* intrinsics that are built into the compiler.
// Our clangd doesn't know them, so we stub them all as variadic no-op macros.
#include "cce_builtin_stubs.h"
#include "cce_intrinsic_stubs.h"
#include "cce_simt_stubs.h"

// SDK headers are supplied by the user's local CANN installation.
#include "__clang_cce_runtime_wrapper.h"

using dim3 = cce::dim3;

// The bisheng compiler makes __cce_scalar intrinsics available at global scope.
// Since our clangd parses them as regular C++ declarations, we need this.
using namespace __cce_scalar;

// The bisheng compiler also makes __asc_aicore namespace functions (printf_impl,
// __assert_fail_msg, etc.) available at global scope for use by assert macros.
// Forward-declare the namespace so that the using-directive is valid even though
// the actual definitions are added later by the SDK include chain.
namespace __asc_aicore {}
using namespace __asc_aicore;

#endif // __CCE_STUBS_H__
