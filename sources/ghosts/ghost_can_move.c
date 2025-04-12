#include "../../includes/headers/so_long.h"

int ghost_can_move_vertical(t_ghost *c_ghost, char **map, int direction)
{
    if (direction == UP && map[(c_ghost->y - 4) / 32] \
		[c_ghost->x / 32] != '1' && c_ghost->x % 32 == 0)
        return (1);
    if (direction == DOWN && map[(c_ghost->y + 4) / 32 + 1] \
		[c_ghost->x / 32] != '1' && c_ghost->x % 32 == 0)
        return (1);
    return (0);
}

int ghost_can_move_horizontal(t_ghost *c_ghost, char **map, int direction)
{
    if (direction == LEFT && map[c_ghost->y / 32] \
		[(c_ghost->x - 4) / 32] != '1' && c_ghost->y % 32 == 0)
        return (1);
    if (direction == RIGHT && map[c_ghost->y / 32] \
		[(c_ghost->x + 4) / 32 + 1] != '1' && c_ghost->y % 32 == 0)
        return (1);
    return (0);
}

int ghost_can_move_fast_vertical(t_ghost *c_ghost, char **map, int direction)
{
    if (direction == UP && map[(c_ghost->y - 16) / 32] \
		[c_ghost->x / 32] != '1' && c_ghost->x % 32 == 0)
        return (1);
    if (direction == DOWN && map[(c_ghost->y + 16) / 32 + 1] \
		[c_ghost->x / 32] != '1' && c_ghost->x % 32 == 0)
        return (1);
    return (0);
}

int ghost_can_move_fast_horizontal(t_ghost *c_ghost, char **map, int direction)
{
    if (direction == LEFT && map[c_ghost->y / 32] \
		[(c_ghost->x - 16) / 32] != '1' && c_ghost->y % 32 == 0)
        return (1);
    if (direction == RIGHT && map[c_ghost->y / 32] \
		[(c_ghost->x + 16) / 32 + 1] != '1' && c_ghost->y % 32 == 0)
        return (1);
    return (0);
}