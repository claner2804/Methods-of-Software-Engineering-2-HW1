
#ifndef HW1_ITEM_H
#define HW1_ITEM_H

#include <iostream>
#include <string>
#include <array>

// Item structure
typedef struct {
    std::string name;
    int value;
    bool isValid;
}Item_t;


//init
void initItem(Item_t* ITEM, std::string name, int gold);
void initItem(Item_t* gegenstand);

#endif //HW1_ITEM_H
