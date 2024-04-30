#ifndef WEAPONITEM_H
#define WEAPONITEM_H
#include "Item.h"

class WeaponItem :    public Item
{
private:
	//bool statAdded;
public:
	//Constructors
	WeaponItem() : Item(){}
	WeaponItem(int _level, int _price, string _name, bool _isWeapon, bool _isCons)
		: Item(_level, _price, _name, true, false){}

	//Deconstructor
	~WeaponItem() {}


	//Member Functions
	void itemInfo() {
		cout << "\nLevel " << level << " " << name;
		
		if (name == "Sword") {
			cout << " (STR " << "+" << level << ")" << endl;
		}
		if (name == "Axe") {
			cout << " (DEF " << "+" << level << ")" << endl;
		}
		if (name == "Bow") {
			cout << " (SPD " << "+" << level << ")" << endl;
		}
		if (name == "Dagger") {
			cout << " (CRT " << "+" << level << ")" << endl;
		}
	}

	 
};

#endif

