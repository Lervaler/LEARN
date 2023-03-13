#ifndef GET_MY_FOOD_H
#define GET_MY_FOOD_H

#include <string>
#include <unordered_map>

#include "interface_food.h"
#include "data_food.h"

class Get_my_food
    :public Interface_food
{
private:
    Data_food _all_food;

public:
    Get_my_food(const Data_food _all_food);
    ~Get_my_food() override;

    std::unordered_map<std::string, int> get_food(std::string name_food) override;
};


#endif // GET_MY_FOOD_H
