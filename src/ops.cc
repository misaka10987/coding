#pragma once

#include <concepts>

#include "root.cc"

/// @brief Namespace for operator overloads.
/// 
namespace coding::ops {

    /// @brief Require a type to overload `==` and `!=` (equality operator).
    /// @note `PartialEq` does not provide any guarantee about whether the operators are properly implemented. 
    /// To further constrain the type, use `Eq`.
    /// @tparam Self the type itself
    /// 
    template<typename Self> concept PartialEq
        = requires(Self const& a, Self const& rhs) {
            { a == rhs } -> ::std::same_as<bool>;
            { a != rhs } -> ::std::same_as<bool>;
    };

    /// @brief a type to properly implement `==` and `!=` (equality operator).
    /// @tparam Self the type itself
    /// 
    /// # Equality
    /// 
    /// This means, that in addition to `a == b` and `a != b` being strict inverses, the relation must be (for all a, b and c):
    /// 
    /// - reflexive: `a == a`;
    /// 
    /// - symmetric: `a == b` implies `b == a`; and
    /// 
    /// - transitive: `a == b` and `b == c` implies `a == c`.
    /// 
    template<typename Self> concept Eq = PartialEq<Self> && ::std::equality_comparable<Self const&>;

    /// @brief Require a type to overload `<`, `<=`, `==`, `>=` and `>` (comparision operator).
    /// @note `PartialOrd` does not provide any guarantee about whether the operators are properly implemented.
    /// To further constrain the type, use `Ord`.
    /// @tparam Self the type itself
    /// 
    template<typename Self> concept PartialOrd
        = requires(Self const& a, Self const& rhs) {
            { a < rhs } -> ::std::same_as<bool>;
            { a <= rhs } -> ::std::same_as<bool>;
            { a == rhs } -> ::std::same_as<bool>;
            { a >= rhs } -> ::std::same_as<bool>;
            { a > rhs } -> ::std::same_as<bool>;
    };

    template<typename Self> concept Ord = PartialOrd<Self> && ::std::totally_ordered<Self const&>;

    /// @brief Require a type to overload `+` (addition operator).
    /// @tparam Self the type itself
    /// @tparam Other the right-hand side
    /// @tparam Output the result of operation
    /// 
    template<typename Self, typename Other = Self, typename Output = Self> concept Add
        = requires(Self a, Other rhs) {
            { a + rhs } -> ::std::same_as<Output>;
    };

    /// @brief Require a type to overload `-` (subtraction operator).
    /// @tparam Self the type itself
    /// @tparam Other the right-hand side
    /// @tparam Output the result of operation
    /// 
    template<typename Self, typename Other = Self, typename Output = Self> concept Sub
        = requires(Self a, Other rhs) {
            { a - rhs } -> ::std::same_as<Output>;
    };

    /// @brief Require a type to overload `*` (multiplication operator).
    /// @tparam Self the type itself
    /// @tparam Other the right-hand side
    /// @tparam Output the result of operation
    /// 
    template<typename Self, typename Other = Self, typename Output = Self> concept Mul
        = requires(Self a, Other rhs) {
            { a* rhs } -> ::std::same_as<Output>;
    };

    /// @brief Require a type to overload `/` (division operator).
    /// @tparam Self the type itself
    /// @tparam Other the right-hand side
    /// @tparam Output the result of operation
    /// 
    template<typename Self, typename Other = Self, typename Output = Self> concept Div
        = requires(Self a, Other rhs) {
            { a / rhs } -> ::std::same_as<Output>;
    };

}
