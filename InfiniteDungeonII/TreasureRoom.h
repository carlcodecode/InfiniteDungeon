#ifndef TREASUREROOM_H
#define TREASUREROOM_H

#include "Room.h"

class TreasureRoom : public Room
{
private:
	string tName;
    string tProp;
	int gold;
public:
	//Constructors
	TreasureRoom() : Room(), tName(""), gold(0), tProp("") {}
	TreasureRoom(int _x, int _y, Player* _p, bool _e, int _l, string _t, int _g, string _tp)
		: Room(_x, _y, _p, _e, _l), tName(_t), gold(_g), tProp(_tp) {}
    TreasureRoom(int _x, int _y, Player* _p, bool _e, int _l)
        : Room(_x, _y, _p, _e, _l), gold(0), tName(""), tProp("") {}

	//Deconstructor
	~TreasureRoom(){}

	//Getters
	string getTName() { return tName; }
	int getGold() { return gold; }
    string getTProp() { return tProp; }

	//Setters
	void setTName(string _t) { tName = _t; }
	void setGold(int _g) { gold = _g; }
    void setTProp(string _tp) { tProp = _tp; }

	//Memberfunctions
	void test() {
		cout << "\nSuccesfully created a treasure room at (" << x << ", " << y << ")" << endl;
		cout << p->getName() << " is currently in the room." << endl;
		cout << "Treasure " << tName << " is here worth: " << gold << " gold!" << endl;

	}

	void runInstance() {
        char esc_char = 27;
        string red = "\033[31m";
        string yellow = "\033[33m";
        string cyan = "\033[36m";
        string purple = "\033[35m";
        string bright = "\033[1m";
        string endColor = "[0m";
        
        cout << "\nLoading Room..." << endl;

        int input;
        cout << "\nThere is a treasure chest in the room. Would you like to open it?\n1 - Yes\n2 - No" << endl;
        cin >> input;
        if (input == 1 && entered == false) {
            randTName();
            randProp();

            if (tProp == "Copper") {
                gold = 50;
            }
            else if (tProp == "Silver") {
                gold = 100;
            }
            else if (tProp == "Gold") {
                gold = 500;
            }
            else if (tProp == "Platinum") {
                gold = 1000;
            }
            else if (tProp == "Diamond") {
                gold = 5000;
            }

            if (entered == false) {
                cout << "\nYou have found a " << tProp << " " << tName << endl;
                cout << esc_char << bright << yellow << "Gained " << gold << " gold!" << esc_char << endColor << endl;
                p->setGold(p->getGold() + gold);
                cout << "\nCurrent gold: " << p->getGold() << endl;
                entered = true;
            }
        }
        else if(input == 1 && entered == true) {
            cout << "\nYou already took the items of this chest... it is empty." << endl;
        }
        else {
            cout << "\nTreasure chest not opened..." << endl;
        }
	}

	void randTName() {
        int chance = rand() % 20;

        switch (chance) {
        case 0:
            tName = "Platter";
            break;
        case 1:
            tName = "Block";
            break;
        case 2:
            tName = "Anklet";
            break;
        case 3:
            tName = "Crown";
            break;
        case 4:
            tName = "Necklace";
            break;
        case 5:
            tName = "Ring";
            break;
        case 6:
            tName = "Goblet";
            break;
        case 7:
            tName = "Chalice";
            break;
        case 8:
            tName = "Bracelet";
            break;
        case 9:
            tName = "Brooch";
            break;
        case 10:
            tName = "Pendant";
            break;
        case 11:
            tName = "Earring";
            break;
        case 12:
            tName = "Scepter";
            break;
        case 13:
            tName = "Medallion";
            break;
        case 14:
            tName = "Tiara";
            break;
        case 15:
            tName = "Statuette";
            break;
        case 16:
            tName = "Candelabrum";
            break;
        case 17:
            tName = "Diadem";
            break;
        case 18:
            tName = "Torc";
            break;
        case 19:
            tName = "Filigree";
            break;
        default:
            break;
        }
	}

    void randProp() {
        int chance = rand() % 100 + 1; // Random number between 1 and 100

        if (chance <= 40) {
            tProp = "Copper";
        }
        else if (chance <= 70) {
            tProp = "Silver";
        }
        else if (chance <= 85) {
            tProp = "Gold";
        }
        else if (chance <= 95) {
            tProp = "Platinum";
        }
        else {
            tProp = "Diamond";
        }
    }


};

#endif

