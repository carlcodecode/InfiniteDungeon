#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include "Inventory.h"
using namespace std;

class Player
{
private:
	int maxHp;
	int hp;
	int str;
	int def;
	int speed;
	int crt;
	int level;
	string status;
	string name;
	string p_class;
	int gold;
	Inventory* backpack;

public:
	//Constructors
	Player() : maxHp(8), hp(10), str(1), def(1), speed(1), crt(1), level(0), status("none"), name(""), p_class(""), gold(0), backpack(nullptr) {}
	Player(int _mhp, int _hp, int _str, int _def, int _speed, int _crt, int _level, string _status, string _name, string _p_class, int _gold, Inventory* _backpack)
		: maxHp(_mhp), hp(_hp), str(_str), def(_def), speed(_speed), crt(_crt), level(_level), status(_status), name(_name), p_class(_p_class), gold(_gold), backpack(_backpack) {}
	Player(int _l, string _n, string _c) : maxHp(0), hp(0), str(0), def(0), speed(0), crt(0), level(_l), status("none"), name(_n), p_class(_c), gold(0), backpack(nullptr) {}
	Player(int _l, string _n, string _c, int _g, Inventory* i) : maxHp(0), hp(0), str(0), def(0), speed(0), crt(0), level(_l), status("none"), name(_n), p_class(_c), gold(_g), backpack(i) {}

	//Deconstructor
	~Player() {
		delete backpack;
	}

	//Getters
	int getMaxHP() { return maxHp; }
	int getHP() { return hp; }
	int getSTR() { return str; }
	int getDEF() { return def; }
	int getSPD() { return speed; }
	int getCRT() { return crt; }
	int getLVL() { return level; }
	string getSTATUS() { return status; }
	string getName() { return name; }
	string getClass() { return p_class; }
	int getGold() { return gold; }
	Inventory* getI() { return backpack; }

	//Setters
	void setMaxHP(int _hp) { maxHp = _hp; }
	void setHP(int _hp) { hp = _hp; }
	void setSTR(int _str) { str = _str; }
	void setDEF(int _def) { def = _def; }
	void setSPD(int _speed) { speed = _speed; }
	void setCRT(int _crt) { crt = _crt; }
	void setLVL(int _level) { level = _level; }
	void setSTATUS(string _status) { status = _status; }
	void setName(int _name) { name = _name; }
	void setClass(int _p_class) { p_class = _p_class; }
	void setGold(int _gold) { gold = _gold; }
	void setI(Inventory* _i) { backpack = _i; }

	//Member Functions
	void printStats() {
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string endColor = "[0m";
		
		cout << esc_char << bright << cyan << "\nStats for " << name << " the " << p_class << esc_char << endColor << endl;
		cout << "Level: " << level << endl;
		cout << "HP: " << hp << "/" << maxHp << endl;
		cout << "STR: " << str << endl;
		cout << "DEF: " << def << endl;
		cout << "SPD: " << speed << endl;
		cout << "CRT: " << crt << endl;
		cout << "STATUS: " << status << endl;
		cout << "Inventory slots: " << backpack->getMaxSize() << endl;
		cout << "Gold: " << gold << endl;

	}

	void createEmptyInventory() {
		vector<Item*>items;

		backpack = new Inventory(0, 0, items);
	}

	void syncStats() {
		maxHp = 2 + level*8;
		str = 0 + level;
		def = 0 + level;
		speed = 0 + level;
		crt = 0 + level;
		backpack->setMaxSize(3 + level);

		if (p_class == "Warrior") {
			str = 0 + level * 2;
			maxHp = 2 + level * 10;
		}
		if (p_class == "Bastion") {
			def = 0 + level * 2;
			maxHp = 2 + level * 10;
		}
		if (p_class == "Rogue") {
			speed = 0 + level * 2;
			crt = 0 + level * 2;
		}
		if (p_class == "Rusher") {
			str = 0 + level * 2;
			speed = 0 + level * 2;
		}

		if (status == "Frozen") {
			speed /= 2;
		}

		for (Item* item : backpack->getList()) {
			if (item->getIsWeapon()) {
				if (item->getName() == "Sword") {
					str += item->getLevel();
					
				}
				if (item->getName() == "Axe") {
					def += item->getLevel();
					
				}
				if (item->getName() == "Bow") {
					speed += item->getLevel();
					
				}
				if (item->getName() == "Dagger") {
					crt += item->getLevel();
					
				}
			}
		}
	}

	void levelUp() {
		level += 1;
		syncStats();
	}

