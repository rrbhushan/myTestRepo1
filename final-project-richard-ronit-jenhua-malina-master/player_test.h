#ifndef __PLAYER_TEST_H__
#define __PLAYER_TEST_H__

#include "player.h"
#include "character.h"
//#include "player.cpp"
#include "generatePlayer.h"
#include "generateRooms.h"
#include "combat.h"
#include "Enemy.h"
#include "slowPrints.h"
#include "bag.h"
#include <iostream>
#include <climits>
using namespace std;


#include "gtest/gtest.h"



TEST(PlayerTest, attack) {
    Player* attacker = new Player();
    attacker->setName("");
    attacker->setMaxHealth(0);
    attacker->setAtk(20);
    attacker->setDefense(0);
    attacker->setSpd(0);
    attacker->setBoolDef(false);
    attacker->setDmgTaken(0);
    attacker->setCombatPt(0);
    Room r1 = Room();
    attacker->move(r1);
    Enemy target("Enemy", 100, 0, 10, 0);
    Room r2 = Room();
    attacker->attack(target);  // [ (50 - 10) / 50 ] * (2 * 20) = 32
    EXPECT_EQ(target.getDmgTaken(), 32);
    delete attacker;
}


TEST(PlayerTest, attackWithDefense) {
    Player* attacker = new Player();
    attacker->setName("");
    attacker->setMaxHealth(0);
    attacker->setAtk(20);
    attacker->setDefense(0);
    attacker->setSpd(0);
    attacker->setBoolDef(false);
    attacker->setDmgTaken(0);
    attacker->setCombatPt(0);
    Room r1 = Room();
    attacker->move(r1);
    Enemy target("target", 100, 0, 10, 0);
    target.setDmgTaken(0);
    target.setBoolDef(true);
    attacker->attack(target);  // [ (50 - 10) / 50 ] * (2 * 20) - 10  = 32
    EXPECT_EQ(target.getDmgTaken(), 22);
    delete attacker;
}


TEST(PlayerTest, GetAndSetName) {
    Player* attacker = new Player();
    attacker->setName("Yor");
    EXPECT_EQ(attacker->getName(), "Yor");
    delete attacker;
}

TEST(PlayerTest, GetAndSetMaxHealth) {
    Player* player = new Player();
    player->setMaxHealth(10000);
    EXPECT_EQ(player->getMaxHealth(), 10000);
    delete player;
}

TEST(PlayerTest, GetAndSetAtk) {
    Player* player = new Player();
    player->setAtk(50);
    EXPECT_EQ(player->getAtk(), 50);
    delete player;
}

TEST(PlayerTest, GetAndSetDefense) {
    Player* player = new Player();
    player->setDefense(5);
    EXPECT_EQ(player->getDefense(), 5);
    delete player;
}

TEST(PlayerTest, GetAndSetSpd) {
    Player* player = new Player();
    player->setSpd(1);
    EXPECT_EQ(player->getSpd(), 1);
    delete player;
}

TEST(PlayerTest, GetAndSetBoolDef) {
    Player* player = new Player();
    player->setBoolDef(false);
    EXPECT_EQ(player->getBoolDef(), false);
    delete player;
}

TEST(PlayerTest, GetAndSetDmgTaken) {
    Player* player = new Player();
    player->setDmgTaken(987);
    EXPECT_EQ(player->getDmgTaken(), 987);
    delete player;
}

TEST(PlayerTest, GetAndSetCombatPt) {
    Player* player = new Player();
    player->setSpd(15);
    player->setCombatPt(1+(player->getSpd()/5));
    EXPECT_EQ(player->getcombatPt(), 4);
    delete player;
}

TEST(PlayerTest, EquipArmor) {
    Player* player = new Player();
    player->setDefense(20);
    player->eqArmor(5);
    player->eqArmor(8);
    EXPECT_EQ(player->getDefense(), 28);
    delete player;
}

TEST(PlayerTest, EquipArmorObj) {
    Player* player = new Player();
    Armor a1("Broken Shield", "Broken Shield Desc", 1, 10);
    player->setDefense(20);
    player->eqArmor(a1);
    EXPECT_EQ(player->getDefense(), 30);

    Armor a2("Better Shield", "Better Shield Desc", 1, 20);
    player->eqArmor(a2);
    EXPECT_EQ(player->getDefense(), 40);
    delete player;
}

TEST(PlayerTest, EquipWeapon) {
    Player* player = new Player();
    player->setAtk(20);
    player->eqWeapon(5);
    player->eqWeapon(8);
    EXPECT_EQ(player->getAtk(), 28);
    delete player;
}

TEST(PlayerTest, EquipWeaponObj) {
    Player* player = new Player();
    Weapon w1("Dull Sword", "Dull Sword Desc", 1, 10);
    player->setAtk(20);
    player->eqWeapon(w1);
    EXPECT_EQ(player->getAtk(), 30);

    Weapon w2("Better Sword", "Better Sword Desc", 1, 20);
    player->eqWeapon(w2);
    EXPECT_EQ(player->getAtk(), 40);
    delete player;
}

TEST(PlayerTest, GetAndSetType) {
    Player* player = new Player();
    player->setType("BRUTE");
    EXPECT_EQ(player->getType(), "BRUTE");
    delete player;
}

TEST(PlayerTest, PlayerBag) {
    Player* player = new Player();
    player->bInventory = new Bag("Bag 1 (Bag)", "Bag 1 Desc", 1);
    Bag* b2 = new Bag("Bag 2 (Bag)", "Bag 2 Desc", 1);
    Armor* a1 = new Armor("Sample Shield (Armor)", "Desc", 5, 20);
    b2->addToBag(a1);
    player->bInventory->addToBag(b2);

    EXPECT_EQ(player->bInventory->vBag.at(0)->getBag().at(0)->getName(), "Sample Shield (Armor)");
    EXPECT_EQ(player->bInventory->vBag.at(0)->getBag().at(0)->getDesc(), "Desc");
    EXPECT_EQ(player->bInventory->vBag.at(0)->getBag().at(0)->getItemCount(), 5);
    EXPECT_EQ(player->bInventory->vBag.at(0)->getBag().at(0)->getDefense(), 20);
    delete player;
}

TEST(PlayerTest, SetAndGetLocation) {
    Player* player = new Player();
    Room r1("Room 1", "Room 1 desc", "NPC1", "Forest, Town", "Dialogue", "Ted", "Sword", "Good Sword", 4);
    player->move(r1);
    EXPECT_EQ(player->getLocation().getName(), "Room 1");
    delete player;
}

#endif

