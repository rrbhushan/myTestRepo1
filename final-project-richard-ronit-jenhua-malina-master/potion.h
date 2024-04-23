#pragma once

#include "item.h"

using namespace std;

class Potion : public Item {
private:
        int attack;
        int defense;
        int health;
public:
        Potion(string n, string d, int i, int a, int df, int h);
        int getAttack() const  { return attack; }
        void setAttack(int a);
        int getDefense() const { return defense; }
        void setDefense(int df);
        int getHealth() const { return health; }
        void setHealth(int h);

};
