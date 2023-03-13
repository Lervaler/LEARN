#ifndef DATA_DRINKS_H
#define DATA_DRINKS_H

#include<string>
#include <unordered_map>

class Data_drinks
{
private:
    std::unordered_map<std::string, int> _drinks;
public:
    Data_drinks(const std::unordered_map<std::string, int>& drinks);
    std::unordered_map<std::string, int> get_drinks(const std::string& name_drinks);
};

#endif // DATA_DRINKS_H
