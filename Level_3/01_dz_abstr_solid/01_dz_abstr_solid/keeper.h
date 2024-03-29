#ifndef KEEPER_H
#define KEEPER_H

#include "my_menu.h"
#include <vector>
#include <string>

class Keeper
{
private:
    std::vector<My_menu> _all_menu;
public:
    My_menu create_punkt(const std::string name);
    My_menu create_ppunkt(const std::string name, const My_menu& menu);

    void show_menu();
    std::vector<My_menu> get_keeper();
};

#endif // KEEPER_H
