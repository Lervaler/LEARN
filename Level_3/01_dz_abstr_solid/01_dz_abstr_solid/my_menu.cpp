#include "my_menu.h"
#include <algorithm>

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

    std::shared_ptr<My_menu> My_menu::get_ptr_my_menu() // указатель на объект
    {
//        return std::shared_ptr<My_menu>(this);
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

