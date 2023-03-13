#ifndef MY_FOOD_H
#define MY_FOOD_H

#include <string>
#include <unordered_map>

#include "interface_food.h"
#include "data_food.h"

class My_food
{
private:
    std::unordered_map<std::string, int> _my_food;

public:
    My_food();
    ~My_food();

    std::unordered_map<std::string, int> get_food(Interface_food& inter, std::string name);
};


#endif // MY_FOOD_H
