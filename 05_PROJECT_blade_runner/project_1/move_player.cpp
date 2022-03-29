#include <GL/freeglut.h>
#include <stdio.h>
#include "player.h"
#include "move_player.h"
#include "map.h"

void move_player(Player player, int key, Map map)
{
    int speed = 1;
    int current_speed = 0;

    switch (key)
    {    case GLUT_KEY_UP:
        if (current_speed == 0)
        {
            current_speed = speed;
            {
                 ++player.y*20;
            }
        }
        else --current_speed;
             break;
         case GLUT_KEY_DOWN:
        if (current_speed == 0)
        {
            current_speed = speed;
            {
                 --player.y*20;
            }
        }
        else --current_speed;
             break;
         case GLUT_KEY_LEFT:
        if (current_speed == 0)
        {
            current_speed = speed;
            {
                 --player.x*20;
            }
        }
        else --current_speed;
             break;
         case GLUT_KEY_RIGHT:
             if (current_speed == 0)
             {
                 current_speed = speed;
                 {
                      ++player.x*20;
                 }
             }
             else --current_speed;
         break;
    };
//    if (player->player.x == 'EXIT')
};
