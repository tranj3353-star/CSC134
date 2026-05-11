#pragma once

#include <vector>
#include <functional>

class Grid
{
private:
    int rows;
    int cols;
    std::vector<float> data;

    int index(int x, int y) const;

public:
    Grid(int rows, int cols, float defaultValue = 0.0f);

    void resize(int newRows, int newCols, float defaultValue = 0.0f);

    void modifyCell(int x, int y, float value);

    float getCell(int x, int y) const;

    int getRows() const;
    int getCols() const;

    void clear(float value = 0.0f);

    // Applies a 2D filter/kernel over the grid
    void filter2D(const std::vector<std::vector<float>>& kernel);
};