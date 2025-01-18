#ifndef ENTITIES_H
#define ENTITIES_H

#include <iostream>

using namespace std;

struct entity
{
	int ycoor;
	int xcoor;
	string entName;
	int RoomNo;
};

struct notes
{
	entity noteInfo;
	string note;
};

// Left notes;

notes Note[3];

void ini_Note(){
	// Note 1: About the school;
	Note[0].noteInfo.entName = "Note by a girl";
	Note[0].noteInfo.RoomNo = 1;
	Note[0].noteInfo.xcoor = 36;
	Note[0].noteInfo.ycoor = 20;
	Note[0].note = "\"They're everywhere. The bullies, the whispers, the shadows that follow you down the halls. I've started calling them the 'Hall Stalkers.'\nThey hide in plain sight, waiting for you to drop your guard. The worst is their leader, the one with the sharpest tongue and the meanest glare.\nAvoid the cafeteria after noon, the storage room on the first floor, and never stay near the lockers too long. If you hear footsteps when no one's around, run.\nThis place isn't safe anymore.\"\n — S.";

	// Note 2: Story of one boy;
	Note[1].noteInfo.entName = "They are monsters";
	Note[1].noteInfo.RoomNo = 1;
	Note[1].noteInfo.xcoor = 21;
	Note[1].noteInfo.ycoor = 14;
	Note[1].note = "\"They're not human. I saw it with my own eyes. They dragged him into the storage room, laughing like it was some kind of game.\nWhen I found him... his eyes were still open, but there was nothing left in them. Just emptiness.\nThey're monsters—real monsters hiding in plain sight, wearing the faces of classmates.\nI don't know how much longer I can stay here. If you're reading this, don't trust anyone.\nThey'll come for you next.\"";

	// Note 3: Where is key to the door;
	Note[2].noteInfo.entName = "Keys of the exit door";
	Note[2].noteInfo.RoomNo = 0;
	Note[2].noteInfo.xcoor = 12;
	Note[2].noteInfo.ycoor = 5;
	Note[2].note = "\"I had it—the key to the exit door. But they were chasing me, and I couldn't hold onto it.\nI dropped it somewhere in the garden, near the old bench. I'm sorry.\nIf you're reading this, find the key before they do. It's the only way out of this nightmare.\nBe quiet. Be quick. And whatever you do, don't let them see you leave.\"";

}

// Enemies;

entity enemy[3];

void assign_Enemies(){
	// Enemy 01 the one in garden;
	enemy[0].entName = "Enemy";
	enemy[0].xcoor = 4;
	enemy[0].ycoor = 12;
	enemy[0].RoomNo = 0;

	// Enemy 02 the one in classroom;
	enemy[1].entName = "Enemy";
	enemy[1].RoomNo = 1;
	enemy[1].xcoor = 8;
	enemy[1].ycoor = 23;

	// Enemy 03 the one in cooridoor;
	enemy[2].entName = "Enemy";
	enemy[2].RoomNo = 2;
	enemy[2].xcoor = 12;
	enemy[2].ycoor = 7;
}

// Doors;

entity doors[3];
entity key; // Key for the exit door;

void doorsAssign(){
	// Door: Classroom - Coridoor;
	doors[0].entName = "Door";
	doors[0].RoomNo = 0;
	doors[0].xcoor = 42;
	doors[0].ycoor = 10;

	// Door: Coridoor - Garden;
	doors[1].entName = "Door";
	doors[1].RoomNo = 1;
	doors[1].xcoor = 12;
	doors[1].ycoor = 10;

	// Door: Garden - Exit;
	doors[2].entName = "Exit Door";
	doors[2].RoomNo = 2;
	doors[2].xcoor = 35;
	doors[2].ycoor = 12;

	// Key: For the Door 3 or Exit Door;
	key.entName = "Exit Door Key";
	key.RoomNo = 2;
	key.xcoor = 7;
	key.ycoor = 4;

}




#endif