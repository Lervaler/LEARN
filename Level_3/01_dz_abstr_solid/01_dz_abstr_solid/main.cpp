#include <iostream>

#include "my_menu.h"

int main()
{
    const std::string name = "MENU";

    My_menu menu(name);
//    std::cout<<menu.get_name_my_menu() <<std::endl;

//    std::cout<<menu.get_ptr_my_menu()<<std::endl;
//    std::make_shared<My_menu>(menu);


    std::shared_ptr<My_menu> good0 = std::make_shared<My_menu>(menu);
    std::shared_ptr<My_menu> good1 = good0->getptr();

    std::cout<<good1<<std::endl;

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
