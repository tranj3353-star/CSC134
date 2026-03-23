/*
M5T1 - More Funcs
Justin Tran
3/18/6
Show off different function types
*/

#include <iostream>
#include "m5t1.h"
using namespace std;

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
