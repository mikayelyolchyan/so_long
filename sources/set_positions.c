#include "../includes/headers/so_long.h"

void	set_player_position(t_game *game, int x, int y)
{
	game->player->start_x = x * game->map->tile_size;
	game->player->start_y = y * game->map->tile_size;
}

void	set_ghost_position(t_ghost *ghost, int x, int y, int tile_size)
{
	ghost->start_x = x * tile_size;
	ghost->start_y = y * tile_size;
}

void	set_power_up_position(t_map *map, int x, int y, int *power_up_index)
{
	if (*power_up_index < map->power_up_dots_count)
	{
		map->power_up_dots_array[*power_up_index].x = x * map->tile_size;
		map->power_up_dots_array[*power_up_index].y = y * map->tile_size;
		(*power_up_index)++;
	}
}

void	set_portal_position(t_game *game, int x, int y)
{
	if (x == 1)
	{
		game->portal[0].x = x;
		game->portal[0].y = y;
	}
	else if (x == game->map->width - 2)
	{
		game->portal[1].x = x;
		game->portal[1].y = y;
	}
}
