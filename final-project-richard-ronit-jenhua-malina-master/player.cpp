#include "player.h"
#include "item.h"
#include <string>
using namespace std;

Player::Player() {
	type = "";
	weaponEq = 0;
	armorEq = 0;
}

void Player::setCombatPt(int c) {
    combatPt = c;
}

void Player::setType(string c) {
	type = c;
}

void Player::eqWeapon(Weapon& w) {
    atk = atk - weaponEq + w.getAttack();
    weaponEq = w.getAttack();

}

void Player::eqArmor(Armor& a) {
    def = def - armorEq + a.getDefense();
    armorEq = a.getDefense();
}

void Player::eqWeapon(int a) {
    atk = atk - weaponEq +a;
    weaponEq = a;
}

void Player::eqArmor(int d) {
    def = def - armorEq + d;
    armorEq = d;
}

void Player::move(Room &r)
{
	location = r;
}

int Player::attack(Character& x) {
    if (x.getBoolDef() == true) {
        int damageDone = ((int)(((50 - x.getDefense()) / 50.0) * (2*this->getAtk()))) - x.getDefense();
        if (damageDone > 0) {
            x.setDmgTaken(damageDone + x.getDmgTaken());
            x.setBoolDef(false);
            return damageDone;
        } else {
            x.setBoolDef(false);
            return 0;
        }
    } else {
        int damageDone1 = ((int)(((50 - x.getDefense()) / 50.0) * (2*this->getAtk())));
        x.setDmgTaken(damageDone1 + x.getDmgTaken());
        return damageDone1;
    }
} 

bool Player::usePotion(string potion) {
        for (int i = 0; i < bInventory->vBag.size(); i++)
        {
                if (bInventory->vBag.at(i)->getName() == "Combat Potion Pouch (Bag)")
                {
                        for (int j = 0; j < bInventory->vBag.at(i)->vBag.size(); i++)
                        {
                                if (bInventory->vBag.at(i)->vBag.at(j)->getName() == potion && (potion == "Potion of Healing" || potion == "Potion of Greater Healing"))
                                {
                                        setDmgTaken(getDmgTaken()-bInventory->vBag.at(i)->vBag.at(j)->getHealth());
					if (getDmgTaken() < 0)
					{
						setDmgTaken(0);
					}
					return true;
                                }
                                else if (bInventory->vBag.at(i)->vBag.at(j)->getName() == potion)
                                {
                                        setAtk(getAtk()*bInventory->vBag.at(i)->vBag.at(j)->getAttack());
                                        setDefense(getDefense()*bInventory->vBag.at(i)->vBag.at(j)->getDefense());
					return true;
                                }
                        }
                }
      }
      return false;	
}
