#pragma once

#include "root.cc"
#include "core.cc"
#include "thread.cc"

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
    class Option final{

    private:

        union Inner {
            T Some;
            unit None;
            ~Inner() {}
        };

        option::Tag tag : 1;

        Inner value;

    public:

        ~Option() {
            if (this->is_some()) this->value.Some.~T();
        }

        /// @brief Construct a `None` value.
        ///
        inline constexpr Option() noexcept : tag(None) {}

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
            return this->value.Some;
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
            return this->value.Some;
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
            return this->value.Some;
        }

        // TODO
        // template<typename U>
        // inline auto map(U* mapping(T const&)) -> Option<U> {
        //     if(this->is_none()) return Option();
        //     auto res = mapping(this->unwrap());
        //     return Option(mv(res));
        // }
    };
}
