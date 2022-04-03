#ifndef PLAYER_H
#define PLAYER_H
#include "map.h"

struct Player
{
    int x;
    int y;
};

extern Player player;

void PrintPlayer(Player player);
void move_player(Player* player, int key);
bool check_position(Player* player, Map* map, int key);

int super_check(Player* player, Map* map, int key);

#endif // PLAYER_H
