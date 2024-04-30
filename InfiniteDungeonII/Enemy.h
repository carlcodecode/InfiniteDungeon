#ifndef ENEMY_H
#define ENEMY_H

#include "Item.h"
#include <cstdlib>
#include "Player.h"
using namespace std;

class Enemy
{
protected:
	int level;
	int gold;
	int hp;
	int str;
	int def;
	int speed;
	int crt;
	string status;
	Item* loot;


public:
	//Constructors
	Enemy()
		: level(1), gold(0), hp(0), str(0), def(0), speed(0), crt(0), status("none"), loot(nullptr) 
	{

	}
	Enemy(int _level, int _gold, int _hp, int _str, int _def, int _speed, int _crt, string _status, Item* _i)
		:level(_level), gold(_gold), hp(_hp), str(_str), def(_def), speed(_speed), crt(_crt), status(_status), loot(_i) {}

	Enemy(int _level, Item* _loot)
		: level(_level), gold(0), hp(0), str(0), def(0), speed(0), crt(0), status("none"), loot(_loot) {}

	//Deconstructor
	~Enemy() {
		delete loot;
	}

	//Getters
	int getLVL() { return level; }
	int getHP() { return hp; }
	int getSTR() { return str; }
	int getDEF() { return def; }
	int getSPD() { return speed; }
	int getCRT() { return crt; }
	int getGold() { return gold; }
	string getSTATUS() { return status; }
	Item* getLoot() { return loot; }

	//Setters
	void setLVL(int _l) { level = _l; }
	void setGold(int _g) { gold = _g; }
	void setHP(int _h) { hp = _h; }
	void setSTR(int _s) { str = _s; }
	void setDEF(int _d) { def = _d; }
	void setSPD(int _s) { speed = _s; }
	void setCRT(int _c) { crt = _c; }
	void setSTATUS(string _s) { status = _s; }
	void setLoot(Item* _l) { loot = _l; }

	//member functions
	virtual void speak() {
		cout << "\nI am an enemy" << endl;
	}

	virtual void death() {
		cout << "\nI died..." << endl;
	}

	virtual void roomEnter() {
		cout << "\nSomething bad is happening" << endl;
	}

	virtual void setStats() {
		hp = level;
		str = level;
		def = level;
		speed = level;
		crt = level;
		gold = level*10+(rand()%(level*40));

	}
	
	virtual void printStats() {
		cout << "\nEnemy Stats:" << endl;
		cout << "Level: " << level << endl;
		cout << "HP: " << hp << endl;
		cout << "STR: " << str << endl;
		cout << "DEF: " << def << endl;
		cout << "SPD: " << speed << endl;
		cout << "CRT: " << crt << endl;
		cout << "STATUS: " << status << endl;
		cout << "GOLD: " << gold << endl;
	}

	virtual void battle(Player* p) {														//SHOULD BE DONE 
		speak();
		setStats();
		int input = 0;
		while (hp > 0 && p->getHP() > 0) {
			cout << "\nCurrent HP: " << p->getHP() << "/" << p->getMaxHP() << endl;
			cout << "Enemy HP: " << hp;
			do {
				cout << "\nBattle Options:" << endl;
				cout << "1 - Attack" << endl;
				cout << "2 - Run Away" << endl;
				cout << "3 - Use Item" << endl;						//Need to implement consumable item inventory
				cin >> input;
				if (input > 3 || input < 1) cout << "\nPlease pick a valid option." << endl;
			} while (input < 1 || input > 3);

			if (input == 1) {
				cout << "\nYou chose to attack!" << endl;
				attack(p);
			}
			else if (input == 2) {
				if (run(p)) {
					cout << "\nYou ran away successfully!" << endl;
					break;
				}
				else {
					cout << "\nCannot escape!" << endl;
					attack(p);
				}
			}
			else if (input == 3) {
				p->useItem();
			}

			if (hp <= 0) {
				int wantLoot = -1;
				cout << "\nEnemy slain." << endl;
				cout << "\nEnemy dropped " << gold << " gold!" << endl;
				p->setGold(p->getGold() + gold);
				cout << "Your current gold amount is: " << p->getGold() << endl;
				cout << "\nEnemy dropped an item!" << endl;
				cout << "Item Info: ";
				loot->itemInfo();
				cout << "Would you like to pick up?\n1 - Yes\n2 - No" << endl;
				cin >> wantLoot;
				if (wantLoot == 1) {
					p->addItem(loot);
					p->syncStats();
				}
				else {
					cout << "Item not picked up." << endl;
				}
			}
			else if (p->getHP() <= 0) {
				cout << "\nYou have been defeated.\nGAME OVER" << endl;
			}
		}
		p->syncStats();
	}

	virtual void attack(Player* p) {
		if (p->getSPD() >= speed) {
			cout <<"\n" << p->getName() << " is faster." << endl;
			if (p->getSTR() > def) {
				int isCrit = rand() % 50;											//You can only crit if your str > than enemy def

				if ((isCrit + p->getCRT()) < 25) {
					hp-=p->getSTR();
					cout << "The enemy took " << p->getSTR() << " damage!" << endl;
				}
				else {
					cout << "Critical hit!" << endl;
					hp -= p->getSTR()*2;
					cout << "The enemy took " << p->getSTR() * 2 << " damage!" << endl;
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "Enemy blocked your attack!" << endl;
				}
				else {
					hp -= p->getSTR();
					cout << "The enemy took " << p->getSTR() << " damage!" << endl;
				}
			}
			if (hp > 0) {
				cout << "\nEnemy attacks!" << endl;
				if (str > p->getDEF()) {
					int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
					if (isCrit + crt < 25) {
						p->setHP(p->getHP()-str);
						cout << "You took " << str << " damage!" << endl;
					}
					else {
						cout << "Enemy scored a Critical hit!" << endl;
						p->setHP(p->getHP() - (str * 2));
						cout << "You took " << str * 2 << " damage!" << endl;
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "You blocked the enemy's attack!" << endl;
					}
					else {
						p->setHP(p->getHP() - str);
						cout << "You took " << str << " damage!" << endl;
					}
				}
			}

		}
		else {
			cout << "\nEnemy is faster!" << endl;
			if (str > p->getDEF()) {
				int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
				if (isCrit + crt < 25) {
					p->setHP(p->getHP() - str);
					cout << "You took " << str << " damage!" << endl;
				}
				else {
					cout << "Enemy scored a Critical hit!" << endl;
					p->setHP(p->getHP() - (str * 2));
					cout << "You took " << str * 2 << " damage!" << endl;
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "You blocked the enemy's attack!" << endl;
				}
				else {
					p->setHP(p->getHP() - str);
					cout << "You took " << str << " damage!" << endl;
				}
			}

			if (p->getHP() > 0) {
				cout << p->getName() << " attacks next." << endl;
				if (p->getSTR() > def) {
					int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
					if (isCrit + crt < 25) {
						hp -= p->getSTR();
						cout << "The enemy took " << p->getSTR() << " damage!" << endl;
					}
					else {
						cout << "Critical hit!" << endl;
						hp -= p->getSTR() * 2;
						cout << "The enemy took " << p->getSTR() * 2 << " damage!" << endl;
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "Enemy blocked your attack!" << endl;
					}
					else {
						hp -= p->getSTR();
						cout << "The enemy took " << p->getSTR() << " damage!" << endl;
					}
				}
			}
		}
	}
	
	virtual bool run(Player* p) {
		if (p->getSPD() > speed) {
			return true;
		}
		else {
			return false;
		}
	}
	
};

#endif