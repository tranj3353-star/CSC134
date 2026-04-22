#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    const int width = 200;   // >= 100
    const int height = 200;  // >= 100

    std::ofstream outFile("concentric.ppm"); // relative path

    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // PPM header (P3 = ASCII format)
    outFile << "P3\n";
    outFile << width << " " << height << "\n";
    outFile << "255\n";

    // Center of the image
    double centerX = width / 2.0;
    double centerY = height / 2.0;

    // Generate pixels using nested loops
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            // Distance from center
            double dx = x - centerX;
            double dy = y - centerY;
            double distance = std::sqrt(dx * dx + dy * dy);

            // Create rings using sine waves for smooth color variation
            double value = std::sin(distance * 0.2);

            // Normalize to [0, 1]
            double normalized = (value + 1.0) / 2.0;

            // Generate vibrant colors
            int r = static_cast<int>(255 * normalized);
            int g = static_cast<int>(255 * (1 - normalized));
            int b = static_cast<int>(255 * std::abs(std::sin(distance * 0.1)));

            // Clamp values just in case
            r = std::min(255, std::max(0, r));
            g = std::min(255, std::max(0, g));
            b = std::min(255, std::max(0, b));

            outFile << r << " " << g << " " << b << " ";
        }
        outFile << "\n";
    }

    outFile.close();

    std::cout << "PPM image 'concentric.ppm' generated successfully.\n";
    return 0;
}