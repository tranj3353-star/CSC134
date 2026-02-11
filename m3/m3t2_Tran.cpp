/*
M3T1
Compare 2 triangles
*/

#include <iostream>
using namespace std;

int main()
{
    //Program: Measure 2 rectangles

    //Init vars
    double length1, width1, area1;
    double length2, width2, area2;

    //Get Info
    cout << "Please enter measurements for rectangles\n\n";
    cout << "Rectangle 1-----------------------------\n";
    cout << "length: ";
    cin >> length1;
    cout << "width: ";
    cin >> width1;

    cout << "Rectangle 2-----------------------------\n";
    cout << "length: ";
    cin >> length2;
    cout << "width: ";
    cin >> width2;

    //Calc areas
    area1 = length1 * width1;
    area2 = length2 * width2;

    //Print output
    cout << "Rectangle 1 area: " << area1 << endl;
    cout << "Rectangle 2 area: " << area2 << endl;

    //Compare
    if (area1 > area2)
    {
        cout << "First rectangle is bigger!" << endl;
    }
    if (area2 > area1)
    {
        cout << "Second rectangle is bigger!" << endl;
    }
    if (area1 == area2)
    {
        cout << "Both rectangles have same area!" << endl;
    }

    return 0;
}