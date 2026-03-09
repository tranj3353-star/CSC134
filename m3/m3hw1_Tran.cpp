/*
CSC 134
M3HW1 - Questions
Justin Tran
2/25/26
GOLD
*/

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void questionOne();
void questionTwo();
void questionThree();
void questionFour();

int main()
{
    cout << setprecision(2) << fixed;

    questionOne();
    questionTwo();
    questionThree();
    questionFour();
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
    double subtotal, tax_amount, total;
    const double TAX_RATE = 0.07;

    //Take order
    cout << "Welcome to the restaurant" << endl;

    string diningAnswer;
    cout << "Please enter 1 if the order is dine in, 2 if it is to go: ";
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
        cout << "Tip: \t\t\t$" << tip << endl;
        subtotal += tip;
        total += tip;
    }

    cout << "SUBTOTAL: \t\t$" << subtotal << endl;
    cout << "Tax: \t\t\t$" << tax_amount << endl;
    cout << "-------------------------" << endl;
    cout << "Total: \t\t\t$" << total << endl;
    cout << "THANK YOU COME AGAIN" << endl << endl;
}




void choices(string choice0, string choice1)
{
    cout << "(0): " << choice0 << endl;
    cout << "(1): " << choice1 << endl << endl;
}

void intro()
{
    cout << "Scenario: " << endl;
    cout << "You're 3 months into a zombie apocalypse. You're with your family and your best friend's family." << endl;
    cout << "Your best friend confesses to you that he got bitten. " << endl << endl;
    choices("Inform the residents of your best friend's situation.",
            "Reassure your friend then kill him in his sleep.");
}

void dead_end_1()
{
    cout << "Death: His family panics and shoots you before you can explain." << endl;
}

void dead_end_2()
{
    cout << "Death: The smell attracts zombies. The house is overrun." << endl;
}

void dead_end_3()
{
    cout << "Death: You search the store and trigger a silent alarm. A swarm traps you inside." << endl;
}

void dead_end_4()
{
    cout << "Death: The strangers on the radio trace your signal. They're raiders." << endl;
}

void dead_end_5()
{
    cout << "Death: You refuse to open the gates in time. The herd breaks through." << endl;
}

void correct_choice_1()
{
    cout << "You do it. He goes peacefully in his sleep." << endl;
    cout << "Now you need to hide his body." << endl << endl;

    choices("Bury him secretly out past the treeline.",
            "Hide the body in the basement.");
}

void correct_choice_2()
{
    cout << "You bury him deep in the woods before dawn." << endl;
    cout << "On your way back, you spot a small herd heading toward the house." << endl << endl;

    choices("Search the nearby store for supplies before they arrive.",
            "Return home and warn everyone.");
}

void correct_choice_3()
{
    cout << "You rush back and warn everyone." << endl;
    cout << "Barricades go up. The herd pounds at the doors but can't get in." << endl;
    cout << "Food is running dangerously low now." << endl << endl;

    choices("Ration what little food remains.",
            "Make a supply run to the nearby grocery store.");
}

void correct_choice_4()
{
    cout << "You and two others carefully clear the grocery store." << endl;
    cout << "In the manager's office, you find a working radio broadcasting a survivor signal." << endl << endl;

    choices("Ignore the signal and focus on supplies.",
            "Respond to the signal cautiously.");
}

void correct_choice_5()
{
    cout << "You respond carefully, giving no exact location." << endl;
    cout << "The voice offers a secure camp with armed guards and farmland." << endl;
    cout << "After scouting it for days, you confirm it's real." << endl;
    cout << "Your group relocates safely." << endl << endl;
    cout << "You survived — for now." << endl;
}






void questionThree()
{
    int choice;
    intro();

    // Step 1 - correct: 1
    cout << "Enter your choice (0 or 1): ";
    cin >> choice;
    if (choice == 1) correct_choice_1();
    else { dead_end_1(); return;}

    // Step 2 - correct: 0
    cout << "Enter your choice (0 or 1): ";
    cin >> choice;
    if (choice == 0) correct_choice_2();
    else { dead_end_2(); return;}

    // Step 3 - correct: 1
    cout << "Enter your choice (0 or 1): ";
    cin >> choice;
    if (choice == 1) correct_choice_3();
    else { dead_end_3(); return;}

    // Step 4 - correct: 0
    cout << "Enter your choice (0 or 1): ";
    cin >> choice;
    if (choice == 0) correct_choice_4();
    else { dead_end_4(); return;}

    // Step 5 - correct: 1
    cout << "Enter your choice (0 or 1): ";
    cin >> choice;
    if (choice == 1) correct_choice_5();
    else { dead_end_5(); return;}
}

void questionFour()
{
    srand(time(0));
    int a = rand() % 10;
    int b = rand() % 10;
    int answer;

    cout << "What is " << a << " + " << b << "?" << endl;
    cout << "Answer: ";
    cin >> answer;

    if (answer == a + b)
    {
        cout << "Correct!" << endl;
    } else {
        cout << "Wrong!" << endl;
    }
}