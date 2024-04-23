#ifndef __ENEMY_TEST_H__
#define __ENEMY_TEST_H__

#include "gtest/gtest.h"

TEST(EnemyTest, attack) {
    Enemy enemy = Enemy("enemyName", 100, 25, 20, 5);
    Enemy target = Enemy("target", 100, 10, 8, 5);
    enemy.attack(target);  // [ (50 - 8) / 50 ] * (2 * 25) = 42
    EXPECT_EQ(target.getDmgTaken(), 42);
}

TEST(EnemyTest, attackWithDefense) {
    Enemy enemy = Enemy("enemyName", 100, 25, 20, 5);
    Enemy target = Enemy("target", 100, 10, 8, 5);
    target.setBoolDef(true);
    enemy.attack(target);  // [ (50 - 8) / 50 ] * (2 * 25) - 8 = 34
    EXPECT_EQ(target.getDmgTaken(), 34);
}

TEST(EnemyTest, GetAndSetName) {
    Enemy enemy = Enemy("enemy", 100, 25, 20, 5);
    enemy.setName("Bird");
    EXPECT_EQ(enemy.getName(), "Bird");
}

TEST(EnemyTest, GetAndSetMaxHealth) {
    Enemy enemy = Enemy("enemy", 100, 25, 20, 5);
    enemy.setMaxHealth(75);
    EXPECT_EQ(enemy.getMaxHealth(), 75);
}

TEST(EnemyTest, GetAndSetAtk) {
    Enemy enemy = Enemy("enemy", 100, 25, 20, 5);
    enemy.setAtk(10);
    EXPECT_EQ(enemy.getAtk(), 10);
}

TEST(EnemyTest, GetAndSetDefense) {
    Enemy enemy = Enemy("enemy", 100, 25, 20, 5);
    enemy.setDefense(0);
    EXPECT_EQ(enemy.getDefense(), 0);
}

TEST(EnemyTest, GetAndSetSpd) {
    Enemy enemy = Enemy("enemy", 100, 25, 20, 5);
    enemy.setSpd(5);
    EXPECT_EQ(enemy.getSpd(), 5);
}

TEST(EnemyTest, GetAndSetBoolDef) {
    Enemy enemy = Enemy("enemy", 100, 25, 20, 5);
    enemy.setBoolDef(true);
    EXPECT_EQ(enemy.getBoolDef(), true);
}

TEST(EnemyTest, GetAndSetDmgTaken) {
    Enemy enemy = Enemy("enemy", 100, 25, 20, 5);
    enemy.setDmgTaken(1000);
    EXPECT_EQ(enemy.getDmgTaken(), 1000);
}

#endif
