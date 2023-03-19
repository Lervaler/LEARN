#include "keeper.h"
#include "my_menu.h"
#include <iostream>

int main()
{
    const std::string name = "FILE";
    const std::string name1 = "VIEW";
    const std::string name2 = "open";
    const std::string name3 = "viewwww";

//    My_menu menu(name);
//    My_menu pukt(name1, menu);
//    My_menu podpukt(name2, pukt);

    Keeper menu;
    My_menu one = menu.create_punkt(name);

    menu.create_ppunkt(name2, one);
    menu.create_ppunkt(name3, menu.create_punkt(name1));

    menu.show_menu();


    int d = 5;
    std::cout<<d;

    return 0;
}
