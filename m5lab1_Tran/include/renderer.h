#pragma once

#include <string>

namespace renderer {

    // Clears the console screen
    void clearScreen();

    // Moves cursor to (x, y)
    void moveCursor(int x, int y);

    // Draws text at position
    void drawText(int x, int y, const std::string& text);

    // Draws a horizontal line
    void drawHorizontalLine(int x, int y, int length, char ch = '-');

    // Draws a vertical line
    void drawVerticalLine(int x, int y, int height, char ch = '|');

    // Draws a box
    void drawBox(int x, int y, int width, int height);

    // Delay in milliseconds
    void delay(int ms);

    // Flush output to screen
    void present();

}