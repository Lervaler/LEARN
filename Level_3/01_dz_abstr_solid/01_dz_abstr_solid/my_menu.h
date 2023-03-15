#ifndef MY_MENU_H
#define MY_MENU_H

#include <string>
#include <memory>
#include <unordered_map>

class My_menu
{
private:
    std::string _name_my_menu; // имя самого меню
    std::unordered_map<std::string, std::shared_ptr<std::string>> _sub_menu;   // уровень и название пункта меню
public:
    std::string get_name_my_menu();
    std::shared_ptr<My_menu> get_ptr_my_menu(); // указатель на объект
    void add_level_1_submenu(const std::string& name_level_1_sub_menu); // создать пункт меню - уровень 1
    void add_sub_submenu(const std::string& name_sub_menu, const std::string& name_sub_sub_menu); //создание подпункта - по имени пункта уровня 1 или ниже

    void show_menu();

    My_menu(const std::string& name_my_menu);
    ~My_menu();
};

#endif // MY_MENU_H
