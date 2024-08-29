#pragma once

#include <cstdint>
#include <utility>
#include <functional>

#define unit unit

/// @brief The unit type.
/// @note Unfortunately due to some C++ features this will take up one byte.
/// 
struct unit {

    /// @brief Construct a unit type.
    /// 
    inline constexpr unit() noexcept {}

    /// @brief Every `unit` is equal.
    /// @param rhs the right-hand side
    /// @return always be `true`
    /// 
    inline constexpr auto operator==(unit const& rhs) const noexcept -> bool { return true; }
};

typedef ::std::intptr_t isize;
typedef ::std::uintptr_t usize;
typedef ::std::int8_t i8;
typedef ::std::int16_t i16;
typedef ::std::int32_t i32;
typedef ::std::int64_t i64;
typedef ::std::uint8_t u8;
typedef ::std::uint16_t u16;
typedef ::std::uint32_t u32;
typedef ::std::uint64_t u64;

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wliteral-suffix"
#endif

inline constexpr auto operator"" usize(unsigned long long x) noexcept -> usize { return (usize) x; };
inline constexpr auto operator"" isize(unsigned long long x) noexcept -> isize { return (isize) x; };
inline constexpr auto operator"" i8(unsigned long long x) noexcept -> i8 { return (i8) x; };
inline constexpr auto operator"" i16(unsigned long long x) noexcept -> i16 { return (i16) x; };
inline constexpr auto operator"" i32(unsigned long long x) noexcept -> i32 { return (i32) x; };
inline constexpr auto operator"" i64(unsigned long long x) noexcept -> i64 { return (i64) x; };
inline constexpr auto operator"" u8(unsigned long long x) noexcept -> u8 { return (u8) x; };
inline constexpr auto operator"" u16(unsigned long long x) noexcept -> u16 { return (u16) x; };
inline constexpr auto operator"" u32(unsigned long long x) noexcept -> u32 { return (u32) x; };
inline constexpr auto operator"" u64(unsigned long long x) noexcept -> u64 { return (u64) x; };

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

#define usize usize
#define isize isize
#define i8 i8
#define i16 i16
#define i32 i32
#define i64 i64
#define u8 u8
#define u16 u16
#define u32 u32
#define u64 u64


#ifdef __GNUC__
typedef __int128_t i128;
typedef __uint128_t u128;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wliteral-suffix"
inline constexpr auto operator"" i128(unsigned long long x) noexcept -> i128 { return (i128) x; };
inline constexpr auto operator"" u128(unsigned long long x) noexcept -> u128 { return (u128) x; };
#pragma GCC diagnostic pop

#define i128 i128
#define u128 u128
#endif

/// @brief Move the ownership of a certain variable.
/// 
#define mv mv

/// @brief The same as `std::move` in `<utility>`. This is here to avoid naming conflict with `std::move` in `<algorithm>`.
/// @warning Use of value after move is undefined.
/// @tparam T
/// @param src value
/// @return rvalue reference
/// 
template<typename T> inline constexpr auto mv(T&& src) noexcept -> typename ::std::remove_reference<T>::type&& {
    return static_cast<typename ::std::remove_reference<T>::type&&>(src);
}

/// @brief Infinite loop.
/// 
#define loop for (;;)

#define Fn(signature) ::std::function<signature>
