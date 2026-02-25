/*
CSC 134
M3Lab - Letter Grade
Justin Tran
2/25/26
*/

#include <iostream>
using namespace std;

int main()
{
    double num_grade;
    string letter_grade;
    cout << "This program converts number grads (0-100) to letter grades. " << endl;
    cout << "Enter grade: ";
    cin >> num_grade;

    if (num_grade >= 90) {
        letter_grade = "A";
    } else if (num_grade >= 80)
    {
        letter_grade = "B";
    } else if (num_grade >= 70)
    {
        letter_grade = "C";
    } else if (num_grade >= 60)
    {
        letter_grade = "D";
    } else {
        letter_grade = "F";
    }

    cout << "A grade of " << num_grade << " is letter grade: " << letter_grade << endl;

    return 0;
}