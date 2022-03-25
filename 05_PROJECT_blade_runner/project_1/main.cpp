#include <GL/freeglut.h>
#include "player.h"
#include "map.h"
#include "move_player.h"

extern Player player;
int key = 0;

void DisplayRender(void)
{
Map map = {1,1};
PrintMap(map);
}


void MyKeyUp(int, int, int)
{
    key = 0;
}
void MyKeyDown(int ch, int, int)
{
    key = ch;
}


void Reshape(int w, int h)
{
    w = 640;
    h = 480;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0,w, 0, h, 1, 0);
}
void ExitKey(unsigned char, int, int)
{
    exit(0);
}




//int speed = 1;
//int current_speed = 0;
//
//void Tick_Rigth(int)
//{
//    if (key == GLUT_KEY_RIGHT)
//    {
//        if(current_speed ==0)
//        {
//             current_speed = speed;
//             {
//                 if (player.x <530)
//                 ++player.x;
//                glutShowWindow();
//             }
//        }
//        else
//        {
//          --current_speed;
//         }
//     }
//    glutTimerFunc(5, &Tick_Rigth, 0);
//}
//
//void Tick_Left(int)
//{
//    if (key == GLUT_KEY_LEFT)
//    {
//        if(current_speed ==0)
//        {
//             current_speed = speed;
//             {
//                 if (player.x>-50)
//                 --player.x;
//                  glutShowWindow();
//             }
//        }
//        else
//        {
//          --current_speed;
//         }
//     }
//    glutTimerFunc(5, &Tick_Left, 0);
//}
//
//void Tick_Up(int)
//{
//    if (key == GLUT_KEY_UP)
//    {
//        if(current_speed ==0)
//        {
//             current_speed = speed;
//             {
//                 if (player.y<395)
//                 ++player.y;
////                 else if (y = 100)
////                 {
////                     speed = 100000000000000;
////                 }
//                glutShowWindow();
//
//             }
//        }
//        else
//        {
//          --current_speed;
//        }
//    }
//    glutTimerFunc(5, &Tick_Up, 0);
//}
//
//void Tick_Down(int)
//{
//    if (key == GLUT_KEY_DOWN)
//    {
//        if(current_speed ==0)
//        {
//             current_speed = speed;
//             {
//                 if (player.y>-20)
//                 --player.y;
//                glutShowWindow();
//             }
//        }
//        else
//        {
//          --current_speed;
//        }
//    }
//    glutTimerFunc(5, &Tick_Down, 0);
//}



int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Wind");

    glutDisplayFunc(&DisplayRender);
    glutSpecialFunc(&MyKeyDown);
    glutSpecialUpFunc(&MyKeyUp);
    glutKeyboardFunc(&ExitKey);
    glutReshapeFunc(&Reshape);

//    glutTimerFunc(5, &Tick_Rigth, 0);
//    glutTimerFunc(5, &Tick_Left, 0);
//    glutTimerFunc(5, &Tick_Up, 0);
//    glutTimerFunc(5, &Tick_Down, 0);

    glutMainLoop();

    return 0;
}
