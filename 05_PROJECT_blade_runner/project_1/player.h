#ifndef PLAYER_H
#define PLAYER_H
#include "map.h"

struct Player
{
    int x;
    int y;
};

void PrintPlayer(Player player);
void move_player(Player* player, int direction, Map* map);

#endif // PLAYER_H
