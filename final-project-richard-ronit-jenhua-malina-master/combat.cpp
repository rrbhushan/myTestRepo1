
#include "combat.h"
#include <iostream> //input and output
#include <stdlib.h> //srand and rand
#include <time.h> //time
#include "player.h"
#include "Enemy.h"
#include "character.h"
#include "slowPrints.h"
#include "DeathPrint.h"

bool combat(Player &x, Enemy &y)
{
	slowStringPrint(x.getName() + " has engaged in combat with " + y.getName() + ".\n", "");
	
	bool plyF = true;  //boolean that determines if the player goes first or not

	if (x.getSpd() >= y.getSpd())
	{
		slowStringPrint(x.getName() + " quick to action, makes the first move!\n", "");
	}
	else
	{
		plyF = false;
		slowStringPrint(y.getName() + " is quicker, and makes the first move!\n", "");
	}
	
	//^code that decides who goes first
	
	if (plyF == false)
	{
		cout << endl;
		cout << y.getName() << " attacks " << x.getName() << "." << endl;
		cout << y.getName() << " did " << y.attack(x) << " damage to " << x.getName() << "." << endl;
		cout << endl;
	}

	while ( (x.getMaxHealth() - x.getDmgTaken() > 0) && (y.getMaxHealth() - y.getDmgTaken() > 0))
	{
		int turnPoint = x.getcombatPt();
		if (x.getBoolDef() == true)
		{
			x.setBoolDef(false);
		}

		int temp_atk = x.getAtk();
		int temp_defense = x.getDefense();

		while (turnPoint > 0)
		{
	
			cout << x.getName() << "'s Health: " << (x.getMaxHealth() - x.getDmgTaken()) << endl;
			cout << y.getName() << "'s Health: " << (y.getMaxHealth() - y.getDmgTaken()) << endl;
			cout << "Combat Points Left: " << turnPoint << " / " << x.getcombatPt() << endl;
			cout << "	Options:" << endl;
			cout << "	1. Attack" << endl;
			cout << " 	2. Defend" << endl;
			cout << "	3. Show Combat Potion Pouch" << endl;
			cout << "	4. Use a Combat Item" << endl;
			
			//char input;
			string input;
			getline(cin, input);
			
			//cin >> input;
			
			if (input == "1")
			{
				cout << endl;
				cout << x.getName() << " attacks " << y.getName() << "." << endl;
				cout << x.getName() << " did " << x.attack(y) << " damage to " << y.getName() << "." << endl;			
				cout << endl;
				turnPoint--;
				break;
			}
			else if (input == "2")
			{
				cout << endl;
				cout << x.getName() << " defends himself." << endl;
				cout << endl;
				x.setBoolDef(true);
				turnPoint--;
				break;
			}
			else if (input == "3")
			{
				for (int i = 0; i < x.bInventory->vBag.size(); i++)
				{
					if (x.bInventory->vBag.at(i)->getName() == "Combat Potion Pouch (Bag)")
					{
						x.bInventory->vBag.at(i)->printBag();
					}
				}
			}
			else if (input == "4")
			{
				if (turnPoint == 1)
				{
					cout << "You only have one Combat Point left to either attack or defend." << endl;
					continue;
				}
				else
				{  
					string itemName;
					cout << "Please enter what item you would like to use or type NO" << endl;
					cin.clear();
					getline(cin, itemName);
					if (itemName == "NO")
					{
						continue;
					}
					else if (x.usePotion(itemName) == true)
					{
						turnPoint--;
						continue;
					}
					else
					{
						cout << "Invalid: No such potion in Combat Potion Pouch\nPlease choose a valid potion" << endl;
						continue;
					}
						
				}
			}
			else
			{
				cout << "Invalid: Please type in one of the numbers given" << endl;
			}
		}
                        
		if (y.getBoolDef() == true)
		{
			y.setBoolDef(false);
		}
			
		int randNum = 0;
		srand (time(NULL));
		randNum = rand() % 3;
			
		if (randNum == 0 || randNum == 1)
		{
			cout << endl;
                	cout << y.getName() << " attacks " << x.getName() << "." << endl;
               		cout << y.getName() << " did " << y.attack(x) << " damage to " << x.getName() << "." << endl;
                	cout << endl;
		}
		else if (randNum == 2)
		{
			 cout << endl;
                         cout << y.getName() << " defends himself." << endl;
                         cout << endl;
                         x.setBoolDef(true);
		}
		x.setAtk(temp_atk);
    		x.setDefense(temp_defense);
	}

	if (x.getDmgTaken() > x.getMaxHealth())
  	{
    		cout << x.getName() << " lost against " << y.getName() << "." << endl;
    		DeathPrint("ASCENSION ENDED\n");
    		return false;
  	}
  	else
  	{
    		cout << x.getName() << " won against " << y.getName() << "." << endl;
    		cout << x.getName() << "'s Health has been reset to full.'" << endl;
    		x.setDmgTaken(0);
		return true;
  	}
	
}


