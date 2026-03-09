/*
CSC 134
M4HW - Times Table
Justin Tran
3/9/26
GOLD
*/

#include <iostream>
using namespace std;

void makeMultColumn(int num)
{
    cout << "Here is multiplication column for " << num << endl;

    for (size_t i = 1; i <= 12; i++)
    {
        cout << num << " times " << i << " is " << num * i << endl;
    }
    
}

int main()
{  
    int userNum;
    cout << "Enter Number 1-12: ";
    cin >> userNum;

    while (userNum < 1 || userNum > 12)
    {
        cout << "OUT OF BOUNDS! " << endl;
        cout << "Enter Number 1-12: ";
        cin >> userNum;
    }

    makeMultColumn(userNum);

    return 0;
}