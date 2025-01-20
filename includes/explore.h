#ifndef EXPLORE_H
#define EXPLORE_H

#include "commands.h"
#include "entities.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int currentCoordinates[3] = {2, 4, 12};
//								^- {"Room no", "x-coordinates", "y-coordinates"} ;
/*
    This above thing describes the way how i'm using coordinate system;
*/

int checkForEntities()
{
    doorsAssign();
    assign_Enemies();
    ini_Note();
    int def = 0;
    bool keyfound = false;
    for (int i = 0; i < 3; i++)
    {
        if (currentCoordinates[0] == doors[i].RoomNo &&
            currentCoordinates[1] == doors[i].xcoor &&
            currentCoordinates[2] == doors[i].ycoor)
        {
            cout << "Door found! Do you want to enter? ( y - Yes, n - No): ";
            char prompt;
            cin >> prompt;
            if (prompt == 'y')
            {
                if (i == 2)
                {
                    if (keyfound)
                    {
                        cout << "You have escaped the school! You Won!" << endl;
                        return 2;
                    }
                    else
                    {
                        cout << "You need a key to open this door!" << endl;
                        return 0;
                    }
                }
                else
                {
                    cout<<" This is door!";
                    return 0;  
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (currentCoordinates[0] == enemy[i].RoomNo &&
            currentCoordinates[1] == enemy[i].xcoor &&
            currentCoordinates[2] == enemy[i].ycoor)
        {
            cout << "You've Encountered an enemy! You lost!";
            return 1;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (currentCoordinates[0] == Note[i].noteInfo.RoomNo &&
            currentCoordinates[1] == Note[i].noteInfo.xcoor &&
            currentCoordinates[2] == Note[i].noteInfo.ycoor)
        {
            cout << "You've found a note! Do you want to read it? ( y - Yes, n - No): ";
            char prompt;
            cin >> prompt;
            if (prompt == 'y')
            {
                cout << Note[i].note << endl;
                return 0;
            }
            else
            {
                return 0;
            }
        }
    }
    if (!keyfound)
    {

        for (int i = 0; i < 3; i++)
        {
            if (currentCoordinates[0] == key.RoomNo &&
                currentCoordinates[1] == key.xcoor &&
                currentCoordinates[2] == key.ycoor)
            {
                cout << "You found a key!";
                keyfound = false;
                return 0;
            }
        }
    }
}

// For Exploration;
int exploreLogic(string direction, int steps)
{
    switch (currentCoordinates[0])
    {
    case 0: // Room = Garden (X: 0-35, Y: 0-20)
        if (direction == directions[0])
        { // LEFT
            if (currentCoordinates[2] - steps >= 0)
                currentCoordinates[2] -= steps;
            else
                cout << "OUT OF BOUND STEPS!\n";
        }
        else if (direction == directions[1])
        { // RIGHT
            if (currentCoordinates[2] + steps <= 35)
                currentCoordinates[2] += steps;
            else
                cout << "OUT OF BOUND STEPS!\n";
        }
        else if (direction == directions[2])
        { // FORWARD
            if (currentCoordinates[1] + steps <= 20)
                currentCoordinates[1] += steps;
            else
                cout << "OUT OF BOUND STEPS!\n";
        }
        else if (direction == directions[3])
        { // BACKWARD
            if (currentCoordinates[1] - steps >= 0)
                currentCoordinates[1] -= steps;
            else
                cout << "OUT OF BOUND STEPS!\n";
        }
        else
        {
            cout << "Invalid direction!\n";
        }
        break;

    case 1: // Room = Classroom (X: 0-42, Y: 0-25)
        if (direction == directions[0])
        { // LEFT
            if (currentCoordinates[2] - steps >= 0)
                currentCoordinates[2] -= steps;
            else
                cout << "OUT OF BOUND STEPS!\n";
        }
        else if (direction == directions[1])
        { // RIGHT
            if (currentCoordinates[2] + steps <= 42)
                currentCoordinates[2] += steps;
            else
                cout << "OUT OF BOUND STEPS!\n";
        }
        else if (direction == directions[2])
        { // FORWARD
            if (currentCoordinates[1] + steps <= 25)
                currentCoordinates[1] += steps;
            else
                cout << "OUT OF BOUND STEPS!\n";
        }
        else if (direction == directions[3])
        { // BACKWARD
            if (currentCoordinates[1] - steps >= 0)
                currentCoordinates[1] -= steps;
            else
                cout << "OUT OF BOUND STEPS!\n";
        }
        else
        {
            cout << "Invalid direction!\n";
        }
        break;

    case 2: // Room = Corridor (X: 0-12, Y: 0-54)
        if (direction == directions[0])
        { // LEFT
            if (currentCoordinates[2] - steps >= 0)
                currentCoordinates[2] -= steps;
            else
                cout << "OUT OF BOUND STEPS!\n";
        }
        else if (direction == directions[1])
        { // RIGHT
            if (currentCoordinates[2] + steps <= 12)
                currentCoordinates[2] += steps;
            else
                cout << "OUT OF BOUND STEPS!\n";
        }
        else if (direction == directions[2])
        { // FORWARD
            if (currentCoordinates[1] + steps <= 54)
                currentCoordinates[1] += steps;
            else
                cout << "OUT OF BOUND STEPS!\n";
        }
        else if (direction == directions[3])
        { // BACKWARD
            if (currentCoordinates[1] - steps >= 0)
                currentCoordinates[1] -= steps;
            else
                cout << "OUT OF BOUND STEPS!\n";
        }
        else
        {
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