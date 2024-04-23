#ifndef __ITEM_H__
#define __ITEM_H__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
    private:
	string name;
	string desc;
	int itemCount;
    public:
	vector<Item *> vBag;
	Item(string n = "", string d = "", int i = 0) { name = n; desc = d; itemCount = i; vBag = {};}
        virtual ~Item() { }
	virtual void print() {
		cout << getItemCount() << "x " << getName() << endl;
		cout << "\t~" <<  getDesc() << endl;
	}
	
	virtual string getName() { return this->name; }
	virtual int getItemCount() { return this->itemCount; }
	virtual string getDesc() { return this->desc; }

	virtual void setName(string s) { name = s; }
	virtual void setItemCount(int i) { itemCount = i; }
	virtual void setDesc(string d) { desc = d; }
	
	virtual void addToBag(Item* n) {};
	virtual void rmFromBag(Item* n) {};
	virtual void printBag() {};

	virtual void setAttack(int atk) {};
	virtual int getAttack() { return 0; }

	virtual void setHealth(int health) {};
	virtual int getHealth() { return 0; }
	
	virtual void setDefense(int def) {};
    	virtual int getDefense() { return 0; }

	virtual vector<Item*> getBag() { return vBag; }
};

#endif //__ITEM_H__
