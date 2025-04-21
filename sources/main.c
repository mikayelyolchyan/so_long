#include "../includes/headers/so_long.h"

void	pacman_initializations(t_game *game, t_map *map)
{
	game->player->pac_open_right = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_open_right.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_open_left = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_open_left.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_open_up = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_open_up.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_open_down = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_open_down.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_semi_left = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_semi_left.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_semi_right = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_semi_right.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_semi_up = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_semi_up.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_semi_down = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_semi_down.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_closed = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/pac_closed.xpm", &map->tile_size, &map->tile_size);
	game->player->pac_black = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/black.xpm", &map->tile_size, &map->tile_size);
	game->player->dying1 = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/Dying/dying1.xpm", &map->tile_size, &map->tile_size);
	game->player->dying2 = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/Dying/dying2.xpm", &map->tile_size, &map->tile_size);
	game->player->dying3 = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/Dying/dying3.xpm", &map->tile_size, &map->tile_size);
	game->player->dying4 = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/Dying/dying4.xpm", &map->tile_size, &map->tile_size);
	game->player->dying5 = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/Dying/dying5.xpm", &map->tile_size, &map->tile_size);
	game->player->dying6 = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/Dying/dying6.xpm", &map->tile_size, &map->tile_size);
	game->player->dying7 = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/Dying/dying7.xpm", &map->tile_size, &map->tile_size);
	game->player->dying8 = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/Dying/dying8.xpm", &map->tile_size, &map->tile_size);
	game->player->dying9 = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/Dying/dying9.xpm", &map->tile_size, &map->tile_size);
	game->player->dying10 = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/Dying/dying10.xpm", &map->tile_size, &map->tile_size);
	game->player->woosh = mlx_xpm_file_to_image(game->mlx, "sprites/Pac-Man/Dying/woosh.xpm", &map->tile_size, &map->tile_size);
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

void	red_ghost_initialization(t_game *game, t_map *map)
{
	game->r_ghost->x = game->r_ghost->start_x;
	game->r_ghost->y = game->r_ghost->start_y;
	game->r_ghost->remainder_x = 0;
    game->r_ghost->remainder_y = 0;
	game->r_ghost->ghost_down1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_down1.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_down2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_down2.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_up1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_up1.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_up2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_up2.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_left1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_left1.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_left2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_left2.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_right1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_right1.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_right2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/R/ghost_right2.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_is_eaten_right = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_right.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_is_eaten_left = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_left.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_is_eaten_up = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_up.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_is_eaten_down= mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_down.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->direction = RIGHT;
	game->r_ghost->prev_x = game->r_ghost->x;
    game->r_ghost->prev_y = game->r_ghost->y;
	game->r_ghost->targ_x = game->map->width * 32;
	game->r_ghost->targ_y = 0;
	game->r_ghost->is_eaten = 0;
	game->r_ghost->is_respawned = 0;
	game->r_ghost->ghost_panic1a = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic1a.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_panic1b = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic1b.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_panic2a = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic2a.xpm", &map->tile_size, &map->tile_size);
	game->r_ghost->ghost_panic2b = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic2b.xpm", &map->tile_size, &map->tile_size);
}

void	orange_ghost_initialization(t_game *game, t_map *map)
{
	game->o_ghost->x = game->o_ghost->start_x;
	game->o_ghost->y = game->o_ghost->start_y;
	game->o_ghost->remainder_x = 0;
    game->o_ghost->remainder_y = 0;
	game->o_ghost->ghost_down1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/O/ghost_down1.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_down2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/O/ghost_down2.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_up1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/O/ghost_up1.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_up2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/O/ghost_up2.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_left1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/O/ghost_left1.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_left2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/O/ghost_left2.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_right1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/O/ghost_right1.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_right2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/O/ghost_right2.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_is_eaten_right = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_right.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_is_eaten_left = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_left.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_is_eaten_up = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_up.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_is_eaten_down = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_down.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->direction = LEFT;
	game->o_ghost->prev_x = game->o_ghost->x;
    game->o_ghost->prev_y = game->o_ghost->y;
	game->o_ghost->targ_x = game->map->width * 32;
	game->o_ghost->targ_y = 0;
	game->o_ghost->is_eaten = 0;
	game->o_ghost->is_respawned = 0;
	game->o_ghost->ghost_panic1a = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic1a.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_panic1b = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic1b.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_panic2a = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic2a.xpm", &map->tile_size, &map->tile_size);
	game->o_ghost->ghost_panic2b = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic2b.xpm", &map->tile_size, &map->tile_size);
}

void	magenta_ghost_initialization(t_game *game, t_map *map)
{
	game->m_ghost->x = game->m_ghost->start_x;
	game->m_ghost->y = game->m_ghost->start_y;
	game->m_ghost->remainder_x = 0;
    game->m_ghost->remainder_y = 0;
	game->m_ghost->ghost_down1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/K/ghost_down1.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_down2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/K/ghost_down2.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_up1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/K/ghost_up1.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_up2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/K/ghost_up2.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_left1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/K/ghost_left1.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_left2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/K/ghost_left2.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_right1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/K/ghost_right1.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_right2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/K/ghost_right2.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_is_eaten_right = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_right.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_is_eaten_left = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_left.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_is_eaten_up = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_up.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_is_eaten_down = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_down.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->direction = LEFT;
	game->m_ghost->prev_x = game->m_ghost->x;
    game->m_ghost->prev_y = game->m_ghost->y;
	game->m_ghost->targ_x = game->map->width * 32;
	game->m_ghost->targ_y = 0;
	game->m_ghost->is_eaten = 0;
	game->m_ghost->is_respawned = 0;
	game->m_ghost->ghost_panic1a = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic1a.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_panic1b = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic1b.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_panic2a = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic2a.xpm", &map->tile_size, &map->tile_size);
	game->m_ghost->ghost_panic2b = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic2b.xpm", &map->tile_size, &map->tile_size);
}

void	blue_ghost_initialization(t_game *game, t_map *map)
{
	game->b_ghost->x = game->b_ghost->start_x;
	game->b_ghost->y = game->b_ghost->start_y;
	game->b_ghost->remainder_x = 0;
    game->b_ghost->remainder_y = 0;
	game->b_ghost->ghost_down1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/B/ghost_down1.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_down2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/B/ghost_down2.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_up1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/B/ghost_up1.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_up2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/B/ghost_up2.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_left1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/B/ghost_left1.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_left2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/B/ghost_left2.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_right1 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/B/ghost_right1.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_right2 = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/B/ghost_right2.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_is_eaten_right = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_right.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_is_eaten_left = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_left.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_is_eaten_up = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_up.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_is_eaten_down = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/black_down.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->direction = RIGHT;
	game->b_ghost->prev_x = game->b_ghost->x;
    game->b_ghost->prev_y = game->b_ghost->y;
	game->b_ghost->targ_x = game->map->width * 32;
	game->b_ghost->targ_y = 0;
	game->b_ghost->is_eaten = 0;
	game->b_ghost->is_respawned = 0;
	game->b_ghost->ghost_panic1a = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic1a.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_panic1b = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic1b.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_panic2a = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic2a.xpm", &map->tile_size, &map->tile_size);
	game->b_ghost->ghost_panic2b = mlx_xpm_file_to_image(game->mlx, "sprites/Ghosts/Panic/ghost_panic2b.xpm", &map->tile_size, &map->tile_size);
}

void	font_initialization(t_game *game)
{
	int i = 15;
	int j = 8;
	game->font->zero = mlx_xpm_file_to_image(game->mlx, "sprites/Fonts/0.xpm", &i, &j);
	game->font->one = mlx_xpm_file_to_image(game->mlx, "sprites/Fonts/1.xpm", &i, &j);
	game->font->two = mlx_xpm_file_to_image(game->mlx, "sprites/Fonts/2.xpm", &i, &j);
	game->font->three = mlx_xpm_file_to_image(game->mlx, "sprites/Fonts/3.xpm", &i, &j);
	game->font->four = mlx_xpm_file_to_image(game->mlx, "sprites/Fonts/4.xpm", &i, &j);
	game->font->five = mlx_xpm_file_to_image(game->mlx, "sprites/Fonts/5.xpm", &i, &j);
	game->font->six = mlx_xpm_file_to_image(game->mlx, "sprites/Fonts/6.xpm", &i, &j);
	game->font->seven = mlx_xpm_file_to_image(game->mlx, "sprites/Fonts/7.xpm", &i, &j);
	game->font->eight = mlx_xpm_file_to_image(game->mlx, "sprites/Fonts/8.xpm", &i, &j);
	game->font->nine = mlx_xpm_file_to_image(game->mlx, "sprites/Fonts/9.xpm", &i, &j);
}

int	start_game(t_game *game, char *argv)
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
	map_is_valid(argv, game);
	//create_map("maps/classic.ber", game);
	game->win = mlx_new_window(game->mlx, map->width * map->tile_size, map->height * map->tile_size + 32, "PACMAN");
	if (!game->win)
	{
		ft_printf("Window creating Error\n");
		return (1);
	}

	map->wall_img = mlx_xpm_file_to_image(game->mlx, "sprites/Walls/wall.xpm", &map->tile_size, &map->tile_size);
	map->white_wall_img = mlx_xpm_file_to_image(game->mlx, "sprites/Walls/white.xpm", &map->tile_size, &map->tile_size);
	map->red_wall_img = mlx_xpm_file_to_image(game->mlx, "sprites/Walls/red.xpm", &map->tile_size, &map->tile_size);
	map->black_wall_img = mlx_xpm_file_to_image(game->mlx, "sprites/Walls/black.xpm", &map->tile_size, &map->tile_size);
	map->food_img = mlx_xpm_file_to_image(game->mlx, "sprites/Pacdots/pacdot_food.xpm", &map->tile_size, &map->tile_size);
	map->portal_img = mlx_xpm_file_to_image(game->mlx, "sprites/Portal/portal.xpm", &map->tile_size, &map->tile_size);
	map->logo_img = mlx_xpm_file_to_image(game->mlx, "sprites/Logo/logo.xpm", &map->tile_size, &map->tile_size);
	map->power_up_img = mlx_xpm_file_to_image(game->mlx, "sprites/Pacdots/pacdot_powerup.xpm", &map->tile_size, &map->tile_size);
	if (!map->wall_img || !map->black_wall_img || !map->food_img || !map->portal_img || !map->logo_img || !map->power_up_img)
	{
		ft_printf("Error: Failed to load Map xpm`s\n");
		return (1);
	}

	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		ft_printf("Error: t_player memory allocation failed\n");
		return (1);
	}

	game->r_ghost = malloc(sizeof(t_ghost));
	game->o_ghost = malloc(sizeof(t_ghost));
	game->m_ghost = malloc(sizeof(t_ghost));
	game->b_ghost = malloc(sizeof(t_ghost));
	if (!game->r_ghost || !game->o_ghost || !game->m_ghost || !game->b_ghost)
	{
		ft_printf("Error: t_ghost memory allocation failed\n");
		return (1);
	}

	game->map->dots_count = 0;
	game->map->power_up_dots_count = 0;
	count_sprites(game);

	game->map->power_up_dots_array = malloc((sizeof(t_power_up_dot) * game->map->power_up_dots_count));
	//game->portal = malloc(sizeof(t_portal));

	find_positions(game);

	pacman_initializations(game, map);
	red_ghost_initialization(game, map);
	orange_ghost_initialization(game, map);
	magenta_ghost_initialization(game, map);
	blue_ghost_initialization(game, map);

	game->font = malloc(sizeof(t_font));
	font_initialization(game);

	game->frame = 0;
	game->frame_delay = 0;
	game->ghost_attack_mode = 0;
	game->power_up_img_delay = 0;
	game->pac_attack_mode = 0;
	game->last_pac_attack_mode = 0;
	game->pac_attack_mode_delay = 0;
	game->score = 0;
	game->eated_dots = 0;
	game->game_start = 0;
	game->game_start_delay = 0;
	game->game_win = 0;
	game->map_flashing_frame = 0;
	game->map_flashing_delay = 0;
	game->map_flashing_count = 0;
	game->game_restart = 0;

	map->x = 0;
	map->y = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (start_game(&game, argv[1]) == 1)
			return (1);
		draw_map(&game);
		mlx_put_image_to_window(game.mlx, game.win, game.player->pac_open_right, game.player->x, game.player->y);
		mlx_put_image_to_window(game.mlx, game.win, game.map->logo_img, game.map->width / 2 * 32 - 65, game.map->height * 32);
		mlx_put_image_to_window(game.mlx, game.win, game.player->pac_semi_right, 4 * 32, game.map->height * 32);
		mlx_put_image_to_window(game.mlx, game.win, game.player->pac_semi_right, 5 * 32, game.map->height * 32);
		mlx_hook(game.win, 17, 1L << 2, ft_exit, &game);
		mlx_hook(game.win, 2, 1L << 0, &ft_hotkey, &game);
		mlx_loop_hook(game.mlx, &game_animation, &game);
		mlx_loop(game.mlx);
	}
	else
		return (1);
	return (0);
}
