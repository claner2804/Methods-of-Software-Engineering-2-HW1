
#ifndef HW1_CHARACTER_H
#define HW1_CHARACTER_H

#include "item.h"
#include "hero.h"
#include <iostream>
#include <string>
#include <array>

typedef struct{
    std::string name;
    int health;
    int gold;
    //ein Array von Items die Inventar darstellen
    std::array<Item_t, 10> inventory;
}Character_t;

//life
void attack(Character_t* character, struct Hero_t* hero);

//init
void initCharacter(Character_t* character, std::string name, int health, int gold);


#endif //HW1_CHARACTER_H
