#include "end_game.h"
#include <GL/freeglut.h>

End_game end_game = {7, 15};

void print_end_game (End_game end_game)
{
    glBegin(GL_POLYGON);

    glColor3f(0.0, 0.7, 0.7);
    glVertex2d(end_game.x * 20, end_game.y * 20);
    glVertex2d(end_game.x * 20 + 500, end_game.y * 20);
    glVertex2d(end_game.x * 20 + 500, end_game.y * 20 + 100);
    glVertex2d(end_game.x * 20, end_game.y * 20 + 100);

  glEnd();
}
