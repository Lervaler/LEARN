#include <iostream>

#include "my_food.h"

My_food::My_food()
    : _my_food()
{}
My_food::~My_food()
{}

std::unordered_map<std::string, int> My_food::get_food(Interface_food& inter, std::string name)
{
    _my_food = inter.get_food(name);
    return _my_food;
}

