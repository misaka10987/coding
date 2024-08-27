#pragma once

#include <bitset>

namespace coding::hash {
    template<typename Self> concept Hash = requires(Self a) {
        { ::std::hash<Self>{}(a) } -> ::std::convertible_to<::std::size_t>;
    };
}
