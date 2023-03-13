#include <iostream>

#include "get_my_food.h"

Get_my_food::Get_my_food(const Data_food food)
    :_all_food(food)
{}

std::unordered_map<std::string, int> Get_my_food::get_food(std::string name_food)
{
    std::unordered_map<std::string, int> _my_food;
    _my_food = _all_food.get_food(name_food);
    if(!_my_food.empty())
        return _my_food;
    else
    {
        std::cout<< "fail my_food "<<std::endl;
        return _my_food; //сделать исключение
    }
}

Get_my_food::~Get_my_food()
{}
