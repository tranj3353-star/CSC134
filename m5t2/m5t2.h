#ifndef M5T2_H_INCLUDED
#define M5T2_H_INCLUDED

#include <iostream>
#include <fstream>
using namespace std;

int square(int num) {
    // input: a number
    // output: the number, squared
    int answer = num * num;
    return answer;
}

void print_table_line(int first, int second) {
    // input: two numbers
    // effect: prints a line with both numbers
    cout << first << "\t" << second << endl;
}

void write_squares_table(string filename, int start, int finish)
{
    ofstream outfile;
    outfile.open(filename);
    if (outfile)
    {
        for (int i = start; i <= finish; i++)
        {
            outfile << i << " " << square(i) << endl;
        }
        outfile.close();
        
    } else {
        cout << "COULD NOT OPEN!" << endl;
    }
}

void read_squares_table(string filename)
{
    ifstream infile;
    infile.open(filename);
    if (infile) {
        int num1, num2;
        while (infile >> num1 >> num2)
        {
            cout << num1 << "\t" << num2 << endl;
        }
    } else {
        cout << "ERROR: FILE NOT FOUND!" << endl;
    }
}

#endif // M5T2_H_INCLUDED