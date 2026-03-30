// M5LAB2
// Justin Tran
// CSC 134
// M5Lab1

#include <iostream>
using namespace std;

// Declare (Write the prototypes for)
// the getLength,
// getWidth, getArea, and displayData
// functions here.

double getWidth();
double getLength();
double getArea(double width, double length);
void displayData(double length, double width, double area);

int main()
{
	// This program calculates the area of a rectangle.
	// TODO: fix any syntax errors
	
   double length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(width, length);
   
   // Display the rectangle's data.
   displayData(length, width, area);
          
   return 0;
}

//***************************************************
// TODO: write the getLength, getWidth, getArea,    *
// and displayData functions below.                 *
//***************************************************

double getWidth()
{
    cout << "Insert Rect Width: ";
    double width;
    cin >> width;
    return width;
}

double getLength()
{
    cout << "Insert Rect Length: ";
    double length;
    cin >> length;
    return length;
}

double getArea(double width, double length)
{
    return width * length;
}

void displayData(double length, double width, double area)
{
    cout << "------------------------" << endl;
    cout << "Length: " << length << endl;
    cout << "Width: " <<width << endl;
    cout << "Area: " <<area << endl;
}