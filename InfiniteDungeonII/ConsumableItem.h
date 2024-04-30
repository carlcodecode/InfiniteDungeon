#ifndef CONSUMABLEITEM_H
#define CONSUMABLEITEM_H
#include "Item.h"
class ConsumableItem : public Item
{
private:
	//bool statAdded;

public:
	//Constructors
	ConsumableItem() : Item(){}
	ConsumableItem(int _level, int _price, string _name, bool _isWeapon, bool _isCons)
		: Item(_level, _price, _name, false, true){}

	//Deconstructor
	~ConsumableItem() {}

	//Member Functions
	void itemInfo() {
		cout << "\nLevel " << level << " " << name;

		if (name == "Potion") {
			cout << " (heals " << level*2 << " HP)" << endl;
		}
		if (name == "Freeze Heal") {
			cout << " (removes freeze status condition)" << endl;
		}
		if (name == "Poison Heal") {
			cout << " (removes poison status condition)" << endl;
		}
	}
};

#endif
