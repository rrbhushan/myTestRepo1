#include <iostream>
#include "generateRooms.h"

void generateRooms(vector<Room>& allRooms, Player& p) {
	Room TOWN("TOWN",
		"*This entire TOWN is underground. The little bit of light and warmth that exists here is from man made fires. Most of the buildings look like they're falling apart and are covered in ash.",
		"*The OLD MAN I talked to is here.",
		"*There's a WELL to the right and it looks like someone is sitting by it, and there's a LAKE to the left",
		"I've heard rumors of at least one person making it out of here before... If you think you can fight your way to the top maybe you can get some answers to why all of this happened, but then again maybe there isn't a way out at all.It's honestly up to you, would you rather die trying to escape or try to have some sort of a life down here?\n",
		"Old Man: ",
		"*There's a RAPIER leaning against a wall",
		"RAPIER",1);
	TOWN.setConnectedRoom("WELL");
	TOWN.setConnectedRoom("LAKE");
	TOWN.bInventory = new Bag("Combat Pouch (Bag)", "Bag Desc", 1);
	Weapon* rapier = new Weapon("Rapier (Weapon)", "It's kind of rusty, but it looks like it would have been very beautiful in its heyday.\n          +10 Attack Power", 1, 10);
	TOWN.bInventory->addToBag(rapier);
	Room WELL("WELL",
		"*This WELL doesn't look like it is in good shape either. The bucket connected to it is leaking and there's even ash in the water.",
		"*There's a young girl sitting against the well. ",
		"*There's a CAVE ENTRANCE up ahead and the TOWN I came from is behind me",
		"Laura says I can't get any closer to the cave. She said it has big scary monsters there guarding the entrance to the next level... \n",
		"Young Girl: ",
		"*It looks like there two blue POTIONS are inside the bucket",
		"POTIONS",2);
	WELL.setConnectedRoom("TOWN");
	WELL.setConnectedRoom("CAVE ENTRANCE");
	WELL.bInventory = new Bag("Combat Pouch (Bag)", "Bag Desc", 1);
	Potion* pGD = new Potion("Potion of Greater Defense", "Triples Defense Stat for 1 Turn", 1, 1, 2, 0);
	Potion* pD = new Potion("Potion of Defense", "Doubles Defense Stat for 1 Turn", 1, 1, 3, 0);
	WELL.bInventory->addToBag(pGD);
	WELL.bInventory->addToBag(pD);
	Room LAKE("LAKE",
		"*Smaller fish have started to eat the mutated fish's corpse. The smell is awful.",
		"",
		"*There's a CAVE ENTRANCE up ahead and the TOWN I came from is behind me",
		"",
		"",
		"*The fish's stomach was ripped open durring the fight... It looks like there is an ARMOR set inside of it",
		"ARMOR",1);
	LAKE.setConnectedRoom("TOWN");
	LAKE.setConnectedRoom("CAVE ENTRANCE");
	LAKE.bInventory = new Bag("Combat Pouch (Bag)", "Bag Desc", 1);
	Armor* a2 = new Armor("Medium Armor (Armor)", "It smells kind of bad, but the metal looks pretty sturdy.\n          +10 Defense Power", 1, 10);
	LAKE.bInventory->addToBag(a2);
	Room CAVEENTRANCE("CAVE ENTRANCE",
		"*The two gargoyles just look like normal broken statues now. I can hear a deep laughter coming from up ahead",
		"",
		"*There's a source of bright LIGHT up ahead. The WELL and the LAKE are behind me outside the cave.",
		"",
		"",
		"*one of gargoyles had a pouch... there's two yellow POTIONS inside of it",
		"POTIONS", 2);
	CAVEENTRANCE.setConnectedRoom("WELL");
	CAVEENTRANCE.setConnectedRoom("LAKE");
	CAVEENTRANCE.setConnectedRoom("LIGHT");
	CAVEENTRANCE.bInventory = new Bag("Combat Pouch (Bag)", "Bag Desc", 1);
	Potion* pGA = new Potion("Potion of Greater Attack", "Triples Attack Stat for 1 Turn", 1, 1, 3, 0);
	Potion* pA = new Potion("Potion of Attack", "Doubles Attack Stat for 1 Turn", 1, 1, 2, 0);
	CAVEENTRANCE.bInventory->addToBag(pGA);
	CAVEENTRANCE.bInventory->addToBag(pA);
	Room LIGHT("LIGHT",
		"*The cave walls suddenly transitioned into what looks like the entrance of an elborate castle. I thought I killed the monster... but there is no body",
		"",
		"*There's a long STAIRWAY in front of me. The cave entrance is behind me",
		"",
		"",
		"*There's an armor and weapon SET displayed on a wall",
		"SET", 2);
	LIGHT.setConnectedRoom("CAVE ENTRANCE");
	LIGHT.bInventory = new Bag("Combat Pouch (Bag)", "Bag Desc", 1);
	Weapon* mS = new Weapon("Mysterious Sword (Weapon)", "The long black blade glistens in the light.\n          +20 Attack Power", 1, 20);
	Armor* mA = new Armor("Mysterious Armor (Armor)", "An all black suit of armor. The helmet completely hides your face\n          +20 Defense Power", 1, 20);
	LIGHT.bInventory->addToBag(mS);
	LIGHT.bInventory->addToBag(mA);
	allRooms.push_back(TOWN);
	allRooms.push_back(WELL);
	allRooms.push_back(LAKE);
	allRooms.push_back(CAVEENTRANCE);
	allRooms.push_back(LIGHT);
	p.move(TOWN);
}
