
#include <iostream>
#include <string>
#include <array>
#include "hero.h"
#include "character.h"

//life
void attack(Character_t* character, struct Hero_t* hero) {
    //zufallszahl zwischen 5 und 15
    int rndNumber = 5 + rand() % (15 - 5 + 1);
    hero->health -= rndNumber;
    std::cout<<character->name<<" trifft "<<hero->name<<" für "<<rndNumber<<" Lebenspunkte!"<<std::endl;
}


//init
void initCharacter(Character_t* character, std::string name, int health, int gold){
    character->name = name;
    character->health = health;
    character->gold = gold;
    //iteriere über das Inventar und setze isValid auf false
    for(int i = 0; i < character->inventory.size();i++){
        character->inventory[i].isValid = false;
    }
}