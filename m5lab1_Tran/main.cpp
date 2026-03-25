#include "include/renderer.h"

int main()
{
    std::string clear = "123";

    renderer::clearScreen();
    renderer::drawText(1, 2, "You're a disease thats trying to kill this human body!");
    return 0;
}