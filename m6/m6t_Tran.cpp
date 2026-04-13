/*
m6t1 - XP TRACKER
Justin Tran
4/13/26
Gather XP per floor, then do stats
*/

#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int xp[SIZE];
    int max = 10;
    double total = 0;
    double avg;

    cout << "DUNGEON XP TRACKER" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Floor " << i+1 << " XP: ";
        cin >> xp[i];
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        total += xp[i];
        if (xp[i] > max)
        {
            max = xp[i];
        }
    }
    
    avg = total / SIZE;

    cout << "OVER " << SIZE << " FLOORS" << endl;
    cout << "TOTAL XP: " << total << endl;
    cout << "AVERAGE XP: " << avg << endl;
    cout << "BEST XP: " << max << endl;
}