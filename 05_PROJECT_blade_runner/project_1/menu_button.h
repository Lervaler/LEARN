#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H
#include "menu.h"

struct Button
{
    int x;
    int y;
};

extern Button button;

void PrintButton(Button button);
void move_button(Button *button, int key);
bool check_pos_button(Button* button, Menu* menu, int key);
#endif // MENU_BUTTON_H
