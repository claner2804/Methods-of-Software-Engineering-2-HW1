
#include "item.h"
#include <iostream>
#include <string>
#include <array>

//init
void initItem(Item_t* ITEM, std::string name, int gold) {
   ITEM->name = name;
   ITEM->value = gold;
   ITEM->isValid = true;
}

//wenn löschung aus inventar immer isvalid auf false setzen
void initItem(Item_t* gegenstand){
    gegenstand->isValid = false;
}