//CSC 134
//M1T1 (Module 1, tutorial 1)

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "hello world!" << endl << endl;

    //Get and display name
    string name;
    cout << "Enter your first name: ";
    cin >> name; //Input
    cout << "Name: " + name << endl << endl;

    //Get and display number
    int num1;
    cout << "Enter whole number: ";
    cin >> num1;
    cout << "Num: " + to_string(num1) << endl;

    //Get exponent from 1st number
    int exponent;
    cout << "Enter whole number for exponentiation: ";
    cin >> exponent;
    int result = pow(num1, exponent);
    cout << num1 << " raised to " << exponent << " is " << result << endl;

    return 0;
}