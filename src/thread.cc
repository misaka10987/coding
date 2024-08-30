#pragma once

#include "root.cc"

#include <thread>
#include <iostream>

/// @brief Namespace for operating with threads.
namespace coding::thread {

    /// @brief Panic the current thread.
    /// @tparam T a type able to be printed with `std::ostream`
    /// @param msg message to print to `stderr` before exit
    /// @return never
    /// 
    template<typename T>
    auto panic(T msg = "") noexcept {
        auto id = std::this_thread::get_id();
        std::cerr
            << std::endl << std::endl
            << "panic at thread '" << id << "': " << msg << std::endl;
        std::exit(-1);
    }
}

namespace coding {
    using thread::panic;
}
