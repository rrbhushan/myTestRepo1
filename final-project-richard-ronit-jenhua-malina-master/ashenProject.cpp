#include "generatePlayer.h"
#include "generateRooms.h"
#include "combat.h"
#include "Enemy.h"
#include "player.h"
#include "slowPrints.h"
#include "bag.h"
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    Player p;
    GeneratePlayer(p);
    vector<Room> allRooms;
    generateRooms(allRooms, p);



    cout << "Old Man: ";
    slowStringPrint("There's a mutated fish in the LAKE if you would like an easy target to test your blade on, or if you are thirsty and not looking for a fight right now you can check out our WELL.\n", "Old Man: ");
    cout << "Old Man: ";
    slowStringPrint("Oh, and I have picked up on alchemy during my time here. I'm putting some health potions in your backpack.\n", "Old Man: ");
    cout << "\n         ***Type 'HELP' at anytime for a list of available options*** \n";
    string input = "";
    string locationToGoTo = "";
    string itemToPickUp;
    string itemToEquip;
    int roomPos = 0;
    cin.ignore(INT_MAX, '\n');
    while (input != "STOP") {
        cout << p.getName() << ": ";
        getline(cin, input);
        if (input == "HELP") {
            cout << "        *** Type in all caps, exactly as the command is written ***\n";
            cout << "             *LOOK AROUND - Gives a description of your surroundings, NPCS you can talk to, items you can pick up, places you can go to.\n";
            cout << "             *MOVE TO <area listed in LOOK AROUND> - Moves you to an area that was described in all caps from LOOK AROUND\n";
            cout << "             *TALK - Talk to NPC in current location\n";
            cout << "             *BACKPACK - Look at inventory\n";
            cout << "             *PICK UP <item listed in LOOK AROUND> - adds items in current location to inventory\n";
            cout << "             *EQUIP <item listed in BACKPACK> - stats are changed depening on what weapon and armor you have equipped\n";
            cout << "             *STATS - See current player stats like attack and defense\n";
        }
        else if (input == "LOOK AROUND") {
            cout << "         ";
            slowStringPrint(p.getLocation().getDescription(), "         ");
            if (!(allRooms.at(roomPos).getItemStatus())) {
                cout << "\n         ";
                slowStringPrint(p.getLocation().getItemsAvailable(), "         ");
            }
            if (allRooms.at(roomPos).getNPCDialogue() != "") {
                cout << "\n         ";
                slowStringPrint(p.getLocation().getNPCsAvailable(), "         ");
            }
            cout << "\n         ";
            slowStringPrint(p.getLocation().getLocationsAvailable(), "         ");
            cout << endl;
        }
        else if (input == "TALK") {
            cout << p.getLocation().getNPCName();
            slowStringPrint(p.getLocation().getNPCDialogue(), p.getLocation().getNPCName());
            cout << endl;
        }
        else if (input.find("MOVE TO ") == 0) {
            locationToGoTo = input.substr(8);
            if (p.getLocation().validMove(locationToGoTo)) {
                for (int i = 0; i < allRooms.size(); ++i) {
                    if (allRooms.at(i).getName() == locationToGoTo) {
                        p.move(allRooms.at(i));
                        roomPos = i;
                        if (p.getLocation().getName()=="LAKE" && !(allRooms.at(roomPos).getEnemyBeat())) {
                            Enemy e = Enemy("Mutated Fish", 100, 10, 10, 1);
			    bool c1 = combat(p, e);
                            if(c1 == false) {
				goto END;
			    }
                            allRooms.at(roomPos).setEnemyBeat(true);
                        }else if (p.getLocation().getName() == "CAVE ENTRANCE" && !(allRooms.at(roomPos).getEnemyBeat())) {
                            Enemy e1 = Enemy("Gargoyle", 100, 15, 15, 5);
			    bool c2 = combat(p, e1);
                            if(c2 == false) {
				goto END;
			    }
                            Enemy e2 = Enemy("Twinned Gargoyle", 150, 20, 20, 10);
			    bool c3 = combat(p, e2);
                            if(c3 == false) {
				goto END;
			    }
                            allRooms.at(roomPos).setEnemyBeat(true);
                        }else if (p.getLocation().getName() == "LIGHT" && !(allRooms.at(roomPos).getEnemyBeat())) {
                            Enemy b = Enemy("Vampire", 250, 25, 25, 20);
			    bool c4 = combat(p, b);
                            if(c4 == false) {
				goto END;
			    }
                            allRooms.at(roomPos).setEnemyBeat(true);
                        }
                    }
                }
                cout << p.getName() << ": ";
                slowStringPrint("I went to the " + p.getLocation().getName(), p.getName() + ": ");
                cout << endl;
            }
            else if (p.getLocation().getName() == locationToGoTo) {
                cout << p.getName() << ": I'm already at the " << locationToGoTo << endl;
            }
            else { cout << "        *** Not a valid place to go to! ***\n"; }
        }
        else if (input.find("PICK UP ") == 0) {
            itemToPickUp = input.substr(8);
            if (p.getLocation().getItemName()==itemToPickUp) {
                if (!(allRooms.at(roomPos).getItemStatus())) {
                    for (int i = 0; i < p.getLocation().getNumOfItemsInRoom(); ++i) {
                        p.bInventory->addToBag(p.getLocation().bInventory->vBag.at(i));
			p.getLocation().bInventory->vBag.at(i) = nullptr;
                    }
                    bool ItemsPickedUp = true;
                    allRooms.at(roomPos).setItemStatus(true);
                    if (allRooms.at(roomPos).getItemStatus()) { cout << p.getName()<< ": I picked up the " << itemToPickUp<<"\n"; }
                }
                else { cout << p.getName() << ": I already picked that up.\n"; }
            }
            else {
                cout << "        *** Not a recognized item! ***\n";
            }
        }
        else if (input == "BACKPACK") {
            p.bInventory->printBag();
        }
        else if (input.find("EQUIP ") == 0) {
            itemToEquip = input.substr(6);
            for (int i = 0; i < p.bInventory->vBag.size(); ++i) {
                if (itemToEquip == p.bInventory->vBag.at(i)->getName()) {
                    if (itemToEquip.find("Armor") != string::npos) {
                        p.eqArmor(p.bInventory->vBag.at(i)->getDefense());
                        cout << p.getName() << ": I equipped the " << p.bInventory->vBag.at(i)->getName()<<endl;
                    }
                    else if (itemToEquip.find("Weapon") != string::npos) {
                        cout << "it a weapon\n";
                        p.eqWeapon(p.bInventory->vBag.at(i)->getAttack());
                        cout << p.getName() << ": I equipped the " << p.bInventory->vBag.at(i)->getName()<<endl;
                    }
                    else { cout << "        *** Not an equipable item! ***\n"; }
                }
            }

        }
        else if (input == "STATS") {
            cout << "        *Health: " << p.getMaxHealth() << endl;
            cout << "        *Attack Power: " << p.getAtk() << endl;
            cout << "        *Defense Power: " << p.getDefense() << endl;
            cout << "        *Speed: " << p.getSpd() << endl; 
        }
      
        else {
            cout << "         *** Not a valid command! Type HELP for a list of available commands. ***\n";
        }

    }
    END: 
    for (int i = 0; i < allRooms.size(); i++)
    {
	delete allRooms.at(i).bInventory;
    }   

}