	//Inventory Modifiers
	void addItem(Item* newItem) {
		int input = -1;
		if (backpack->getCurSize() == backpack->getMaxSize()) {
			cout << "\nInventory is currently full! Would you like to drop an item?" << endl;
			cout << "1 - Yes\n2 - No" << endl;
			cin >> input;
			if (input == 1) {
				removeItem();
				//list_items.push_back(newItem);
				backpack->plusItem(newItem);
				backpack->setCurSize(backpack->getCurSize()+1);
				cout << "\nItem successfully added to inventory!\nShowing new Inventory" << endl;
				backpack->printContents();
			}
			if (input == 2) {
				cout << "Item was not added to inventory." << endl;
			}
		}
		else {
			backpack->plusItem(newItem);
			backpack->setCurSize(backpack->getCurSize() + 1);
			cout << "\nItem successfully added to inventory!\nShowing new Inventory" << endl;
			backpack->printContents();
		}
	}

	void removeItem() {
		int pos = -1;
		int confirm = -1;

		if (backpack->getCurSize() == 0) { cout << "\nThere are no items to remove!" << endl; }
		else {
			backpack->printContents();
			cout << "\nPlease enter the position of the item you would like to remove: ";
			cin >> pos;

			cout << "\Are you sure you want to drop this item?\n1 - Yes\n2 - No" << endl;
			cin >> confirm;

			if (confirm == 1) {
				backpack->eraseItem(pos);
				backpack->setCurSize(backpack->getCurSize()-1);
				cout << "\Item successfully dropped.\Showing new Inventory: " << endl;
				backpack->printContents();
			}
			else {
				cout << "\nItem not dropped." << endl;
			}
		}
	}

	void useItem() {
		int input = -1;
		if (backpack->getCurSize() == 0) { cout << "\nThere are no items to use!" << endl; }
		else {

			do {
				backpack->printContents();
				cout << "\nPlease enter the position of the item you would like to use." << endl;
				cout << "(enter 0 to exit inventory)" << endl;
				cin >> input;
				if (input != 0) {
					if (backpack->getList().at(input - 1)->getIsCons()) {
						/*if (backpack->getList().at(input - 1)->getName() == "Potion") {
							if (hp == maxHp) { cout << "\nHP is already full!" << endl; }
							else {
								cout << "Using Potion..." << endl;
								backpack->eraseItem(input);
								backpack->setCurSize(backpack->getCurSize() - 1);
								//status = "healty";
							}
						}*/
						if (backpack->getList().at(input - 1)->getName() == "Freeze Heal") {
							if (status != "Frozen") { cout << "\nYou are not frozen..." << endl; }
							else {
								cout << "Using Freeze Heal..." << endl;
								backpack->eraseItem(input);
								backpack->setCurSize(backpack->getCurSize() - 1);
								status = "none";
								cout << "You are no longer frozen!" << endl;
								syncStats();
							}
						}
						else if (backpack->getList().at(input - 1)->getName() == "Poison Heal") {
							if (status != "Poisoned") { cout << "\nYou are not poisoned..." << endl; }
							else {
								cout << "Using Poison Heal..." << endl;
								backpack->eraseItem(input);
								backpack->setCurSize(backpack->getCurSize() - 1);
								status = "none";
								cout << "You are no longer poisoned!" << endl;
								syncStats();

							}
						}
						else if (backpack->getList().at(input - 1)->getName() == "Potion") {
							if (hp == maxHp) { cout << "\nHP is already full!" << endl; }
							else {
								int hpMod = backpack->getList().at(input - 1)->getLevel();
								cout << "Using Potion..." << endl;
								backpack->eraseItem(input);
								backpack->setCurSize(backpack->getCurSize() - 1);
								hp += hpMod*2;
								if (hp > maxHp) { hp = maxHp; }
								cout << "Healed for " << hpMod*2 <<"!" << endl;
								printStats();
							}
						}
					}
					else {
						cout << "\nItem is not a consumable! Please select another item." << endl;
					}
				}
			} while (input != 0);

		}

	}

	void inventoryMenu() {
		int input = -1;
		cout << "\nOpening inventory menu" << endl;
		do {
			cout << "\nPlease select an option below:" << endl;
			cout << "1 - View inventory" << endl;
			cout << "2 - Get item info" << endl;
			cout << "3 - Drop an item" << endl;
			cout << "4 - Use an item" << endl;
			cout << "5 - Exit" << endl;

			cin >> input;

			if (input == 1) {
				backpack->printContents();
			}
			if (input == 2) {
				int input2 = -1;
				backpack->printContents();
				if (backpack->getCurSize() > 0) {
					do {

						cout << "\nPlease select the position of the item you would like more information on" << endl;
						cout << "(enter 0 to go back to main inventory menu)" << endl;
						cin >> input2;
						if (input2 != 0) {
							cout << "\nLoading information..." << endl;
							backpack->getList().at(input2 - 1)->itemInfo();
						}
					} while (input2 != 0);
				}
			}
			if (input == 3) {
				removeItem();
			}
			if (input == 4) {
				useItem();
			}
			if (input == 5) {
				cout << "\nExiting inventory menu..." << endl;
			}
		} while (input != 5);
	}

};
#endif
