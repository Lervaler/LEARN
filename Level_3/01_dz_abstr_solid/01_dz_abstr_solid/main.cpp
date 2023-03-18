#include <iostream>

#include "my_menu.h"
#include "keeper.h"

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

//    std::cout<<menu.get_name_my_menu() <<std::endl;

//    std::cout<<menu.get_ptr_my_menu()<<std::endl;
//    std::make_shared<My_menu>(menu);

//
//    std::shared_ptr<My_menu> good0 = std::make_shared<My_menu>(menu);
//    std::shared_ptr<My_menu> good1 = good0->getptr();
//
//    std::cout<<good1<<std::endl;

//    const std::string sub = "FILE";
//    const std::string sub2 = "EDIT";
//
//    menu.add_level_1_submenu(sub);
//    menu.add_level_1_submenu(sub2);
//
//    const std::string ssub2 = "open";
//
//   menu.add_sub_submenu(sub, ssub2);
//
//   const std::string sssub2 = "open_open";
//   menu.add_sub_submenu(ssub2, sssub2);
//
//   menu.show_menu();
//
    int d = 5;
    std::cout<<d;

    return 0;
}
