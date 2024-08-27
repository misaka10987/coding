#pragma once

#include <memory>
namespace coding::ptr {
    template <typename T> using Box = ::std::unique_ptr<T>;
    template <typename T> using Rc = ::std::shared_ptr<T>;
}
