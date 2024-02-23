//Headerdatei Hero

#ifndef HW1_HERO_H
#define HW1_HERO_H

#include <iostream>
#include <string>
#include <array>
#include "item.h"
#include "character.h"

struct Hero_t{
    std::string name;
    int health;
    int gold;
    //ein Array von Items die Inventar darstellen
    std::array<Item_t, 10> inventory;
    //ein Array von Items die die Ausrüstung darstellen
    std::array<Item_t, 2> equipment;
};

//life
void attack(Hero_t* hero, Character_t* enemy);
void sellItem(Hero_t* hero, int index);
bool fight(Hero_t* hero, Character_t* enemy);


//init
void initHero(Hero_t* hero, std::string name, int health, int gold);

#endif //HW1_HERO_H
