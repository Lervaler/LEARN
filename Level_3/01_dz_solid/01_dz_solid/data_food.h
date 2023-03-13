#ifndef DATA_FOOD_H
#define DATA_FOOD_H
#include<string>
#include <unordered_map>

class Data_food
{
private:
    std::unordered_map<std::string, int> _food;
public:
    Data_food(const std::unordered_map<std::string, int>& food);
    std::unordered_map<std::string, int> get_food(const std::string& name_food);
};


#endif // DATA_FOOD_H
