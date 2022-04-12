#include "menu.h"
#include "menu_button.h"
#include <GL/freeglut.h>
#include "menu.h"

Button button = {12, 19};

void PrintButton(Button button)
{
    glBegin(GL_POLYGON);

    glColor3f(0.0, 0.9, 0.9);
    glVertex2d(button.x * 20, button.y * 20);
    glVertex2d(button.x * 20 + 20, button.y * 20);
    glVertex2d(button.x * 20 + 20, button.y * 20 + 20);
    glVertex2d(button.x * 20, button.y * 20 + 20);

    glEnd();
}

int button_speed = 25;
int current_b_speed = 0;

Button move_button_impl(Button* button, int key)
{
    switch (key)
    {
      case GLUT_KEY_UP:
      return {button->x, button->y + 2};
      case GLUT_KEY_DOWN:
      return {button->x, button->y - 2};
    };
    return *button;
}

void move_button(Button *button, int key)
{
    if (current_b_speed == 0)
    {
      current_b_speed = button_speed;
      *button = move_button_impl(button, key);
    }
    else
    {
        --current_b_speed;
    }
}

bool check_pos_button(Button* button, Menu* menu, int key)
{
    Button tmp = move_button_impl(button, key);

    return menu->menu[tmp.y][tmp.x] == CHOOSE_MENU_GAME ||
           menu->menu[tmp.y][tmp.x] == CHOOSE_MENU_EXIT;
}













