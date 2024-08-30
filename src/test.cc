#include "lib.cc"

using namespace coding;

auto f(Result<String, String> a) -> Result<String, String> {
    auto x = [](String y) {return y + "3"; };
    auto z = a.map_err<String>(x);
    return z;
}

auto main() -> int {
    auto a = Option(1);
    auto b = Option<int>();
    auto c = a.map<int>([](auto x) {return x + 1; });
    debug(c.unwrap());
    info("hi");
    return 0;
}
