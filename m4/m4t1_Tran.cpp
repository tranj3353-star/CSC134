/*
M4T1 - While Loop
CSC 134
Justin Tran
3/4/26
*/

#include <iostream>
using namespace std;

int main()
{
    const int MIN = 1;
    const int MAX = 10;

    int num = MIN;
    int squared;

    cout << "Number\tNum Squared" << endl;
    cout << "___________________" << endl;

    while (num <= MAX) {
        squared = num * num;
        cout << num << "\t" << squared << endl;
        num++;
    }

    return 0;
}