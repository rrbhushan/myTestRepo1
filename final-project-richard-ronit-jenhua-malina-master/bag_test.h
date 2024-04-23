#ifndef __BAG_TEST_H__
#define __BAG_TEST_H__

#include "gtest/gtest.h"

#include "bag.h"
#include "weapon.h"
#include "armor.h"
#include "item.h"

using namespace std;

TEST(BagTest, TestName) {
	Bag* b1 = new Bag("Sample Bag (Bag)", "Sample Desc", 1);
	EXPECT_EQ(b1->getName(), "Sample Bag (Bag)");
	delete b1;
}

TEST(BagTest, TestDesc) {
	Bag* b1 = new Bag("Sample Bag (Bag)", "Sample Desc", 1);
	EXPECT_EQ(b1->getDesc(), "Sample Desc");
	delete b1;
}

TEST(BagTest, TestCount) {
	Bag* b1 = new Bag("Sample Bag (Bag)", "Sample Desc", 1);
	EXPECT_EQ(b1->getItemCount(), 1);
	delete b1;
}

TEST(BagTest, AddMultipleOfSameItem) {
	Bag* b1 = new Bag("Sample Bag (Bag)", "Sample Desc", 1);
	Weapon* w1 = new Weapon("Sample Sword (Weapon)", "Desc", 1, 20);
	Weapon* w2 = new Weapon("Sample Sword (Weapon)", "Desc", 2, 20);
	b1->addToBag(w1);
	b1->addToBag(w2);
	EXPECT_EQ(b1->vBag.at(0)->getName(), "Sample Sword (Weapon)");
	EXPECT_EQ(b1->vBag.at(0)->getDesc(), "Desc");
	EXPECT_EQ(b1->vBag.at(0)->getItemCount(), 3);
	EXPECT_EQ(b1->vBag.at(0)->getAttack(), 20);
	delete b1;
}

TEST(BagTest, CheckIfBagIsVector) {
	Bag* b1 = new Bag("Sample Bag (Bag)", "Sample Desc", 1);
	EXPECT_EQ(b1->vBag, b1->getBag());
	delete b1;
}

TEST(BagTest, RemoveItemTest) {
	Bag* b1 = new Bag("Sample Bag (Bag)", "Sample Desc", 1);
	Armor* a1 = new Armor("Sample Shield (Armor)", "Desc", 5, 20);
	Armor* a2 = new Armor("Sample Shield (Armor)", "Desc", 2, 20);
	b1->addToBag(a1);
	b1->rmFromBag(a2);
	EXPECT_EQ(b1->vBag.at(0)->getItemCount(), 3);

	Armor* a3 = new Armor("Sample Shield (Armor)", "Desc", 3, 20);
	b1->rmFromBag(a3);
	EXPECT_EQ(b1->vBag.size(), 0);
	
	delete a2;
	delete a3;
	delete b1;
}

TEST(BagTest, BagWithinBag) {
	Bag* b1 = new Bag("Bag 1 (Bag)", "Bag 1 Desc", 1);
	Bag* b2 = new Bag("Bag 2 (Bag)", "Bag 2 Desc", 1);
	Armor* a1 = new Armor("Sample Shield (Armor)", "Desc", 5, 20);
	b2->addToBag(a1);
	b1->addToBag(b2);

	EXPECT_EQ(b1->vBag.at(0)->getBag().at(0)->getName(), "Sample Shield (Armor)");
        EXPECT_EQ(b1->vBag.at(0)->getBag().at(0)->getDesc(), "Desc");
        EXPECT_EQ(b1->vBag.at(0)->getBag().at(0)->getItemCount(), 5);
        EXPECT_EQ(b1->vBag.at(0)->getBag().at(0)->getDefense(), 20);

	delete b1;
}

TEST(BagTest, RemoveItemInBagInBag) {
	Bag* b1 = new Bag("Bag 1 (Bag)", "Bag 1 Desc", 1);
	Bag* b2 = new Bag("Bag 2 (Bag)", "Bag 2 Desc", 1);
	Armor* a1 = new Armor("Sample Shield (Armor)", "Desc", 5, 20);
	Armor* a2 = new Armor("Sample Shield (Armor)", "Desc", 5, 20);

	b2->addToBag(a1);
	b1->addToBag(b2);

	b2->rmFromBag(a2);

	EXPECT_EQ(b1->vBag.at(0)->getBag().size(), 0);
        
	delete a2;
	delete b1;
}

#endif //__BAG_TEST_H__
