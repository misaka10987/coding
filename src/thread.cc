#pragma once

#include <thread>
#include <iostream>

namespace coding::thread {

    /**
     * @brief Panic the current thread.
     * 
     * @param msg message to print to `stderr`
     * @return never
     */
    auto panic(char const* msg = "") noexcept {
        auto id = ::std::this_thread::get_id();
        ::std::cerr
            << msg << ::std::endl
            << "panic at thread '" << id << "'" << ::std::endl;
        ::std::terminate();
    }
}

namespace coding {
    using thread::panic;
}
