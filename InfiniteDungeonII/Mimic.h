#ifndef MIMIC_H
#define MIMIC_H
#include "Enemy.h"

class Mimic : public Enemy
{
private:
	Item* loot2;
public:
	//Constructors
	Mimic() : Enemy(), loot2(nullptr)
	{

	}
	Mimic(int _level, int _gold, int _hp, int _str, int _def, int _speed, int _crt, string _status, Item* _i, Item* _i2)
		: Enemy(_level, _gold, _hp, _str, _def, _speed, _crt, _status, _i), loot2(_i2) {}

	Mimic(int _level, Item* _loot, Item* _loot2)
		: Enemy(_level, _loot), loot2(_loot2) {}

	//Deconstructor
	~Mimic() {
		delete loot;
		delete loot2;
	}

	//Member Function
	void speak() {
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string endColor = "[0m";

		cout << esc_char << yellow;
		
		int rn = rand() % 10;

		switch (rn) {
		case 0:
			cout << "*Creak, creak*" << endl;
			break;
		case 1:
			cout << "*Clack, clack*" << endl;
			break;
		case 2:
			cout << "*Rustle, rustle*" << endl;
			break;
		case 3:
			cout << "*Ssshhh*" << endl;
			break;
		case 4:
			cout << "*Tap, tap*" << endl;
			break;
		case 5:
			cout << "*Whisper, whisper*" << endl;
			break;
		case 6:
			cout << "*Thud, thud*" << endl;
			break;
		case 7:
			cout << "*Gurgle, gurgle*" << endl;
			break;
		case 8:
			cout << "*Groan, groan*" << endl;
			break;
		case 9:
			cout << "*Silence*" << endl;
			break;
		default:
			break;
		}

		cout << esc_char << endColor;
	}

	void death() {
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string endColor = "[0m";

		cout << esc_char << yellow;
		
		int rn = rand() % 5;

		switch (rn) {
		case 0:
			cout << "*Crack, crack*" << endl;
			break;
		case 1:
			cout << "*Thunk, thunk*" << endl;
			break;
		case 2:
			cout << "*Snap, snap*" << endl;
			break;
		case 3:
			cout << "*Hiss, hiss*" << endl;
			break;
		case 4:
			cout << "*Plop*" << endl;
			break;
		default:
			break;
		}

		cout << esc_char << endColor;
	}

	void roomEnter() {
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string endColor = "[0m";

		
		int input;
		cout << "\nThere is a treasure chest in the room. Would you like to open it?\n1 - Yes\n2 - No" << endl;
		cin >> input;
		cout << esc_char << yellow;
		if (input == 1) {
			cout << "*CREAK, CRACK*" << endl;
		}
		else {
			cout << "*Shuffle, shuffle*" << endl;
		}

		cout << esc_char << endColor;
	}

	void setStats() {
		hp = level * 8 + (rand() % (level * 2));
		str = level;
		def = level;
		speed = level;
		crt = level;
		gold = (level * 10 + (rand() % (level * 50)));
	}

	void printStats() {
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string endColor = "[0m";

		cout << esc_char << bright << red << "\nMimic Stats:" << esc_char << endColor << endl;
		cout << "Level: " << level << endl;
		cout << "HP: " << hp << endl;
		cout << "STR: " << str << endl;
		cout << "DEF: " << def << endl;
		cout << "SPD: " << speed << endl;
		cout << "CRT: " << crt << endl;
		cout << "STATUS: " << status << endl;
		cout << "GOLD: " << gold << endl;
	}

