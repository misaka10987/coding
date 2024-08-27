#include<cstdlib>
#include<iostream>

/**
 * @todo
 *
 */
inline namespace result {
    template<typename T, typename E>
    union ResultValue {
        T ok;
        E err;
    };

    enum ResultTag {
        Ok,
        Err,
    };

    template<typename T, typename E>
    class Result {
    private:
        ResultValue<T, E> value;
        ResultTag tag : 1;
        constexpr Result(ResultValue<T, E> value, ResultTag const tag) {
            this->value = value;
            this->tag = tag;
        }
    public:
        static constexpr auto ok(T value) -> Result const&& {
            return Result(value, Ok);
        }
        static constexpr auto err(E value) -> Result const&& {
            return Result(value, Err);
        }
        constexpr auto is_ok() -> bool {
            return this->tag == Ok;
        }
        constexpr auto is_err() -> bool {
            return this->tag == Err;
        }
        // auto ok() -> T {
        //     if (!this->ok) {
        //         std::cerr << "panic: Result is Err, expected Ok" << std::endl;
        //         std::abort();
        //     }
        //     return this->value->ok;
        // }
    };
    template<typename T, typename E> using ok = Result<T, E>::ok;
}

