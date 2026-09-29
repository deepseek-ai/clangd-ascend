// SPDX-License-Identifier: MIT
// Minimal stdint definitions for the Clang-based CCE editor shim.
// Types and limits come from the target compiler; no libc headers are needed.
#ifndef CLANGD_ASCEND_STDINT_STUBS_H
#define CLANGD_ASCEND_STDINT_STUBS_H

// Keep later CANN/Clang and system stdint headers from redefining these types.
#ifndef __CLANG_STDINT_H
#define __CLANG_STDINT_H
#endif
#ifndef _STDINT_H
#define _STDINT_H

typedef __INT8_TYPE__ int8_t;
typedef __UINT8_TYPE__ uint8_t;
typedef __INT16_TYPE__ int16_t;
typedef __UINT16_TYPE__ uint16_t;
typedef __INT32_TYPE__ int32_t;
typedef __UINT32_TYPE__ uint32_t;
typedef __INT64_TYPE__ int64_t;
typedef __UINT64_TYPE__ uint64_t;
typedef __INT_LEAST8_TYPE__ int_least8_t;
typedef __UINT_LEAST8_TYPE__ uint_least8_t;
typedef __INT_LEAST16_TYPE__ int_least16_t;
typedef __UINT_LEAST16_TYPE__ uint_least16_t;
typedef __INT_LEAST32_TYPE__ int_least32_t;
typedef __UINT_LEAST32_TYPE__ uint_least32_t;
typedef __INT_LEAST64_TYPE__ int_least64_t;
typedef __UINT_LEAST64_TYPE__ uint_least64_t;
typedef __INT_FAST8_TYPE__ int_fast8_t;
typedef __UINT_FAST8_TYPE__ uint_fast8_t;
typedef __INT_FAST16_TYPE__ int_fast16_t;
typedef __UINT_FAST16_TYPE__ uint_fast16_t;
typedef __INT_FAST32_TYPE__ int_fast32_t;
typedef __UINT_FAST32_TYPE__ uint_fast32_t;
typedef __INT_FAST64_TYPE__ int_fast64_t;
typedef __UINT_FAST64_TYPE__ uint_fast64_t;
typedef __INTPTR_TYPE__ intptr_t;
typedef __UINTPTR_TYPE__ uintptr_t;
typedef __INTMAX_TYPE__ intmax_t;
typedef __UINTMAX_TYPE__ uintmax_t;

#define INT8_MAX __INT8_MAX__
#define INT8_MIN (-INT8_MAX - 1)
#define UINT8_MAX __UINT8_MAX__
#define INT16_MAX __INT16_MAX__
#define INT16_MIN (-INT16_MAX - 1)
#define UINT16_MAX __UINT16_MAX__
#define INT32_MAX __INT32_MAX__
#define INT32_MIN (-INT32_MAX - 1)
#define UINT32_MAX __UINT32_MAX__
#define INT64_MAX __INT64_MAX__
#define INT64_MIN (-INT64_MAX - 1)
#define UINT64_MAX __UINT64_MAX__

#define INT_LEAST8_MAX __INT_LEAST8_MAX__
#define INT_LEAST8_MIN (-INT_LEAST8_MAX - 1)
#define UINT_LEAST8_MAX __UINT_LEAST8_MAX__
#define INT_LEAST16_MAX __INT_LEAST16_MAX__
#define INT_LEAST16_MIN (-INT_LEAST16_MAX - 1)
#define UINT_LEAST16_MAX __UINT_LEAST16_MAX__
#define INT_LEAST32_MAX __INT_LEAST32_MAX__
#define INT_LEAST32_MIN (-INT_LEAST32_MAX - 1)
#define UINT_LEAST32_MAX __UINT_LEAST32_MAX__
#define INT_LEAST64_MAX __INT_LEAST64_MAX__
#define INT_LEAST64_MIN (-INT_LEAST64_MAX - 1)
#define UINT_LEAST64_MAX __UINT_LEAST64_MAX__

#define INT_FAST8_MAX __INT_FAST8_MAX__
#define INT_FAST8_MIN (-INT_FAST8_MAX - 1)
#define UINT_FAST8_MAX __UINT_FAST8_MAX__
#define INT_FAST16_MAX __INT_FAST16_MAX__
#define INT_FAST16_MIN (-INT_FAST16_MAX - 1)
#define UINT_FAST16_MAX __UINT_FAST16_MAX__
#define INT_FAST32_MAX __INT_FAST32_MAX__
#define INT_FAST32_MIN (-INT_FAST32_MAX - 1)
#define UINT_FAST32_MAX __UINT_FAST32_MAX__
#define INT_FAST64_MAX __INT_FAST64_MAX__
#define INT_FAST64_MIN (-INT_FAST64_MAX - 1)
#define UINT_FAST64_MAX __UINT_FAST64_MAX__

#define INTPTR_MAX __INTPTR_MAX__
#define INTPTR_MIN (-INTPTR_MAX - 1)
#define UINTPTR_MAX __UINTPTR_MAX__
#define INTMAX_MAX __INTMAX_MAX__
#define INTMAX_MIN (-INTMAX_MAX - 1)
#define UINTMAX_MAX __UINTMAX_MAX__

#define SIZE_MAX __SIZE_MAX__
#define PTRDIFF_MAX __PTRDIFF_MAX__
#define PTRDIFF_MIN (-PTRDIFF_MAX - 1)
#define SIG_ATOMIC_MAX __SIG_ATOMIC_MAX__
#define SIG_ATOMIC_MIN (-SIG_ATOMIC_MAX - 1)

#ifndef WCHAR_MAX
#define WCHAR_MAX __WCHAR_MAX__
#endif
#ifndef WCHAR_MIN
#ifdef __WCHAR_UNSIGNED__
#define WCHAR_MIN 0U
#else
#define WCHAR_MIN (-WCHAR_MAX - 1)
#endif
#endif

#ifndef WINT_MAX
#define WINT_MAX __WINT_MAX__
#endif
#ifndef WINT_MIN
#ifdef __WINT_UNSIGNED__
#define WINT_MIN 0U
#else
#define WINT_MIN (-WINT_MAX - 1)
#endif
#endif

// Expand the compiler-provided suffix before token concatenation.
#define CCE_STDINT_JOIN_IMPL(value, suffix) value##suffix
#define CCE_STDINT_JOIN(value, suffix) CCE_STDINT_JOIN_IMPL(value, suffix)
#define INT8_C(value) CCE_STDINT_JOIN(value, __INT8_C_SUFFIX__)
#define UINT8_C(value) CCE_STDINT_JOIN(value, __UINT8_C_SUFFIX__)
#define INT16_C(value) CCE_STDINT_JOIN(value, __INT16_C_SUFFIX__)
#define UINT16_C(value) CCE_STDINT_JOIN(value, __UINT16_C_SUFFIX__)
#define INT32_C(value) CCE_STDINT_JOIN(value, __INT32_C_SUFFIX__)
#define UINT32_C(value) CCE_STDINT_JOIN(value, __UINT32_C_SUFFIX__)
#define INT64_C(value) CCE_STDINT_JOIN(value, __INT64_C_SUFFIX__)
#define UINT64_C(value) CCE_STDINT_JOIN(value, __UINT64_C_SUFFIX__)
#define INTMAX_C(value) CCE_STDINT_JOIN(value, __INTMAX_C_SUFFIX__)
#define UINTMAX_C(value) CCE_STDINT_JOIN(value, __UINTMAX_C_SUFFIX__)

#endif // _STDINT_H
#endif // CLANGD_ASCEND_STDINT_STUBS_H
