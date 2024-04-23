#pragma once

#include "character.h"
//#include "player.h"

using namespace std;

class Enemy : public Character
{
    public:
	Enemy(string name, int maxHealth, int atk, int defense, int spd);
	int attack(Character& x);
};
