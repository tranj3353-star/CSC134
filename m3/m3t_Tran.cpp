/*
CSC 134
M3T3 - Craps and rand nums
Justin Tran
2/18/26
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function prototype - Declare what's coming
int roll();

int main() {
    srand(time(0));

    int roll1 = roll();
    int roll2 = roll();
    string status;
    int point;
    int total = roll1 + roll2;

    cout << "Roll is: " << roll1 << " + " << roll2 << " = " << total << endl;
    if (total == 7 || total == 11) // || is OR
    {
        status = "win";
    } else if (total == 2 || total == 3 || total == 12)
    {
        status = "lose";
    } else 
    {
        point = total;
        status = "point";
    }

    cout << "Roll results: " << status << endl;

    return 0;
}

int roll()
{
    return (rand() % 6) + 1;
}