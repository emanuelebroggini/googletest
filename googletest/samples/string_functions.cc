#include <string>
#include <cctype>  // For the toupper() function

#include "string_functions.h"

std::string ToUpperCase(const std::string& input) {
    std::string upperCaseString = input;

    // Convert each character to uppercase
    for (char& c : upperCaseString) {
        c = std::toupper(c);
    }

    return upperCaseString;
}
