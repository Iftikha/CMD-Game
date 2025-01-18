#ifndef EXPLORE_H
#define EXPLORE_H

#include "commands.h"
#include "entities.h"

using namespace std;

int currentCoordinates[3] = {2, 4, 12};
//								^- {"Room no", "x-coordinates", "y-coordinates"} ;
/*
	This above thing describes the way how i'm using coordinate system;
*/

int checkForEntities() {
    int def = 0; bool keyfound = false;
    // Check for notes
    for (int i = 0; i < 3; i++) {
        if (currentCoordinates[0] == Note[i].noteInfo.RoomNo &&
            currentCoordinates[1] == Note[i].noteInfo.ycoor &&
            currentCoordinates[2] == Note[i].noteInfo.xcoor) {
            cout << "You found a note: " << Note[i].noteInfo.entName << endl;
            cout << "Do you want to read the note? (y - Yes, n - No)";
            char prompt;cin>> prompt;
            if( prompt == 'y'){
                cout<<Note[i].note;
            }
                return def;
        }
    }

    // Check for enemies
    for (int i = 0; i < 3; i++) {
        if (currentCoordinates[0] == enemy[i].RoomNo &&
            currentCoordinates[1] == enemy[i].ycoor &&
            currentCoordinates[2] == enemy[i].xcoor) {
            cout << "You were caught by enemy! Beware next time!";
            def = 1;
            return def;
        }
    }

    // Check for doors
    for (int i = 0; i < 3; i++) {
        if (currentCoordinates[0] == doors[i].RoomNo &&
            currentCoordinates[1] == doors[i].ycoor &&
            currentCoordinates[2] == doors[i].xcoor) {
            cout << "You found a door! Do you want to enter? ( y - Yes, n - No)";
            char prompt;
            cin>>prompt;
            if(prompt == 'y'){
                if(doors[i].RoomNo == 0){
                    if(keyfound){
                        def = 2;
                        return def;
                    }
                }
                currentCoordinates[0] = doors[i].RoomNo;
            }
            return def;
        }
    }

    // Check for the key
    if (currentCoordinates[0] == key.RoomNo &&
        currentCoordinates[1] == key.ycoor &&
        currentCoordinates[2] == key.xcoor) {
        cout << "You found the key: " << key.entName << endl;
        cout << "This key might open the exit door." << endl;
        keyfound = true;
        return def;
    }
}


// For Exploration;
int exploreLogic(string direction, int steps) {
    switch (currentCoordinates[0]) {
        case 0: // Room = Garden (X: 0-35, Y: 0-20)
            if (direction == directions[0]) { // LEFT
                if (currentCoordinates[2] - steps >= 0)
                    currentCoordinates[2] -= steps;
                else
                    cout << "OUT OF BOUND STEPS!\n";
            } else if (direction == directions[1]) { // RIGHT
                if (currentCoordinates[2] + steps <= 35)
                    currentCoordinates[2] += steps;
                else
                    cout << "OUT OF BOUND STEPS!\n";
            } else if (direction == directions[2]) { // FORWARD
                if (currentCoordinates[1] + steps <= 20)
                    currentCoordinates[1] += steps;
                else
                    cout << "OUT OF BOUND STEPS!\n";
            } else if (direction == directions[3]) { // BACKWARD
                if (currentCoordinates[1] - steps >= 0)
                    currentCoordinates[1] -= steps;
                else
                    cout << "OUT OF BOUND STEPS!\n";
            } else {
                cout << "Invalid direction!\n";
            }
            break;

        case 1: // Room = Classroom (X: 0-42, Y: 0-25)
            if (direction == directions[0]) { // LEFT
                if (currentCoordinates[2] - steps >= 0)
                    currentCoordinates[2] -= steps;
                else
                    cout << "OUT OF BOUND STEPS!\n";
            } else if (direction == directions[1]) { // RIGHT
                if (currentCoordinates[2] + steps <= 42)
                    currentCoordinates[2] += steps;
                else
                    cout << "OUT OF BOUND STEPS!\n";
            } else if (direction == directions[2]) { // FORWARD
                if (currentCoordinates[1] + steps <= 25)
                    currentCoordinates[1] += steps;
                else
                    cout << "OUT OF BOUND STEPS!\n";
            } else if (direction == directions[3]) { // BACKWARD
                if (currentCoordinates[1] - steps >= 0)
                    currentCoordinates[1] -= steps;
                else
                    cout << "OUT OF BOUND STEPS!\n";
            } else {
                cout << "Invalid direction!\n";
            }
            break;

        case 2: // Room = Corridor (X: 0-12, Y: 0-54)
            if (direction == directions[0]) { // LEFT
                if (currentCoordinates[2] - steps >= 0)
                    currentCoordinates[2] -= steps;
                else
                    cout << "OUT OF BOUND STEPS!\n";
            } else if (direction == directions[1]) { // RIGHT
                if (currentCoordinates[2] + steps <= 12)
                    currentCoordinates[2] += steps;
                else
                    cout << "OUT OF BOUND STEPS!\n";
            } else if (direction == directions[2]) { // FORWARD
                if (currentCoordinates[1] + steps <= 54)
                    currentCoordinates[1] += steps;
                else
                    cout << "OUT OF BOUND STEPS!\n";
            } else if (direction == directions[3]) { // BACKWARD
                if (currentCoordinates[1] - steps >= 0)
                    currentCoordinates[1] -= steps;
                else
                    cout << "OUT OF BOUND STEPS!\n";
            } else {
                cout << "Invalid direction!\n";
            }
            break;

        default:
            cout << "Invalid room!\n";
            break;
    }

    int cont;
    // Check for entities after movement
    cont = checkForEntities();
    return cont;
}

#endif