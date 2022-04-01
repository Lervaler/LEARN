#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "map.h"

extern Player player;
int key = 0;
 Map map;

 void MyKeyUp(int, int, int)
 {
     key = 0;
 }
 void MyKeyDown(int ch, int, int)
 {
     key = ch;
 }

void DisplayRender(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    print_map(&map);
    glFlush();
}

void Reshape(int, int)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0,800, 0, 600, 1, 0);
}
//void ExitKey(unsigned char, int, int)
//{
//    exit(0);
//}

void tick(int)
{
//    if( check_position( &player, &map) == false)
//    move_player(&player, key);
//    if( check_position( &player, &map) == true)
//    move_player(&player, key);

//    switch (super_check(&player, &map))
//{
//    case 1:
//        move_player(&player, key);
//        glutShowWindow();
//        glutTimerFunc(5, &tick, 0);
//        break;
//    case 2:
//    move_player(&player, key);
//    glutShowWindow();
//    glutTimerFunc(5, &tick, 0);
//        break;
//    case 3:
//    move_player(&player, key);
//    glutShowWindow();
//    glutTimerFunc(5, &tick, 0);
//        break;
//    case 4:
//        move_player (&player, key);
//        glutShowWindow();
//        glutTimerFunc(5, &tick, 0);
//        break;
//    case 5:
//    exit (0);
//

//        move_player(&player, key);
        switch (check_position(&player, &map))
    {
        case true:
            move_player(&player, key);
            glutShowWindow();
            glutTimerFunc(5, &tick, 0);
            break;
        case false:
            move_player(&player, key);
            glutShowWindow();
            glutTimerFunc(5, &tick, 0);
            break;
}

    glutShowWindow();
    glutTimerFunc(5, &tick, 0);
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Wind");

    init_map(&map, "D:/01_Projects/HomeWork/LEARN/LEARN/05_PROJECT_blade_runner/project_1/map.txt");

    glutDisplayFunc(&DisplayRender);
    glutSpecialFunc(&MyKeyDown);
    glutSpecialUpFunc(&MyKeyUp);
//    glutKeyboardFunc(&ExitKey);
    glutReshapeFunc(&Reshape);

    glutTimerFunc(5, &tick, 0);

    glutMainLoop();

    return 0;
}
