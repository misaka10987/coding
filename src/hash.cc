#pragma once

#include "root.cc"

#include <bitset>

/// @brief Namespace for hashing.
/// 
namespace coding::hash {

    /// @brief Require a type to implement hashing.
    /// @tparam Self the type itself
    /// 
    template<typename Self> concept Hash = requires(Self a) {
        { ::std::hash<Self>{}(a) } -> ::std::convertible_to<::std::size_t>;
    };
}
