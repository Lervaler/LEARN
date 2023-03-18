#ifndef MY_MENU_H
#define MY_MENU_H

#include <string>
#include <memory>
#include <unordered_map>

class My_menu
    : public std::enable_shared_from_this<My_menu>
{
private:
    std::string _name_punkt; // имя пункта, подпункта, под-под-пункта и тд
    std::unordered_map<std::string, std::shared_ptr<My_menu>> _master;   // имя и указатель на уровень выше ("на хозяина") master
    mutable std::unordered_map<std::string, std::shared_ptr<My_menu>> _vassal;
public:
    std::string get_name_my_menu();
    std::shared_ptr<My_menu> get_ptr_my_menu(); // указатель на объект
    std::shared_ptr<My_menu> getptr();
    void add_level_1_submenu(const std::string& name_level_1_sub_menu); // создать пункт меню - уровень 1
    void add_sub_submenu(const std::string& name_sub_menu, const std::string& name_sub_sub_menu); //создание подпункта - по имени пункта уровня 1 или ниже

    void show_name_menu();

    My_menu(const std::string& name_my_menu);
    My_menu(const std::string& name_my_ppunkt, const My_menu& belong_for);
    ~My_menu();
};

#endif // MY_MENU_H
