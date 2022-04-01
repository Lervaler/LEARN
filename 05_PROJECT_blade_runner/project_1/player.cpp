#include <GL/freeglut.h>
#include <stdlib.h>
#include "player.h"
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

int speed = 25;
int current_speed = 0;

void move_player(Player* player, int key)
{
    switch (key)
    {    case GLUT_KEY_UP:
        if (current_speed == 0)
        {
            current_speed = speed;
            {
                 player->y = player->y+20;
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
                 player->y = player->y-20;
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
                 player->x = player->x-20;
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
                      player->x = player->x+20;
                 }
             }
             else
             --current_speed;
         break;
    };
//    if (map->map[player->x][player->y] == EXIT)
//        return exit(0);
//    if ((player->x && player->y) == EXIT)
//        return exit (0);

//    if (player == map->map[0][38])
//        return exit (0);
}

bool check_position(Player* player, Map* map)
{
     if(map->map[player->x][player->y] == FREE_SPACE)
        return true;
     else if(map->map[player->x][player->y] == GOLD)        //
        return true;
     else if(map->map[player->x][player->y] == LADDER)     //
        return true;
     else if (map->map[player->x][player->y] == BLOCK)
        return false;
    else if(map->map[player->x][player->y] == EXIT)         //
        return false;
}

int super_check(Player* player, Map* map)
{
    if(map->map[player->x][player->y] == FREE_SPACE)
       return 1;
    else if(map->map[player->x][player->y] == GOLD)        //
       return 2;
    else if(map->map[player->x][player->y] == LADDER)     //
       return 3;
    else if (map->map[player->x][player->y] == BLOCK)
       return 4;
   else if(map->map[player->x][player->y] == EXIT)         //
       return 5;
}




