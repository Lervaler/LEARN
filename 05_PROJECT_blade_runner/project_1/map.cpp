#include <GL/freeglut.h>
#include <stdio.h>
#include "map.h"
#include "player.h"
#include "move_player.h"
#include <stdlib.h>

extern Player player = {0, 0};

void init_map(Map* map, const char* path)
{
    FILE* file = fopen(path, "r");
    for(int i = 0; i<SIZE_h; ++i)
    {
        fscanf(file, "%s", map->map[i]);
    }
    fclose(file);
}

void print_map(const Map* map)
{
    for (int i=0; i<SIZE_h; ++i)
    {
        for (int j=0; j<SIZE_w; ++j)
        {
            glBegin(GL_POLYGON);
            switch(map->map[i][j])
            {
                case BLOCK:
                glColor3f(0.0, 0.0, 0.9);
                break;
                case FREE_SPACE:
                glColor3f(0.0, 0.0, 0.0);
                break;
                case LADDER:
                glColor3f(0.0, 0.5, 0.0);
                break;
                case EXIT:
                glColor3f(0.5, 0.5, 0.0);
                break;
                case GOLD:
                glColor3f(0.5, 0.5, 0.5);
                break;
            }
            glVertex2i(j*20, 580 - i*20);
            glVertex2i(j*20+30, 580-  i*20);
            glVertex2i(j*20+30, 580 - i*20+20);
            glVertex2i(j*20, 580 -i*20+20);

            glEnd ();
        }
    }
    PrintPlayer(player);
}

