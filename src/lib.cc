#pragma once

#ifndef _CODING_MISAKA10987
#define _CODING_MISAKA10987

#include <cstdint>
#define isize ::std::intptr_t
#define usize ::std::uintptr_t
#define i8 ::std::int8_t
#define i16 ::std::int16_t
#define i32 ::std::int32_t
#define i64 ::std::int64_t
#define u8 ::std::uint8_t
#define u16 ::std::uint16_t
#define u32 ::std::uint32_t
#define u64 ::std::uint64_t

#ifdef __GNUC__
#define i128 __int128_t
#define u128 __uint128_t
#endif

#define str char const*
#include <string>
#include <iostream>
#include <optional>
#include <format>
#include <variant>
#include <vector>

#include "collections.cc"
#include "hash.cc"
#include "mem.cc"
#include "ops.cc"
#include "ptr.cc"

namespace coding {
    typedef ::std::string String;
#define loop for (;;)
#define unit unit
    /**
     * @brief The unit type.
     * @note Unfortunately due to some C++ features this will take up one byte.
     */
    struct unit {
        /**
         * @brief Construct a unit type.
         */
        constexpr unit() noexcept {}
        constexpr bool const operator== (unit const& rhs) noexcept { return true; }
        constexpr bool const operator!=(unit const& rhs) noexcept { return false; }
    };

    template <typename T> using Option = ::std::optional<T>;

    template <typename T, typename E> using Result = ::std::variant<T, E>;

    template <typename T> using Vec = ::std::vector<T>;


    template<typename T> auto println(T const& v) {
        ::std::cout << v << ::std::endl;
    }
}

#endif // #ifndef _CODING_MISAKA10987
