#include <string>
#include <iostream>
#include <fmt/core.h>
#include <re2/re2.h>

int main() {
    RE2 re("(\\w+)\\s*(\\d+)");
    assert(re.ok());


    std::string str_to_match;
    std::getline(std::cin, str_to_match);

    std::string str;
    int i;

    if (RE2::FullMatch(str_to_match, re, &str, &i)) {
        fmt::print("string was: {}, and int was {}\n", str, i);
    }
}

