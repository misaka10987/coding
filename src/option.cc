#pragma once

#include "root.cc"
#include "core.cc"
#include "thread.cc"

#include <variant>

namespace coding::option {

    /// @brief Tag for the `Option` to `switch` on.
    /// 
    enum Tag {

        /// @brief Indicates an `Option`al value exists.
        ///
        Some,

        /// @brief Indicates an `Option` value does not exist.
        ///
        None,
    };
}

namespace coding {

    using option::Tag::Some;
    using option::Tag::None;

    /// @brief An optional type. Acts like Rust's `Option`.
    /// @tparam T the type when `Some`.
    ///
    template<typename T>
    class Option final {

    private:

        struct _None {};

        option::Tag tag : 1;

        std::variant < T, _None> value;

    public:

        /// @brief Construct a `None` value.
        ///
        inline constexpr Option() noexcept : tag(None), value(_None()) {}

        /// @brief Construct a `Some` value.
        /// @param value the value with
        ///
        inline constexpr Option(T const& value) noexcept : tag(Some), value(value) {}

        /// @brief Construct a `Some` value.
        /// @param value the value with
        ///
        inline constexpr Option(T const&& value) noexcept : tag(Some), value(value) {}

        /// @brief Implicitly cast to `Tag`.
        /// This allows `switch`ing directly on the `Option`.
        /// 
        inline constexpr operator option::Tag() const noexcept {
            return this->tag;
        }

        inline constexpr auto is_some() const noexcept -> bool {
            return this->tag == Some;
        }

        inline constexpr auto is_none() const noexcept -> bool {
            return this->tag == None;
        }

        /// @brief Unwrap the `Option` to a `Some` value, taking ownership.
        /// @return the value
        ///
        /// # Panic
        ///
        /// Panics if the value is `None`.
        ///
        inline auto unwrap() const&& noexcept -> T {
            if (this->is_none()) panic("unwrap on `None` value");
            return std::get<T>(this->value);
        }

        /// @brief Unwrap the `Option` to a `Some` value.
        /// @return the value
        ///
        /// # Panic
        ///
        /// Panics if the value is `None`.
        ///
        inline auto unwrap() const& noexcept -> T const& {
            if (this->is_none()) panic("unwrap on `None` value");
            return std::get<T>(this->value);
        }

        /// @brief Unwrap the `Option` to a `Some` value.
        /// @return the value
        ///
        /// # Panic
        ///
        /// Panics if the value is `None`.
        ///
        inline auto unwrap() & noexcept -> T& {
            if (this->is_none()) panic("unwrap on `None` value");
            return std::get<T>(this->value);
        }

        /// @brief Maps the `Some` value if it is, otherwise return a `None`.
        /// @tparam U the type mapped to
        /// @tparam F the type of which the function has
        /// @param mapping the mapping function to call
        /// @return the mapped new `Option`
        /// 
        template<typename U, Fn<U, T const&> F>
        inline constexpr auto map(F mapping) const& noexcept -> Option<U> {
            if (this->is_none()) return Option();
            auto some = mapping(std::get<T>(this->value));
            return Option(some);
        }
    };
}
