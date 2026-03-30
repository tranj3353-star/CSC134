#include "input.h"
#include <iostream>
#include <algorithm>

namespace input {

    char getChoice(const std::vector<char>& validOptions) {
        char input;

        while (true) {
            std::cin >> input;

            // normalize to lowercase
            input = std::tolower(input);

            for (char option : validOptions) {
                if (input == std::tolower(option)) {
                    return input;
                }
            }

            std::cout << "Invalid input. Try again: ";
        }
    }

    int getInt(int min, int max) {
        int value;

        while (true) {
            std::cin >> value;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid number. Try again: ";
                continue;
            }

            if (value >= min && value <= max) {
                return value;
            }

            std::cout << "Enter a number between " << min << " and " << max << ": ";
        }
    }

    std::string getLine() {
        std::string line;
        std::cin.ignore(); // clear leftover newline
        std::getline(std::cin, line);
        return line;
    }

}