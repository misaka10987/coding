#pragma once

#include <concepts>
namespace coding::mem {
    template<typename Self> concept Clone = ::std::copy_constructible<Self>;
}
