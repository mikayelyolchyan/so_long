#include "../../includes/headers/so_long.h"

static void	blue_ghost_main_textures(t_game *game, t_map *map)
{
	game->b_ghost->ghost_down1 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/B/ghost_down1.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_down2 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/B/ghost_down2.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_up1 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/B/ghost_up1.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_up2 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/B/ghost_up2.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_left1 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/B/ghost_left1.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_left2 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/B/ghost_left2.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_right1 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/B/ghost_right1.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_right2 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/B/ghost_right2.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_is_eaten_right = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/black_right.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_is_eaten_left = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/black_left.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_is_eaten_up = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/black_up.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_is_eaten_down = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/black_down.xpm", &map->tile_size, &map->tile_size);
}

void	blue_ghost_initialization(t_game *game, t_map *map)
{
	if (map->ghost_count != 4)
		return ;
	blue_ghost_main_textures(game, map);
	ghost_panic_textures(game, map, game->b_ghost);
	game->b_ghost->x = game->b_ghost->start_x;
	game->b_ghost->y = game->b_ghost->start_y;
	game->b_ghost->remainder_x = 0;
	game->b_ghost->remainder_y = 0;
	game->b_ghost->direction = RIGHT;
	game->b_ghost->pending_direction = RIGHT;
	game->b_ghost->prev_x = game->b_ghost->x;
	game->b_ghost->prev_y = game->b_ghost->y;
	game->b_ghost->targ_x = game->map->width * 32;
	game->b_ghost->targ_y = 0;
	game->b_ghost->is_eaten = 0;
	game->b_ghost->is_respawned = 0;
}
