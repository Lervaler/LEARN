#include <GL/freeglut.h>
#include "map.h"
#include "player.h"
#include "move_player.h"

extern Player player = {1, 1};

void PrintMap(Map map)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
PrintPlayer(player);
//move_player(player, extern key);

glBegin(GL_POLYGON);                 // стена
glColor3f(0.0, 0.0, 0.9);
glVertex2i(map.x+0, map.y+ 0);
glVertex2i(map.x+10,map.y+ 0);
glVertex2i(map.x+10,map.y+ 480);
glVertex2i(map.x+0, map.y+480);
glEnd ();

glBegin(GL_POLYGON);                 // стена
glColor3f(0.0, 0.0, 0.9);
glVertex2i(map.x+11, 0);
glVertex2i(map.x+0, 11);
glVertex2i(map.x+640, 11);
glVertex2i(map.x+640, 0);
glEnd ();

glBegin(GL_POLYGON);                 // стена
glColor3f(0.0, 0.0, 0.9);
glVertex2i(map.x+640, map.y+480);
glVertex2i(map.x+640,map.y+ 470);
glVertex2i(map.x+0,map.y+ 470);
glVertex2i(map.x+0,map.y+ 640);
glEnd ();

glBegin(GL_POLYGON);                 // стена
glColor3f(0.0, 0.0, 0.9);
glVertex2i(map.x+640,map.y+ 480);
glVertex2i(map.x+630,map.y+ 480);
glVertex2i(map.x+630,map.y+ 0);
glVertex2i(map.x+640,map.y+ 0);
glEnd ();

glBegin(GL_POLYGON);                 // этаж
glColor3f(0.0, 0.0, 0.9);
glVertex2i(map.x+0, map.y+200);
glVertex2i(map.x+0, map.y+210);
glVertex2i(map.x+90, map.y+210);
glVertex2i(map.x+90, map.y+200);
glEnd ();

glFlush();

}
