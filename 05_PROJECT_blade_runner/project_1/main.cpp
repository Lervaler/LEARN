#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "map.h"
#include "end_game.h"
#include "scode.h"
#include <stdlib.h>


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
    if (map.map[player.y][player.x] == EXIT)
    print_end_game (end_game);
    glFlush();
}

void Reshape(int, int)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0,800, 0, 600, 1, 0);
}
void ExitKey(unsigned char, int, int)
{
    exit(0);
}


void tick(int)
{

    if (key != 0 && check_position(&player, &map, key))
    {
        if (map.map[player.y - 1][player.x] != BLOCK &&
            map.map[player.y][player.x] != LADDER &&
            map.map[player.y][player.x] != EXIT)
            do {move_player(&player, GLUT_KEY_DOWN);}
            while (map.map[player.y - 1][player.x] != BLOCK);

        else if (map.map[player.y][player.x] == FREE_SPACE ||
                map.map[player.y][player.x] ==LADDER ||
                map.map[player.y][player.x] == GOLD)
             //   map.map[player.y][player.x] == EXIT)
                move_player(&player, key);

        else if (map.map[player.y][player.x] == EXIT)
                exit (0);

        else if (map.map[player.y][player.x] == GOLD)  // придумать как перезаписать gold на free после прохода
            {
                move_player(&player, key);
// FILE* file = fopen("D:/01_Projects/HomeWork/LEARN/LEARN/05_PROJECT_blade_runner/project_1/map.txt", "r+t");
//    for(int i = 0; i<SIZE_h; ++i)
//    {
//        fread(map.map[SIZE_h - i - 1], SIZE_w, 1, file);
//        if (i == GOLD)
//          i == FREE_SPACE;
//        fseek(file, 2, SEEK_CUR);
//    }
//    fclose(file);
             }
    };

    glutShowWindow();
    glutTimerFunc(5, &tick, 0);

}

int count = 0;                        // придумать как сделать счет
void score (Player* player, Map* map)
{
    if (map->map[player->y][player->x] == GOLD)
    {
        ++count;
    }
     if (count > 3)
    {printf ("count = %d", &count);};
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
    glutKeyboardFunc(&ExitKey);
    glutReshapeFunc(&Reshape);

    glutTimerFunc(5, &tick, 0);



    glutMainLoop();

    return 0;
}
