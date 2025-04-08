#include "../includes/headers/so_long.h"

void	find_positions(t_game *game)
{
	int	x;
	int	y;
	t_map *map;

	map = game->map;
	y = 0;
	while(map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				game->player->start_x = x * map->tile_size;
				game->player->start_y = y * map->tile_size;
			}
			else if (map->map[y][x] == 'R')
			{
				game->r_ghost->start_x = x * map->tile_size;
				game->r_ghost->start_y = y * map->tile_size;
			}
			x++;
		}
		y++;
	}
}