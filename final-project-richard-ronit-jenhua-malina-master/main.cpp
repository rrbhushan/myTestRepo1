#include <iostream>
#include <string>
#include <vector>
#include "item.h"
#include "bag.h"
#include "weapon.h"
#include "armor.h"
#include "player.h"
#include "room.h"
int main() {
	
	//CURRENT ISSUE: Everything in this file compiles fine, however there is a memory leak when adding Bag b2 into Bag b1
	
	//Initialize Player
	Player p1;	


	//Initializing Bag (b1) and Weapon (w1)
	Weapon* w1 = new Weapon("Sample Sword (Weapon)", "Desc", 1, 20);
	p1.bInventory = new Bag("Combat Pouch (Bag)", "Bag Desc", 1);

	//Insert Weapon w1 into Bag b1
	p1.bInventory->addToBag(w1);
	
	//Initializing Bag (b2) and Armor (a1)
	Bag* b2 = new Bag("Combat Pouch 2 (Bag)", "Bag Desc", 1);
	Armor* a1 = new Armor("Sample Shield (Armor)", "Desc", 1, 20);
	
	//Insert Armor a1 into Bag b2
        b2->addToBag(a1);
	//b2->addToBag(w1);
	//b2->rmFromBag(w1);

	//Insert Bag b2 into Bag b1
	p1.bInventory->addToBag(b2);
	
	//p1.bInventory->getBag().at(1)->addToBag(new Armor("Sample Shield (Armor)", "Desc", 1, 20));
	//p1.bInventory->getBag().at(1)->addToBag(new Weapon("Sample Shield (Armor)", "Desc", 1, 20));
	//Item* w4 = new Weapon("Sharp Sword (Weapon)", "This is a sharp sword.", 1, 50);
	//b2->addToBag(w4);
	
	p1.bInventory->print();			//Prints Bag b1 as a standard item (Quantity, Name, Desc)
        cout << endl << endl;
        p1.bInventory->printBag();			//Prints Bag b1 as a bag (Header, Contents)
        cout << endl << endl;
        p1.bInventory->vBag.at(1)->printBag();	//Prints Bag b2 as a bag while embedded inside of Bag b1
        cout << endl << endl;
	
	Item* w2; //Create ptr for future use

        for (int i = 0; i < p1.bInventory->vBag.size(); ++i) {
                if (p1.bInventory->vBag.at(i)->getName().find("Weapon") != string::npos) {	
			w2 = p1.bInventory->vBag.at(i);	//Locates a weapon inside of Bag b1, then stores address into w2
                        break;
                }
        }
	
        w2->print();					//Print Weapon w2 as an Item
        cout << endl << endl;

	//Print w2's unique attribute (Attack value)
	cout << w2->getName() << "'s attack stat: " << w2->getAttack() << endl << endl;

	Item* a2; //Create ptr for future use
	
	for (int i = 0; i < p1.bInventory->vBag.size(); ++i) {
               if (p1.bInventory->vBag.at(i)->getName().find("Bag") != string::npos) {
               		//Looks for a bag within Bag b1, then searches for an armor within the located bag
			for (int j = 0; j < p1.bInventory->vBag.at(i)->getBag().size(); ++j) {
				if (p1.bInventory->vBag.at(i)->getBag().at(j)->getName().find("Armor") != string::npos) {
					a2 = p1.bInventory->vBag.at(i)->getBag().at(j);	//Stores address of located armor into a2
					break;
				}
			}
                }
        }
	
	a2->print();                                    //Print Weapon w2 as an Item
	cout << endl << endl;
	
	//Print a2's unique attribute (Defense value)
	cout << a2->getName() << "'s defense stat: " << a2->getDefense() << endl << endl;
	
        //delete p1.bInventory;
	//delete b2;
	
	//delete p1;
	
	return 0;
}
