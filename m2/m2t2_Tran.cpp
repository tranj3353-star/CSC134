/*
CSC 134
M2T2 - Receipt
Justin Tran
1/28/26
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //Init vars
    string meal_name = "Carolina Reaper Burger";
    double meal_price = 5.99;
    int meal_count;
    double subtotal, tip, tax_amount, total;
    const double TAX_RATE = 0.07;

    //Take order
    cout << "Welcome to the restaurant" << endl;
    cout << "How many " << meal_name << " would you like?: ";
    cin >> meal_count;
    cout << "Prepping Order!" << endl;

    //Calc subtotal and total
    subtotal = meal_price * meal_count;
    tax_amount = subtotal * TAX_RATE;
    total = subtotal + tax_amount;

    //Print receipts
    cout << "-------------------------" << endl;
    cout << meal_name << " X " << meal_count << endl;
    cout << "SUBTOTAL: \t\t$" << subtotal << endl;
    cout << "Tax: \t\t\t$" << tax_amount << endl;
    cout << "-------------------------" << endl;
    cout << "Total: \t\t\t$" << total << endl;
    cout << "THANK YOU COME AGAIN" << endl << endl;

    return 0;
}