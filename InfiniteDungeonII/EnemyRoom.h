#ifndef ENEMYROOM_H
#define ENEMYROOM_H

#include "Room.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Slime.h"
#include "Kobold.h"
#include "Mimic.h"
#include "Ghost.h"
#include "Rat.h"
#include "WeaponItem.h"
#include "ConsumableItem.h"



class EnemyRoom : public Room
{
private:
	Enemy* e;

public: 
	//Constructors
	EnemyRoom() : Room(), e(nullptr) {}
	EnemyRoom(int _x, int _y, Player* _p, bool _en, int _l, Enemy* _e) : Room(_x, _y, _p, _en, _l), e(_e) {}
    EnemyRoom(int _x, int _y, Player* _p, bool _e, int _l)
        : Room(_x, _y, _p, _e, _l), e(nullptr){}

	//Deconstructors
	~EnemyRoom() {
		delete e;
	}

	//Getters
	Enemy* getEnemy() { return e; }

	//Setters
	void setEnemy(Enemy* _e) { e = _e; }

	//Member functions
	void test(){
		cout << "\nSuccesfully created an enemy room at (" << x << ", " << y << ")" << endl;
		cout << p->getName() << " is currently in the room." << endl;
	}

	void runInstance() {
		cout << "\nLoading Room..." << endl;

        createRandomEnemy();
        e->roomEnter();
        e->battle(p);
        if (p->getHP() <= 0) {
            exit(0);
        }

	}

    void createRandomEnemy() {
        int chance = rand() % 100 + 1; 

        if (level == 1) {
            e = new Goblin(level, createRandomItem());
        }
        else if (level == 2) {
            if (chance <= 50) {
                e = new Goblin(level, createRandomItem());
            }
            else {
                e =  new Slime(level, createRandomItem());
            }
        }
        else if (level == 3) {
            if (chance <= 40) {
                e =  new Goblin(level, createRandomItem());
            }
            else if (chance <= 80) {
                e =  new Slime(level, createRandomItem());
            }
            else {
                e =  new Kobold(level, createRandomItem());
            }
        }
        else if (level == 4) {
            if (chance <= 30) {
                e =  new Goblin(level, createRandomItem());
            }
            else if (chance <= 60) {
                e =  new Slime(level, createRandomItem());
            }
            else if (chance <= 80) {
                e =  new Kobold(level, createRandomItem());
            }
            else {
                e =  new Mimic(level, createRandomItem(), createRandomItem());
            }
        }
        else if (level == 5) {
            if (chance <= 25) {
                e =  new Goblin(level, createRandomItem());
            }
            else if (chance <= 50) {
                e =  new Slime(level, createRandomItem());
            }
            else if (chance <= 70) {
                e =  new Kobold(level, createRandomItem());
            }
            else if (chance <= 90) {
                e =  new Mimic(level, createRandomItem(), createRandomItem());
            }
            else {
                e =  new Ghost(level, createRandomItem());
            }
        }
        else { // level >= 6
            if (chance <= 18) {
                e =  new Goblin(level, createRandomItem());
            }
            else if (chance <= 36) {
                e =  new Slime(level, createRandomItem());
            }
            else if (chance <= 52) {
                e =  new Kobold(level, createRandomItem());
            }
            else if (chance <= 68) {
                e =  new Mimic(level, createRandomItem(), createRandomItem());
            }
            else if (chance <= 84) {
                e =  new Ghost(level, createRandomItem());
            }
            else {
                e =  new Rat(level, createRandomItem());
            }
        }
    }

    Item* createRandomItem() {
        int chance = rand() % 100 + 1; // Random number between 1 and 100
        int c_chance = rand() % 100 + 1;
        int w_chance = rand() % 100 + 1;

        if (chance <= 50) {
            if (c_chance <= 40) {
                return new ConsumableItem(level, 0, "Potion", false, true);
            }
            else if (c_chance <= 70) {
                return new ConsumableItem(level, 0, "Freeze Heal", false, true);
            }
            else if (c_chance <= 100) {
                return new ConsumableItem(level, 0, "Poison Heal", false, true);
            }
        }
        else {
            if (w_chance <= 25) {
                return new WeaponItem(level, 0, "Sword", true, false);
            }
            else if (w_chance <= 50) {
                return new WeaponItem(level, 0, "Bow", true, false);
            }
            else if (w_chance <= 75) {
                return new WeaponItem(level, 0, "Axe", true, false);
            }
            else if (w_chance <= 100) {
                return new WeaponItem(level, 0, "Dagger", true, false);
            }
        }
    }
    

};

#endif

