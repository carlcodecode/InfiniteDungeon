#ifndef RAT_H
#define RAT_H
#include "Enemy.h"
class Rat : public Enemy
{
public:
	//Constructors
	Rat() : Enemy()
	{

	}
	Rat(int _level, int _gold, int _hp, int _str, int _def, int _speed, int _crt, string _status, Item* _i)
		: Enemy(_level, _gold, _hp, _str, _def, _speed, _crt, _status, _i) {}

	Rat(int _level, Item* _loot)
		: Enemy(_level, _loot) {}

	//Deconstructor
	~Rat() {
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

		cout << esc_char << purple;
		
		int rn = rand() % 10;

		switch (rn) {
		case 0:
			cout << "You've stumbled into my domain, adventurer! Prepare to face the fury of my fangs!" << endl;
			break;
		case 1:
			cout << "In the darkness of these tunnels, I am king! None can challenge my rule!" << endl;
			break;
		case 2:
			cout << "Feel the bite of my razor-sharp teeth! My claws hunger for your flesh!" << endl;
			break;
		case 3:
			cout << "You may think yourself brave, but facing me will test the very limits of your courage!" << endl;
			break;
		case 4:
			cout << "Beware the shadows, for that's where I strike! The sting of my venom awaits you!" << endl;
			break;
		case 5:
			cout << "In the darkness, I am unstoppable! Prepare for a battle you won't soon forget!" << endl;
			break;
		case 6:
			cout << "You'll find my bite more than just painful... it's a toxin that spells your doom!" << endl;
			break;
		case 7:
			cout << "Every scratch, every bite... brings you closer to the venom's embrace!" << endl;
			break;
		case 8:
			cout << "Even if you defeat me, the poison lingers. A reminder of your folly in challenging me!" << endl;
			break;
		case 9:
			cout << "Rats may be small, but I am mighty! Face me if you dare, and taste the wrath of the underworld!" << endl;
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

		cout << esc_char << purple;

		int rn = rand() % 10;

		switch (rn) {
		case 0:
			cout << "You may have defeated me, but my brethren will avenge my demise!" << endl;
			break;
		case 1:
			cout << "The darkness... it calls to me. Farewell, adventurer... may we meet again in the shadows..." << endl;
			break;
		case 2:
			cout << "My venom... it failed me. My reign... ends here..." << endl;
			break;
		case 3:
			cout << "My strength... wanes. But beware... the rats of these tunnels are many..." << endl;
			break;
		case 4:
			cout << "You think this victory... will save you? You've only just begun to face... the darkness..." << endl;
			break;
		case 5:
			cout << "No... I refuse to die like this... Curse you, adventurer... Curse you..." << endl;
			break;
		case 6:
			cout << "My bite... my venom... was it not enough? The shadows... they... consume me..." << endl;
			break;
		case 7:
			cout << "You may have slain me, but the darkness within... it will never die..." << endl;
			break;
		case 8:
			cout << "The rat king... will avenge me... Beware his wrath..." << endl;
			break;
		case 9:
			cout << "My end draws near... but remember, adventurer... the rats are always watching..." << endl;
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

		cout << esc_char << purple;

		int rn = rand() % 10;
		cout << endl;
		switch (rn) {
		case 0:
			cout << "*Squeak* Welcome, intruder! Prepare to face the venomous wrath of the dungeon's vermin!" << endl;
			break;
		case 1:
			cout << "*Scuttle* Look who's stumbled into our lair! Ready to dance with death, are you?" << endl;
			break;
		case 2:
			cout << "*Chitter* Another foolhardy adventurer? Beware the poisoned fangs of the rat, for they hunger for your demise!" << endl;
			break;
		case 3:
			cout << "*Scurry* Ah, fresh prey! Shall we indulge in a deadly game of cat and mouse?" << endl;
			break;
		case 4:
			cout << "*Sniff* What's that scent? The aroma of fear? Delicious! Let's see if you can withstand the venomous bite!" << endl;
			break;
		case 5:
			cout << "*Whisker twitch* Don't mind us, just sharpening our venomous fangs in anticipation of your demise!" << endl;
			break;
		case 6:
			cout << "*Gnaw* Hey there! Care for a taste of our toxic embrace? It's sure to leave a lasting impression!" << endl;
			break;
		case 7:
			cout << "*Skitter* If you're seeking a challenge, look no further! The poison coursing through our veins thirsts for your demise!" << endl;
			break;
		case 8:
			cout << "*Squeal* Oh, we love welcoming new prey! But be warned: our bite carries the sting of death!" << endl;
			break;
		case 9:
			cout << "*Chew* Haha, don't mind the gnawing. It's just our way of luring you into our poisonous trap!" << endl;
			break;
		default:
			break;
		}

		cout << esc_char << endColor;
	}

	void setStats() {
		hp = level * 8 + (rand() % (level * 2));
		str = level;
		def = level;
		speed = level;
		crt = level + (rand() % (level*2));
		gold = (level * 10 + (rand() % (level * 50)));
	}

	void printStats() {
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string green = "\033[32";
		string endColor = "[0m";

		cout << esc_char << bright << red << "\nRat Stats:" << esc_char << endColor << endl;
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
		string green = "\033[32";
		string endColor = "[0m";
		
		setStats();
		int input = 0;
		cout << esc_char << red << "\nBattle with level " << level << " Rat begins!" << esc_char << endColor << endl;
		printStats();
		while (hp > 0 && p->getHP() > 0) {
			cout << endl;
			speak();
			cout << "\nCurrent HP: " << p->getHP() << "/" << p->getMaxHP() << endl;
			cout << "Rat HP: " << hp;
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
				cout << "\nRat dropped " << gold << " gold!" << endl;
				p->setGold(p->getGold() + gold);
				cout << "Your current gold amount is: " << p->getGold() << endl;
				cout << "\nRat dropped an item!" << endl;
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
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string green = "\033[32";
		string endColor = "[0m";
		
		if (p->getSPD() >= speed) {
			cout << "\n" << p->getName() << " is faster." << endl;
			if (p->getSTR() > def) {
				int isCrit = rand() % 50;											//You can only crit if your str > than enemy def

				if ((isCrit + p->getCRT()) < 25) {
					hp -= p->getSTR();
					cout << "The rat took " << p->getSTR() << " damage!" << endl;
				}
				else {
					cout << "Critical hit!" << endl;
					hp -= p->getSTR() * 2;
					cout << "The rat took " << p->getSTR() * 2 << " damage!" << endl;
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "Rat blocked your attack!" << endl;
				}
				else {
					hp -= p->getSTR();
					cout << "The rat took " << p->getSTR() << " damage!" << endl;
				}
			}
			if (hp > 0) {
				cout << "\nRat attacks!" << endl;
				if (str > p->getDEF()) {
					int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
					if (isCrit + crt < 25) {
						p->setHP(p->getHP() - str);
						cout << "You took " << str << " damage!" << endl;
					}
					else {
						cout << "Rat scored a Critical hit!" << endl;
						p->setHP(p->getHP() - (str * 2));
						cout << "You took " << str * 2 << " damage!" << endl;

						if (p->getSTATUS() == "none") {
							cout << "\nThe rat's fangs imbue poison in your body!" << endl;
							poison(p);
						}
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "You blocked the rat's attack!" << endl;
					}
					else {
						p->setHP(p->getHP() - str);
						cout << "You took " << str << " damage!" << endl;
					}
				}
			}

		}
		else {
			cout << "\nRat is faster!" << endl;
			if (str > p->getDEF()) {
				int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
				if (isCrit + crt < 25) {
					p->setHP(p->getHP() - str);
					cout << "You took " << str << " damage!" << endl;
				}
				else {
					cout << "Rat scored a Critical hit!" << endl;
					p->setHP(p->getHP() - (str * 2));
					cout << "You took " << str * 2 << " damage!" << endl;

					if (p->getSTATUS() == "none") {
						cout << "\nThe rat's fangs imbue poison in your body!" << endl;
						poison(p);
					}
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "You blocked the rat's attack!" << endl;
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
						cout << "The rat took " << p->getSTR() << " damage!" << endl;
					}
					else {
						cout << "Critical hit!" << endl;
						hp -= p->getSTR() * 2;
						cout << "The rat took " << p->getSTR() * 2 << " damage!" << endl;
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "Rat blocked your attack!" << endl;
					}
					else {
						hp -= p->getSTR();
						cout << "The rat took " << p->getSTR() << " damage!" << endl;
					}
				}
			}
		}

		if (p->getSTATUS() == "Poisoned") {
			cout << esc_char << red << "\n You take " << level / 2 << " poison damage..." << esc_char << endColor << endl;
			p->setHP(p->getHP() - level/2);
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

	void poison(Player* p) {
		if (p->getSTATUS() == "none") {
			p->setSTATUS("Poisoned");
		}
	}
};

#endif