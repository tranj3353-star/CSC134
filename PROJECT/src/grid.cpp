#include "grid.h"

#include <algorithm>

Grid::Grid(int rows, int cols, float defaultValue)
    : rows(rows), cols(cols), data(rows * cols, defaultValue)
{
}

int Grid::index(int x, int y) const
{
    return y * cols + x;
}

void Grid::resize(int newRows, int newCols, float defaultValue)
{
    rows = newRows;
    cols = newCols;
    data.assign(rows * cols, defaultValue);
}

void Grid::modifyCell(int x, int y, float value)
{
    if (x < 0 || x >= cols || y < 0 || y >= rows)
        return;

    data[index(x, y)] = value;
}

float Grid::getCell(int x, int y) const
{
    if (x < 0 || x >= cols || y < 0 || y >= rows)
        return 0.0f;

    return data[index(x, y)];
}

int Grid::getRows() const
{
    return rows;
}

int Grid::getCols() const
{
    return cols;
}

void Grid::clear(float value)
{
    std::fill(data.begin(), data.end(), value);
}

void Grid::filter2D(const std::vector<std::vector<float>>& kernel)
{
    if (kernel.empty() || kernel[0].empty())
        return;

    int kernelHeight = kernel.size();
    int kernelWidth = kernel[0].size();

    int kCenterY = kernelHeight / 2;
    int kCenterX = kernelWidth / 2;

    std::vector<float> output = data;

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            float sum = 0.0f;

            for (int ky = 0; ky < kernelHeight; ky++)
            {
                for (int kx = 0; kx < kernelWidth; kx++)
                {
                    int sampleX = x + (kx - kCenterX);
                    int sampleY = y + (ky - kCenterY);

                    if (sampleX < 0 || sampleX >= cols ||
                        sampleY < 0 || sampleY >= rows)
                    {
                        continue;
                    }

                    sum += getCell(sampleX, sampleY) * kernel[ky][kx];
                }
            }

            output[index(x, y)] = sum;
        }
    }

    data = output;
}