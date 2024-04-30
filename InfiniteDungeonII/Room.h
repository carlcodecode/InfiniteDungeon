#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstdlib>
#include "Player.h"

using namespace std;

class Room
{
protected:
	int x;
	int y;
	Player* p;
	bool entered;
	int level;

public:
	//Constructors
	Room() : x(0), y(0), p(nullptr), entered(false), level(0) {}
	Room(int _x, int _y, Player* _p, bool _e, int _l) : x(_x), y(_y), p(_p), entered(_e), level(_l) {}

	//Deconstructor
	~Room() {
		delete p;
	}

	//Getters
	int getX() { return x; }
	int getY() { return y; }
	Player* getP() { return p; }
	bool getE() { return entered; }
	int getLvl() { return level; }

	//Setters
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	void setP(Player* _p) { p = _p; }
	void setE(bool _e) { entered = _e; }
	void setLvl(int _l) { level = _l; }

	//Member functions
	virtual void test() {
		cout << "\nSuccesfully created a room at (" << x << ", " << y << ")" << endl;
		cout << p->getName() << " is currently in the room." << endl;

	}

	bool same(Room* other) {
		if (x == other->getX() && y == other->getY()) {
			return true;
		}
		else {
			return false;
		}
	}

	virtual void runInstance() = 0;

	void printCoords() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

#endif


