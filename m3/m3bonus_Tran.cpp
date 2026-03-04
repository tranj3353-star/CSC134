#include <iostream>
#include <cstdlib>   // for rand()
#include <ctime>     // for time() — used to seed random numbers
using namespace std;

// === GLOBAL GAME STATE ===
int worldPopulation = 7800;
int infected        = 1;
int dead            = 0;
int cureProgress    = 0;
int infectionRate   = 2;
int lethality       = 1;   // % of infected who die per turn
int cureSpeed       = 5;   // how many % cure advances per turn

// === HELPER: Random number between min and max (inclusive) ===
// Example: randomInt(1, 6) works like rolling a dice
int randomInt(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// === SHOW STATUS ===
void showStatus() {
    int healthy = worldPopulation - infected - dead;
    cout << "\n====== WORLD STATUS ======" << endl;
    cout << "Infected:      " << infected      << " million" << endl;
    cout << "Dead:          " << dead          << " million" << endl;
    cout << "Healthy:       " << healthy       << " million" << endl;
    cout << "Cure progress: " << cureProgress  << "%" << endl;
    cout << "Infection rate:" << infectionRate << "% per turn" << endl;
    cout << "Lethality:     " << lethality     << "% per turn" << endl;
    cout << "==========================" << endl;
}

// === RANDOM EVENTS ===
// Called once per turn with a chance of triggering
void randomEvent() {
    int roll = randomInt(1, 100);

    // 30% chance something happens each turn
    if (roll > 30) return;

    // Pick which event (1-5)
    int event = randomInt(1, 5);

    cout << "\n*** RANDOM EVENT ***" << endl;

    if (event == 1) {
        int boost = randomInt(5, 15);
        cureProgress += boost;
        cout << "Scientists make a breakthrough! Cure +" << boost << "%" << endl;

    } else if (event == 2) {
        int spike = randomInt(3, 8);
        infectionRate += spike;
        cout << "A superspreader event occurs! Infection rate +" << spike << "%" << endl;

    } else if (event == 3) {
        int deaths = randomInt(10, 50);
        dead += deaths;
        infected -= deaths;
        if (infected < 0) infected = 0;
        cout << "Hospital collapse! " << deaths << " million die suddenly." << endl;

    } else if (event == 4) {
        int slowdown = randomInt(3, 8);
        cureProgress -= slowdown;
        if (cureProgress < 0) cureProgress = 0;
        cout << "Lab fire destroys research! Cure -" << slowdown << "%" << endl;

    } else if (event == 5) {
        int lockdown = randomInt(1, 3);
        infectionRate -= lockdown;
        if (infectionRate < 1) infectionRate = 1;  // never goes below 1%
        cout << "Country goes into lockdown! Infection rate -" << lockdown << "%" << endl;
    }
}

// === PICK UPGRADE ===
void pickUpgrade() {
    cout << "\nChoose an upgrade:" << endl;
    cout << "1. Air transmission   — infection rate +3%" << endl;
    cout << "2. Drug resistance    — slow the cure by 8%" << endl;
    cout << "3. Increased lethality — death rate +2% (spreads fear, slows cure speed)" << endl;
    cout << "4. Symptom suppression — infected look healthy, slows cure by 5%" << endl;
    cout << "5. Skip turn" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        infectionRate += 3;
        cout << ">> Airborne mutation! Infection rate now " << infectionRate << "%" << endl;

    } else if (choice == 2) {
        cureProgress -= 8;
        if (cureProgress < 0) cureProgress = 0;
        cout << ">> Cure pushed back to " << cureProgress << "%" << endl;

    } else if (choice == 3) {
        lethality += 2;
        cureSpeed -= 1;
        if (cureSpeed < 1) cureSpeed = 1;
        cout << ">> More lethal now. Lethality: " << lethality << "%, Cure speed: " << cureSpeed << "%/turn" << endl;

    } else if (choice == 4) {
        cureProgress -= 5;
        if (cureProgress < 0) cureProgress = 0;
        cout << ">> Symptoms hidden. Cure set back to " << cureProgress << "%" << endl;

    } else if (choice == 5) {
        cout << ">> Turn skipped." << endl;

    } else {
        cout << ">> Unknown upgrade, turn skipped." << endl;
    }
}

// === ADVANCE TURN ===
void advanceTurn() {
    int healthy = worldPopulation - infected - dead;

    // Spread disease
    int newInfected = healthy * infectionRate / 100;
    infected += newInfected;

    // Kill some infected
    int newDead = infected * lethality / 100;
    dead += newDead;
    infected -= newDead;

    // Cure advances — with a small random wobble (+/- 2)
    int wobble = randomInt(-2, 2);
    cureProgress += cureSpeed + wobble;
    if (cureProgress < 0)   cureProgress = 0;
    if (cureProgress > 100) cureProgress = 100;  // BUG FIX: cap at 100!
}

// === CHECK GAME OVER ===
// Returns true if the game has ended (either win OR lose)
bool checkGameOver() {
    int healthy = worldPopulation - infected - dead;

    if (cureProgress >= 100) {
        cout << "\n╔══════════════════════════════╗" << endl;
        cout << "║  CURE COMPLETE — YOU LOSE!   ║" << endl;
        cout << "║  Humanity survives... for now.║" << endl;
        cout << "╚══════════════════════════════╝" << endl;
        cout << "Final death toll: " << dead << " million" << endl;
        return true;  // BUG FIX: was returning false before!
    }

    if (healthy <= 0 && infected <= 0) {
        cout << "\n╔══════════════════════════════╗" << endl;
        cout << "║  EXTINCTION — YOU WIN!       ║" << endl;
        cout << "║  No one left to save.        ║" << endl;
        cout << "╚══════════════════════════════╝" << endl;
        cout << "Final death toll: " << dead << " million" << endl;
        return true;
    }

    return false;
}

// === MAIN ===
int main() {
    // Seed the random number generator ONCE at the start
    // Without this, rand() gives the same sequence every run
    srand(time(0));

    cout << "=== PLAGUE INC LITE ===" << endl;
    cout << "Name your disease: ";
    string diseaseName;
    cin >> diseaseName;
    cout << "\n" << diseaseName << " has infected patient zero. The world has no idea yet.\n" << endl;

    int turn = 1;

    while (true) {
        cout << "\n--- TURN " << turn << " ---" << endl;
        showStatus();
        randomEvent();    // might trigger, might not
        pickUpgrade();
        advanceTurn();

        if (checkGameOver()) {
            break;
        }

        turn++;
    }

    return 0;
}