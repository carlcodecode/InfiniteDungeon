#ifndef SHOPROOM_H
#define SHOPROOM_H

#include "Room.h"
#include "ConsumableItem.h"
#include "WeaponItem.h"

class ShopRoom : public Room
{
private:
	Inventory* shopItems;

public:
	//Constructors
	ShopRoom() : Room(), shopItems(nullptr) {}
	ShopRoom(int _x, int _y, Player* _p, bool _e, int _l, Inventory* _shop)
		: Room(_x, _y, _p, _e, _l), shopItems(_shop) {}
    ShopRoom(int _x, int _y, Player* _p, bool _e, int _l)
        : Room(_x, _y, _p, _e, _l), shopItems(nullptr) {}

	//Deconstructor
	~ShopRoom() {
		delete shopItems;
	}

	//Getters
	Inventory* getShopItems() { return shopItems; }

	//Setters
	void setShopItems(Inventory* _shop) { shopItems = _shop; }

	//Member Functions
	void test() {
		cout << "\nSuccesfully created a shop room at (" << x << ", " << y << ")" << endl;
		cout << p->getName() << " is currently in the room." << endl;
		shopItems->printShop();

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
   
		
        if (entered == false) { 
            cout << "\nEntered a shop room!" << endl;
            cout << esc_char << bright << purple << "\nWelcome to my Shop adventurer!" << esc_char << endColor << endl;
            createShop(); 
            entered = true;
        }
        else {
            cout << esc_char << bright << purple << "\nWelcome to my Shop adventurer!" << esc_char << endColor << endl;
        }
        shopMenu();
	}

    Item* createRandomItem() {
        int chance = rand() % 100 + 1; // Random number between 1 and 100
        int c_chance = rand() % 100 + 1;
        int w_chance = rand() % 100 + 1;
        int price = level * 50;

        if (chance <= 50) {
            if (c_chance <= 40) {
                return new ConsumableItem(level, price, "Potion", false, true);
            }
            else if (c_chance <= 70) {
                return new ConsumableItem(level, price, "Freeze Heal", false, true);
            }
            else if (c_chance <= 100) {
                return new ConsumableItem(level, price, "Poison Heal", false, true);
            }
        }
        else {
            if (w_chance <= 25) {
                return new WeaponItem(level, price, "Sword", true, false);
            }
            else if (w_chance <= 50) {
                return new WeaponItem(level, price, "Bow", true, false);
            }
            else if (w_chance <= 75) {
                return new WeaponItem(level, price, "Axe", true, false);
            }
            else if (w_chance <= 100) {
                return new WeaponItem(level, price, "Dagger", true, false);
            }
        }
    }

    void createShop() {
        vector<Item*>items;
        for (int i = 0; i < 6; i++) {
            items.push_back(createRandomItem());
        }

        Inventory* shop = new Inventory(6, 6, items);

        shopItems = shop;
    }

    void shopMenu() {
        int input = -1;
        do {
            cout << "\nWhat would you like to do?\n1 - Buy\n2 - Exit" << endl;

            int input2 = -1;
            cin >> input;
            if (input == 1) {
                do {
                    shopItems->printShop();
                    cout << "\nPlease select an item to buy.\n(press 0 to exit)" << endl;
                    cin >> input2;
                    if (input2 != 0) {
                        if (p->getGold() < shopItems->getList().at(input2)->getPrice()) {
                            cout << "\nNot enough money!" << endl;
                        }
                        else {
                            p->addItem(shopItems->getList().at(input2));
                            shopItems->eraseItem(input2);
                            p->setGold(p->getGold() - shopItems->getList().at(input2)->getPrice());
                            cout << "\nCurrent Gold: " << p->getGold() << endl;
                        }
                    }
                    else {
                        cout << "\nExiting menu..." << endl;
                    }
                } while (input2 != 0);
            }
            else {
                cout << "\nExiting shop..." << endl;
            }
        } while (input != 2);
    }

};

#endif

