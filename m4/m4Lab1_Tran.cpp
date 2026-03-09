//M4LAB1 - Loop in a loop
//Justin Tran
// 3/9/26

#include <iostream>
using namespace std;

int main() {
    string emoji = "😭";
    int height = 100;
    int width = 50;

    cout << "Enter Height: ";
    cin >> height;
    cout << "Enter Width: ";
    cin >> width;
    
    for (size_t y = 0; y < height; y++)
    {
        for (size_t x = 0; x < width; x++)
        {
            cout << emoji;
        }
        cout << endl;
    }
    

    return 0;
}