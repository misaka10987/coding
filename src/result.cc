#pragma once

#include "root.cc"
#include "core.cc"
#include "thread.cc"

#include<cstdlib>
#include<iostream>


namespace coding::result {

    /// @brief Tag for the `Result` to `switch` on.
    /// 
    enum Tag {

        /// @brief Indicates a `Result` is `Ok`.
        /// 
        Ok,

        /// @brief Indicates a `Result` is not `Ok`.
        /// 
        Err,
    };
}

namespace coding {

    using result::Tag::Ok;
    using result::Tag::Err;

    /// @brief A type for wrapping potential errors. Acts like Rust's `Result`.
    /// @tparam T the normal type
    /// @tparam E the error type
    /// 
    template<typename T, typename E>
    class Result final{
    private:

        union Inner {
            T Ok;
            E Err;
            ~Inner() {}
        };

        result::Tag tag : 1;

        Inner value;

    public:

        inline constexpr Result(result::Tag tag, Inner value) noexcept : tag(tag), value(value) {}

        ~Result() {
            switch (*this) {
            case Ok: {
                this->value.Ok.~T();
                break;
            }
            case Err: {
                this->value.Err.~E();
                break;
            }
            }
        }

        /// @brief Construct an `Ok` value
        /// @param value the value with
        /// @return new `Result`
        /// 
        static inline constexpr auto ok(T const& value) noexcept -> Result {
            return Result(Ok, { .Ok = value });
        }

        /// @brief Construct an `Ok` value
        /// @param value the value with
        /// @return new `Result`
        /// 
        static inline constexpr auto ok(T const&& value) noexcept -> Result {
            return Result(Ok, { .Ok = mv(value) });
        }

        /// @brief Construct an `Err` value
        /// @param value the value with
        /// @return new `Result`
        /// 
        static inline constexpr auto err(E const& value) noexcept -> Result {
            return Result(Err, { .Err = value });
        }

        /// @brief Construct an `Err` value
        /// @param value the value with
        /// @return new `Result`
        /// 
        static inline constexpr auto err(E const&& value) noexcept -> Result {
            return Result(Err, { .Err = mv(value) });
        }

        /// @brief Implicitly cast to `Tag`.
        /// This allows `switch`ing directly on the `Result`.
        /// 
        inline constexpr operator result::Tag() const noexcept {
            return this->tag;
        }

        inline constexpr auto is_ok() const noexcept -> bool {
            return this->tag == Ok;
        }

        inline constexpr auto is_err() const noexcept -> bool {
            return this->tag == Err;
        }

        /// @brief Unwrap the `Result` to an `Ok` value, taking ownership.
        /// @return the value
        /// 
        /// # Panic
        /// 
        /// Panics if the value is `Err`.
        /// 
        inline auto unwrap() const&& noexcept -> T {
            if (this->is_err()) panic("unwrap on `Err` value");
            return this->value.Ok;
        }

        /// @brief Unwrap the `Result` to an `Ok` value.
        /// @return the value
        /// 
        /// # Panic
        /// 
        /// Panics if the value is `Err`.
        /// 
        inline auto unwrap() const& noexcept -> T const& {
            if (this->is_err()) panic("unwrap on `Err` value");
            return this->value.Ok;
        }

        /// @brief Unwrap the `Result` to an `Ok` value.
        /// @return the value
        /// 
        /// # Panic
        /// 
        /// Panics if the value is `Err`.
        /// 
        inline auto unwrap() & noexcept -> T& {
            if (this->is_err()) panic("unwrap on `Err` value");
            return this->value.Ok;
        }

    };

}
