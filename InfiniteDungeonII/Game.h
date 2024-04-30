#ifndef GAME_H
#define GAME_H

#include "DungeonLevel.h"
#include <fstream>
#include <string>

class Game
{
private:
	int level;
	bool f;
	string fname;
	int seed;
public:
	//Constructor
	Game() : level(1), f(true), fname(""), seed(1) {}
	Game(int l) : level(l), f(true), fname(""), seed(1) {}

	//Deconstructor
	~Game() {}

	//Getters
	int getLevel() { return level; }

	//Setters
	void setLevel(int l) { level = l; }

	//Member Functions
	Player* createChar() {
		string name;
		int inputClass;
		string p_class;
		cout << "\nCharacter creation: " << endl;
		cout << "\nPlease enter a name for your character: " << endl;
		cin.ignore();
		getline(cin, name);
		cout << "\nPlease select a class: " << endl;
		cout << "\n1 - Warrior (for higher STR and HP!)\n2 - Rogue (for higher SPD and CRT!)\n3 - Bastion (for higher DEF and HP!)\n4 - Rusher (for higher SPD and STR!)" << endl;
		cin >> inputClass;

		switch (inputClass) {
		case 1:
			p_class = "Warrior";
			break;
		case 2:
			p_class = "Rogue";
			break;
		case 3:
			p_class = "Bastion";
			break;
		case 4:
			p_class = "Rusher";
			break;
		default:
			break;
		}

		Player* p = new Player(level, name, p_class);
		return p;
	}

	DungeonLevel* generateLevel(Player * p) {
		DungeonLevel* d = new DungeonLevel(level, p);
		p->setLVL(level);
		p->syncStats();
		return d;
	}

	void ascendLevel() {
		level++;
	}

	void saveFile(Player* p) {
		ofstream sfile(fname);
		sfile << seed << endl;
		sfile << level << endl;
		sfile << p->getName() << endl;
		sfile << p->getClass() << endl;
		sfile << p->getGold() << endl;
		sfile << p->getI()->getCurSize() << endl;
		for (int i = 0; i < p->getI()->getCurSize(); i++) {
			sfile << p->getI()->getList().at(i)->getLevel() << endl;
			sfile << p->getI()->getList().at(i)->getPrice() << endl;
			sfile << p->getI()->getList().at(i)->getName() << endl;
			sfile << p->getI()->getList().at(i)->getIsWeapon() << endl;
			sfile << p->getI()->getList().at(i)->getIsCons() << endl;
		}
	}

	void loadTest(string _fname) noexcept(false){
		ifstream ifile(_fname);

		if (!ifile.is_open()) { throw FileIOError(); }
	}
	
	void seedTest(int _s) noexcept(false){
		if (_s > 2147483646) { throw invalidSeed(); }
	}

	void fNameTest(string _fname) noexcept(false) {
		if (_fname.substr(_fname.length() - 4) != ".txt") { throw invalidFName(); }
	}
	
	Player* loadFile(string _fname) {
		ifstream ifile(_fname);
		
		if (!ifile.is_open()) {
			cout << "File not found." << endl;

			return nullptr;
		}
		else {
			
			ifile >> seed;
			ifile >> level;

			srand(seed);

			string name;
			string pclass;
			int gold;
			int bpSize;

			ifile.ignore();
			getline(ifile, name);
			ifile >> pclass;
			ifile >> gold;
			ifile >> bpSize;

			int iLevel;
			int iPrice;
			string iName;
			bool iWeap;
			bool iCons;

			
			vector<Item*>loadi;
			for (int i = 0; i < bpSize; i++) {
				ifile >> iLevel;
				ifile >> iPrice;
				ifile.ignore();
				getline(ifile, iName);
				ifile >> iWeap;
				ifile >> iCons;

				if (iWeap) {
					Item* i = new WeaponItem(iLevel, iPrice, iName, iWeap, iCons);
					loadi.push_back(i);
				}
				else {
					Item* i = new ConsumableItem(iLevel, iPrice, iName, iWeap, iCons);
					loadi.push_back(i);
				}
				
			}

			Inventory* bp = new Inventory(bpSize, level + 3, loadi);

			Player* loadP = new Player(level, name, pclass, gold, bp);

			return loadP;
		}

		
	}



