#pragma once

#include <bitset>

namespace coding::hash {

    /**
     * @brief Require a type to implement hashing.
     *
     * @tparam Self the type itself
     *
     */
    template<typename Self> concept Hash = requires(Self a) {
        { ::std::hash<Self>{}(a) } -> ::std::convertible_to<::std::size_t>;
    };
}
