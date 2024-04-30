#ifndef SLIME_H
#define SLIME_H

#include "Enemy.h"
class Slime : public Enemy
{
public:
	//Constructors
	Slime() : Enemy() 
	{

	}
	Slime(int _level, int _gold, int _hp, int _str, int _def, int _speed, int _crt, string _status, Item* _i)
		: Enemy(_level, _gold, _hp, _str, _def, _speed, _crt, _status, _i) {}

	Slime(int _level, Item* _loot)
		: Enemy(_level, _loot) {}

	//Deconstructor
	~Slime() {
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

		cout << esc_char << bright << purple;
		
		int rn = rand() % 10;

		switch (rn) {
		case 0:
			cout << "Squish, squish... I hunger for adventurers!" << std::endl;
			break;
		case 1:
			cout << "Glop, glop... Your fate is sealed in my gooey grasp!" << std::endl;
			break;
		case 2:
			cout << "Slosh, slosh... Prepare to be engulfed in slime!" << std::endl;
			break;
		case 3:
			cout << "Blorp, blorp... I'll dissolve you into nothingness!" << std::endl;
			break;
		case 4:
			cout << "Squelch, squelch... Feel the slimy embrace of defeat!" << std::endl;
			break;
		case 5:
			cout << "Bloop, bloop... You can't escape my sticky ambush!" << std::endl;
			break;
		case 6:
			cout << "Splish, splash... Your journey ends here, in my domain!" << std::endl;
			break;
		case 7:
			cout << "Gurgle, gurgle... Your demise will be swallowed by slime!" << std::endl;
			break;
		case 8:
			cout << "Squidge, squidge... Resistance is futile against the slime onslaught!" << std::endl;
			break;
		case 9:
			cout << "Plop, plop... I'll leave nothing but a trail of ooze in my wake!" << std::endl;
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

		cout << esc_char << bright << purple;
		
		int rn = rand() % 10;

		switch (rn) {
		case 0:
			cout << "Splat! The slime dissolves into a puddle of goo." << std::endl;
			break;
		case 1:
			cout << "Pop! The slime bursts into a splatter of slimey droplets." << std::endl;
			break;
		case 2:
			cout << "Fizzle! The slime fizzles away, leaving only a sticky residue." << std::endl;
			break;
		case 3:
			cout << "Slurp! The slime slurps into the ground, disappearing without a trace." << std::endl;
			break;
		case 4:
			cout << "Gurgle! The slime gurgles and evaporates into thin air." << std::endl;
			break;
		case 5:
			cout << "Sploosh! The slime splashes everywhere before vanishing completely." << std::endl;
			break;
		case 6:
			cout << "Plop! The slime plops down, leaving behind only a slimy residue." << std::endl;
			break;
		case 7:
			cout << "Fizz! The slime fizzles away, leaving behind a faint odor of slime." << std::endl;
			break;
		case 8:
			cout << "Squelch! The slime squelches and vanishes into thin air." << std::endl;
			break;
		case 9:
			cout << "Bloop! The slime lets out one final bloop before disappearing." << std::endl;
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

		cout << esc_char << bright << purple;
		
		int rn = rand() % 10;
		cout << endl;
		switch (rn) {
		case 0:
			cout << "*Squelch* Who goes there? Another challenger?" << endl;
			break;
		case 1:
			cout << "*Gloop* Welcome to my domain! Prepare to be slimed!" << endl;
			break;
		case 2:
			cout << "*Slurp* Intruder detected! Get ready for a gooey showdown!" << endl;
			break;
		case 3:
			cout << "*Splat* You've stumbled into the lair of the almighty slime! Tremble before my squishy might!" << endl;
			break;
		case 4:
			cout << "*Squelchy squish* Another unsuspecting victim? How delightful! Let the sliming commence!" << endl;
			break;
		case 5:
			cout << "*Gurgle* Ah, fresh meat! I hope you're ready for a slippery battle!" << endl;
			break;
		case 6:
			cout << "*Blorp* You dare disturb the peace of the slime kingdom? Prepare to face the consequences!" << endl;
			break;
		case 7:
			cout << "*Slosh* I smell... prey. Time to show you the true power of the slime!" << endl;
			break;
		case 8:
			cout << "*Drip* You've entered the realm of the slime lord! Prepare to be enveloped in my gooey embrace!" << endl;
			break;
		case 9:
			cout << "*Plop* Another foolish adventurer? You won't last long against the might of this slime!" << endl;
			break;
		default:
			break;
		}

		cout << esc_char << endColor;
	}

	void setStats() {
		hp = level * 12 + (rand() % (level * 4));
		str = level;
		def = level;
		speed = level;
		crt = level;
		gold = level * 10 + (rand() % (level * 50));
	}

	void heal() {
		hp += (rand() % (level * 2));
	}

	void printStats() {
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string endColor = "[0m";
		
		cout << esc_char << bright << red << "\nSlime Stats:" << esc_char << endColor << endl;
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
		cout << esc_char << red << "\nBattle with level " << level << " Slime begins!" << esc_char << endColor << endl;
		printStats();
		while (hp > 0 && p->getHP() > 0) {
			cout << endl;
			speak();
			cout << "\nCurrent HP: " << p->getHP() << "/" << p->getMaxHP() << endl;
			cout << "Slime HP: " << hp;
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
					cout << "\nSlime sticks you to battle. Can't escape!" << endl;
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
				cout << "\nSlime dropped " << gold << " gold!" << endl;
				p->setGold(p->getGold() + gold);
				cout << "Your current gold amount is: " << p->getGold() << endl;
				cout << "\nSlime dropped an item!" << endl;
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
		int healMod = rand() % 2;													//Slime has a 50% chance to heal
		if (p->getSPD() >= speed) {
			cout <<"\n" << p->getName() << " is faster." << endl;
			if (p->getSTR() > def) {
				int isCrit = rand() % 50;											//You can only crit if your str > than enemy def

				if ((isCrit + p->getCRT()) < 25) {
					hp -= p->getSTR();
					cout << "The slime took " << p->getSTR() << " damage!" << endl;
				}
				else {
					cout << "Critical hit!" << endl;
					hp -= p->getSTR() * 2;
					cout << "The slime took " << p->getSTR() * 2 << " damage!" << endl;
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "Slime blocked your attack!" << endl;
				}
				else {
					hp -= p->getSTR();
					cout << "The slime took " << p->getSTR() << " damage!" << endl;
				}
			}
			if (hp > 0) {
				cout << "\nSlime attacks!" << endl;
				if (str > p->getDEF()) {
					int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
					if (isCrit + crt < 25) {
						p->setHP(p->getHP() - str);
						cout << "You took " << str << " damage!" << endl;
					}
					else {
						cout << "Slime scored a Critical hit!" << endl;
						p->setHP(p->getHP() - (str * 2));
						cout << "You took " << str * 2 << " damage!" << endl;
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "You blocked the slime's attack!" << endl;
					}
					else {
						p->setHP(p->getHP() - str);
						cout << "You took " << str << " damage!" << endl;
					}
				}
			}

		}
		else {
			cout << "\nSlime is faster!" << endl;
			if (str > p->getDEF()) {
				int isCrit = rand() % 50;											//You can only crit if your str > than enemy def
				if (isCrit + crt < 25) {
					p->setHP(p->getHP() - str);
					cout << "You took " << str << " damage!" << endl;
				}
				else {
					cout << "Slime scored a Critical hit!" << endl;
					p->setHP(p->getHP() - (str * 2));
					cout << "You took " << str * 2 << " damage!" << endl;
				}
			}
			else {
				int blocked = rand() % 2;
				if (blocked == 0) {
					cout << "You blocked the slime's attack!" << endl;
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
						cout << "The slime took " << p->getSTR() << " damage!" << endl;
					}
					else {
						cout << "Critical hit!" << endl;
						hp -= p->getSTR() * 2;
						cout << "The slime took " << p->getSTR() * 2 << " damage!" << endl;
					}
				}
				else {
					int blocked = rand() % 2;
					if (blocked == 0) {
						cout << "Slime blocked your attack!" << endl;
					}
					else {
						hp -= p->getSTR();
						cout << "The slime took " << p->getSTR() << " damage!" << endl;
					}
				}
			}
		}

		if (healMod < 1 && hp > 0) {
			cout << "\nSlime heals this turn" << endl;
			heal();
		}

		if (p->getSTATUS() == "Poisoned") {
			cout << "\n You take " << level / 2 << " poison damage..." << endl;
			p->setHP(p->getHP() - level / 2);
		}


	}

	bool run(Player* p) {
		return false;
	}
};

#endif

