#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
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

// renderer.cpp
// Simple console renderer for a turn-based game
// Compatible with VSCode / GitHub Codespaces (Linux-based)



namespace renderer {

    // Clears the console screen (ANSI escape codes)
    void clearScreen() {
        std::cout << "\033[2J\033[1;1H";
    }

    // Moves cursor to x, y
    void moveCursor(int x, int y) {
        std::cout << "\033[" << y << ";" << x << "H";
    }

    // Prints text at position
    void drawText(int x, int y, const std::string& text) {
        moveCursor(x, y);
        std::cout << text;
    }

    // Draws a horizontal line
    void drawHorizontalLine(int x, int y, int length, char ch) {
        moveCursor(x, y);
        for (int i = 0; i < length; ++i) std::cout << ch;
    }

    // Draws a vertical line
    void drawVerticalLine(int x, int y, int height, char ch) {
        for (int i = 0; i < height; ++i) {
            moveCursor(x, y + i);
            std::cout << ch;
        }
    }

    // Draws a box
    void drawBox(int x, int y, int width, int height) {
        drawHorizontalLine(x, y, width);
        drawHorizontalLine(x, y + height - 1, width);
        drawVerticalLine(x, y, height);
        drawVerticalLine(x + width - 1, y, height);
    }

    // Simple delay (useful for turn-based pacing)
    void delay(int ms) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    // Flush output (important for real-time rendering)
    void present() {
        std::cout.flush();
    }

}
