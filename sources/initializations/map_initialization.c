#include "../../includes/headers/so_long.h"

void	map_initialization(t_game *game, t_map *map)
{
	map->wall_img = mlx_xpm_file_to_image(game->mlx, \
		"textures/Walls/wall.xpm", &map->tile_size, &map->tile_size);
	map->white_wall_img = mlx_xpm_file_to_image(game->mlx, \
		"textures/Walls/white.xpm", &map->tile_size, &map->tile_size);
	map->red_wall_img = mlx_xpm_file_to_image(game->mlx, \
		"textures/Walls/red.xpm", &map->tile_size, &map->tile_size);
	map->black_wall_img = mlx_xpm_file_to_image(game->mlx, \
		"textures/Walls/black.xpm", &map->tile_size, &map->tile_size);
	map->food_img = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pacdots/pacdot_food.xpm", &map->tile_size, &map->tile_size);
	map->portal_img = mlx_xpm_file_to_image(game->mlx, \
		"textures/Portal/portal.xpm", &map->tile_size, &map->tile_size);
	map->logo_img = mlx_xpm_file_to_image(game->mlx, \
		"textures/Logo/logo.xpm", &map->tile_size, &map->tile_size);
	map->power_up_img = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pacdots/pacdot_powerup.xpm", \
			&map->tile_size, &map->tile_size);
	map->exit_img = mlx_xpm_file_to_image(game->mlx, \
		"textures/Exit/exit.xpm", &map->tile_size, &map->tile_size);
}