	void battle(Player* p) {														//SHOULD BE DONE 
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string endColor = "[0m";
		
		setStats();
		int input = 0;
		cout << esc_char << red << "\nBattle with level " << level << " Mimic begins!" << esc_char << endColor << endl;
		printStats();
		while (hp > 0 && p->getHP() > 0) {
			cout << endl;
			speak();
			cout << "\nCurrent HP: " << p->getHP() << "/" << p->getMaxHP() << endl;
			cout << "Mimic HP: " << hp;
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
				cout << endl;
				death();
				cout << "\nMimic dropped " << gold << " gold!" << endl;
				p->setGold(p->getGold() + gold);
				cout << "Your current gold amount is: " << p->getGold() << endl;
				
				cout << "\nMimic dropped an item!" << endl;
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

				cout << "\nMimic dropped another item!" << endl;
				cout << "Item Info: ";
				loot2->itemInfo();
				cout << "Would you like to pick up?\n1 - Yes\n2 - No" << endl;
				cin >> wantLoot;
				if (wantLoot == 1) {
					p->addItem(loot2);
					p->syncStats();
				}
				else {
					cout << "Item not picked up." << endl;
				}
			}
			else if (p->getHP() <= 0) {
				cout << esc_char << red << "\nYou have been defeated.\nGAME OVER" << esc_char << endColor << endl;
			}
		}
		p->syncStats();
	}

	void attack(Player* p) {
		if (p->getSPD() >= speed) {
			cout << "\n" << p->getName() << " is faster." << endl;
			if (p->getSTR() > def) {
				int isCrit = rand() % 50;											//You can only crit if your str > than enemy def

				if ((isCrit + p->getCRT()) < 25) {
					hp -= p->getSTR();
					cout << "The mimic took " << p->getSTR() << " damage!" << endl;
				}
				else {
					cout << "Critical hit!" << endl;
					hp -= p->getSTR() * 2;
					cout << "The mimic took " << p->getSTR() * 2 << " damage!" << endl;
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "Mimic blocked your attack!" << endl;
				}
				else {
					hp -= p->getSTR();
					cout << "The mimic took " << p->getSTR() << " damage!" << endl;
				}
			}
			if (hp > 0) {
				cout << "\nMimic attacks!" << endl;
				if (str > p->getDEF()) {
					int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
					if (isCrit + crt < 25) {
						p->setHP(p->getHP() - str);
						cout << "You took " << str << " damage!" << endl;
					}
					else {
						cout << "Mimic scored a Critical hit!" << endl;
						p->setHP(p->getHP() - (str * 2));
						cout << "You took " << str * 2 << " damage!" << endl;
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "You blocked the mimic's attack!" << endl;
					}
					else {
						p->setHP(p->getHP() - str);
						cout << "You took " << str << " damage!" << endl;
					}
				}
			}

		}
		else {
			cout << "\nMimic is faster!" << endl;
			if (str > p->getDEF()) {
				int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
				if (isCrit + crt < 25) {
					p->setHP(p->getHP() - str);
					cout << "You took " << str << " damage!" << endl;
				}
				else {
					cout << "Mimic scored a Critical hit!" << endl;
					p->setHP(p->getHP() - (str * 2));
					cout << "You took " << str * 2 << " damage!" << endl;
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "You blocked the mimic's attack!" << endl;
				}
				else {
					p->setHP(p->getHP() - str);
					cout << "You took " << str << " damage!" << endl;
				}
			}

			if (p->getHP() > 0) {
				cout << "\n" << p->getName() << " attacks next." << endl;
				if (p->getSTR() > def) {
					int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
					if (isCrit + crt < 25) {
						hp -= p->getSTR();
						cout << "The mimic took " << p->getSTR() << " damage!" << endl;
					}
					else {
						cout << "Critical hit!" << endl;
						hp -= p->getSTR() * 2;
						cout << "The mimic took " << p->getSTR() * 2 << " damage!" << endl;
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "Mimic blocked your attack!" << endl;
					}
					else {
						hp -= p->getSTR();
						cout << "The mimic took " << p->getSTR() << " damage!" << endl;
					}
				}
			}
		}

		if (p->getSTATUS() == "Poisoned") {
			cout << "\n You take " << level / 2 << " poison damage..." << endl;
			p->setHP(p->getHP() - level / 2);
		}

	}

	bool run(Player* p) {
		if (p->getSPD() > speed) {
			return true;
		}
		else {
			return false;
		}
	}
};

#endif

