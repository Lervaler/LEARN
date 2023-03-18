#include "my_menu.h"
#include <algorithm>
#include <iostream>

    My_menu::My_menu(const std::string& name_my_menu)
        :_name_my_menu(std::move(name_my_menu))
//        ,_sub_menu(0)   std::unordered_map<std::string, std::shared_ptr<std::string>>
    {}




    My_menu::~My_menu()
    {}

    std::string My_menu::get_name_my_menu()
    {
        return _name_my_menu;
    }

//    std::shared_ptr<My_menu> My_menu::get_ptr_my_menu() // указатель на объект
//   {
//       return std::shared_ptr<My_menu>(this);
//   }


    std::shared_ptr<My_menu> My_menu::getptr()
    {
        return shared_from_this();
    }


    void My_menu::add_level_1_submenu(const std::string& name_level_1_sub_menu) // создать пункт меню - уровень 1
    {
        auto level = std::make_shared<std::string> (_name_my_menu);
        _sub_menu.insert_or_assign(name_level_1_sub_menu, level);
    }

    void My_menu::add_sub_submenu(const std::string& name_sub_menu, const std::string& name_sub_sub_menu) //создание подпункта - по имени пункта уровня 1 или ниже
    {
        if(_sub_menu.find(name_sub_menu) != _sub_menu.end())
        {
            auto key = _sub_menu.find(name_sub_menu);
            auto level = std::make_shared<std::string>(key->first);
            _sub_menu.insert_or_assign(name_sub_sub_menu, level);
        }
    }

    void My_menu::show_menu()
    {

        char point = ' ';

        std::cout<<_name_my_menu<<std::endl;
        std::cout<<" "<<std::endl;
        for(const auto& [first, second]: _sub_menu)
        {
            if(*second == _name_my_menu)
            {
                std::cout<<point<<first<<std::endl;
            }
        }

        bool proverka = true;
        while(proverka)
        {
            std::string choise;
            std::cin>>choise;

            if(choise == "stop")
            {
                exit(0);
            }
            else if(choise == _name_my_menu)
            {
                for(const auto& [first, second]: _sub_menu)
                {
                    if(*second == _name_my_menu)
                    {
                        std::cout<<point<<first<<std::endl;
                    }
                }
            }
            else
            {
                auto search = _sub_menu.find(choise);

                if(search != _sub_menu.end())
                {
                    system("cls");
                    for(const auto& [first, second]: _sub_menu)
                    {
                        if(*second == choise)
                        {
                            std::cout<<point<<first<<std::endl;
                        }
                    }
                }
            }
        }

    }
