/*
 * Phase Test 2 --- RPG Combat Encounter
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// ----------------------------
//  Parallel arrays --- each index represents one
//  enemy type across all three arrays
//  Do not modify these arrays, but you will read from them in
// ----------------------------
const int ENEMY_COUNT = 6;

string enemyNames[ENEMY_COUNT] = { "Goblin", "Skeleton", "Orc",
                                     "Troll",  "Dragon",   "Wraith" };
int    enemyHP[ENEMY_COUNT] = { 30, 25,  50,  70, 100, 40 };
int    enemyAttack[ENEMY_COUNT] = { 5,  4,   8,  10,  15,  7 };

// ----------------------------
//  Task 1 --- selectEnemy
//  Picks a random index into the parallel arrays
//  and writes the corresponding name, hp, and
//  attack values into the three output pointer
// 
// //  Key points:
//    - rand() % ENEMY_COUNT gives a valid index
//    - each pointer is dereferenced with * to
//      write back into the caller's variables
// ----------------------------
void selectEnemy(string* nameOut, int* hpOut, int* attackOut) {
    int idx = rand() % ENEMY_COUNT; // Done already for you.

    // START OF YOUR CODE
    
    // Write the enemy's name, HP, and attack values into the output parameters by dereferencing the pointers
    // END OF YOUR CODE

    * nameOut = enemyNames[idx];   //grab the enemey name 
    *hpOut = enemyHP[idx];     //pulling the match hpp
    * attackOut = enemyAttack[idx];  // get their attack start

    //idont know justis why its shows red line under
    // ohh my god i cleard 
}

// ----------------------------
//  Task 2 --- isDefeated
//  Dereferences hpPtr to read the current HP
//  and returns true if it has reached zero or
//  below.
// ----------------------------
bool isDefeated(int* hpPtr) {
    // START OF YOUR CODE
    // checking if the acutal healath numbers is 0 or les
    //using *hpptr so we check the value noth the memory adrs


    if (*hpPtr <= 0)
    {                    //yep theay are dead                      
        return true;

        // Return true if HP is zero or negative, false otherwise
        return false; // still alive 
    }
    // END OF YOUR CODE
}

// ----------------------------
//  Task 3 --- applyDamage
//  Subtracts damage from the HP value pointed
//  to by hpPtr, clamps it at zero, then writes
//  a formatted log message into logBuffer via
//  sprintf.
//
//  Expected format:
//    "<name> takes <damage> damage. HP remaining: <hp>"
// ----------------------------
void applyDamage(string name, int* hpPtr, int damage, char* logBuffer) {
    *hpPtr -= damage;

    // START OF YOUR CODE
    // HP must not fall below zero
    // END OF YOUR CODE


    if ( *hpptr < 0) {
        *hpptr = 0;// look 0 so it dosent go below level


        // Format a combat log message showing the target's name, damage taken, and remaining HP
        sprintf_s(logBuffer, 128, "%s takes %d damage. HP remaining: %d", name.c_str(), damage, *hpPtr);
    }
}

// ----------------------------
//  Provided --- Do not modify
// ----------------------------
void playEncounter() {
    string enemyName;
    int    enemyCurrentHP;
    int    enemyCurrentAttack;
    int    playerHP = 50;
    int    playerAttack = 8;
    char   logBuffer[128];


    selectEnemy(&enemyName, &enemyCurrentHP, &enemyCurrentAttack);


    cout << "A wild " << enemyName << " appears!" << endl;
    cout << "Enemy HP: " << enemyCurrentHP
        << "  Attack: " << enemyCurrentAttack << endl << endl;

    while (playerHP > 0 && !isDefeated(&enemyCurrentHP)) {
        // player attacks --- random damage in range [1, playerAttack]
        int dmg = (rand() % playerAttack) + 1;


        applyDamage(enemyName, &enemyCurrentHP, dmg, logBuffer);


        cout << logBuffer << endl;

        // enemy retaliates if still alive
        if (!isDefeated(&enemyCurrentHP)) {
            int eDmg = (rand() % enemyCurrentAttack) + 1;
            playerHP -= eDmg;
            if (playerHP < 0) playerHP = 0;
            cout << enemyName << " strikes back for " << eDmg
                << " damage. Player HP: " << playerHP << endl;
        }
        cout << endl;
    }

    if (isDefeated(&enemyCurrentHP)) {
        SetConsoleTextAttribute(hConsole, 10); // green
        cout << "Victory! You defeated the " << enemyName << "!\n\n" << endl;
        SetConsoleTextAttribute(hConsole, 7); // normal
    }
    else {
        SetConsoleTextAttribute(hConsole, 12); // red
        cout << "You were defeated...\n\n" << endl;
        SetConsoleTextAttribute(hConsole, 7); // normal
    }
}

int main() {
    srand((unsigned)time(NULL));

    // START OF YOUR CODE

    // Call playEncounter to run one combat encounter with a random enemy
    
     playEncounter(); // kick off the fight scean but 
     //i don know why its shows red line 

    // END OF YOUR CODE
    system("PAUSE");
    return 0;
}
