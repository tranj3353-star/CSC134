/*
M5T1 - More Funcs
Justin Tran
3/18/6
Show off different function types
*/

#include <iostream>
using namespace std;

void say_hi();
int show_answer();
double square_number(double num);

int main()
{
    say_hi();
    cout << "Answer is " << show_answer() << endl;
    double numInput;
    cout << "Enter Number: ";
    cin >> numInput;
    cout << "Squared is " << square_number(numInput) << endl;
    return 0;
}

void say_hi()
{
    cout << "Hello world!" << endl;
    return;
}

int show_answer()
{
    return 42;
}

double square_number(double num)
{
    return num * num;
}
