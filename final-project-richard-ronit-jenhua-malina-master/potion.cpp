#include "potion.h"
#include <string>
#include <iostream>

using namespace std;

Potion::Potion(string n = "", string d = "", int i = 1, int a = 1, int df = 1, int h = 0) : Item(n, d, i) {
        attack = a;
        defense = df;
        health = h;
}

void Potion::setAttack(int a)
{
        attack = a;
}

void Potion::setDefense(int df)
{
        defense = df;
}

void Potion::setHealth(int h)
{
        health = h;
}
