#ifndef MAP_H
#define MAP_H

constexpr char SIZE_h = 30;
constexpr char SIZE_w = 40;

enum MapType
{
    BLOCK = '#',
    FREE_SPACE = '.',
    LADDER = '&',
    EXIT = 'X',
    GOLD = 'G'
};

struct Map
{
    char map[SIZE_h][SIZE_w];
};

void init_map(Map* map, const char* path);
void print_map(const Map* map);

#endif // MAP_H
