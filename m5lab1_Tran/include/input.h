#pragma once

#include <string>
#include <vector>

namespace input {

    // Get a single validated choice (e.g. A, B, C)
    char getChoice(const std::vector<char>& validOptions);

    // Get integer within range
    int getInt(int min, int max);

    // Get full line input
    std::string getLine();

}