#include <GL/freeglut.h>
#include <stdlib.h>
#include "player.h"
#include "map.h"

Player player = {1, 1};

void PrintPlayer(Player player)
{
    glBegin(GL_POLYGON);

    glColor3f(0.8, 0.0, 0.0);
    glVertex2d(player.x * 32, player.y * 32);
    glVertex2d(player.x * 32 + 32, player.y * 32);
    glVertex2d(player.x * 32 + 32, player.y * 32 + 32);
    glVertex2d(player.x * 32, player.y * 32 + 32);

    glEnd();
}

int speed = 25;
int current_speed = 0;

Player move_player_impl(Player* player, int key)
{
    switch (key)
    {
      case GLUT_KEY_UP:
          return {player->x, player->y + 1};
      case GLUT_KEY_DOWN:
          return {player->x, player->y - 1};
      case GLUT_KEY_LEFT:
          return {player->x - 1, player->y};
      case GLUT_KEY_RIGHT:
          return {player->x + 1, player->y};
    };
    return *player;
}

void move_player(Player *player, int key)
{
    if (current_speed == 0)
    {
      current_speed = speed;
      *player = move_player_impl(player, key);
    }
    else
    {
        --current_speed;
    }
}

bool check_position(Player* player, Map *map, int key)
{
    Player tmp = move_player_impl(player, key);

    if (tmp.y > player->y)
        return map->map[tmp.y][tmp.x] == LADDER ||
               map->map[tmp.y][tmp.x] == EXIT;

    return map->map[tmp.y][tmp.x] == FREE_SPACE ||
           map->map[tmp.y][tmp.x] == LADDER ||
           map->map[tmp.y][tmp.x] == GOLD;
}
