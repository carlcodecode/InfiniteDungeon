#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H

#include "Room.h"
#include "EnemyRoom.h"
#include "TreasureRoom.h"
#include "ShopRoom.h"
#include "SaveRoom.h"

class DungeonLevel
{
private:
	int level;
	int x;
	int y;
	Player* p;
	vector<Room*>rooms;
	int rc;
	int mr;

public:
	//Constructors
	DungeonLevel() : level(1), x(0), y(0), rc(0), mr(0), p(nullptr) {}
	DungeonLevel(int _l, Player* _p) : level(_l), x(0), y(0), rc(0), mr(0), p(_p) {}

	//Deconstructor
	~DungeonLevel() {
		delete p;
		for (Room* room : rooms) {
			delete room;
		}
	}

	//Getters
	int getLevel() { return level; }
	int getX() { return x; }
	int getY() { return y; }
	Player* getP() { return p; }
	vector<Room*> getRooms() { return rooms; }
	int getRC() { return rc; }
	int getMR() { return mr; }

	//Setters
	void setLevel(int _l) { level = _l; }
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	void setP(Player* _p) { p = _p; }
	void setRooms(vector<Room*>_rooms) { rooms = _rooms; }
	void setRC(int _p) { rc = _p; }
	void setMR(int _p) { mr = _p; }

	//Member functions
	void test() {
		cout << "Created a room" << endl;
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		cout << p->getName() << " is in the room" << endl;
	}

	Room* createTreasureRoom() {
		Room* tRoom = new TreasureRoom(x, y, p, false, level);
		return tRoom;
	}

	Room* createEnemyRoom() {
		Room* tRoom = new EnemyRoom(x, y, p, false, level);
		return tRoom;
	}

	Room* createShopRoom() {
		Room* tRoom = new ShopRoom(x, y, p, false, level);
		return tRoom;
	}

	Room* createSaveRoom() {
		Room* tRoom = new SaveRoom(x, y, p, false, level);
		return tRoom;
	}

	void generateDungeon() {
		if (level < 18) {
			mr = level + 3;
		}
		else {
			mr = 20;
		}

		Room* sRoom = createSaveRoom();
		rooms.push_back(sRoom);

		for (int i = 1; i < mr; i++) {
			int rn = rand() % 2;
			if (rn == 0) {
				x += 1;
			}
			else {
				y += 1;
			}
			int rn2 = rand() % 100 + 1;
			if (rn2 <= 20) {
				Room* trRoom = createTreasureRoom();
				rooms.push_back(trRoom);
			}
			else if (rn2 <= 70) {
				Room* eRoom = createEnemyRoom();
				rooms.push_back(eRoom);
			}
			else if (rn2 <= 100) {
				Room* sRoom = createShopRoom();
				rooms.push_back(sRoom);
			}
		}
	}
	void runInstance() {
		rc = 0;

		generateDungeon();
		x = 0;
		y = 0;
		rooms.at(0)->runInstance();
		menu();
		
	}

	void move() {
		int input = 0;
		bool locked = true;
		//int pos = 0;
		cout << "\nWhere would you like to move?" << endl;
		cout << "1 - Up" << endl;
		cout << "2 - Down" << endl;
		cout << "3 - Left" << endl;
		cout << "4 - Right" << endl;
		cin >> input;

		if (input == 1) {
			y += 1;
		}
		else if (input == 2) {
			y -= 1;
		}
		else if (input == 3) {
			x -= 1;
		}
		else if (input == 4) {
			x += 1;
		}

		for (Room* room : rooms) {
			if (room->getX() == x && room->getY() == y) {
				locked = false;
				room->runInstance();
				//if (pos == mr-1) cout << "hello" << endl;
				break;
			}
			//pos++;
			
		}

		if (locked) {
			cout << "\nRoom is locked. Please try another direction." << endl;
			if (input == 1) {
				y -= 1;
			}
			else if (input == 2) {
				y += 1;
			}
			else if (input == 3) {
				x += 1;
			}
			else if (input == 4) {
				x -= 1;
			}
		}

		
	}

	void menu() {
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string endColor = "[0m";

		cout << esc_char << bright << purple << "\n~Main Dungeon Menu~" << esc_char << endColor << endl;
		
		int input = -1;
		do {
			cout << "\n1 - View Stats" << endl;
			cout << "2 - Open Inventory" << endl;
			cout << "3 - Move" << endl;
			cout << "4 - Get Coordinates" << endl;
			cout << "5 - Exit Dungeon Menu" << endl;

			cin >> input;

			if (input == 1) {
				p->printStats();
			}
			else if (input == 2) {
				p->inventoryMenu();
			}
			else if (input == 3) {
				move();
			}
			else if (input == 4) {
				cout << "\nCoordinates are: (" << x << ", " << y << ")" << endl;
			}
			else if (input == 5) {
				cout << "\nExiting dungeon menu. Shifting layout..." << endl;
			}
		} while (input != 5);
	}

};

#endif

