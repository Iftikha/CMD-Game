#include "includes/commands.h"
#include "includes/explore.h"
#include "includes/help.h"
#include "includes/room.h"
#include "includes/entities.h"

using namespace std;

void commandHandle(string inputCommand) {
    string command;
    string direction;
    string noofSteps;
    int step;

    istringstream iss(inputCommand);
    iss >> command;

    // Check for basic commands
    for (int i = 0; i < 2; i++) {
        if (command == basic_commands[i]) {
            if (command == "exit") {
                cout << "Exiting the game. Goodbye!" << endl;
                exit(0);
            }
            cout << "Game started. Explore and complete the quest!" << endl;
            return;
        }
    }

    // Check for exploration commands
    for (int i = 0; i < 2; i++) {
        if (command == explore_commands[i]) {
            iss >> direction >> noofSteps;
            try {
                step = stoi(noofSteps);
            } catch (exception& e) {
                cout << "Invalid number of steps. Please try again." << endl;
                return;
            }

            int cont = exploreLogic(direction, step);
            if (cont == 2) {
                cout << "You have escaped the school! You Won!" << endl;
                exit(0);
            } else if (cont == 1) {
                cout << "You Lose!" << endl;
                exit(0);
            }
            return;
        }
    }

    // Miscellaneous commands
    if (command == misc_commands[0]) {
        help();
        return;
    }

    if (command == misc_commands[1]) {
        cout << "=================== QUEST PAGE ====================" << endl;
        cout << "\nQuests:";
        cout << "\n\t - Escape the school!";
        return;
    }

    cout << "Unknown command. Type 'help' for a list of commands." << endl;
}

int main() {
    string inputCommand;
    cout << "Welcome to the game! Type 'start' to begin or 'help' for instructions." << endl;

    while (true) {
    	cout << "\n\t Current Room: " << currentCoordinates[0] << " \t Current Coordinates -> X: " << currentCoordinates[1] << " Y: " << currentCoordinates[2];
        cout << "\n> ";
        getline(cin, inputCommand);
		if(inputCommand == "exit"){
			break;
		}
        commandHandle(inputCommand);
    }
	cout << "\n=================================== THE END =========================================\n";

    return 0;
}
