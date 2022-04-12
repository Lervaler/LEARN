#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "menu.h"
#include "menu_button.h"
#include "player.h"
#include "pick_up.h"
#include "end_game.h"

int key = 0;
int invisible = 0;
Menu menu;
Map map;

void MyKeyUp(int, int, int) // клавиша не нажата
{
    key = 0;
}
void MyKeyDown(int ch, int, int) // клавиша нажата
{
    key = ch;
}

void invisible_score(Player* player, Map* map)       // для скрывания меню
{
    if(map->map[player->y][player->x] == INVISIBLE)
    {
        map->map[player->y][player->x] = FREE_SPACE;
        ++invisible;
        printf("invisible = %d\n", invisible);
    };
}

void DisplayRender(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    invisible_score(&player, &map);  // уход вправо делает +1 к невидимой точке
    if (invisible ==0)
    {
        print_menu(&menu);       // делает меню, если невидимая = 0
    }
    if (menu.menu[button.y][button.x] == CHOOSE_MENU_EXIT && key == GLUT_KEY_RIGHT)  // выход
    {
        exit (0);
    }
    if (invisible >0)   // если прошли невидимую точку, меню больше не видно
    {
       print_map(&map);
       pick_up(&player, &map);
       if (map.map[player.y][player.x] == EXIT) print_end_game (end_game);
    }

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
    if (key != 0 && check_pos_button(&button, &menu, key))
    move_button(&button, key);

    if (key != 0 && check_position(&player, &map, key))
    {
        if (map.map[player.y - 1][player.x] != BLOCK &&
            map.map[player.y][player.x] != LADDER &&
            map.map[player.y][player.x] != EXIT)
        {
            do
            {
                move_player(&player, GLUT_KEY_DOWN);             // скорость падения?
            }
            while(map.map[player.y - 1][player.x] != BLOCK);
        }

        else if(map.map[player.y][player.x] == FREE_SPACE ||
                 map.map[player.y][player.x] ==LADDER ||
                 map.map[player.y][player.x] == GOLD)
        {
            move_player(&player, key);
        }

         else if(map.map[player.y][player.x] == EXIT)
        {
             exit (0);
        }
    };

    glutShowWindow();
    glutTimerFunc(5, &tick, 0);
}


int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Wind");

    init_menu(&menu, "D:/01_Projects/HomeWork/LEARN/LEARN/05_PROJECT_blade_runner/project_1/menu.txt");

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
