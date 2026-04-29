#pragma once

class Rectangle {
    private:
        double width;
        double length;
    
    public:
        double getWidth() {
            return width;
        }
        double getLength() {
            return length;
        }
        double getArea() {
            double area = length * width;
            return area;
        }
        void setWidth(double w) {
            width = w;
        }
        void setLength(double l) {
            length = l;
        }
        void drawRect()
        {
            for (size_t y = 0; y < length; y++)
            {
                for (size_t x = 0; x < width; x++)
                {
                    std::cout << "O";
                }
                std::cout << endl;
            }
            
        }
};
