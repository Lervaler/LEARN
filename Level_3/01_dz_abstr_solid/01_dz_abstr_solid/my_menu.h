#ifndef MY_MENU_H
#define MY_MENU_H

#include "interface.h"
#include <string>
#include <memory>
#include <unordered_map>

class My_menu
    : public std::enable_shared_from_this<My_menu>
    , public Interface
{
private:
    std::string _name_punkt; // имя пункта, подпункта, под-под-пункта и тд
    std::unordered_map<std::string, std::shared_ptr<My_menu>> _master;   // имя и указатель на уровень выше ("на хозяина") master
//    mutable std::unordered_map<std::string, std::shared_ptr<My_menu>> _vassal; // пока не нужен
public:
    std::string get_name_my_menu();
    std::shared_ptr<My_menu> getptr(); // указатель на объект
    std::string get_master();
    void show_name_menu();

    explicit My_menu(const std::string& name_my_menu);
    My_menu(const std::string& name_my_ppunkt, const My_menu& belong_for);
    ~My_menu();
};

#endif // MY_MENU_H
