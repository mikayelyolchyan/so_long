#include "../../includes/headers/so_long.h"

static void	pac_init_main_textures(t_game *game, t_map *map)
{
	game->player->pac_open_right = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/pac_open_right.xpm", \
		&map->tile_size, &map->tile_size);
	game->player->pac_open_left = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/pac_open_left.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_open_up = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/pac_open_up.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_open_down = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/pac_open_down.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_semi_left = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/pac_semi_left.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_semi_right = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/pac_semi_right.xpm", \
		&map->tile_size, &map->tile_size);
	game->player->pac_semi_up = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/pac_semi_up.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_semi_down = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/pac_semi_down.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_closed = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/pac_closed.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_black = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/black.xpm", &map->tile_size, &map->tile_size);
}

static void	pac_init_dying_textures(t_game *game, t_map *map)
{
	game->player->dying1 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/Dying/dying1.xpm", &map->tile_size, &map->tile_size);
	game->player->dying2 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/Dying/dying2.xpm", &map->tile_size, &map->tile_size);
	game->player->dying3 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/Dying/dying3.xpm", &map->tile_size, &map->tile_size);
	game->player->dying4 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/Dying/dying4.xpm", &map->tile_size, &map->tile_size);
	game->player->dying5 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/Dying/dying5.xpm", &map->tile_size, &map->tile_size);
	game->player->dying6 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/Dying/dying6.xpm", &map->tile_size, &map->tile_size);
	game->player->dying7 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/Dying/dying7.xpm", &map->tile_size, &map->tile_size);
	game->player->dying8 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/Dying/dying8.xpm", &map->tile_size, &map->tile_size);
	game->player->dying9 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/Dying/dying9.xpm", &map->tile_size, &map->tile_size);
	game->player->dying10 = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/Dying/dying10.xpm", &map->tile_size, &map->tile_size);
	game->player->woosh = mlx_xpm_file_to_image(game->mlx, \
		"textures/Pac-Man/Dying/woosh.xpm", &map->tile_size, &map->tile_size);
}

void	pacman_initializations(t_game *game, t_map *map)
{
	pac_init_main_textures(game, map);
	pac_init_dying_textures(game, map);
	game->player->x = game->player->start_x;
	game->player->y = game->player->start_y;
	game->player->prev_x = game->player->x;
	game->player->prev_y = game->player->y;
	game->player->direction = RIGHT;
	game->player->pending_direction = -1;
	game->player->move_count = 0;
	game->player->died_count = 0;
	game->player->dying_frame = 0;
	game->player->dying_frame_delay = 0;
}
