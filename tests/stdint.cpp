// SPDX-License-Identifier: MIT
#include "../include/cce_stubs/stdint_stubs.h"
#include <cstdint>
#include <limits>
#include <type_traits>

static_assert(sizeof(std::int8_t) == 1);
static_assert(sizeof(std::uint16_t) == 2);
static_assert(sizeof(std::int32_t) == 4);
static_assert(sizeof(std::uint64_t) == 8);
static_assert(sizeof(std::uintptr_t) == sizeof(void*));
static_assert(std::is_signed_v<std::intmax_t>);
static_assert(std::is_unsigned_v<std::uintmax_t>);

#define CHECK_LIMITS(name, type) \
    static_assert(name##_MIN == std::numeric_limits<type>::min()); \
    static_assert(name##_MAX == std::numeric_limits<type>::max())
CHECK_LIMITS(INT8, std::int8_t);
CHECK_LIMITS(INT16, std::int16_t);
CHECK_LIMITS(INT32, std::int32_t);
CHECK_LIMITS(INT64, std::int64_t);
CHECK_LIMITS(INT_LEAST16, std::int_least16_t);
CHECK_LIMITS(INT_FAST16, std::int_fast16_t);
CHECK_LIMITS(INTPTR, std::intptr_t);
CHECK_LIMITS(INTMAX, std::intmax_t);
#undef CHECK_LIMITS

static_assert(UINT64_MAX == std::numeric_limits<std::uint64_t>::max());
static_assert(SIZE_MAX == std::numeric_limits<std::size_t>::max());
static_assert(INT64_C(9223372036854775807) == INT64_MAX);
static_assert(UINT64_C(18446744073709551615) == UINT64_MAX);
static_assert(std::is_same_v<decltype(INTMAX_C(1)), std::intmax_t>);
static_assert(std::is_same_v<decltype(UINTMAX_C(1)), std::uintmax_t>);

#if INT32_MIN != (-2147483647 - 1) || UINT32_C(4294967295) != UINT32_MAX
#error Integer limits and constants must also work in preprocessor expressions
#endif
