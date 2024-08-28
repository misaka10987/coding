#include "lib.cc"



auto main() -> int {
    using namespace coding;
    using namespace ops;
    auto x = Box(new i64(-39i64));
    auto const _ = &x;
    std::cout << *x << std::endl;
    return 0;
}
