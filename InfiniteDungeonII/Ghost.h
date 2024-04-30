#ifndef GHOST_H
#define GHOST_H
#include "Enemy.h"

class Ghost : public Enemy
{
public:
	//Constructors
	Ghost() : Enemy()
	{

	}
	Ghost(int _level, int _gold, int _hp, int _str, int _def, int _speed, int _crt, string _status, Item* _i)
		: Enemy(_level, _gold, _hp, _str, _def, _speed, _crt, _status, _i) {}

	Ghost(int _level, Item* _loot)
		: Enemy(_level, _loot) {}

	//Deconstructor
	~Ghost() {
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

		cout << esc_char << bright << cyan;
		
		int rn = rand() % 10;

		switch (rn) {
		case 0:
			cout << "Boo! Did I scare you? Oh, I hope so!" << endl;
			break;
		case 1:
			cout << "Feel the chill of the grave, mortal!" << endl;
			break;
		case 2:
			cout << "I've been waiting for someone to play with for centuries!" << endl;
			break;
		case 3:
			cout << "You can't escape me, adventurer. I'll haunt you to the ends of the earth!" << endl;
			break;
		case 4:
			cout << "Your fear feeds me, makes me stronger!" << endl;
			break;
		case 5:
			cout << "Do you hear the whispers of the departed? They're telling you to run!" << endl;
			break;
		case 6:
			cout << "Come closer, mortal. I promise it won't hurt... much." << endl;
			break;
		case 7:
			cout << "You think you can defeat me? Foolish mortal! I am eternal!" << endl;
			break;
		case 8:
			cout << "I am the ghost of this dungeon, and you are trespassing on my domain!" << endl;
			break;
		case 9:
			cout << "Your soul will make a fine addition to my collection!" << endl;
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

		cout << esc_char << bright << cyan;
		
		int rn = rand() % 10;

		switch (rn) {
		case 0:
			cout << "Looks like I'm ghosting this battle! Get it? Ghosting? Ah, never mind..." << endl;
			break;
		case 1:
			cout << "Well, that's a wrap for me! Time to haunt some other place... if I can find my way there." << endl;
			break;
		case 2:
			cout << "Guess I'll be taking a ghost nap now. Wake me up when it's time for the afterlife party!" << endl;
			break;
		case 3:
			cout << "Woo-hoo! I'm finally free from this dungeon! Catch you on the other side, adventurers!" << endl;
			break;
		case 4:
			cout << "So this is what it feels like to pass on... Not bad, not bad at all!" << endl;
			break;
		case 5:
			cout << "Thanks for releasing me from this spectral prison, brave souls. I owe you one!" << endl;
			break;
		case 6:
			cout << "Ah, sweet release! Farewell, mortal realm. I'll miss the spooktacular battles." << endl;
			break;
		case 7:
			cout << "Time to fade into the ether... but not before I give you one last spooky farewell!" << endl;
			break;
		case 8:
			cout << "Well, I guess it's back to ghostly haunting duties for me. At least I'll have some new stories to tell!" << endl;
			break;
		case 9:
			cout << "Goodbye, cruel world! Wait, scratch that. Goodbye, adventurers! Thanks for the memories... and the battles!" << endl;
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

		cout << esc_char << bright << cyan;
		
		int rn = rand() % 10;
		cout << endl;
		switch (rn) {
		case 0:
			cout << "*Eerie whisper* You've trespassed into the realm of the restless dead..." << endl;
			break;
		case 1:
			cout << "*Ghastly moan* Beware, mortal, for you stand on the threshold of eternal darkness..." << endl;
			break;
		case 2:
			cout << "*Chilling wail* You cannot escape your fate... the ghostly realm awaits!" << endl;
			break;
		case 3:
			cout << "*Haunting laughter* Foolish mortal, your presence here is an affront to the spirits..." << endl;
			break;
		case 4:
			cout << "*Spine-tingling hiss* Your mortal senses betray you, for you tread where the living dare not..." << endl;
			break;
		case 5:
			cout << "*Spectral whisper* Can you feel the chill of the grave, mortal? It draws ever closer..." << endl;
			break;
		case 6:
			cout << "*Echoing groan* Your existence fades into shadow, consumed by the darkness that surrounds you..." << endl;
			break;
		case 7:
			cout << "*Sinister murmur* The spirits hunger for your soul, mortal. Will you defy their grasp?" << endl;
			break;
		case 8:
			cout << "*Ghostly sigh* You are but a flickering candle in the abyss, soon to be extinguished..." << endl;
			break;
		case 9:
			cout << "*Whispers from beyond* Turn back now, mortal, for the realm of the dead offers no sanctuary..." << endl;
			break;
		default:
			break;
		}

		cout << esc_char << endColor;
	}

	void setStats() {
		hp = level * 8 + (rand() % (level * 2));
		str = level;
		def = level + (rand() % (level*2));
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

		cout << esc_char << bright << red << "\nGhost Stats:" << esc_char << endColor << endl;
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
		cout << esc_char << cyan << "\nBattle with level " << level << " Ghost begins!" << esc_char << endColor << endl;
		printStats();
		while (hp > 0 && p->getHP() > 0) {
			cout << endl;
			speak();
			cout << "\nCurrent HP: " << p->getHP() << "/" << p->getMaxHP() << endl;
			cout << "Ghost HP: " << hp;
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
				cout << "\nGhost dropped " << gold << " gold!" << endl;
				p->setGold(p->getGold() + gold);
				cout << "Your current gold amount is: " << p->getGold() << endl;
				cout << "\nGhost dropped an item!" << endl;
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
		int freezeMod = rand() % 2;
		if (p->getSPD() >= speed) {
			cout << "\n" << p->getName() << " is faster." << endl;
			if (p->getSTR() > def) {
				int isCrit = rand() % 50;											//You can only crit if your str > than enemy def

				if ((isCrit + p->getCRT()) < 25) {
					hp -= p->getSTR();
					cout << "The ghost took " << p->getSTR() << " damage!" << endl;
				}
				else {
					cout << "Critical hit!" << endl;
					hp -= p->getSTR() * 2;
					cout << "The ghost took " << p->getSTR() * 2 << " damage!" << endl;
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "Your attack went through the Ghost!" << endl;
					if (freezeMod == 0 && p->getSTATUS() == "none") {
						cout << "\nYou have been frozen!" << endl;
						freeze(p);
						p->printStats();
					}
				}
				else {
					hp -= p->getSTR();
					cout << "The ghost took " << p->getSTR() << " damage!" << endl;
				}
			}
			if (hp > 0) {
				cout << "\nGhost attacks!" << endl;
				if (str > p->getDEF()) {
					int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
					if (isCrit + crt < 25) {
						p->setHP(p->getHP() - str);
						cout << "You took " << str << " damage!" << endl;
					}
					else {
						cout << "Ghost scored a Critical hit!" << endl;
						p->setHP(p->getHP() - (str * 2));
						cout << "You took " << str * 2 << " damage!" << endl;
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "You blocked the ghost's attack!" << endl;
					}
					else {
						p->setHP(p->getHP() - str);
						cout << "You took " << str << " damage!" << endl;
					}
				}
			}

		}
		else {
			cout << "\nGhost is faster!" << endl;
			if (str > p->getDEF()) {
				int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
				if (isCrit + crt < 25) {
					p->setHP(p->getHP() - str);
					cout << "You took " << str << " damage!" << endl;
				}
				else {
					cout << "Ghost scored a Critical hit!" << endl;
					p->setHP(p->getHP() - (str * 2));
					cout << "You took " << str * 2 << " damage!" << endl;
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "You blocked the ghost's attack!" << endl;
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
						cout << "The ghost took " << p->getSTR() << " damage!" << endl;
					}
					else {
						cout << "Critical hit!" << endl;
						hp -= p->getSTR() * 2;
						cout << "The ghost took " << p->getSTR() * 2 << " damage!" << endl;
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "Your attack went through the Ghost!" << endl;
						if (freezeMod == 0 && p->getSTATUS() == "none") {
							cout << "\nYou have been frozen!" << endl;
							freeze(p);
							
						}
					}
					else {
						hp -= p->getSTR();
						cout << "The ghost took " << p->getSTR() << " damage!" << endl;
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

	void freeze(Player* p) {
		if (p->getSTATUS() == "none") {
			p->setSTATUS("Frozen");
			p->setSPD(p->getSPD() / 2);
		}
	}
};

#endif