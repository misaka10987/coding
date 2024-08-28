#pragma once

#include "root.cc"
#include "core.cc"

#include <memory>

namespace coding {

    /**
     * @brief A generic pointer with unique ownership.
     *
     * @tparam T the type pointing to
     */
    template<typename T>
    class Box {
    private:
        T* const p;
    public:

        /**
         * @brief Construct from raw pointer.
         * @warning Always create `Box`es with `new`ed pointers, otherwise the behaviour is undefined.
         *
         */
        inline constexpr Box(T* raw_ptr) noexcept : p(raw_ptr) {}

        inline constexpr Box(Box const&& box) noexcept : p(box.p) {}

        ~Box() {
            delete this->p;
        }

        inline constexpr auto operator*() const noexcept -> T const& {
            return *this->p;
        }

        inline constexpr auto operator*() noexcept -> T& {
            return *this->p;
        }

        inline constexpr auto operator&() const noexcept -> T const* {
            return this->p;
        }

        inline constexpr auto operator&() noexcept -> T* {
            return this->p;
        }
    };
}

/**
 * @brief Namespace for smart pointers.
 * 
 */
namespace coding::ptr {
    template <typename T> using Rc = ::std::shared_ptr<T>;

}

