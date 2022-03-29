#include <GL/freeglut.h>
#include "player.h"
#include <math.h>

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


