#include "room.h"

using namespace std;

Room::Room() {
    name = "";
}

Room::Room(string n, string d, string NPCA, string locA, string npcD, string npcN, string i, string iN, int NumOfItems) {
    name = n;
    description = d;
    NPCDialogue = npcD;
    NPCName = npcN;
    NPCsAvailable = NPCA;
    locationsAvailable = locA;
    itemsAvailable = i;
    itemName = iN;
    numOfItems = NumOfItems;
    itemsTaken = false;
    EnemyBeat = false;
}

void Room::setItemStatus(bool b) {
    itemsTaken = b;
}

void Room::setEnemyBeat(bool b) {
    EnemyBeat = b;
}

void Room::setName(string n) {
    name = n;
}

void Room::setConnectedRoom(string r) {
    connectedRooms.push_back(r);
}

void Room::setConnectedRooms(vector<string> cr) {
    for (int i = 0; i < cr.size(); ++i) {
        connectedRooms.push_back(cr.at(i));
    }
}

bool Room::validMove(string r) {
    for (int i = 0; i < connectedRooms.size(); ++i) {
        if (connectedRooms.at(i) == r) {
            return true;
        }
    }
    return false;
}
