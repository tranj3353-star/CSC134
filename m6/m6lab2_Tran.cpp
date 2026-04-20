#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

enum Room { Bedroom, Kitchen, LivingRoom, Attic, Basement };

string roomName(Room r)
{
    switch (r)
    {
        case Bedroom: return "Bedroom";
        case Kitchen: return "Kitchen";
        case LivingRoom: return "Living Room";
        case Attic: return "Attic";
        case Basement: return "Basement";
    }
    return "Unknown";
}

string roomDesc(Room r)
{
    switch (r)
    {
        case Bedroom:
            return "A small starting room. There is a single door to the north.";
        case Kitchen:
            return "A narrow, slightly cluttered passage-like kitchen.";
        case LivingRoom:
            return "A central room connecting multiple parts of the house.";
        case Attic:
            return "A dusty attic filled with old forgotten items.";
        case Basement:
            return "A cold damp basement with a heavy atmosphere.";
    }
    return "";
}

unordered_map<int, unordered_map<string, int>> mapData = {
    {Bedroom,     {{"n", Kitchen}}},
    {Kitchen,      {{"s", Bedroom}, {"w", LivingRoom}}},
    {LivingRoom,   {{"n", Attic}, {"s", Basement}, {"e", Kitchen}}},
    {Attic,        {{"s", LivingRoom}}},
    {Basement,     {{"n", LivingRoom}}}
};

string normalize(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    if (s == "north") return "n";
    if (s == "south") return "s";
    if (s == "east")  return "e";
    if (s == "west")  return "w";

    return s;
}

void printMap(int current)
{
    cout << "\n--- MAP ---\n";
    for (auto &room : mapData)
    {
        cout << roomName((Room)room.first);

        if (room.first == current)
            cout << "  <-- YOU";

        cout << "\n";

        for (auto &dir : room.second)
        {
            cout << "  " << dir.first << " -> " << roomName((Room)dir.second) << "\n";
        }
    }
    cout << "-----------\n";
}

int main()
{
    int currentPos = Bedroom;
    string input;

    while (true)
    {
        cout << "\nYou are in: " << roomName((Room)currentPos) << "\n";
        cout << roomDesc((Room)currentPos) << "\n";

        printMap(currentPos);

        cout << "\nMove (N/S/E/W): ";
        cin >> input;

        input = normalize(input);

        if (mapData[currentPos].find(input) != mapData[currentPos].end())
        {
            currentPos = mapData[currentPos][input];
        }
        else
        {
            cout << "You hit a wall.\n";
        }
    }
}