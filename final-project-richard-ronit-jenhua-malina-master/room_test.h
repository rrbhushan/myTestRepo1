#ifndef __ROOM_TEST_H__
#define __ROOM_TEST_H__

TEST(RoomTest, getName) {
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

	EXPECT_EQ(TOWN.getName(),"TOWN");
	delete TOWN.bInventory;
}

TEST(RoomTest, getDescription) {
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

        EXPECT_EQ(TOWN.getDescription(),"*This entire TOWN is underground. The little bit of light and warmth that exists here is from man made fires. Most of the buildings look like they're falling apart and are covered in ash.");
        delete TOWN.bInventory;
}

TEST(RoomTest, getNPCsAvailable) {
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

        EXPECT_EQ(TOWN.getNPCsAvailable(),"*The OLD MAN I talked to is here.");
        delete TOWN.bInventory;
}

TEST(RoomTest, getLocationsAvailable) {
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

        EXPECT_EQ(TOWN.getLocationsAvailable(),"*There's a WELL to the right and it looks like someone is sitting by it, and there's a LAKE to the left");
        delete TOWN.bInventory;
}

TEST(RoomTest, getNPCDialogue) {
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

        EXPECT_EQ(TOWN.getNPCDialogue(),"I've heard rumors of at least one person making it out of here before... If you think you can fight your way to the top maybe you can get some answers to why all of this happened, but then again maybe there isn't a way out at all.It's honestly up to you, would you rather die trying to escape or try to have some sort of a life down here?\n");
        delete TOWN.bInventory;
}

TEST(RoomTest, getNPCName) {
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

        EXPECT_EQ(TOWN.getNPCName(),"Old Man: ");
        delete TOWN.bInventory;
}


#endif
