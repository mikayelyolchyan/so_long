#include "../../includes/headers/so_long.h"

static void	magenta_ghost_main_textures(t_game *game, t_map *map)
{
	game->m_ghost->ghost_down1 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/K/ghost_down1.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_down2 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/K/ghost_down2.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_up1 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/K/ghost_up1.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_up2 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/K/ghost_up2.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_left1 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/K/ghost_left1.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_left2 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/K/ghost_left2.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_right1 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/K/ghost_right1.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_right2 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/K/ghost_right2.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_is_eaten_right = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/black_right.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_is_eaten_left = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/black_left.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_is_eaten_up = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/black_up.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_is_eaten_down = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/black_down.xpm", &map->tile_size, &map->tile_size);
}

void	magenta_ghost_initialization(t_game *game, t_map *map)
{
	if (map->ghost_count != 4)
		return ;
	magenta_ghost_main_textures(game, map);
	ghost_panic_textures(game, map, game->m_ghost);
	game->m_ghost->x = game->m_ghost->start_x;
	game->m_ghost->y = game->m_ghost->start_y;
	game->m_ghost->remainder_x = 0;
	game->m_ghost->remainder_y = 0;
	game->m_ghost->direction = LEFT;
	game->m_ghost->prev_x = game->m_ghost->x;
	game->m_ghost->prev_y = game->m_ghost->y;
	game->m_ghost->targ_x = game->map->width * 32;
	game->m_ghost->targ_y = 0;
	game->m_ghost->is_eaten = 0;
	game->m_ghost->is_respawned = 0;
}
