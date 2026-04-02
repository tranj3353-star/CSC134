#include "include/renderer.h"
#include "include/input.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

/*
To run you have to play the game file via console.
Go to File > Open Folder then open this folder.
Then in console enter ./game to run
*/

// ─── World State ─────────────────────────────────────────────────────────────
long long uninfected = 8000000000LL;
long long infected   = 0;
long long dead       = 0;
std::string name;

// ─── Disease Stats ────────────────────────────────────────────────────────────
int infectivity = 1;   // how fast it spreads
int lethality   = 0;   // how fast infected die
int visibility  = 0;   // how aware humans are (triggers cure)

int dnaPoints   = 3;   // currency for upgrades
int turn        = 0;
bool gameover   = false;
bool cureStarted = false;
int cureProgress = 0;  // 0–100

// ─── Forward Declarations ────────────────────────────────────────────────────
void intro();
void drawHeader();
void drawStats();
void drawMenu();
void doUpgrades();
void doTurn();
void checkWinLose();
void showEvent(const std::string& msg);
void gameLoop();

// ─── Main ─────────────────────────────────────────────────────────────────────
int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    intro();
    gameLoop();
    return 0;
}

// ─── Intro ────────────────────────────────────────────────────────────────────
void intro()
{
    renderer::clearScreen();
    renderer::drawBox(1, 1, 50, 10);
    renderer::drawText(4, 3,  "██████╗ ██╗      █████╗  ██████╗ ██╗   ██╗███████╗");
    renderer::drawText(4, 4,  "██╔══██╗██║     ██╔══██╗██╔════╝ ██║   ██║██╔════╝");
    renderer::drawText(4, 5,  "██████╔╝██║     ███████║██║  ███╗██║   ██║█████╗  ");
    renderer::drawText(4, 6,  "██╔═══╝ ██║     ██╔══██║██║   ██║██║   ██║██╔══╝  ");
    renderer::drawText(4, 7,  "██║     ███████╗██║  ██║╚██████╔╝╚██████╔╝███████╗");
    renderer::drawText(4, 8,  "╚═╝     ╚══════╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚══════╝");
    renderer::drawText(4, 10, "  A S C I I   D I S E A S E   S I M U L A T O R");
    renderer::drawText(4, 12, "You are a disease. Infect and kill all 8 billion humans.");
    renderer::drawText(4, 13, "Evolve before they find a cure!");
    renderer::drawText(4, 15, "Name your disease: ");
    renderer::present();

    // put cursor after prompt
    renderer::moveCursor(23, 15);
    name = input::getLine();

    renderer::clearScreen();
    renderer::drawText(4, 5, "A new pathogen emerges: [ " + name + " ]");
    renderer::drawText(4, 7, "Patient Zero has been infected...");
    renderer::present();
    renderer::delay(2000);

    infected   = 1;
    uninfected = 8000000000LL - 1;
}

// ─── Header / Stats ───────────────────────────────────────────────────────────
void drawHeader()
{
    renderer::drawHorizontalLine(1, 1, 60);
    renderer::drawText(1, 2, " PLAGUE: " + name);
    renderer::drawHorizontalLine(1, 3, 60);
}

void drawStats()
{
    renderer::drawText(1, 4,  " Uninfected : " + std::to_string(uninfected) + "        ");
    renderer::drawText(1, 5,  " Infected   : " + std::to_string(infected)   + "        ");
    renderer::drawText(1, 6,  " Dead       : " + std::to_string(dead)       + "        ");
    renderer::drawHorizontalLine(1, 7, 60);
    renderer::drawText(1, 8,  " Turn: " + std::to_string(turn) +
                              "   DNA Points: " + std::to_string(dnaPoints)  + "        ");
    renderer::drawText(1, 9,  " Infectivity: " + std::to_string(infectivity) +
                              "  Lethality: "  + std::to_string(lethality)   +
                              "  Visibility: " + std::to_string(visibility)  + "        ");

    if (cureStarted) {
        std::string bar = " Cure [";
        int filled = cureProgress / 5;
        for (int i = 0; i < 20; ++i)
            bar += (i < filled) ? '#' : '-';
        bar += "] " + std::to_string(cureProgress) + "%   ";
        renderer::drawText(1, 10, bar);
    } else {
        renderer::drawText(1, 10, " Cure: Not started              ");
    }
    renderer::drawHorizontalLine(1, 11, 60);
}

