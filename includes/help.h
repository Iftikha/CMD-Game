#ifndef __HELP__H__
#define __HELP__H__

#include <iostream>
#include "commands.h"
using namespace std;

void help(){
     cout << "==================== HELP PAGE ====================" << endl;
    
    // Basic Commands
    cout << "\nBasic Commands:" << endl;
    cout << "1. start  - Starts the game." << endl;
    cout << "2. exit   - Exits the game." << endl;

    // Navigation Commands
    cout << "\nNavigation Commands:" << endl;
    cout << "1. look   - Look around your current location." << endl;
    cout << "2. move   - Move in a specified direction." << endl;
    cout << "   Format: move <direction> <number of steps>" << endl;
    cout << "   Directions: left, right, forward, backward" << endl;

    // Miscellaneous Commands
    cout << "\nMiscellaneous Commands:" << endl;
    cout << "1. help   - Displays this help page." << endl;
    cout << "2. quest  - Displays your current quest information." << endl;

    cout << "===================================================" << endl;
}

void instructions(){
    cout << "Welcome to the School Escape Game!" << endl;
    cout << "\nHere are your instructions:" << endl;
    cout << "1. Navigate through the areas: Classroom, Corridor, and Garden." << endl;
    cout << "2. Look for notes to uncover clues about what's happening." << endl;
    cout << "3. Use the 'move' command to move in the area." << endl;
    cout << "4. Be careful! There are dangers lurking in the shadows." << endl;
    cout << "5. Find the key in the garden to unlock the exit door and escape." << endl;
    cout << "6. If you're atuck with commands use 'help' command to help you out." << endl;
    cout << "\nGood luck and stay safe!" << endl;
}


#endif  //!__HELP__H__