#include <GL/freeglut.h>
#include "player.h"
#include <math.h>

void PrintPlayer(Player player)
{
glBegin(GL_POLYGON);
glColor3f(0.8, 0.0, 0.0);
    for (float i = 0; i <(2*M_PI); i = i+0.1)
        {
        int x = 100;
        int y = 100;
        x = player.x + 30*cos(i);
        y = player.y +30*sin(i);
        glVertex2d(x +40, y+40);
        }
glEnd();
}


