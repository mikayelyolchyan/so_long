#include "../includes/headers/so_long.h"

void	find_positions(t_game *game)
{
	int	x;
	int	y;
	t_map *map;
	int	power_up_index = 0;

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
			else if (map->map[y][x] == 'U')
            {
                if (power_up_index < map->power_up_dots_count)
                {
					map->power_up_dots_array[power_up_index].x = x * map->tile_size;
                    map->power_up_dots_array[power_up_index].y = y * map->tile_size;
                    //printf("Power-up %d: x=%d, y=%d (map: %d,%d)\n", power_up_index, map->power_up_dots_array[power_up_index].x, map->power_up_dots_array[power_up_index].y, x, y);
                    power_up_index++;
                }
            }
			x++;
		}
		y++;
	}
}