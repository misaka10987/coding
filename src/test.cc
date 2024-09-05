#include "lib.cc"

using namespace coding;

class X {
public:
    int x;
    int* p;
    X() :x() {
        p = new int;
    }

    X(X& xxx) {
        coding_trace("copy");
        this->p = nullptr;
    }

    ~X() {
        delete this->p;
    }
    // auto operator=(X rhs) = delete;
};

auto main() -> int {
    coding_info(3);
    // std::unique_ptr<std::string> a = std::make_unique_for_overwrite<std::string>();
    // std::string b = "123";
    // a = std::make_unique<std::string>(b);
    auto a = Lazy<X>([](void) {return X(); });
    *a;
    auto b = a;
    // // auto c = *b;
    // auto& y = *a;
    // if (true) {
    //     auto& z = *a;
    //     auto& t = *a;
    // }
    return 0;
}