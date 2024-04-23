#pragma once

#include <string>
#include <iostream>
#include "item.h"

using namespace std;

class Weapon : public Item {
public:
    int getAttack();
    void setAttack(int atk);
    Weapon(string n = "", string d = "", int i = 1, int atk = 0);
    //~Weapon() {} 
private:
    int attack;
};

