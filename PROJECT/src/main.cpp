#include "grid.h"
#include "renderer.h"
#include "parser.h"

#include <chrono>
#include <thread>
#include <algorithm>
#include <iostream>

// Default ambient light level - pixels start here before emboss shifts them.
// Range 0.0-1.0; a small value like 0.03 keeps unlit areas dark.
static constexpr float DEFAULT_AMBIENT = 0.03f;

int main(int argc, char* argv[])
{
    float ambient = DEFAULT_AMBIENT;
    if (argc > 1)
    {
        try { ambient = std::stof(argv[1]); }
        catch (...) { std::cerr << "Invalid ambient value, using default.\n"; }
    }
    ambient = std::clamp(ambient, 0.0f, 1.0f);

    // --- Open the binary video file ---
    Parser parser("data.bin");
    auto header = parser.getHeader();

    const int W   = header.width;   // 160
    const int H   = header.height;  // 120
    const int fps = header.fps;

    const int frameDelayMs = (fps > 0) ? (1000 / fps) : 33;

    // --- Emboss kernel (3x3, 2-D vector form) ---
    //  -2  -1   0
    //  -1   1   1
    //   0   1   2
    std::vector<std::vector<float>> emboss = {
        { -2.0f, -1.0f,  0.0f },
        { -1.0f,  1.0f,  1.0f },
        {  0.0f,  1.0f,  2.0f }
    };

    Grid grid(H, W, 0.0f);
    Frame frame;

    while (parser.readNextFrame(frame))
    {
        auto t0 = std::chrono::steady_clock::now();

        // Unpack 2400-byte packed frame -> 19200 raw pixels (0 or 1)
        auto pixels = parser.unpackBits(frame.data);

        // Fill grid with raw pixels + ambient bias
        for (int y = 0; y < H; ++y)
            for (int x = 0; x < W; ++x)
                grid.modifyCell(x, y, static_cast<float>(pixels[y * W + x]) + ambient);

        // Apply emboss - result can be negative or > 1
        grid.filter2D(emboss);

        // Normalize the filtered grid to [0, 1] so the full
        // emboss dynamic range maps across the brightness ramp
        // instead of being crushed by the renderer's clamp.
        float minVal =  1e9f;
        float maxVal = -1e9f;
        for (int y = 0; y < H; ++y)
            for (int x = 0; x < W; ++x)
            {
                float v = grid.getCell(x, y);
                minVal = std::min(minVal, v);
                maxVal = std::max(maxVal, v);
            }

        float range = maxVal - minVal;
        if (range > 1e-6f)
        {
            for (int y = 0; y < H; ++y)
                for (int x = 0; x < W; ++x)
                    grid.modifyCell(x, y, (grid.getCell(x, y) - minVal) / range);
        }

        //renderer::clearScreen();
        renderer::draw(grid);

        // Pace playback to match the file's FPS
        auto t1 = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count();
        int sleepMs = frameDelayMs - static_cast<int>(elapsed);
        if (sleepMs > 0)
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepMs));
    }

    return 0;
}