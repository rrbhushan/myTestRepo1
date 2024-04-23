#include "gtest/gtest.h"

#include "item.h"
#include "weapon.h"
#include "weapon.cpp"
#include "armor.h"
#include "armor.cpp"
#include "potion.h"
#include "potion.cpp"
#include "bag.h"
#include "bag.cpp"
#include "character.h"
#include "character.cpp"
#include "Enemy.h"
#include "Enemy.cpp"
#include "player.h"
#include "player.cpp"
#include "room.h"
#include "room.cpp"

#include "weapon_test.h"
#include "armor_test.h"
#include "bag_test.h"
#include "potion_test.h"
#include "Enemy_test.h"
#include "room_test.h"
#include "player_test.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

