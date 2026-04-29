/*
Justin Tran
4/29/26
m7t2 - pointers
GOLD
*/

using namespace std;
#include <iostream>
#include "Rectangle.h"

string setName();
void setName(string& name);

int main()
{
    string name = "Bob";
    string* pName = &name;

    setName(name);

    cout << "name: " << name << endl;
    cout << "pName: " << pName << endl;
    cout << "*pName: " << *pName << endl;

    Rectangle r1 = Rectangle();
    double w, l;
    cout << "Enter width, length seperated by space: ";
    cin >> w >> l;
    r1.setWidth(w);
    r1.setLength(l);
    cout << "Area: " << r1.getArea() << endl;
    r1.drawRect();
}

string setName()
{
    string name;
    cout << "Enter name: ";
    cin >> name;
    return name;
}

void setName(string& name)
{
    cout << "Enter Name: ";
    cin >> name;
}