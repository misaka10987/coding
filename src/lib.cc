#pragma once

#include "root.cc"
#include "core.cc"

#include "collections.cc"
#include "hash.cc"
#include "log.cc"
#include "ops.cc"
#include "option.cc"
#include "ptr.cc"
#include "result.cc"
#include "str.cc"

#include <iostream>
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

    template <typename T> using Vec = ::std::vector<T>;

    template<typename T> auto println(T const& v) {
        ::std::cout << v << ::std::endl;
    }
}
