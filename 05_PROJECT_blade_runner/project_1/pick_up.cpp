#include <stdio.h>
#include "pick_up.h"
#include "player.h"
#include "map.h"

int count = 0;
void pick_up(Player* player, Map* map)
{
    if (map->map[player->y][player->x] == GOLD)
    {
        map->map[player->y][player->x] = FREE_SPACE;
        ++count;
        printf ("count = %d\n", count);
    };
}
