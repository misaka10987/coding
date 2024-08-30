#include "lib.cc"

using namespace coding;

auto f(Result<String, String> a) -> Result<String, String> {
    auto x = [](String y) {return y + "3"; };
    auto z = a.map_err<String>(x);
    return z;
}

auto main() -> int {
    info("hi");
    return 0;
}
