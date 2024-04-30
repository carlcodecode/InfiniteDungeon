#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Item
{
protected:
	string name;
	int level;
	int price;
	bool isWeapon;
	bool isCons;

public:
	//Constructors
	Item() : level(1), price(0), name(""), isWeapon(false), isCons(false) {}
	Item(int _level, int _price, string _name, bool _isWeapon, bool _isCons)
		: level(_level), price(_price), name(_name), isWeapon(_isWeapon), isCons(_isCons) {}

	//Destructor
	~Item() {}

	//Getters
	int getLevel() { return level; }
	int getPrice() { return price; }
	string getName() { return name; }
	bool getIsWeapon() { return isWeapon; }
	bool getIsCons() { return isCons; }

	//Setters
	void setLevel(int _level) { level = _level; }
	void setPrice(int _price) { price = _price; }
	void setName(string _name) { name = _name; }
	void setIsWeapon(bool _isWeapon) { isWeapon = _isWeapon; }
	void setIsCons(bool _isCons) { isCons = _isCons; }

	//Member functions
	virtual void itemInfo() {
		cout << "\nLevel " << level << " " << name << endl;
		cout << "This item costs " << price << " gold." << endl;
	}

	


};

#endif