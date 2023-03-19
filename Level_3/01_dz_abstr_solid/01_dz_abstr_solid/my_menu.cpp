#include "my_menu.h"
#include <algorithm>
#include <iostream>

    My_menu::My_menu(const std::string& name_punkt)
        :_name_punkt(std::move(name_punkt))
//        ,_master(0)   std::unordered_map<std::string, std::shared_ptr<std::string>>
//        , _vassal(0)    std::unordered_map<std::string, std::shared_ptr<My_menu>> _vassal;
    {}

    My_menu::My_menu(const std::string& name_my_ppunkt, const My_menu& host)
        :_name_punkt(std::move(name_my_ppunkt))
    {
        std::shared_ptr<My_menu> ptr = std::make_shared<My_menu>(host);
        std::shared_ptr<My_menu> ptr_of_master = ptr->getptr();
        _master.insert_or_assign(host._name_punkt, ptr_of_master);

//        std::shared_ptr<My_menu> ptr_vassal = std::make_shared<My_menu>(this);
//        std::shared_ptr<My_menu> ptr_on_vassal = this->getptr();
//        host._vassal.insert_or_assign(name_my_ppunkt, ptr_on_vassal);
    }

    My_menu::~My_menu()
    {}

    std::string My_menu::get_name_my_menu()
    {
        return _name_punkt;
    }

    std::shared_ptr<My_menu> My_menu::getptr()
    {
        return shared_from_this();
    }

    void My_menu::show_name_menu()
    {
        std::cout<<_name_punkt<<std::endl;
    }

    std::string My_menu::get_master()
    {
        std::string name = "empty";
        for(auto elem: _master)
        {
            name = elem.first;
        }
        return name;
    }
