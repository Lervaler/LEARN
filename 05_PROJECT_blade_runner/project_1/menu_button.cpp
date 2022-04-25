#include "menu.h"
#include "menu_button.h"
#include <GL/freeglut.h>
#include "menu.h"

Button button = {12, 19};

void PrintButton(Button button)
{
    glBindTexture (GL_TEXTURE_2D, 6);

    glColor3f(1, 1, 1);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_POLYGON);
    glTexCoord2i(0, 0);    glVertex2d(button.x * 32, button.y * 32);
    glTexCoord2i(0, 1);    glVertex2d(button.x * 32, button.y * 32 + 32);
    glTexCoord2i(1, 1);    glVertex2d(button.x * 32 + 32, button.y * 32 + 32);
    glTexCoord2i(1, 0);    glVertex2d(button.x * 32 + 32, button.y * 32);

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













