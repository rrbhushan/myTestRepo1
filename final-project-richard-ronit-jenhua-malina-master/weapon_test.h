#ifndef __WEAPON_TEST_H__
#define __WEAPON_TEST_H__

#include "gtest/gtest.h"

//Weapon Tests
TEST(WeaponTest, getName) {
    Weapon *weapon = new Weapon("weaponName", "desc", 1, 10);
    EXPECT_EQ(weapon->getName(), "weaponName");
    delete weapon;
}

TEST(WeaponTest, getDesc) {
    Weapon *weapon = new Weapon("weaponName", "desc", 1, 10);
    EXPECT_EQ(weapon->getDesc(), "desc");
    delete weapon;
}

TEST(WeaponTest, getItemCount) {
    Weapon *weapon = new Weapon("weaponName", "desc", 1, 10);
    EXPECT_EQ(weapon->getItemCount(), 1);
    delete weapon;
}

TEST(WeaponTest, getAttack) {
    Weapon *weapon = new Weapon("weaponName", "desc", 1, 10);
    EXPECT_EQ(weapon->getAttack(), 10);
    delete weapon;
}

TEST(WeaponTest, setAttack) {
    Weapon *weapon = new Weapon("weaponName", "desc", 1, 10);
    weapon->setAttack(8);
    EXPECT_EQ(weapon->getAttack(), 8);
    delete weapon;
}
//----------------------------------------------------------------

#endif
