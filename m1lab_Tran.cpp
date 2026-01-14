//CSC 134
//M1LAB - Sales
//Justin Tran
//1/14/26

/*
We're selling bananas
Tell users how much you have
How much each costs
Total cost
*/
#include <iostream>
using namespace std;

int main() {
    string item = "bananas";
    int item_count = 100;
    int purchased;
    double price_each = 0.79;

    cout << "Welcome to our " << item << " store!" << endl;
    cout << "We have " << item_count << " " << item << "!" << endl;
    cout << "They cost $" << price_each << " each!" << endl;

    cout << "How many would you like to buy?: ";
    cin >> purchased;

    double total_price = purchased * price_each;

    cout << "You purchased " << purchased << " " << item << endl;
    cout << "Total price is $" << total_price << endl;

    return 0;
}