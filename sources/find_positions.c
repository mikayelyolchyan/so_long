#include "../includes/headers/so_long.h"

static void	process_map_tile(t_game *game, int x, int y, int *power_up_index)
{
	t_map	*map;

	map = game->map;
	if (map->map[y][x] == 'P')
		set_player_position(game, x, y);
	else if (map->map[y][x] == 'R')
		set_ghost_position(game->r_ghost, x, y, map->tile_size);
	else if (map->map[y][x] == 'O')
		set_ghost_position(game->o_ghost, x, y, map->tile_size);
	else if (map->map[y][x] == 'M')
		set_ghost_position(game->m_ghost, x, y, map->tile_size);
	else if (map->map[y][x] == 'B')
		set_ghost_position(game->b_ghost, x, y, map->tile_size);
	else if (map->map[y][x] == 'U')
		set_power_up_position(map, x, y, power_up_index);
	else if (map->map[y][x] == 'T')
		set_portal_position(game, x, y);
}

void	find_positions(t_game *game)
{
	int		x;
	int		y;
	int		power_up_index;
	t_map	*map;

	map = game->map;
	power_up_index = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			process_map_tile(game, x, y, &power_up_index);
			x++;
		}
		y++;
	}
}
