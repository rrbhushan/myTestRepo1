#ifndef __BAG_H__
#define __BAG_H__

#include <iostream>
#include <string>
#include <vector>

#include "item.h"
using namespace std;

class Bag : public Item {
    public:
	vector<Item *> vBag;
    public:
	//Item getItem(unsigned);
	Bag(string n = "", string d = "", int i = 0) : Item(n, d, i) {
		vBag = {};
	}
	~Bag() {
		for ( int i = 0; i < vBag.size(); ++i ) {
			delete vBag.at(i);
		}
	}
        void printBag();
	void addToBag(Item* n);
	void rmFromBag(Item* n);
	vector<Item *> getBag() { return vBag; }
};

#endif //__BAG_H__
