#ifndef MENU_H
#define MENU_H
//#include "state.h"

constexpr int SIZE_h_m = 30;
constexpr int SIZE_w_m = 40;

enum Menu_Type
{
    NAME_MENU_GAME = '$',
    NAME_MENU_EXIT = '!',
    SPASE_MENU = '^',
    CHOOSE_MENU_GAME = '&',
    CHOOSE_MENU_EXIT = '@',
    FREE_SPACE_MENU = '.',
};

struct Menu
{
    char menu[SIZE_h_m][SIZE_w_m];
};

void init_menu(Menu* menu, const char* path);
void print_menu(const Menu* menu);

#endif // MENU_H
