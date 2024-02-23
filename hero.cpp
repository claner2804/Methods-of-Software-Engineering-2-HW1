
#include <iostream>
#include <string>
#include <array>
#include "hero.h"
#include "character.h"
#include "item.h"


//life
void attack(Hero_t* hero, Character_t* enemy){
    //zufallszahl zwischen 15 und 25
    int rndNumber = 15 + rand() % 11;
    if (hero->health > 0) {
        enemy->health -= rndNumber;
        std::cout<<hero->name<<" trifft "<<enemy->name<<" fuer "<<rndNumber<<" Lebenspunkte!"<<std::endl;
    }
}

void sellItem(Hero_t* hero, int index){
    if(hero->inventory[index].isValid){
        hero->gold += hero->inventory[index].value;
        hero->inventory[index].isValid = false;
    }
}

bool fight(Hero_t* hero, Character_t* enemy){
    while(true){
        if(enemy->health <= 0){
            return true;
        }
        else if (hero->health <=0) {
            return false;
        }
        attack(hero, enemy);
        attack(enemy, hero);
    }


}


//init
void initHero(Hero_t* hero, std::string name, int health, int gold){
    hero->name = name;
    hero->health = health;
    hero->gold = gold;
    //iteriere über das Inventar und setze isValid auf false
    for(int i = 0; i < hero->inventory.size();i++){
        hero->inventory[i].isValid = false;
    }
    //iteriere über die Ausrüstung und setze isValid auf false
    for(int i = 0; i < hero->equipment.size(); i++){
        hero->equipment[i].isValid = false;
    }
}