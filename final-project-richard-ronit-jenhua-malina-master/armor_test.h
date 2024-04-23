#ifndef __ARMOR_TEST_H__
#define __ARMOR_TEST_H__

#include "gtest/gtest.h"

//Armor Tests
TEST(ArmorTest, getName) {
    Armor *armor = new Armor("armorName", "desc", 1, 10);
    EXPECT_EQ(armor->getName(), "armorName");
    delete armor;
}
TEST(ArmorTest, getDesc) {
    Armor *armor = new Armor("armorName", "desc", 1, 10);
    EXPECT_EQ(armor->getDesc(), "desc");
    delete armor;
}

TEST(ArmorTest, getItemCount) {
    Armor *armor = new Armor("armorName", "desc", 1, 10);
    EXPECT_EQ(armor->getItemCount(), 1);
    delete armor;
}

TEST(ArmorTest, getDefense) {
    Armor *armor = new Armor("armorName", "desc", 1, 10);
    EXPECT_EQ(armor->getDefense(), 10);
    delete armor;
}

TEST(ArmorTest, setDefense) {
    Armor *armor = new Armor("armorName", "desc", 1, 10);
    armor->setDefense(8);
    EXPECT_EQ(armor->getDefense(), 8);
    delete armor;
}
//----------------------------------------------------------------

#endif
