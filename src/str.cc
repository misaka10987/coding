#pragma once

#include "core.cc"
#include "thread.cc"

#include <cstring>
#include <cstdlib>

#include<thread>

#define str str

/// @brief Demo version, not optimized.
/// 
class str final {

public:

    /// @brief Points to a c-style string.
    /// 
    char const* const head;

    /// @brief Length of string.
    /// 
    usize const len;

    /// @brief Construct from raw parts.
    /// @warning The behaviour is undefined unless `head` is a `NULL`-ending string with length of `len` (length excludes the tailing `NULL`).
    /// @param head pointer to string
    /// @param len length of string
    /// @return new `str`
    /// 
    inline constexpr str(char const* head, usize len) noexcept :head(head), len(len) {}


    /// @brief Construct from c-style string. This calculates the length and clones.
    /// @param c_str c-style NULL-ending string
    /// @return new `str`
    /// 
    inline str(char const* c_str) noexcept : head(c_str), len(::std::strlen(c_str)) {}

    inline constexpr str(::std::string_view str_view) noexcept : head(str_view.begin()), len(str_view.length()) {}

    /// @brief Get the tail position of the string, i.e. this always points to the ending `NULL`.
    /// @return the pointer to tail
    /// 
    inline constexpr auto tail() const noexcept -> char const* {
        return this->head + this->len;
    }

    /// @brief Borrow a `std::string_view` from the current instance.
    /// @return `std::string_view`, of the same lifespan
    /// 
    inline constexpr auto operator&() const noexcept -> ::std::string_view {
        return ::std::string_view(this->head, this->len);
    }

    /// @brief Index the string.
    /// @param idx the index
    /// @return the `idx`th char
    /// 
    /// # Panic
    /// 
    /// Panic if the index is out of bound.
    inline auto operator[](usize idx) const noexcept -> char {
        if (idx > this->len) coding::panic("index out of bound");
        return this->index_unchecked(idx);
    }

    /// @brief Same as `.operator[]` but does not perform boundary check.
    /// @param idx the index
    /// @return the `idx`th char
    /// 
    inline constexpr auto index_unchecked(usize idx) const noexcept -> char {
        return this->head[idx];
    }

    /// @brief A `char`-by-`char` iterator over a `str`.
    /// 
    class CharIterator final {

    private:

        /// @brief The `str` the iterator towards.
        /// 
        char const* const head;

        /// @brief Current position.
        /// 
        usize pos;

    public:

        /// @brief Construct an iterator on `head` currently at `head[pos]`.
        /// @param head the string
        /// @param pos the index
        /// 
        inline constexpr CharIterator(char const* head, usize pos) noexcept : head(head), pos(pos) {}

        inline auto operator++() noexcept { this->pos++; }

        inline auto operator--() noexcept { this->pos--; }

        inline constexpr auto operator*() const noexcept -> char {
            return *(this->head + this->pos);
        }

        inline constexpr auto operator==(CharIterator const& rhs) const noexcept -> bool {
            return this->head == rhs.head && this->pos == rhs.pos;
        }

    };

    inline constexpr auto begin() const noexcept -> CharIterator {
        return CharIterator(this->head, 0);
    }

    inline constexpr auto end() const noexcept -> CharIterator {
        return CharIterator(this->head, this->len);
    }

    /// @brief `.split()`ted result. Iterating over this to get every segment.
    /// 
    class Split final {

    private:

        /// @brief The head of (sub)string to split on.
        /// 
        ::std::string_view s;

        /// @brief The pattern to split with.
        /// 
        ::std::string_view pat;

    public:

        /// @brief Construct the split helper from `str`.
        /// @param s the string to split on
        /// @param pat the pattern to split with
        /// 
        inline constexpr Split(str s, str pat) noexcept : s(&s), pat(&pat) {}

        class Iterator final {

        private:

            /// @brief The string to split on.
            /// 
            ::std::string_view s;

            /// @brief The pattern to split with.
            /// 
            ::std::string_view pat;

            usize next = 0;
        public:

            inline constexpr Iterator(::std::string_view s, ::std::string_view pat) noexcept : s(s), pat(pat) {}

            inline constexpr auto operator++() noexcept {
                this->s = this->s.substr(this->next);
            }

            inline auto operator--() noexcept {
                coding::panic("unimplemented");
            }

            inline auto operator*() noexcept -> str {
                auto p = this->s.find(this->pat);
                if (p == ::std::string_view::npos) {
                    this->next = this->s.length();
                    return str(this->s);
                }
                this->next = p + this->pat.length();
                return str(this->s.substr(0, p));
            }

