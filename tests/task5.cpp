#include <iostream>
#include <functional>
#include <type_traits>

template <typename T>
class Pipeline {
private:
    T value;

public:
    Pipeline(T initial) : value(initial) {}

    template <typename F>
    auto operator|(F&& func) {
        using ResultType = std::conditional_t<std::is_same_v<std::void_t<decltype(func(std::declval<T>()))>, void>,
                                             std::decay_t<T>,
                                             decltype(func(std::declval<T>()))>;

        return Pipeline<ResultType>(func(std::move(value)));
    }

    void operator()() {
        std::cout << value << std::endl;
    }
};

int main() {
    std::string str = "Hello World!";

    auto pipeline = Pipeline<std::string>(str)
                    | [](const auto& x) { return x.size(); }
                    | [](auto x) { return x * 2; }
                    | [](auto x) { std::cout << x; };

    pipeline();
    return 0;
}
