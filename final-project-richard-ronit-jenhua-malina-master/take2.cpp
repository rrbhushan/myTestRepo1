#include "GeneratePlayer.h"
#include "player.h"
#include "slowPrints.h"
#include "sample.h"
#include "bag.h"
#include <iostream>
using namespace std;

int main()
{
	Player p = GeneratePlayer();
	vector<Room> allRooms;
	vector<string> connectedToTown;
	connectedToTown.push_back("WELL");
	Room TOWN("TOWN",
		"*This entire TOWN is underground. The little bit of light and warmth that exists here is from man made fires. Most of the buildings look like they're falling apart and are covered in ash.",
		"*The OLD MAN I talked to is here.",
		"*There's a WELL to the right and it looks like someone is sitting by it, and there's a LOCATION NAME to the left",
		"I've heard rumors of at least one person making it out of here before... If you think you can fight your way to the top maybe you can get some answers to why all of this happened, but then again maybe there isn't a way out at all.It's honestly up to you, would you rather die trying to escape or try to have some sort of a life down here?\n",
		"Old Man: ");
	TOWN.setConnectedRooms(connectedToTown);
	Room WELL("WELL",
		"*This WELL doesn't look like it is in good shape either. The bucket connected to it is leaking and there's even ash in the water. I think I see something shiny in it though...",
		"*There's a young girl sitting against the well. It is weird to think even kids can get sent here...",
		"*There's a CAVE ENTRANCE up ahead and the TOWN I came from is behind me",
		"Laura says I can't get any closer to the cave. She said it has a big scary monster there gaurding the entrance to the next level.\n",
		"Young Girl: ");
	vector<string> connectedToWell;
	connectedToWell.push_back("TOWN");
	connectedToWell.push_back("CAVE ENTRANCE");
	WELL.setConnectedRooms(connectedToWell);
	allRooms.push_back(TOWN);
	allRooms.push_back(WELL);
	p.move(TOWN);
	cout << "Old Man: ";
	slowStringPrint(p.getLocation().getNPCDialogue(), "Old Man: ");
	cout << "\n        ~Type HELP at anytime for a list of available options\n";
	string input = "";
	string locationToGoTo;
	cin.ignore(INT_MAX, '\n');
	while (input != "stop") {
		cout << p.getName() << ": ";
		getline(cin, input);
		if (input == "HELP") {
			cout << "        ~Available options are in all caps and must be typed exactly to work\n        Type LOOK AROUND to get a description of your surroundings, places you can move to, people you can tak to, and items you can pick up in an area\n        Type MOVE TO <area name in all caps given in LOOK AROUND>\n        Type TALK to speak to any NPCs that are around\n";
		}
		else if (input == "LOOK AROUND") {
			cout << "         ";
			slowStringPrint(p.getLocation().getDescription(), "         ");
			cout << "\n         ";
			slowStringPrint(p.getLocation().getNPCsAvailable(), "         ");
			cout << "\n         ";
			slowStringPrint(p.getLocation().getLocationsAvailable(), "         ");
			cout << endl;
		}
		else if (input == "TALK") {
			cout << p.getLocation().getNPCName();
			slowStringPrint(p.getLocation().getNPCDialogue(), p.getLocation().getNPCName());
			cout << endl;
		}
		else if (input.find("MOVE TO ") == 0) {
			locationToGoTo = input.substr(8);
			if (p.getLocation().validMove(locationToGoTo)) {
				for (int i = 0; i < allRooms.size(); ++i) {
					if (allRooms.at(i).getName() == locationToGoTo) {
						p.move(allRooms.at(i));
					}
				}
				cout << p.getName() << ": ";
				slowStringPrint("I went to the " + p.getLocation().getName(), p.getName() + ": ");
				cout << endl;
			}
		}
		else if (input == "BACKPACK") {
			Bag x("test name","test desc");
			p.addToInv(x);
			p.addToInv(x);
			p.printInv();

			//Bag y = p.getItem(0);
		}
		else {
			cout << "         ***Not a valid command! Type HELP for a list of available commands.***\n";
		}
			
	}
}
