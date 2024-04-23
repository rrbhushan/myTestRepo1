#include "character.h"

void Character::setAtk(int a) {
	atk = a;
}

void Character::setDefense(int d) {
	def = d;
}

void Character::setSpd(int s) {
	spd = s;
}


void Character::setMaxHealth(int h) {
	maxHealth = h;
}

void Character::setName(string n) {
	name = n;
}

void Character::setBoolDef(bool def) {
	BoolDef = def;
}

void Character::setDmgTaken(int d) {
	dmgTaken = d;
}

Character::Character() {
	setAtk(0);
	setDefense(0);
	setSpd(0);
	setMaxHealth(0);
	setName("name");
	setBoolDef(false);
	setDmgTaken(0);
}
Character::Character(string name, int maxHealth, int atk, int defense, int spd) {
	setAtk(atk);
	setDefense(defense);
	setSpd(spd);
	setMaxHealth(maxHealth);
	setName(name);
	setBoolDef(false);
	setDmgTaken(0);
}
