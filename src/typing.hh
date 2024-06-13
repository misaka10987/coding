#pragma once
#ifndef _TYPING_MISAKA10987
#define _TYPING_MISAKA10987

#define fn inline auto
#define let const auto

#define loop for(;;)

struct unit_t {
    constexpr bool const operator==(unit_t const& rhs) { return true; }
};
constexpr unit_t const unit;

#define str char[]

#include<cstdint>
typedef std::intptr_t isize;
typedef std::uintptr_t usize;
typedef std::int8_t i8;
typedef std::int16_t i16;
typedef std::int32_t i32;
typedef std::int64_t i64;
typedef std::uint8_t u8;
typedef std::uint16_t u16;
typedef std::uint32_t u32;
typedef std::uint64_t u64;

#ifdef __GNUC__
typedef __int128_t i128;
typedef __uint128_t u128;
#endif

#include<string>
typedef std::string String;

#include<optional>
template<typename T> using Option = std::optional<T>;

#include<variant>
template<typename T, typename E> using Result = std::variant<T, E>;

#include<memory>
template<typename T> using Box = std::unique_ptr<T>;
template<typename T> using Rc = std::shared_ptr<T>;

#include<vector>
template<typename T> using Vec = std::vector<T>;

#include<list>
#include<queue>
#include<unordered_map>
#include<unordered_set>

inline namespace collections
{
    template<typename T> using VecDeque = std::queue<T>;
    template<typename T> using LinkedList = std::list<T>;
    template<typename K, typename V> using HashMap = std::unordered_map<K, V>;
    template<typename K> using HashSet = std::unordered_set<K>;
}

#endif //#ifndef _TYPING_MISAKA10987