            /// @brief This is actually implemented to indicate the terminal status of the iterator.
            /// @warning This is NOT a comparison operator.
            /// @return whether the iteration has finished
            /// 
            inline constexpr auto operator==(Iterator const& _) const noexcept -> bool {
                return this->s.length() == 0;
            }
        };


        /// @brief Begin iteration.
        /// @warning Manual call is undefined. Always call with `for(auto it:split)`.
        /// @return the iterator
        /// 
        inline constexpr auto begin() const noexcept -> Iterator {
            return Iterator(this->s, this->pat);
        }

        /// @brief End iteration.
        /// @warning Manual call is undefined. Always call with `for(auto it:split)`.
        /// @return the iterator
        /// 
        inline constexpr auto end() const noexcept -> Iterator {
            return Iterator(this->s, this->pat);
        }
    };

    /// @brief Split the string on specified pattern.
    /// @param pat the pattern
    /// @return iterable
    /// 
    inline constexpr auto split(str pat) const noexcept -> Split {
        return Split(*this, pat);
    }
};

/// @brief An owned string type.
/// 
class String final {

private:

    /// @brief Head of the string, i.e. points to the first byte like a c-styled string.
    /// 
    char* head;

    /// @brief Length of the string excluding the tailing `NULL`.
    /// 
    usize length;

    /// @brief Current capacity of the string container in bytes.
    /// 
    usize cap;

    /// @brief Get the tail position of the string, i.e. this always points to the ending `NULL`.
    /// @return the pointer to tail
    /// 
    inline constexpr auto tail() noexcept -> char* {
        return this->head + this->len();
    }

    /// @brief Reallocate the string with specified capacity, preserving content.
    /// @param new_cap new capacity
    /// @return 
    /// 
    inline auto realloc(usize new_cap) noexcept {
        this->cap = new_cap == 0 ? 1 : new_cap;
        auto p = ::std::realloc((void*) this->head, this->cap);
        this->head = (char*) p;
    }

public:

    ~String() {
        if (this->head) std::cerr << "free" << std::endl;
        else std::cerr << "free nullptr" << std::endl;
        ::std::free((void*) this->head);
    }

    /// @brief Length of the string excluding the tailing `NULL`.
    /// @return the length
    /// 
    inline constexpr auto len() const noexcept -> usize {
        return this->length;
    }

    /// @brief Construct from a c-style string. This automatically calculates `c_str`'s length and clones it.
    /// @param c_str a c-style string
    /// 
    inline String(char const* c_str) noexcept {
        this->length = ::std::strlen(c_str);
        this->cap = this->len() + 1;
        this->head = (char*) ::std::malloc(this->cap);
        ::std::memcpy(this->head, c_str, this->length);
    }

    /// @brief Move constructor.
    /// @param s a moved `String`
    /// 
    inline String(String const&& s) noexcept {
        this->head = s.head;
        this->length = s.length;
        this->cap = s.cap;

        // To avoid double free. I am not sure if this is a best practice.
        // Theoratically, this is safe, since `s` is moved and never accessed again.
        auto x = (char**) (usize) &s.head;
        *x = nullptr;
    }

    inline constexpr auto operator*() const noexcept -> str {
        return str(this->head, this->len());
    }

    inline constexpr operator str() const noexcept {
        return str(this->head, this->len());
    }

    /// @brief Reference by a raw c-style string.
    /// @return the pointer to head of string
    /// 
    inline constexpr auto operator&() const noexcept -> char const* {
        return this->head;
    }

    /// @brief Reduce current allocated size to the minimum possible.
    /// @return self
    /// 
    inline auto minimize() noexcept -> String& {
        if (this->cap > this->len() * 2 + 1) this->realloc(this->len() + 1);
        return *this;
    }

    /// @brief Clear the current content, making the instance an empty string.
    /// @return self
    /// 
    inline auto clear() noexcept -> String& {
        this->realloc(1);
        return *this;
    }

    /// @brief Prepare `buf_size` bytes allocated space for appending.
    /// @param buf_size the number of bytes
    /// @return self
    /// 
    inline auto buf(usize buf_size) noexcept -> String& {
        auto a = this->len() + buf_size + 1;
        if (this->cap <= a) this->realloc(a);
        return *this;
    }

    /// @brief Append a `str` to the tail of the current string.
    /// @param s the content to append
    /// @return self
    /// 
    inline auto append(str s) noexcept -> String& {
        this->buf(s.len);
        ::std::memcpy(this->tail(), s.head, s.len);
        this->length += s.len;
        return *this;
    }

};
