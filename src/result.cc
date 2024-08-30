#pragma once

#include "root.cc"
#include "core.cc"
#include "log.cc"
#include "thread.cc"

#include <variant>
#include <concepts>

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

    /// @brief A type for wrapping potential errors. Acts like Rust's `Result`.
    /// @tparam T the normal type
    /// @tparam E the error type
    /// 
    template<typename T, typename E>
    class Result final {
    private:

        /// @brief `Result` use `std::variant` to store the internal value, which does not support stroing the same type.
        /// In case this happens, `Result` automatically wraps the `Err` value with this struct.
        /// @tparam U the original type
        /// 
        template<typename U>
        struct Error {

            U value;

            /// @brief Construct the wrapper.
            /// @param value the original value
            /// 
            inline constexpr Error(U value) noexcept : value(value) {}

            inline constexpr auto operator*() const noexcept -> U const& {
                return this->value;
            }

            inline constexpr auto operator*()  noexcept -> U& {
                return this->value;
            }

            inline constexpr operator U() const&& noexcept {
                return this->value;
            }

            inline constexpr operator U const& () const& noexcept {
                return this->value;
            }

            inline constexpr operator U& () & noexcept {
                return this->value;
            }
        };

        /// @brief Tags whether the `Result` is `Ok` or `Err`.
        /// 
        result::Tag tag : 1;

        /// @brief Internal storage of result.
        /// 
        std::variant<T, Error<E>> value;

        inline constexpr Result(T ok) noexcept : tag(Ok), value(ok) {}

        inline constexpr Result(Error<E> err) noexcept : tag(Err), value(err) {}

    public:

        /// @brief Construct an `Ok` instance
        /// @param value the value with
        /// @return new `Result`
        /// 
        inline constexpr static auto ok(T value) noexcept -> Result {
            return Result(value);
        }

        /// @brief Construct an `Err` instance
        /// @param value the value with
        /// @return new `Result`
        /// 
        inline constexpr static auto err(E value) noexcept -> Result {
            return Result(Error<E>(value));
        }

        /// @brief Implicitly cast to `Tag`.
        /// This allows `switch`ing directly on the `Result`.
        /// 
        inline constexpr operator result::Tag() const noexcept {
            return this->tag;
        }

        /// @brief It does what you think it does.
        /// 
        inline constexpr auto is_ok() const noexcept -> bool {
            return this->tag == Ok;
        }

        /// @brief It does what you think it does.
        /// 
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
        inline constexpr auto unwrap() const&& noexcept -> T {
            if (this->is_err()) panic("unwrap `Result` on an `Err` value");
            return std::get<T>(this->value);
        }

        /// @brief Unwrap the `Result` to an `Ok` value.
        /// @return the value
        /// 
        /// # Panic
        /// 
        /// Panics if the value is `Err`.
        /// 
        inline constexpr auto unwrap() const& noexcept -> T const& {
            if (this->is_err()) panic("unwrap `Result` on an `Err` value");
            return std::get<T>(this->value);
        }

        /// @brief Unwrap the `Result` to an `Ok` value.
        /// @return the value
        /// 
        /// # Panic
        /// 
        /// Panics if the value is `Err`.
        /// 
        inline constexpr auto unwrap() & noexcept -> T& {
            if (this->is_err()) panic("unwrap `Result` on an `Err` value");
            return std::get<T>(this->value);
        }

        /// @brief Unwrap the `Result` to an `Err` value, taking ownership.
        /// @return the value
        /// 
        /// # Panic
        /// 
        /// Panics if the value is `Ok`.
        /// 
        inline constexpr auto unwrap_err() const&& noexcept -> E {
            if (this->is_ok()) panic("unwrap `Result` error on an `Ok` value");
            return std::get<Error<E>>(this->value);
        }

        /// @brief Unwrap the `Result` to an `Err` value.
        /// @return the value
        /// 
        /// # Panic
        /// 
        /// Panics if the value is `Ok`.
        /// 
        inline constexpr auto unwrap_err() const& noexcept -> E const& {
            if (this->is_ok()) panic("unwrap `Result` error on an `Ok` value");
            return std::get<Error<E>>(this->value);
        }

        /// @brief Unwrap the `Result` to an `Err` value.
        /// @return the value
        /// 
        /// # Panic
        /// 
        /// Panics if the value is `Ok`.
        /// 
        inline constexpr auto unwrap_err() & noexcept -> E& {
            if (this->is_ok()) panic("unwrap `Result` error on an `Ok` value");
            return std::get<Error<E>>(this->value);
        }

        /// @brief Maps the `Ok` value if it is, otherwise return the same `Err` value.
        /// @tparam U the type mapped to
        /// @param mapping the mapping function to call
        /// @return the mapped new `Result`
        /// 
        template<typename U>
        inline constexpr auto map(Fn(U(T const&)) mapping) const& noexcept -> Result<U, E> {
            if (this->is_err()) return Result<U, E>::err(std::get<Error<E>>(this->value));
            auto ok = mapping(std::get<T>(this->value));
            return Result<U, E>::ok(ok);
        }

        /// @brief Maps the `Err` value if it is, otherwise return the same `Ok` value.
        /// @tparam U the type mapped to
        /// @param mapping the mapping function to call
        /// @return the mapped new `Result`
        /// 
        template<typename U>
        inline constexpr auto map_err(Fn(U(T const&)) mapping) const& noexcept -> Result<T, U> {
            if (this->is_ok()) return Result<T, U>::ok(std::get<T>(this->value));
            auto err = mapping(std::get<Error<E>>(this->value));
            return Result<T, U>::err(err);
        }

    };

    /// @brief Same as `Result<T,E>::ok`, construct new `Result` instance with `Ok` value.
    /// @tparam T the `Ok` type
    /// @tparam E the `Err` type
    /// @param value the value with
    /// @return new `Result`
    /// 
    template<typename T, typename E>
    inline constexpr auto ok(T value) noexcept -> Result<T, E> {
        return Result<T, E>::ok(value);
    }

    /// @brief Same as `Result<T,E>::err`, construct new `Result` instance with `Err` value.
    /// @tparam T the `Ok` type
    /// @tparam E the `Err` type
    /// @param value the value with
    /// @return new `Result`
    /// 
    template<typename T, typename E>
    inline constexpr auto err(E value) noexcept -> Result<T, E> {
        return Result<T, E>::err(value);
    }

}

namespace coding {

    using result::Tag::Ok;
    using result::Tag::Err;

    template<typename T, typename E> using Result = result::Result<T, E>;

    using result::ok, result::err;

}
