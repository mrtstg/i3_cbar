#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string exec(const char* cmd, bool delete_newline = true) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    if (delete_newline && !result.empty() && result[result.length()-1] == '\n') {
        result.erase(result.length()-1);
    }
    return result;
}
