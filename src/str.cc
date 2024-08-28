#pragma once

#include <cstring>
#include <cstdlib>

#include "core.cc"

#define str str

/**
 * @brief Demo version, not optimized.
 *
 */
class str {

private:

    /**
     * @brief Points to a NULL-ending c-style string.
     *
     */
    char const* const data;

    /**
     * @brief Length of string.
     *
     */
    usize const len;

    inline constexpr str(char* data, usize len) noexcept :data(data), len(len) {}

public:

    ~str() {
        ::std::free((void*) this->data);
    }

    /**
     * @brief Construct from raw parts.
     * @warning The behaviour is undefined unless `data` is a `NULL`-ending string with length of `len` (length excludes the tailing `NULL`).
     *
     * @param data pointer to string
     * @param len length of string
     * @return new `str`
     */
    inline static auto from_raw(char* data, usize len) noexcept -> str {
        return str(data, len);
    }

    /**
     * @brief Construct from c-style string. This calculates the length and clones.
     *
     * @param c_str c-style NULL-ending string
     * @return new `str`
     */
    inline static auto from_c_str(char const* c_str) noexcept -> str {
        auto len = ::std::strlen(c_str);
        auto p = (char*)::std::malloc(len + 1);
        ::std::strcpy(p, c_str);
        return from_raw(p, len);
    }

    /**
     * @brief Get the inner c-style string.
     *
     * @return a c-style string, with the same lifespan as `this`
     */
    inline auto operator*() noexcept -> char const* {
        return this->data;
    }
};
