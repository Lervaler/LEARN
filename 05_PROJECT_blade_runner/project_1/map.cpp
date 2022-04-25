#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "player.h"
#include "enemy.h"
#include "end_game.h"
#include "texture.h"

void init_map(Map* map, const char* path)
{
    FILE* file = fopen(path, "r");
    for(char i = 0; i<SIZE_h; ++i)
    {
        fread(map->map[SIZE_h - i - 1], SIZE_w, 1, file);
        fseek(file, 2, SEEK_CUR);
    }
    fclose(file);
}

void print_map(const Map* map)
{

    for (char i=0; i<SIZE_h; ++i)
    {
        for (char j=0; j<SIZE_w; ++j)
        {
            switch(map->map[i][j])
            {
                case BLOCK:
                glBindTexture (GL_TEXTURE_2D, 1);
                break;
                case FREE_SPACE:
                glBindTexture (GL_TEXTURE_2D, 2);
                break;
                case LADDER:
                glBindTexture (GL_TEXTURE_2D, 3);
                break;
                case EXIT:
                glBindTexture (GL_TEXTURE_2D, 4);
                break;
                case GOLD:
                glBindTexture (GL_TEXTURE_2D, 5);
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
    PrintPlayer(player);
    PrintEnemy(enemy);
}

