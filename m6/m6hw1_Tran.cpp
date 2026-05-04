/*
Justin Tran
5/4/26
M6HW1
GOLD
*/

#include <iostream>
#include <string>

using namespace std;

// Rooms
enum Room {
    START,
    HALLWAY,
    STORAGE,
    EXIT
};

int main() {
    Room currentRoom = START;

    bool hasKey = false;
    bool doorUnlocked = false;

    string input;

    cout << "Welcome to Escape Rooms!\n";

    while (true) {
        cout << "\n------------------\n";

        // ROOM DESCRIPTIONS
        if (currentRoom == START) {
            cout << "You are in a small room.\n";
            cout << "There is a sign: 'Find the key to escape.'\n";
            cout << "Exits: hallway\n";
        }
        else if (currentRoom == HALLWAY) {
            cout << "You are in a hallway.\n";
            cout << "There is a locked door and a path to storage.\n";
            cout << "Exits: start, storage, door\n";
        }
        else if (currentRoom == STORAGE) {
            cout << "You are in a storage room.\n";
            if (!hasKey)
                cout << "You see a key on the ground.\n";
            cout << "Exits: hallway\n";
        }

        // INPUT
        cout << "\nWhat do you do? ";
        cin >> input;

        // MOVEMENT
        if (input == "hallway" && currentRoom == START) {
            currentRoom = HALLWAY;
        }
        else if (input == "start" && currentRoom == HALLWAY) {
            currentRoom = START;
        }
        else if (input == "storage" && currentRoom == HALLWAY) {
            currentRoom = STORAGE;
        }
        else if (input == "hallway" && currentRoom == STORAGE) {
            currentRoom = HALLWAY;
        }

        // PICK UP KEY
        else if (input == "take" && currentRoom == STORAGE && !hasKey) {
            cout << "You picked up the key.\n";
            hasKey = true;
        }

        // UNLOCK DOOR
        else if (input == "unlock" && currentRoom == HALLWAY) {
            if (hasKey) {
                cout << "You unlock the door.\n";
                doorUnlocked = true;
            } else {
                cout << "You need a key.\n";
            }
        }

        // EXIT GAME
        else if (input == "door" && currentRoom == HALLWAY) {
            if (doorUnlocked) {
                cout << "\nYou escape! You win!\n";
                break;
            } else {
                cout << "The door is locked.\n";
            }
        }

        else {
            cout << "Invalid action.\n";
        }
    }

    return 0;
}