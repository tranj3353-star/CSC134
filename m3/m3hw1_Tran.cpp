/*
CSC 134
M3HW1 - Questions
Justin Tran
2/25/26
GOLD
*/

#include <iostream>
using namespace std;

void questionOne();
void questionTwo();
void questionThree();

int main()
{
    questionOne();
    return 0;
}

void questionOne()
{
    cout << "Hello, I’m a C++ program!" << endl;
    cout << "Do you like me? Please type yes or no." << endl;
    string answer;
    cin >> answer;
    if (answer == "yes")
    {
        cout << "That’s great! I’m sure we’ll get along." << endl;
    } else if (answer == "no") {
        cout << "Well, maybe you’ll learn to like me later." << endl;
    } else {
        cout << "If you’re not sure… that’s OK." << endl;
    }
}

void questionTwo()
{
    //Init vars
    string meal_name = "Carolina Reaper Burger";
    double meal_price = 5.99;
    int meal_count;
    double subtotal, tip, tax_amount, total;
    const double TAX_RATE = 0.07;

    //Take order
    cout << "Welcome to the restaurant" << endl;

    string diningAnswer;
    cout << "Please enter 1 if the order is dine in, 2 if it is to go: " << endl;
    cin >> diningAnswer;

    cout << "How many " << meal_name << " would you like?: ";
    cin >> meal_count;
    cout << "Prepping Order!" << endl;

    //Calc subtotal and total
    subtotal = meal_price * meal_count;
    tax_amount = subtotal * TAX_RATE;
    total = subtotal + tax_amount;
    double tip = meal_price * 0.15;

    //Print receipts
    cout << "-------------------------" << endl;
    cout << meal_name << " X " << meal_count << endl;

    if (diningAnswer == "1")
    {
        cout << "Tip: \t\t$" << tip << endl;
        subtotal += tip;
        total += tip;
    }

    cout << "SUBTOTAL: \t\t$" << subtotal << endl;
    cout << "Tax: \t\t\t$" << tax_amount << endl;
    cout << "-------------------------" << endl;
    cout << "Total: \t\t\t$" << total << endl;
    cout << "THANK YOU COME AGAIN" << endl << endl;
}

void questionThree()
{

}

void questionFour()
{

}