	void run() {
		char esc_char = 27;
		string red = "\033[31m";
		string yellow = "\033[33m";
		string cyan = "\033[36m";
		string purple = "\033[35m";
		string bright = "\033[1m";
		string endColor = "[0m";
		
		cout << esc_char << red << "Welcome to Infinite Dungeon - a game by carlcodecode" << esc_char << endColor << endl;
		cout << "\nPlease select an option below: " << endl;
		
		int start = -1;
		cout << "1 - New Game" << endl;
		cout << "2 - Load Game" << endl;

		cin >> start;

		if (start == 1) {
			cout << "\nWhat do you want to name your save file? (.txt format)" << endl;
			cin >> fname;

			try {
				fNameTest(fname);
			}
			catch (invalidFName) {
				fname += ".txt";
				cout << "\nAppended .txt to file name" << endl;
			}

			cout << "\nPlease enter an integer-value seed (this will determine all the random instances in the game): ";
			cin >> seed;

			try {
				seedTest(seed);
			}
			catch (invalidSeed) {
				cout << "Please choose a seed under 2147483647" << endl;
				cin >> seed;
			}

			srand(seed);
			cout << endl;

			Player* myP = createChar();			// Creating player

			Inventory* myI = new Inventory();	// Creating player inventory
			myP->setI(myI);
			
			myP->syncStats();					// Initializing the stats
			myP->setHP(myP->getMaxHP());			// Setting HP to full
			myP->printStats();

			cout << esc_char << red << "\nEntering dungeon..." << esc_char << endColor << endl;

			int mmInput = -1;

			do {
				cout << esc_char << bright << purple << "\n~Game Menu~" << esc_char << endColor << endl;
				cout << "1 - Progress through level " << level << endl;
				cout << "2 - Ascend to level " << level + 1 << " (cost to ascend: " << level*100 << ")" << endl;
				cout << "3 - Exit game " << endl;

				cin >> mmInput;

				DungeonLevel* dl = generateLevel(myP);
				

				if (mmInput == 1) {
					myP->setHP(myP->getMaxHP());
					saveFile(myP);
					dl->runInstance();
					
				}
				else if (mmInput == 2) {
					int price = 100 * level;
					if (myP->getGold() >= price) {
						int aIn = -1;
						cout << "\nAre you sure you want to ascend? \n1 - Yes\n2 - No" << endl;
						cin >> aIn;
						if (aIn == 1) {
							cout << esc_char << bright << yellow << "\n" << myP->getName() << " ascends to level " << level + 1 << "!" << esc_char << endColor << endl;
							myP->setGold(myP->getGold() - price);
							ascendLevel();
						}
						else {
							cout << "\nThe Dungeon Master is displeased..." << endl;
							cout << "\nShifting floor layout..." << endl;
						}
					}
					else {
						cout << "\nThe Dungeon Master is confused, " << esc_char << bright << red << "\"You know you don't have enough gold right? Hahahaha\"" << esc_char << endColor << endl;
						cout << "\nShifting floor layout..." << endl;
					}
					
				}
				else if (mmInput == 3) {
					int cIn;
					cout << "\nAre you sure you want to exit? (All progress after the campfire room will not be saved)" << endl;
					cout << "1 - Yes\n2 - No" << endl;
					cin >> cIn;
					if (cIn == 1) {
						cout << "Thanks for playing!\nExiting Game..." << endl;
					}
					else {
						mmInput = 0;
						cout << "Continuing game..." << endl;
					}
				}
			} while (mmInput != 3 && myP->getHP()>0);
		}
		else {
			cout << "\nPlease enter the name of the file you want to load. (.txt format)" << endl;
			string lname;

			cin >> lname;

			try {
				loadTest(lname);
			}
			catch(FileIOError){
				cout << "\nFile could not be opened!" << endl;
				exit(0);
			}

			cout << "\nLoading game..." << endl;

			Player* myP = loadFile(lname);
			myP->syncStats();
			myP->setHP(myP->getMaxHP());
			myP->printStats();

			cout << esc_char << red << "\nEntering dungeon..." << esc_char << endColor << endl;

			int mmInput = -1;

			do {
				cout << esc_char << bright << purple << "\n~Game Menu~" << esc_char << endColor << endl;
				cout << "1 - Progress through level " << level << " (Save game)" << endl;
				cout << "2 - Ascend to level " << level + 1 << " (cost to ascend: " << level * 100 << ")" << endl;
				cout << "3 - Exit game " << endl;

				cin >> mmInput;

				DungeonLevel* dl = generateLevel(myP);


				if (mmInput == 1) {
					myP->setHP(myP->getMaxHP());
					dl->runInstance();
					saveFile(myP);
				}
				else if (mmInput == 2) {
					int price = 100 * level;
					if (myP->getGold() >= price) {
						int aIn = -1;
						cout << "\nAre you sure you want to ascend? \n1 - Yes\n2 - No" << endl;
						cin >> aIn;
						if (aIn == 1) {
							cout << esc_char << bright << yellow << "\n" << myP->getName() << " ascends to level " << level + 1 << "!" << esc_char << endColor << endl;
							myP->setGold(myP->getGold() - price);
							ascendLevel();
							
						}
						else {
							cout << "\nThe Dungeon Master is displeased..." << endl;
							cout << "\nShifting floor layout..." << endl;
						}
					}
					else {
						cout << "\nThe Dungeon Master is confused, " << esc_char << bright << red << "\"You know you don't have enough gold right? Hahahaha\"" << esc_char << endColor << endl;
						cout << "\nShifting floor layout..." << endl;
					}

				}
				else if (mmInput == 3) {
					int cIn;
					cout << "\nAre you sure you want to exit? (All progress after the campfire room will not be saved)" << endl;
					cout << "1 - Yes\n2 - No" << endl;
					cin >> cIn;
					if (cIn == 1) {
						cout << "Thanks for playing!\nExiting Game..." << endl;
					}
					else {
						mmInput = 0;
						cout << "Continuing game..." << endl;
					}
				}
			} while (mmInput != 3 && myP->getHP() > 0);

		}
	}


	//Exception Handling
	class FileIOError {
	};

	class invalidFName{
	};

	class invalidSeed {
	};



};

#endif
