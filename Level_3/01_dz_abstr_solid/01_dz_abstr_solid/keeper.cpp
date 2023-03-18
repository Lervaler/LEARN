#include "keeper.h"
#include <iostream>
#include <algorithm>


    My_menu Keeper::create_punkt(const std::string name)
    {
        My_menu punkt = My_menu(std::move(name));
        _all_menu.push_back(punkt);
        return punkt;
    }
    My_menu Keeper::create_ppunkt(const std::string name, const My_menu& menu)
    {
        My_menu punkt = My_menu(std::move(name), menu);
        _all_menu.push_back(punkt);
        return punkt;
    }

    void Keeper::show_menu()
    {
        std::vector<std::string> names;
        std::cout<<"MENU:" << std::endl;
        for(auto elem: _all_menu)
            if(elem.get_master() == "empty")
            {
                std::cout<<elem.get_name_my_menu() << std::endl;
                names.push_back(elem.get_name_my_menu());
            }

        std::string pre_word;

        while(true)
        {
            std::string word;
            std::cin >> word;

            if(word == "stop")
            {
                exit(0);
            }
//           else if(word == "back")
//           {
//               system("cls");
//
//               for(auto elem: _all_menu)
//               {
//                 //      if(elem.get_name_my_menu() == pre_word)
//                       {
//                           std::cout<<elem.get_name_my_menu() << std::endl;
//                        //   std::cout<<elem.get_name_my_menu()<< std::endl;
//                       }
//               }
//           }
            else if(std::find(names.begin(), names.end(), word) != names.end())
            {
                pre_word = word;
                system("cls");
                for(auto elem: _all_menu)
                {
                    if(elem.get_master() != "empty")
                    {
                        if(elem.get_master() == word)
                        {
                            std::cout<<elem.get_name_my_menu()<< std::endl;
                        }
                    }
                }
            }
        }
    }

