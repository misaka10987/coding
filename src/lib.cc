#pragma once

#include "core.cc"
#include "collections.cc"
#include "hash.cc"
#include "mem.cc"
#include "ops.cc"
#include "ptr.cc"
#include "str.cc"

#include <string>
#include <iostream>
#include <optional>
#include <format>
#include <variant>
#include <vector>

template<typename T>
inline constexpr auto operator*(T const& x) noexcept -> T const& {
    return x;
}

template<typename T>
inline constexpr auto operator*(T& x) noexcept -> T& {
    return x;
}

namespace coding {

    typedef ::std::string String;
#define loop for (;;)
#define unit unit
#include <concepts>

    /**
     * @brief The unit type.
     * @note Unfortunately due to some C++ features this will take up one byte.
     */
    struct unit {
        /**
         * @brief Construct a unit type.
         */
        inline constexpr unit() noexcept {}
        /**
         * @brief Every `unit` is equal.
         *
         * @param rhs the right-hand side
         * @return always be `true`
         */
        inline constexpr auto operator==(unit const& rhs) const    noexcept -> bool const { return true; }
    };

    template <typename T> using Option = ::std::optional<T>;

    template <typename T, typename E> using Result = ::std::variant<T, E>;

    template <typename T> using Vec = ::std::vector<T>;

    template<typename T> auto println(T const& v) {
        ::std::cout << v << ::std::endl;
    }
}
