#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>
class Inventory
{
private:
	int curSize;
	int maxSize;
	vector<Item*>list_items;

public:
	//Constructors
	Inventory() : curSize(0), maxSize(4) {}
	Inventory(int _curSize, int _maxSize, vector<Item*>_list_items)
		: curSize(_curSize), maxSize(_maxSize), list_items(_list_items) {}

	//Deconstructor
	~Inventory() {
		for (Item* single_item : list_items) {
			delete single_item;
		}
	}

	//Getters
	int getCurSize() { return curSize; }
	int getMaxSize() { return maxSize; }
	vector<Item*> getList() { return list_items; }

	//Setters
	void setCurSize(int _curSize) { curSize = _curSize; }
	void setMaxSize(int _maxSize) { maxSize = _maxSize; }
	void setList(vector<Item*> i) { list_items = i; }

	//Member Functions
	void printContents() {
		if (curSize == 0) { cout << "\nInventory is currently empty." << endl; }
		else {
			cout << "\nInventory contents: " << endl;
			int pos = 1;

			for (Item* item : list_items) {
				cout << pos << ": Lvl " << item->getLevel() << " " << item->getName() << endl;
				pos++;
			}
		}
	}

	void eraseItem(int pos) {
		list_items.erase(list_items.begin() + (pos - 1));
	}

	void plusItem(Item* item) {
		list_items.push_back(item);
	}

	void printShop() {
		if (curSize == 0) { cout << "\nThere is nothing left in the shop!" << endl; }
		else {
			cout << "\nShop items: " << endl;
			int pos = 1;
			
			for (Item* item : list_items) {
				cout << pos << ": Lvl " << item->getLevel() << " " << item->getName() << " - " << item->getPrice() << " gold" << endl;
				pos++;
			}

		}
	}

};

#endif

