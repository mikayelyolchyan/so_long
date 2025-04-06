#include "../includes/headers/so_long.h"

int	start_game(t_game *game)
{
	t_map	*map;

	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		ft_printf("Error: t_map memory allocation failed\n");
		return (1);
	}
	map = game->map;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("MiniLibX initialization Error\n");
		return (1);
	}
	map->tile_size = 32;
	create_map("maps/classic.ber", game);
	game->win = mlx_new_window(game->mlx, map->width * map->tile_size, map->height * map->tile_size + 32, "PACMAN");
	if (!game->win)
	{
		ft_printf("Window creating Error\n");
		return (1);
	}

	map->wall_img = mlx_xpm_file_to_image(game->mlx, "sprites/Walls/wall.xpm", &map->tile_size, &map->tile_size);
	map->black_wall_img = mlx_xpm_file_to_image(game->mlx, "sprites/Walls/black.xpm", &map->tile_size, &map->tile_size);
	map->food_img = mlx_xpm_file_to_image(game->mlx, "sprites/Pacdots/pacdot_food.xpm", &map->tile_size, &map->tile_size);
	map->portal_img = mlx_xpm_file_to_image(game->mlx, "sprites/Portal/portal.xpm", &map->tile_size, &map->tile_size);
	map->logo_img = mlx_xpm_file_to_image(game->mlx, "sprites/Logo/logo.xpm", &map->tile_size, &map->tile_size);
	map->power_up_img = mlx_xpm_file_to_image(game->mlx, "sprites/Pacdots/pacdot_powerup.xpm", &map->tile_size, &map->tile_size);
	if (!map->wall_img || !map->food_img)
	{
		ft_printf("Error: Failed to load Map xpms\n");
		return (1);
	}
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		ft_printf("Error: t_player memory allocation failed\n");
		return (1);
	}
	game->player->pac_open_right = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_open_right.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_open_left = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_open_left.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_open_up = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_open_up.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_open_down = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_open_down.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_semi_left = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_semi_left.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_semi_right = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_semi_right.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_semi_up = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_semi_up.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_semi_down = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_semi_down.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_closed = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_closed.xpm", &map->tile_size, &map->tile_size);

	game->player->x = 13 * map->tile_size;
	game->player->y = 17 * map->tile_size;
	game->player->direction = RIGHT;
	game->player->pending_direction = -1;

	game->r_ghost = malloc(sizeof(t_ghost));
	if (!game->player)
	{
		ft_printf("Error: r_ghost memory allocation failed\n");
		return (1);
	}
	game->r_ghost->ghost_down1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_down1.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_down2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_down2.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_up1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_up1.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_up2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_up2.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_left1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_left1.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_left2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_left2.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_right1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_right1.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_right2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_right2.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->x = 14 * map->tile_size;
	game->r_ghost->y = 11 * map->tile_size;
	game->r_ghost->direction = RIGHT;
	game->r_ghost->prev_x = -1;
    game->r_ghost->prev_y = -1;
	game->r_ghost->targ_x = game->map->width * 32;
	game->r_ghost->targ_y = 0;

	game->r_ghost->ghost_panic1a = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic1a.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_panic1b = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic1b.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_panic2a = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic2a.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_panic2b = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic2b.xpm", &map->tile_size, &map->tile_size);

	game->frame = 0;
	game->frame_delay = 0;
	game->ghost_attack_mode = 0;
	game->power_up_img_delay = 0;
	game->pac_attack_mode = 0;
	game->last_pac_attack_mode = 0;
	game->pac_attack_mode_delay = 0;
	map->x = 0;
	map->y = 0;
	return (0);
}

int	main(void)
{
	t_game	game;

	if (start_game(&game) == 1)
		return (1);

	draw_map(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.player->pac_open_right, game.player->x, game.player->y);
	mlx_put_image_to_window(game.mlx, game.win, game.map->logo_img, game.map->width / 2 * 32 - 65, game.map->height * 32);
	mlx_hook(game.win, 17, 1L << 2, ft_exit, &game);
	mlx_hook(game.win, 2, 1L << 0, &ft_hotkey, &game);
	mlx_loop_hook(game.mlx, &game_animation, &game);
	mlx_loop(game.mlx);
	return (0);
}
