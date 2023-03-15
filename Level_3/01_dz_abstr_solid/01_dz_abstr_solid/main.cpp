#include <iostream>

#include "my_menu.h"

int main()
{
    const std::string name = "MENU";

    My_menu menu(name);
//    std::cout<<menu.get_name_my_menu() <<std::endl;

//    std::cout<<menu.get_ptr_my_menu()<<std::endl;

    const std::string sub = "FILE";
    const std::string sub2 = "EDIT";

    menu.add_level_1_submenu(sub);
    menu.add_level_1_submenu(sub2);

    const std::string ssub2 = "open";

   menu.add_sub_submenu(sub, ssub2);

   const std::string sssub2 = "open_open";
   menu.add_sub_submenu(ssub2, sssub2);

   menu.show_menu();

    int d = 5;
     std::cout<<d;

    return 0;
}