// ─── Menu ─────────────────────────────────────────────────────────────────────
void drawMenu()
{
    renderer::drawText(1, 13, " [E] Evolve (spend DNA)   [N] Next Turn   [Q] Quit");
    renderer::drawText(1, 14, " > ");
}

// ─── Upgrades Screen ──────────────────────────────────────────────────────────
void doUpgrades()
{
    bool done = false;
    while (!done) {
        renderer::clearScreen();
        drawHeader();
        renderer::drawText(1, 4, " DNA Points available: " + std::to_string(dnaPoints));
        renderer::drawHorizontalLine(1, 5, 60);
        renderer::drawText(1, 6,  " [1] +Infectivity  (cost 2) - spread faster");
        renderer::drawText(1, 7,  " [2] +Lethality    (cost 3) - kill faster");
        renderer::drawText(1, 8,  " [3] +Visibility   (cost 1) - risky, but boosts lethality");
        renderer::drawText(1, 9,  " [4] -Visibility   (cost 2) - stay hidden longer");
        renderer::drawText(1, 10, " [B] Back");
        renderer::drawHorizontalLine(1, 11, 60);
        renderer::drawText(1, 12, " Current -> Inf:" + std::to_string(infectivity) +
                                  " Let:" + std::to_string(lethality) +
                                  " Vis:" + std::to_string(visibility));
        renderer::drawText(1, 14, " Choice: ");
        renderer::present();

        char c = input::getChoice({'1','2','3','4','b'});

        if (c == 'b') { done = true; }
        else if (c == '1') {
            if (dnaPoints >= 2) { infectivity++; dnaPoints -= 2; showEvent("Infectivity increased!"); }
            else showEvent("Not enough DNA points!");
        }
        else if (c == '2') {
            if (dnaPoints >= 3) { lethality++; dnaPoints -= 3; showEvent("Lethality increased!"); }
            else showEvent("Not enough DNA points!");
        }
        else if (c == '3') {
            if (dnaPoints >= 1) { visibility++; dnaPoints -= 1; showEvent("Visibility raised - humans notice!"); }
            else showEvent("Not enough DNA points!");
        }
        else if (c == '4') {
            if (dnaPoints >= 2 && visibility > 0) { visibility--; dnaPoints -= 2; showEvent("Visibility reduced - staying hidden."); }
            else if (visibility == 0) showEvent("Visibility already at minimum!");
            else showEvent("Not enough DNA points!");
        }
    }
}

// ─── Event Flash ─────────────────────────────────────────────────────────────
void showEvent(const std::string& msg)
{
    renderer::clearScreen();
    drawHeader();
    renderer::drawBox(5, 5, 50, 5);
    renderer::drawText(7, 7, msg);
    renderer::drawText(7, 8, "Press any key...");
    renderer::present();
    input::getChoice({'y','n','e','b','1','2','3','4','q',' ','a','s','d','f','g','h','j','k','l','m','p','r','t','u','v','w','x','z','c','i','o'});
}

