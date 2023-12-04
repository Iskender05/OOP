#include <iostream>
#include <sstream>
#include <stdexcept>

class FormatStringException : public std::exception {
public:
    explicit FormatStringException(const std::string& message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

class FormatString {
public:
    explicit FormatString(const std::string& format) : format(format) {}

    template<typename... Args>
    std::string operator()(Args&&... args) const {
        if (sizeof...(Args) != arg_number()) {
            throw FormatStringException("Incorrect number of arguments");
        }

        std::stringstream result;
        substituteArgs(result, 1, std::forward<Args>(args)...);
        return result.str();
    }

    size_t arg_number() const {
        size_t count = 0;
        size_t pos = 0;

        while ((pos = format.find('%', pos)) != std::string::npos) {
            ++count;
            pos += 2; // Skip '%X' where X is the argument number
        }

        return count;
    }

private:
    std::string format;

    template<typename T, typename... Args>
    void substituteArgs(std::stringstream& result, size_t argIndex, T&& arg, Args&&... args) const {
        size_t pos = format.find('%');
        result << format.substr(0, pos); // Copy the substring before '%'

        if (argIndex > arg_number()) {
            throw FormatStringException("Incorrect number of arguments");
        }

        result << arg;
        substituteArgs(result, argIndex + 1, std::forward<Args>(args)...);
    }

    void substituteArgs(std::stringstream& result, size_t argIndex) const {
        size_t pos = format.find('%');
        result << format.substr(pos); // Copy the remaining substring
    }
};

// User-defined literal for FormatString
FormatString operator"" _fstr(const char* str, size_t) {
    return FormatString(str);
}

int main() {
    FormatString format_str = "Hello, %2. I am %1! Buy, %2"_fstr;

    try {
        std::string str = format_str(3.14, 'F');
        std::cout << str << std::endl;  // Should print: "Hello, F. I am 3.14! Buy, F"
    } catch (const FormatStringException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::string another_str = format_str('Q', 333);
        std::cout << another_str << std::endl;  // Should print: "Hello, 333. I am Q! Buy, 333"
    } catch (const FormatStringException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
