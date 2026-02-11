/*
CSC 134
M2HW1 - Gold
Justin Tran
2/11/26
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << setprecision(2) << fixed;

    cout << "---Question 1---" << endl;

    string name;
    string acct_num = "99081536";
    double balance, deposit, withdrawal, final_balance;
    cout << "Name?: ";
    getline(cin, name);
    cout << "Current Balance?: ";
    cin >> balance;
    cout << "Amount to Deposit?: ";
    cin >> deposit;
    cout << "Amount to Withdrawal?: ";
    cin >> withdrawal;

    final_balance = balance + deposit - withdrawal;

    cout << endl << endl << "Account Name: " << name << endl;
    cout << "Account Number: " << acct_num << endl;
    cout << "Final Balance: $" << final_balance << endl << endl;

    cout << "---Question 2---" << endl;

    //Initialize variables
    double length, width, height, volume; //Feet
    const double COST_PER_CUBIC_FOOT = 0.3;
    const double CHARGE_PER_CUBIC_FOOT = 0.52;
    double cost, customer_price, profit;

    //Inputs
    cout << "Crate Purchase Program" << endl;
    cout << "Enter the size of your crate" << endl;
    cout << "Length?: ";
    cin >> length;
    cout << "Width?: ";
    cin >> width;
    cout << "Height?: ";
    cin >> height;

    //Calculations
    volume = length * width * height;
    cost = volume * COST_PER_CUBIC_FOOT;
    customer_price = volume * CHARGE_PER_CUBIC_FOOT;
    profit = customer_price - cost;

    //Outputs
    cout << setprecision(2) << fixed;
    cout << "\n ----- Crate Info ----- \n";
    cout << "Volume: " << volume << " cubic ft. " << endl;
    cout << "Cost to make: $" << cost << endl;
    cout << "Retail price: $" << customer_price << endl;
    cout << "Profit:       $" << profit << endl << endl;

    cout << "---Question 3---" << endl;
    int pizza_ordered, slices_per_pizza, visitor_amount, pizza_remainder;

    cout << "How many pizzas ordered?: ";
    cin >> pizza_ordered;
    cout << "How many slices per pizza?: ";
    cin >> slices_per_pizza;
    cout << "How many visitors?: ";
    cin >> visitor_amount;

    pizza_remainder = pizza_ordered * slices_per_pizza - (visitor_amount * 3);
    cout << endl << "Number of leftovers: " << pizza_remainder << endl << endl;

    cout << "---Question 4---" << endl;

    return 0;
}