#include <iostream>

#include "data_drinks.h"

Data_drinks::Data_drinks(const std::unordered_map<std::string, int>& drinks)
    :_drinks(std::move(drinks))
{}

    std::unordered_map<std::string, int> Data_drinks::get_drinks(const std::string& name_drinks)
    {
        std::unordered_map<std::string, int> our_drinks;

        if(_drinks.find(name_drinks) != _drinks.end())
        {
            our_drinks[name_drinks] = _drinks[name_drinks];
            return our_drinks;
        }
        else  // тут нужно искючение
        {
            std::cout <<"empty drinks";
            return our_drinks;
        }
    }
