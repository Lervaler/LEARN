//#include "state.h"
#include "menu.h"
#include "menu_button.h"
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>

void init_menu(Menu* menu, const char* path)
{
    FILE* file = fopen(path, "r");
    for(int i = 0; i<SIZE_h_m; ++i)
    {
        fread(menu->menu[SIZE_h_m - i - 1], SIZE_w_m, 1, file);
        fseek(file, 2, SEEK_CUR);
    }
    fclose(file);
}

void print_menu(const Menu* menu)
{
    for (int i=0; i<SIZE_h_m; ++i)
    {
        for (int j=0; j<SIZE_w_m; ++j)
        {
            glBegin(GL_POLYGON);
            switch(menu->menu[i][j])
            {
                case NAME_MENU:
                glColor3f(0.8, 0.8, 0.8);
                break;
                case FREE_SPACE_MENU:
                glColor3f(0.0, 0.0, 0.0);
                break;
                case SPASE_MENU:
                glColor3f(0.9, 0.0, 0.0);
                break;
                case CHOOSE_MENU_GAME:
                glColor3f(0.9, 0.0, 0.5);
                break;
                case CHOOSE_MENU_EXIT:
                glColor3f(0.9, 0.0, 0.5);
                break;
            }
            glVertex2i(j * 20,      i * 20);
            glVertex2i(j * 20 + 30, i * 20);
            glVertex2i(j * 20 + 30, i * 20 + 20);
            glVertex2i(j * 20,      i * 20 + 20);

            glEnd ();
        }
    }
    PrintButton(button);
}
















