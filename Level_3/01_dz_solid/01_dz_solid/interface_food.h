#ifndef INTERFACE_FOOD_H
#define INTERFACE_FOOD_H

#include <string>
#include <unordered_map>

class Interface_food
{
public:
    virtual std::unordered_map<std::string, int> get_food(std::string name_food) = 0;
    virtual ~Interface_food() = default;
};

#endif // INTERFACE_FOOD_H
