#include <iostream>

#include "data_food.h"

Data_food::Data_food(const std::unordered_map<std::string, int>& food)
    :_food(std::move(food))
{}

    std::unordered_map<std::string, int> Data_food::get_food(const std::string& name_food)
    {
        std::unordered_map<std::string, int> our_food;

        if(_food.find(name_food) != _food.end())
        {
            our_food[name_food] = _food[name_food];
            return our_food;
        }
        else  // тут нужно искючение
        {
            std::cout <<"empty food";
            return our_food;
        }
    }