// ─── Turn Logic ───────────────────────────────────────────────────────────────
void doTurn()
{
    turn++;

    // ── Spread ──
    long long newInfections = 0;
    if (uninfected > 0 && infected > 0) {
        // base spread: infectivity * infected * random factor
        double spreadRate = infectivity * 0.02 + (std::rand() % 5) * 0.005;
        newInfections = static_cast<long long>(infected * spreadRate);
        // cap at remaining uninfected
        if (newInfections > uninfected) newInfections = uninfected;
        infected   += newInfections;
        uninfected -= newInfections;
    }

    // ── Deaths ──
    long long newDeaths = 0;
    if (lethality > 0 && infected > 0) {
        double deathRate = lethality * 0.01 + (std::rand() % 3) * 0.003;
        newDeaths = static_cast<long long>(infected * deathRate);
        if (newDeaths > infected) newDeaths = infected;
        dead    += newDeaths;
        infected -= newDeaths;
    }

    // ── DNA points from deaths/infections ──
    dnaPoints += 1 + (newDeaths > 0 ? 1 : 0) + (newInfections > 1000000LL ? 1 : 0);

    // ── Cure progress ──
    // Cure starts if visibility >= 3 or >25% of world infected
    double infectedFraction = static_cast<double>(infected + dead) / 8000000000.0;
    if (!cureStarted && (visibility >= 3 || infectedFraction > 0.25)) {
        cureStarted = true;
        showEvent("!! CURE RESEARCH HAS BEGUN !!");
    }
    if (cureStarted) {
        int cureSpeed = 2 + visibility;            // more visible = faster cure
        if (lethality > 3) cureSpeed += lethality; // killing too fast alerts scientists
        cureProgress += cureSpeed + (std::rand() % 3);
        if (cureProgress > 100) cureProgress = 100;
    }

    // ── Random events ──
    int roll = std::rand() % 20;
    if (roll == 0 && uninfected > 0)
        showEvent("Mutation! Bonus spread this turn.");
    else if (roll == 1 && cureStarted)
        showEvent("Setback in cure labs - progress slowed!");
    else if (roll == 2)
        showEvent("International travel spreads " + name + " further.");
}

// ─── Win / Lose Check ────────────────────────────────────────────────────────
void checkWinLose()
{
    // WIN: everyone is dead or infected (and no uninfected left)
    if (uninfected == 0 && infected == 0) {
        renderer::clearScreen();
        drawHeader();
        renderer::drawBox(5, 5, 50, 8);
        renderer::drawText(8, 7,  "  *** HUMANITY WIPED OUT ***");
        renderer::drawText(8, 8,  "  " + name + " has won.");
        renderer::drawText(8, 9,  "  Total dead: " + std::to_string(dead));
        renderer::drawText(8, 10, "  Turns taken: " + std::to_string(turn));
        renderer::drawText(8, 12, "  Game Over. Press Q to quit.");
        renderer::present();
        gameover = true;
        return;
    }

    // LOSE: cure complete
    if (cureProgress >= 100) {
        renderer::clearScreen();
        drawHeader();
        renderer::drawBox(5, 5, 50, 8);
        renderer::drawText(8, 7,  "  *** CURE FOUND! ***");
        renderer::drawText(8, 8,  "  Humanity defeats " + name + ".");
        renderer::drawText(8, 9,  "  Infected remaining: " + std::to_string(infected));
        renderer::drawText(8, 10, "  Dead: " + std::to_string(dead));
        renderer::drawText(8, 12, "  Game Over. Press Q to quit.");
        renderer::present();
        gameover = true;
        return;
    }

    // LOSE: disease burned out (everyone died before infecting all)
    if (infected == 0 && uninfected > 0 && lethality > 0) {
        renderer::clearScreen();
        drawHeader();
        renderer::drawBox(5, 5, 50, 7);
        renderer::drawText(8, 7,  "  *** DISEASE BURNED OUT ***");
        renderer::drawText(8, 8,  "  " + name + " killed its hosts too fast.");
        renderer::drawText(8, 9,  "  Survivors: " + std::to_string(uninfected));
        renderer::drawText(8, 11, "  Game Over. Press Q to quit.");
        renderer::present();
        gameover = true;
    }
}

// ─── Game Loop ────────────────────────────────────────────────────────────────
void gameLoop()
{
    while (!gameover) {
        renderer::clearScreen();
        drawHeader();
        drawStats();
        drawMenu();
        renderer::present();

        char choice = input::getChoice({'e','n','q'});

        if (choice == 'q') {
            renderer::clearScreen();
            renderer::drawText(1, 5, "Quitting... " + name + " fades into history.");
            renderer::present();
            renderer::delay(1500);
            break;
        }
        else if (choice == 'e') {
            doUpgrades();
        }
        else if (choice == 'n') {
            doTurn();
            checkWinLose();
        }
    }

    if (gameover) {
        // wait for quit
        input::getChoice({'q'});
    }
}