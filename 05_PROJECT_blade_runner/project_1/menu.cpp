//#include "state.h"
#include "menu.h"
#include "menu_button.h"
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include "texture.h"

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
            switch(menu->menu[i][j])
            {
                case NAME_MENU_GAME:
                glBindTexture (GL_TEXTURE_2D, 6);
                break;
                case NAME_MENU_EXIT:
                glBindTexture (GL_TEXTURE_2D, 10);
                break;
                case FREE_SPACE_MENU:
                glBindTexture (GL_TEXTURE_2D, 7);
                break;
                case SPASE_MENU:
                glBindTexture (GL_TEXTURE_2D, 8);
                break;
                case CHOOSE_MENU_GAME:
                glBindTexture (GL_TEXTURE_2D, 9);
                break;
                case CHOOSE_MENU_EXIT:
                glBindTexture (GL_TEXTURE_2D, 9);
                break;
            }

            glColor3f(1, 1, 1);
            glEnable(GL_TEXTURE_2D);

            glBegin(GL_POLYGON);
            glTexCoord2i(0, 0);    glVertex2i(j * 32,      i * 32);
            glTexCoord2i(0, 1);    glVertex2i(j * 32,      i * 32 + 32);
            glTexCoord2i(1, 1);    glVertex2i(j * 32 + 32, i * 32 + 32);
            glTexCoord2i(1, 0);    glVertex2i(j * 32 + 32, i * 32);

            glEnd ();
            glDisable(GL_TEXTURE_2D);
        }
    }
    PrintButton(button);
}
















