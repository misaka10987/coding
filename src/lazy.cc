#pragma once

#include "root.cc"
#include "core.cc"

#include <functional>

namespace coding {

    /// @brief A lazy-evaluation smart pointer.
    /// @tparam T the evaluated type
    /// 
    template<typename T>
    class Lazy {

    private:

        /// @brief Storage for the actual value, `nullptr` for uninitialized.
        /// 
        mutable T* maybe_uninit = nullptr;

        /// @brief The calculation that is lazy evaluated.
        /// 
        std::function(T(void)) provider;

    public:

        inline constexpr Lazy(std::function(T(void)) calc) noexcept : provider(calc) {}

        inline constexpr Lazy(Lazy const& other) noexcept : provider(other.provider) {
            if (other.maybe_uninit) this->maybe_uninit = new T(*other.maybe_uninit);
        }

        inline constexpr ~Lazy() noexcept {
            delete this->maybe_uninit;
        }

        inline constexpr auto operator*() const noexcept -> T const& {
            if (!this->maybe_uninit) this->maybe_uninit = new T(this->provider());
            return *this->maybe_uninit;
        }

        inline constexpr auto operator*() noexcept -> T& {
            if (!this->maybe_uninit) this->maybe_uninit = new T(this->provider());
            return *this->maybe_uninit;
        }
    };

}
