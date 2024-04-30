#ifndef GOBLIN_H
#define GOBLIN_H

#include "Enemy.h"
class Goblin : public Enemy
{
public:
	//Constructors
	Goblin() : Enemy()
	{

	}
	Goblin(int _level, int _gold, int _hp, int _str, int _def, int _speed, int _crt, string _status, Item* _i)
		: Enemy(_level, _gold, _hp, _str, _def, _speed, _crt, _status, _i) {}

	Goblin(int _level, Item* _loot)
		: Enemy(_level, _loot) {}

	//Deconstructor
	~Goblin() {
		delete loot;
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

		cout << esc_char << bright << red;
		
		int rn = rand() % 10;

		switch (rn) {
		case 0:
			cout << "Oi, what's this? More meat for the grinder?" << endl;
			break;
		case 1:
			cout << "You there! Trespassers aren't welcome in our dungeon!" << endl;
			break;
		case 2:
			cout << "Fresh faces, fresh loot! Hand over your belongings!" << endl;
			break;
		case 3:
			cout << "Looks like we've got ourselves some easy pickings!" << endl;
			break;
		case 4:
			cout << "Haha! Another day, another chance to bash some skulls!" << endl;
			break;
		case 5:
			cout << "Welcome to the goblin's domain! Hope you brought snacks!" << endl;
			break;
		case 6:
			cout << "An intruder? Bah! I'll make quick work of you, no problem!" << endl;
			break;
		case 7:
			cout << "Don't just stand there gawking! Time to pay the toll or face the consequences!" << endl;
			break;
		case 8:
			cout << "Ha! You think you can survive a day in our dungeon? I'll see about that!" << endl;
			break;
		case 9:
			cout << "Prepare for a warm, goblin-y welcome!" << endl;
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

		cout << esc_char << bright << red;
		
		int rn = rand() % 10;

		switch (rn) {
		case 0:
			cout << "Ouch... It hurts... Why did it have to end like this?" << endl;
			break;
		case 1:
			cout << "I-I'm fading... The darkness... it's consuming me..." << endl;
			break;
		case 2:
			cout << "This... this wasn't supposed to happen... I had dreams..." << endl;
			break;
		case 3:
			cout << "I just wanted to protect my home... Why did it have to come to this?" << endl;
			break;
		case 4:
			cout << "It's so cold... Is this... Is this what it feels like to die?" << endl;
			break;
		case 5:
			cout << "I'm sorry... I'm so sorry... Please... forgive me..." << endl;
			break;
		case 6:
			cout << "I never got to say goodbye... to tell them I loved them..." << endl;
			break;
		case 7:
			cout << "I thought I was strong... I thought I could make a difference..." << endl;
			break;
		case 8:
			cout << "I don't want to go... I'm not ready to leave this world..." << endl;
			break;
		case 9:
			cout << "Tell my family... Tell them I tried... Tell them I'm sorry..." << endl;
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

		cout << esc_char << bright << red;
		
		int rn = rand() % 10;
		cout << endl;
		switch (rn) {
		case 0:
			cout << "*Growl* Who dares intrude upon my territory?" << endl;
			break;
		case 1:
			cout << "*Snarl* Another fool seeks to challenge the mighty goblin!" << endl;
			break;
		case 2:
			cout << "*Grunts* Prepare to face my wrath!" << endl;
			break;
		case 3:
			cout << "*Chuckles* You're no match for the cunning of a goblin!" << endl;
			break;
		case 4:
			cout << "*Sneers* I'll make quick work of you, puny adventurer!" << endl;
			break;
		case 5:
			cout << "*Threatening growl* You've made a grave mistake crossing paths with a goblin!" << endl;
			break;
		case 6:
			cout << "*Taunts* You think you can defeat me? Ha! Prepare to be humbled!" << endl;
			break;
		case 7:
			cout << "*Laughs* Another victim for the goblin's blade!" << endl;
			break;
		case 8:
			cout << "*Snickers* You'll regret ever setting foot in my domain!" << endl;
			break;
		case 9:
			cout << "*Sneers* I'll relish the taste of victory over your broken body!" << endl;
			break;
		default:
			break;
		}

		cout << esc_char << endColor;
	}

	void setStats() {
		hp = level * 4 + (rand() % (level * 2));
		str = level;
		def = level;
		speed = level;
		crt = level;
		gold = (level * 10 + (rand() % (level * 50)))/2;
	}

	void printStats() {
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string endColor = "[0m";

		cout << esc_char << bright << red << "\nGoblin Stats:" << esc_char << endColor << endl;
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
		cout << esc_char << red << "\nBattle with level " << level << " Goblin begins!" << esc_char << endColor << endl;
		printStats();
		while (hp > 0 && p->getHP() > 0) {
			cout << endl;
			speak();
			cout << "\nCurrent HP: " << p->getHP() << "/" << p->getMaxHP() << endl;
			cout << "Goblin HP: " << hp;
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
				cout << "\nGoblin dropped " << gold << " gold!" << endl;
				p->setGold(p->getGold() + gold);
				cout << "Your current gold amount is: " << p->getGold() << endl;
				cout << "\nGoblin dropped an item!" << endl;
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
					cout << "The goblin took " << p->getSTR() << " damage!" << endl;
				}
				else {
					cout << "Critical hit!" << endl;
					hp -= p->getSTR() * 2;
					cout << "The goblin took " << p->getSTR() * 2 << " damage!" << endl;
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "Goblin blocked your attack!" << endl;
				}
				else {
					hp -= p->getSTR();
					cout << "The goblin took " << p->getSTR() << " damage!" << endl;
				}
			}
			if (hp > 0) {
				cout << "\nGoblin attacks!" << endl;
				if (str > p->getDEF()) {
					int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
					if (isCrit + crt < 25) {
						p->setHP(p->getHP() - str);
						cout << "You took " << str << " damage!" << endl;
					}
					else {
						cout << "Goblin scored a Critical hit!" << endl;
						p->setHP(p->getHP() - (str * 2));
						cout << "You took " << str * 2 << " damage!" << endl;
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "You blocked the goblin's attack!" << endl;
					}
					else {
						p->setHP(p->getHP() - str);
						cout << "You took " << str << " damage!" << endl;
					}
				}
			}

		}
		else {
			cout << "\nGoblin is faster!" << endl;
			if (str > p->getDEF()) {
				int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
				if (isCrit + crt < 25) {
					p->setHP(p->getHP() - str);
					cout << "You took " << str << " damage!" << endl;
				}
				else {
					cout << "Goblin scored a Critical hit!" << endl;
					p->setHP(p->getHP() - (str * 2));
					cout << "You took " << str * 2 << " damage!" << endl;
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "You blocked the goblin's attack!" << endl;
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
						cout << "The goblin took " << p->getSTR() << " damage!" << endl;
					}
					else {
						cout << "Critical hit!" << endl;
						hp -= p->getSTR() * 2;
						cout << "The goblin took " << p->getSTR() * 2 << " damage!" << endl;
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "Goblin blocked your attack!" << endl;
					}
					else {
						hp -= p->getSTR();
						cout << "The goblin took " << p->getSTR() << " damage!" << endl;
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