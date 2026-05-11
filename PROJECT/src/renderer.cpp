#include "renderer.h"

#include <iostream>
#include <string>
#include <algorithm>

namespace renderer
{
    // Brightness ramp
    static const std::string gradient = " .:-=+*#%@";

    void clearScreen()
    {
        // ANSI escape sequence
        std::cout << "\x1B[2J\x1B[H";
    }

    void draw(const Grid& grid)
    {
        clearScreen();

        int rows = grid.getRows();
        int cols = grid.getCols();

        for (int y = 0; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                float value = grid.getCell(x, y);

                // Clamp to 0-1 range
                value = std::clamp(value, 0.0f, 1.0f);

                int index = static_cast<int>(
                    value * (gradient.size() - 1)
                );

                std::cout << gradient[index];
            }

            std::cout << '\n';
        }

        std::cout.flush();
    }
}