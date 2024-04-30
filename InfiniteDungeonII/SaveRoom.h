#ifndef SAVEROOM_H
#define SAVEROOM_H
#include "Room.h"

class SaveRoom : public Room
{
public:
	//Constructors
	SaveRoom() : Room() {}
	SaveRoom(int _x, int _y, Player* _p, bool _e, int _l)
		: Room(_x, _y, _p, _e, _l) {}

	//Deconstructor
	~SaveRoom() {}

	//Member Functions 
	void test() {
		cout << "You are in a save room." << endl;
	}

	void runInstance() {
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string endColor = "[0m";
		
		
		if (entered == false) {
			cout << "\nA campfire burns nearby..." << endl;
			cout << esc_char << bright << cyan << "Game saving..." << esc_char << endColor << endl;
			entered = true;
			cout << "\nThe campfire burns out..." << endl;
		}
		else {
			cout << "\nEmpty room..." << endl;
		}
	}

};

#endif

