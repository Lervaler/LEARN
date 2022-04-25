#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "menu.h"
#include "menu_button.h"
#include "player.h"
#include "pick_up.h"
#include "enemy.h"
#include "end_game.h"
#include "texture.h"

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

void DisplayRender()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (invisible ==0)
    {
        print_menu(&menu);       // делает меню, если невидимая = 0
        if (menu.menu[button.y][button.x] == CHOOSE_MENU_GAME && key == GLUT_KEY_RIGHT)  // начать игру
        {
            invisible = 1;
        }
        if (menu.menu[button.y][button.x] == CHOOSE_MENU_EXIT && key == GLUT_KEY_RIGHT)  // выход
        {
            exit (0);
        }
    }

    if (invisible >0)   // если невидимая = 1, меню больше не видно
    {
       print_map(&map);
       pick_up(&player, &map);
       if (map.map[player.y][player.x] == EXIT) print_end_game (end_game);
    }

//glutSwapBuffers();
    glFlush();
}

void Reshape(int, int)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0,1280, 0, 1024, 1, 0);
}

void ExitKey(unsigned char, int, int)
{
    exit(0);
}

void tick(int)
{
    if (key != 0 && check_pos_button(&button, &menu, key))     // передвижение кнопки выбора игра-выход
    move_button(&button, key);

    if (check_position_enemy(&enemy, &map) )
        if(map.map[enemy.y][enemy.x] == FREE_SPACE ||
                         map.map[enemy.y][enemy.x] ==LADDER ||
                         map.map[enemy.y][enemy.x] == GOLD )
                {
                     if (invisible > 0)
                     move_enemy(&enemy);
                }

    if (key != 0 && check_position(&player, &map, key))       // передвижение игрока
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
            if (invisible > 0)
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
    glutInitWindowSize(1280,1024);
    glutCreateWindow("Wind");
    glClear(GL_COLOR_BUFFER_BIT);

    LoadTexture(1, "tex.bmp", 32, 32);         //  блоки игры               BLOCK
    LoadTexture(2, "free.bmp", 32, 32);        // пустота в игре            FREE_SPASCE
    LoadTexture(3, "ladder_1.bmp", 32, 32);    // лестница                  LADDER
    LoadTexture(4, "door.bmp", 32, 32);        //  выход в игре             EXIT
    LoadTexture(5, "gold_1.bmp", 32, 32);        //   золото                  GOLD

    LoadTexture(6, "yes.bmp", 32, 32);     // строка начать игру в меню и кнопка выбора NAME_MENU_GAME
    LoadTexture(7, "free.bmp", 32, 32);    // пустота в остальных местах      FREE_SPACE_MENU
    LoadTexture(8, "block_11.bmp", 32, 32);// рамка вокруг меню               SPASE_MENU
    LoadTexture(9, "romb.bmp", 32, 32); //место для галочки в меню выбора     CHOOSE_MENU_GAME-EXIT
    LoadTexture(10, "no.bmp", 32, 32);  // строка выйти из игры в меню        NAME_MENU_EXIT

//    LoadTexture(11, "end_game.bmp", 256, 160);  // end game

    init_menu(&menu, "menu.txt");

    init_map(&map, "map.txt");

    glutDisplayFunc(&DisplayRender);
    glutSpecialFunc(&MyKeyDown);
    glutSpecialUpFunc(&MyKeyUp);
    glutKeyboardFunc(&ExitKey);
    glutReshapeFunc(&Reshape);

    glutTimerFunc(5, &tick, 0);
    glutMainLoop();

    return 0;
}
