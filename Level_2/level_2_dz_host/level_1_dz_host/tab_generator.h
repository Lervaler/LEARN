#ifndef TAB_GENERATOR_H
#define TAB_GENERATOR_H
#include<string>
#include <filesystem>

class Tab_Generator
{
public:
    Tab_Generator(int&& host_numbers, int&& time_start);
    void Gen_file(const std::string &path);
    std::string tab_cleaner(const std::string &path);

private:
    int _host_numbers;
    int _time_start;
};

#endif // TAB_GENERATOR_H
