#ifndef KOBOLD_H
#define KOBOLD_H

#include "Enemy.h"
class Kobold : public Enemy
{
public:
	//Constructors
	Kobold() : Enemy()
	{

	}
	Kobold(int _level, int _gold, int _hp, int _str, int _def, int _speed, int _crt, string _status, Item* _i)
		: Enemy(_level, _gold, _hp, _str, _def, _speed, _crt, _status, _i) {}

	Kobold(int _level, Item* _loot)
		: Enemy(_level, _loot) {}

	//Deconstructor
	~Kobold() {
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

		cout << esc_char << bright << yellow;
		
		int rn = rand() % 10;

		switch (rn) {
		case 0:
			cout << "Mine! All shiny treasures belong to me, this mighty kobold!" << endl;
			break;
		case 1:
			cout << "Gold, gems, trinkets... I want it all! And I'll take it, too!" << endl;
			break;
		case 2:
			cout << "Bah! You think you can outsmart a kobold when it comes to treasure?" << endl;
			break;
		case 3:
			cout << "Step aside, fools! This kobold is on the hunt for wealth!" << endl;
			break;
		case 4:
			cout << "What's that glinting over there? Don't mind if I help myself..." << endl;
			break;
		case 5:
			cout << "Riches beyond measure await those clever enough to follow this kobold!" << endl;
			break;
		case 6:
			cout << "You there! Hand over your valuables or face my wrath!" << endl;
			break;
		case 7:
			cout << "Hoarder? No, just a kobold with impeccable taste in shiny things!" << endl;
			break;
		case 8:
			cout << "Every coin, every bauble, every piece of gold... It's all mine!" << endl;
			break;
		case 9:
			cout << "The kobold's motto: 'Finders keepers, losers weepers!'" << endl;
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

		cout << esc_char << bright << yellow;
		
		int rn = rand() % 10;

		switch (rn) {
		case 0:
                cout << "Oh, the agony! My precious coins... they're slipping through my stubby fingers!" << endl;
                break;
            case 1:
                cout << "Alas, poor kobold! Bereft of gold, I shuffle off this mortal coil..." << endl;
                break;
            case 2:
                cout << "My hoard... my treasure... gone in the blink of an eye! Guess I'll just roll over and cry..." << endl;
                break;
            case 3:
                cout << "Farewell, cruel world! And farewell, even crueler thieves who took all my shiny stuff!" << endl;
                break;
            case 4:
                cout << "Death comes for me, but not before I bid adieu to my beloved stash of shiny things..." << endl;
                break;
            case 5:
                cout << "It's not fair! All I wanted was to swim in my mountain of gold coins... now I'm swimming in regret..." << endl;
                break;
            case 6:
                cout << "Here lies a kobold who once had it all... now he's just a broke little creature in a big, scary world." << endl;
                break;
            case 7:
                cout << "Goodbye, my treasures! May you find better owners than the heartless adventurers who plundered my hoard!" << endl;
                break;
            case 8:
                cout << "Oh, woe is me! My pockets are empty, my heart is heavy, and my time is up..." << endl;
                break;
            case 9:
                cout << "Rest in peace, dear wealth! I'll miss counting you, fondling you, and sleeping on a bed made of you..." << endl;
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

		cout << esc_char << bright << yellow;
		
		int rn = rand() % 10;
		cout << endl;
		switch (rn) {
		case 0:
			cout << "*Chittering* Ah, another treasure-seeker? You dare challenge my might?" << endl;
			break;
		case 1:
			cout << "*Snarls* You seek riches in our domain? Prepare to face the wrath of this kobold!" << endl;
			break;
		case 2:
			cout << "*Grunts* The treasures you covet belong ME!!!! Begone, thief!" << endl;
			break;
		case 3:
			cout << "*Chuckles* Greed has brought you here, but it will be your downfall in the end!" << endl;
			break;
		case 4:
			cout << "*Sneers* Gold and gems? They're mine, all mine! You'll not lay a hand on them!" << endl;
			break;
		case 5:
			cout << "*Threatening growl* You dare try to take my gold?!!! Prepare to suffer for your greed!" << endl;
			break;
		case 6:
			cout << "*Taunts* You think you can steal my stash!? Think again!" << endl;
			break;
		case 7:
			cout << "*Laughs* Another dungeon dweller?? How amusing! But none shall claim the kobold's riches!" << endl;
			break;
		case 8:
			cout << "*Snickers* You came seeking wealth, but you'll leave empty-handed, at the mercy of this kobold's greed!" << endl;
			break;
		case 9:
			cout << "*Sneers* The treasures of this kobold are not for the likes of you! Prepare to leave with nothing!" << endl;
			break;
		default:
			break;
		}

		cout << esc_char << endColor;
	}

	void setStats() {
		hp = level * 8 + (rand() % (level * 2));
		str = level + (rand() % (level*2));
		def = level;
		speed = level;
		crt = level;
		gold = (level * 10 + (rand() % (level * 50))) * 2;
	}

	void printStats() {
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string endColor = "[0m";

		cout << esc_char << bright << red << "\nKobold Stats:" << esc_char << endColor << endl;
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
		cout << esc_char << red << "\nBattle with level " << level << " Kobold begins!" << esc_char << endColor << endl;
		printStats();
		while (hp > 0 && p->getHP() > 0) {
			cout << endl;
			speak();
			cout << "\nCurrent HP: " << p->getHP() << "/" << p->getMaxHP() << endl;
			cout << "Kobold HP: " << hp;
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
				cout << "\nKobold dropped " << gold << " gold!" << endl;
				p->setGold(p->getGold() + gold);
				cout << "Your current gold amount is: " << p->getGold() << endl;
				cout << "\nKobold dropped an item!" << endl;
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
					cout << "The kobold took " << p->getSTR() << " damage!" << endl;
				}
				else {
					cout << "Critical hit!" << endl;
					hp -= p->getSTR() * 2;
					cout << "The kobold took " << p->getSTR() * 2 << " damage!" << endl;
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "Kobold blocked your attack!" << endl;
				}
				else {
					hp -= p->getSTR();
					cout << "The kobold took " << p->getSTR() << " damage!" << endl;
				}
			}
			if (hp > 0) {
				cout << "\nKobold attacks!" << endl;
				if (str > p->getDEF()) {
					int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
					if (isCrit + crt < 25) {
						p->setHP(p->getHP() - str);
						cout << "You took " << str << " damage!" << endl;
					}
					else {
						cout << "Kobold scored a Critical hit!" << endl;
						p->setHP(p->getHP() - (str * 2));
						cout << "You took " << str * 2 << " damage!" << endl;
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "You blocked the kobold's attack!" << endl;
					}
					else {
						p->setHP(p->getHP() - str);
						cout << "You took " << str << " damage!" << endl;
					}
				}
			}

		}
		else {
			cout << "\nKobold is faster!" << endl;
			if (str > p->getDEF()) {
				int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
				if (isCrit + crt < 25) {
					p->setHP(p->getHP() - str);
					cout << "You took " << str << " damage!" << endl;
				}
				else {
					cout << "Kobold scored a Critical hit!" << endl;
					p->setHP(p->getHP() - (str * 2));
					cout << "You took " << str * 2 << " damage!" << endl;
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "You blocked the kobold's attack!" << endl;
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
						cout << "The kobold took " << p->getSTR() << " damage!" << endl;
					}
					else {
						cout << "Critical hit!" << endl;
						hp -= p->getSTR() * 2;
						cout << "The kobold took " << p->getSTR() * 2 << " damage!" << endl;
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "Kobold blocked your attack!" << endl;
					}
					else {
						hp -= p->getSTR();
						cout << "The kobold took " << p->getSTR() << " damage!" << endl;
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