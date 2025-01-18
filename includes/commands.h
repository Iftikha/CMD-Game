#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string basic_commands[2] = {"start", "exit"}; // REQUIRED FOR THE STARTUP OF THE GAME
string explore_commands[2] = {"look", "move"}; // NAVIGATION COMMANDS
string misc_commands[2] = {"help", "quest"}; // MISCELLANEOUS COMMANDS FOR THE IN-GAME HELP
string directions[4] = {"left", "right", "forward", "backward"}; /* These commands are nothing without navigation commands.
	format to write them: move left "no of steps"; */






#endif