#ifndef __POTION_TEST_H__
#define __POTION_TEST_H__

#include "gtest/gtest.h"

TEST(PotionTest, getAttack) {
    Potion *potion = new Potion("potionName", "desc", 1, 7, 8, 9);
    EXPECT_EQ(potion->getAttack(), 7);
    delete potion;
}

TEST(PotionTest, setAttack) {
    Potion *potion = new Potion("potionName", "desc", 1, 7, 8, 9);
    potion->setAttack(11);
    EXPECT_EQ(potion->getAttack(), 11);
    delete potion;
}

TEST(PotionTest, getDefense) {
    Potion *potion = new Potion("potionName", "desc", 1, 7, 8, 9);
    EXPECT_EQ(potion->getDefense(), 8);
    delete potion;
}

TEST(PotionTest, setDefense) {
    Potion *potion = new Potion("potionName", "desc", 1, 7, 8, 9);
    potion->setDefense(11);
    EXPECT_EQ(potion->getDefense(), 11);
    delete potion;
}

TEST(PotionTest, getHealth) {
    Potion *potion = new Potion("potionName", "desc", 1, 7, 8, 9);
    EXPECT_EQ(potion->getHealth(), 9);
    delete potion;
}

TEST(PotionTest, setHealth) {
    Potion *potion = new Potion("potionName", "desc", 1, 7, 8, 9);
    potion->setHealth(11);
    EXPECT_EQ(potion->getHealth(), 11);
    delete potion;
}



#endif //__POTION_TEST_H__
