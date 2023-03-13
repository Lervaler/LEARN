#include <iostream>

#include "menu.h"
#include "data_food.h"
#include "get_my_food.h"
#include "my_food.h"

int main()
{

    std::unordered_map<std::string, int> t_food = {{"chiken", 12}, {"donat", 5}, {"soup", 34} };
    Data_food food(t_food);
//    std::unordered_map<std::string, int> my_food = food.get_food("dd");

//    for(auto elem: my_food)
//    {
//        std::cout <<"KEY = "<<elem.first <<" VALUE = "<<elem.second <<std::endl;
//    }

    My_food myff_food;

    Get_my_food interface_food(food);

    std::unordered_map<std::string, int> eeemy_food = myff_food.get_food(interface_food, "donat");


    for(auto elem: eeemy_food)
    {
        std::cout <<"KEY = "<<elem.first <<" VALUE = "<<elem.second <<std::endl;
    }

//    Menu menu;
//    menu.print_menu();
    return 0;
}
