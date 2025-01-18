#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

struct room
{
	string roomName;
	int roomW; // X-coordinate
	int roomL; // Y-Coordinate
};

room Rooms[3];

void roomsDesign(){
	// Garden i.e ROOM 1;
	Rooms[0].roomName = "Garden";
	Rooms[0].roomL = 20; // Y-Coordinate
	Rooms[0].roomW = 35; // X-Coordinate

	// Classroom i.e ROOM 2;
	Rooms[1].roomName = "Classroom";
	Rooms[1].roomL = 25; // Y-Coordinate
	Rooms[1].roomW = 42; // X-Coordinate

	// Coridoor i.e ROOM 3;
	Rooms[2].roomName = "Coridoor";
	Rooms[2].roomL = 54; // Y-Coordinate
	Rooms[2].roomW = 12; // X-Coordinate
}

#endif