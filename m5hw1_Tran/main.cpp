/*
Justin Tran
CSC-134
M5HW1
4/1/26
Gold
*/

#include <iostream>
#include <iomanip>
using namespace std;

void questionOne();
void questionTwo();
void questionThree();
void questionFour();
void questionFive();
double noNegValidation(double num, string msg);

int main()
{
    cout << setprecision(2) << fixed;

    while (true)
    {
        int choice;
        cout << "Choose 1-6 (6 is quit): ";
        cin >> choice;

        switch (choice)
        {
            case 1: {
                questionOne();
                break;}
            case 2: {
                questionTwo();
                break;}
            case 3: {
                questionThree();
                break;}
            case 4:
                questionFour();
                break;
            case 5: 
                questionFive();
                break;
            case 6:
                return 1;
                break;
            default:
                cout << "ERROR! invalid option!" << endl;
                break;
        }
    }
    

    return 0;
}

void questionOne()
{
    string monthOne;
    double rainOne;
    cout << "Enter Month: ";
    cin >> monthOne;
    cout << "Enter rainfall in inches for " << monthOne << ": ";
    cin >> rainOne;

    string monthTwo;
    double rainTwo;
    cout << "Enter Month: ";
    cin >> monthTwo;
    cout << "Enter rainfall in inches for " << monthTwo << ": ";
    cin >> rainTwo;

    string monthThree;
    double rainThree;
    cout << "Enter Month: ";
    cin >> monthThree;
    cout << "Enter rainfall in inches for " << monthThree << ": ";
    cin >> rainThree;

    cout << "The avg rainfall in inches for " + monthOne + ", " + monthTwo + 
    ", " + monthThree + " is " << (rainOne + rainTwo + rainThree) / 3 << endl;

}

void questionTwo()
{
    double length;
    double width;
    double height;

    cout << "Enter length: ";
    cin >> length;
    while (length <= 0)
    {
        cout << "ERROR! Must be greater than 0!" << endl;
        cout << "Enter length: ";
        cin >> length;
    }

    cout << "Enter width: ";
    cin >> width;
    while (width <= 0)
    {
        cout << "ERROR! Must be greater than 0!" << endl;
        cout << "Enter width: ";
        cin >> width;
    }

    cout << "Enter height: ";
    cin >> height;
    while (height <= 0)
    {
        cout << "ERROR! Must be greater than 0!" << endl;
        cout << "Enter height: ";
        cin >> height;
    }

    cout << "VOLUME: " << height * width * length << endl;
}

void questionThree()
{
    int num;
    cout << "Enter number 1-10: ";
    cin >> num;
    while (num <= 0 || num > 10)
    {
        cout << "ERROR! NEEDS TO BE 1-10!" << endl;
        cout << "Enter number 1-10: ";
        cin >> num;
    }

    cout << "Roman numeral is: ";

    switch (num)
    {
    case 1:
        cout << "I";
        break;
    case 2:
        cout << "II";
        break;
    case 3:
        cout << "III";
        break;
    case 4:
        cout << "IV";
        break;
    case 5:
        cout << "V";
        break;
    case 6:
        cout << "VI";
        break;
    case 7:
        cout << "VII";
        break;
    case 8:
        cout << "VIII";
        break;
    case 9:
        cout << "IX";
        break;
    case 10:
        cout << "X";
        break;
    default:
        break;
    }
    cout << endl;
}

void questionFour()
{
    double pi = 3.14159;
    while (true)
    {
        int choice;
        cout << R"(Geometry Calculator
1. Calculate the Area of a Circle
2. Calculate the Area of a Rectangle
3. Calculate the Area of a Triangle
4. Quit
Enter your choice (1-4): )";
        cin >> choice;
        
        switch (choice)
        {
            case 1: {
                double radius;
                cout << "Enter Radius: ";
                cin >> radius;
                radius = noNegValidation(radius, "Enter Radius: ");
                cout << "Area: " << radius * radius * pi;
                break;}
            case 2: {
                double length;
                double width;
                cout << "Enter length: ";
                cin >> length;
                length = noNegValidation(length, "Enter length: ");
                cout << "Enter width: ";
                cin >> width;
                width = noNegValidation(width, "Enter width: ");
                cout << "Area: " << length * width;
                break;}
            case 3: {
                double base;
                double height;
                cout << "Enter base: ";
                cin >> base;
                base = noNegValidation(base, "Enter base: ");
                cout << "Enter height: ";
                cin >> height;
                height = noNegValidation(height, "Enter height: ");
                cout << "Area: " << base * height * 0.5;
                break;}
            case 4:
                return;
                break;
            default:
                cout << "ERROR! invalid option!";
                break;
        }
        cout << endl;
    }
}

void questionFive()
{
    double speed;
    cout << "Speed in mph: ";
    cin >> speed;
    speed = noNegValidation(speed, "Speed in mph: ");
    int hours;
    cout << "Hours: ";
    cin >> hours;
    while (hours <= 0)
    {
        cout << "ERROR! Greater than Zero needed!" << endl;
        cout << "Hours: ";
        cin >> hours;
    }
    cout << "Hour \t Distance Travelled" << endl;
    for (size_t i = 1; i <= hours; i++)
    {
        cout << i << "\t" << i * speed << endl;
    }
    cout << endl;
}

double noNegValidation(double num, string msg)
{
    while (num < 0)
    {
        cout << "ERROR! No negative nums!" << endl;
        cout << msg;
        cin >> num;
    }
    return num;
}