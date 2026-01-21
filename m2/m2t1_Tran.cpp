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
#include <iomanip>
using namespace std;

int main() {
    string item_name;
    int item_count;
    int purchased;
    double price_each;

    cout << "Welcome to the store setup program. " << endl;
    cout << "Name of item?: ";
    getline(cin, item_name);
    cout << "Number of items?: ";
    cin >> item_count;
    cout << "Price each?: ";
    cin >> price_each;

    cout << setprecision(2) << fixed;

    cout << "Welcome to our " << item_name << " store!" << endl;
    cout << "We have " << item_count << " " << item_name << "!" << endl;
    cout << "They cost $" << price_each << " each!" << endl;

    cout << "How many would you like to buy?: ";
    cin >> purchased;

    double total_price = purchased * price_each;

    cout << "You purchased " << purchased << " " << item_name << endl;
    cout << "Total price is $" << total_price << endl;

    return 0;
}