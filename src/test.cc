#include "str.cc"

auto main(int argc, char const* const* argv) -> int {
    str a = argv[1];
    for (auto i : a.split(argv[2])) std::cout << "'" << &i << "'" << std::endl;
    return 0;
}
