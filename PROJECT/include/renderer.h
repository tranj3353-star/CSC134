#pragma once

#include "grid.h"

namespace renderer
{
    // Draws the grid as ASCII art
    void draw(const Grid& grid);

    // Clears terminal screen before redraw
    void clearScreen();
}