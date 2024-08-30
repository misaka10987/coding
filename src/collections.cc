#pragma once

#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "ops.cc"
#include "hash.cc"

namespace coding::collections {
    using ops::Eq, ops::Ord;
    using hash::Hash;

    template <typename T> using VecDeque = std::queue<T>;

    template <typename T> using LinkedList = std::list<T>;

    template <typename K, typename V>
        requires(Eq<K> and Hash<K>)
    using HashMap = std::unordered_map<K, V>;

    template <typename T>
        requires(Eq<T> and Hash<T>)
    using HashSet = std::unordered_set<T>;

    template <typename K, typename V>
        requires (Eq<K> and Ord<K>)
    using TreeMap = std::map<K, V>;

    template <typename T>
        requires (Eq<T> and Ord<T>)
    using TreeSet = std::set<T>;
} // namespace collections
