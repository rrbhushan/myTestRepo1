#pragma once

#include <string>
#include <iostream>
#include "item.h"

using namespace std;

class Armor : public Item {
public:
    int getDefense();
    void setDefense(int df);
    Armor(string n = "", string d = "", int i = 1, int df = 0 );
    //~Armor(){ }
private:
    int defense;

};

