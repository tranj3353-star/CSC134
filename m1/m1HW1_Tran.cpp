#include <iostream>
using namespace std;

int main()
{
    string movieName = "\"Edge of Tomorrow\"";
    int yearReleased = 2014;
    double internationalGrossMillions = 280.8;

    cout << "The movie " << movieName << " came out in " << yearReleased << endl;
    cout << "It grossed $" << internationalGrossMillions << " Million internationally (excluding domestic)" << endl << endl;
    cout << "This movie is about Earth facing an alien invasion. The aliens have a secret time loop power. " << endl;
    cout << "The protagonist accidentally steals this power but has to activate it via death. " << endl;
    cout << "After looping hundreds of times in the same day, the protagonist and his friends finally kill the alien boss. " << endl << endl;

    cout << "Interesting Things: " << endl;
    cout << "Quote: " << "\"Battle is the Great Redeemer. \" - Sergeant Farell" << endl << endl;
    cout << "I love the scene where the protagonist is adamant that they won't be able to survive" << endl;
    cout << "with the current path they are taking, implying that he knows this because he looped " << endl;
    cout << "countless times. " << endl << endl;
    cout << "Quote: " << "\"I wish... I didn't know you. But I do. \" - William Cruise" << endl << endl;

    return 0;
}