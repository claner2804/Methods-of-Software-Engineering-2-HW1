#include <iostream>
#include <string>
#include <array>
#include "hero.h"
#include "character.h"
#include "item.h"

//structs für die Objekte erstellen
struct Hero_t hero;
Character_t character1;
Character_t character2;
Item_t item1;
Item_t item2;
Item_t item3;
Item_t item4;
Item_t item5;
Item_t item6;
Item_t item7;
Item_t item8;
Item_t item9;
Item_t item10;


int main(){

    //1 Held erstellen
    std::string heroName = "Annina";
    initHero(&hero,heroName,300,0);

    //2 Charaktere erstellen
    std::string character1Name = "Matthias";
    std::string character2Name = "Pascal";
    initCharacter(&character1, character1Name, 50, 0);
    initCharacter(&character2,character2Name,100,0);

    //10 Items erstellen
    std::string itemName1 = "Schwert";
    std::string itemName2 = "Helm";
    std::string itemName3 = "Schild";
    std::string itemName4 = "Stiefel";
    std::string itemName5 = "Zaubertrank";
    std::string itemName6 = "Schmuck";
    std::string itemName7 = "Diamant";
    std::string itemName8 = "Rubin";
    std::string itemName9 = "Smaragd";
    std::string itemName10 = "Topas";
    initItem(&item1,"Schwert",140);
    initItem(&item2,"Helm",120);
    initItem(&item3,"Schild",100);
    initItem(&item4,"Stiefel",80);
    initItem(&item5,"Zaubertrank",60);
    initItem(&item6,"Schmuck",200);
    initItem(&item7,"Diamant",400);
    initItem(&item8,"Rubin",300);
    initItem(&item9,"Smaragd",250);
    initItem(&item10,"Topas",200);


    //Kampf 1
    fight(&hero,&character1);
    if(fight(&hero,&character1)){
        std::cout<<character1.name << " fiel in Ohnmacht! "<< hero.name << " hat noch " << hero.health << " Lebenspunkte uebrig! " << std::endl;
        //Gegenstand als Beute in Inventar aufnehmen
        hero.inventory[0] = item1;
        std::cout << "Gegenstand " << item1.name << " wurde zum Inventar der Heldin hinzugefügt! " << std::endl;
    }
    else{
           std::cout<<hero.name << " fiel in Ohnmacht! "<< character1.name << " hat noch " << character1.health << " Lebenspunkte uebrig! " << std::endl;
    }

    std::cout<<std::endl;

    //Kampf 2
    fight(&hero,&character2);
    if(fight(&hero,&character2)){
        std::cout<<character2.name << " fiel in Ohnmacht! "<< hero.name << " hat noch " << hero.health << " Lebenspunkte uebrig! " << std::endl;
        //Gegenstand als Beute in Inventar aufnehmen
        hero.inventory[1] = item2;
        std::cout << "Gegenstand " << item2.name << " wurde zum Inventar der Heldin hinzugefügt! " << std::endl;
    }
    else{
        std::cout<<hero.name << " fiel in Ohnmacht! "<< character2.name << " hat noch " << character2.health << " Lebenspunkte uebrig! " << std::endl;
    }

    //alle Gegenstände verkaufen
    //der Held hat nur 2 Gegenstände im Inventar, die er verkaufen kann
    for(int i = 0; i < 2; i++){
        sellItem(&hero,i);
        std::cout << "Gegenstand " << hero.inventory[i].name << " wurde verkauft! " << hero.name << " besitzt nun " << hero.gold << " Goldstücke! " << std::endl;
        std::cout << "Der Held hat nun " << hero.gold << " Goldstücke! " << std::endl;
    }


    return 0;
}