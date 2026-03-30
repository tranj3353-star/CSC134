#include "include/renderer.h"
#include "include/input.h"
#include <iostream>

int uninfected = 8000000000;
int infected = 0;
int dead = 0;
std::string name;

void intro();
void drawHeader();

int main()
{
    intro();
    
    return 0;
}

void intro()
{
    renderer::clearScreen();
    renderer::drawText(1, 2, "You're a disease thats trying to kill every human!");
    renderer::drawText(1, 4, "Input Name: ");
    name = input::getLine();
    renderer::present();
    renderer::clearScreen();
}

void drawHeader()
{
    renderer::drawHorizontalLine(1,2, 30);
    renderer::drawHorizontalLine(1,6, 30);
    renderer::drawText(1,3, "Uninfected: " + std::to_string(uninfected));
    renderer::drawText(1,4, "Infected: " + std::to_string(infected));
    renderer::drawText(1,5, "Dead: " + std::to_string(dead));
    renderer::moveCursor(1, 10);
}