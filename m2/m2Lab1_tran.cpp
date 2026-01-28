/*
CSC 134
M2LAB1 - Crates
Justin Tran
1/28/26
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //Initialize variables
    double length, width, height, volume; //Feet
    const double COST_PER_CUBIC_FOOT = 0.23;
    const double CHARGE_PER_CUBIC_FOOT = 0.5;
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
    cout << "Profit:       $" << profit << endl;

    return 0;
}