#include <GL/freeglut.h>
#include "player.h"
#include <math.h>
#include "map.h"

void PrintPlayer(Player player)
{
glBegin(GL_POLYGON);

    glColor3f(0.8, 0.0, 0.0);
    glVertex2d(player.x +40, player.y+40);
    glVertex2d(player.x +20, player.y+40);
    glVertex2d(player.x +20, player.y+20);
    glVertex2d(player.x +40, player.y+20);

glEnd();
}

int speed = 1;
int current_speed = 0;

void move_player(Player* player, int key, Map* map)
{

    switch (key)
    {    case GLUT_KEY_UP:
        if (current_speed == 0)
        {
            current_speed = speed;
            {
                 ++player->y*20;
            }
        }
        else
        --current_speed;
         break;
         case GLUT_KEY_DOWN:
        if (current_speed == 0)
        {
            current_speed = speed;
            {
                 --player->y*20;
            }
        }
        else
        --current_speed;
         break;
         case GLUT_KEY_LEFT:
        if (current_speed == 0)
        {
            current_speed = speed;
            {
                 --player->x*20;
            }
        }
        else
        --current_speed;
             break;
         case GLUT_KEY_RIGHT:
             if (current_speed == 0)
             {
                 current_speed = speed;
                 {
                      ++player->x*20;
                 }
             }
             else
             --current_speed;
         break;
    };
//    if (player->player.x == 'EXIT')
};


