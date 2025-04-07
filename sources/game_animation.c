#include "../includes/headers/so_long.h"

void	handle_all_animation_timings(t_game *game)
{
	game->frame_delay++;
	game->ghost_attack_mode_delay++;
	game->power_up_img_delay++;
	//printf("%llu\n", game->attack_mode_delay);
	if (game->frame_delay >= 1024)
	{
		game->frame = (game->frame + 1) % 4;
		game->frame_delay = 0;
		update_direction(game);
		ghost_moving(game);

		if (game->pac_attack_mode == 1)
		{
			pac_fast_moving(game);
			game->pac_attack_mode_delay++;
			if (game->pac_attack_mode_delay >= 200)
			{
				game->pac_attack_mode = 0;
				game->pac_attack_mode_delay = 0;
			}
		}
		else
			pac_moving(game);

		if (game->ghost_attack_mode_delay >= 900000)
			game->ghost_attack_mode_delay = 0;

		if (game->power_up_img_delay >= 5000)
		{
			if (game->map->map[3][1] == 'U')
				mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, 1 * game->map->tile_size, 3 * game->map->tile_size);
			if (game->map->map[3][24] == 'U')
				mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, 24 * game->map->tile_size, 3 * game->map->tile_size);
			if (game->map->map[17][1] == 'U')
				mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, 1 * game->map->tile_size, 17 * game->map->tile_size);
			if (game->map->map[17][24] == 'U')
				mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, 24 * game->map->tile_size, 17 * game->map->tile_size);
		}
		if (game->power_up_img_delay >= 10000)
		{
			game->power_up_img_delay = 0;
			if (game->map->map[3][1] == 'U')
				mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, 1 * game->map->tile_size, 3 * game->map->tile_size);
			if (game->map->map[3][24] == 'U')
				mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, 24 * game->map->tile_size, 3 * game->map->tile_size);
			if (game->map->map[17][1] == 'U')
				mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, 1 * game->map->tile_size, 17 * game->map->tile_size);
			if (game->map->map[17][24] == 'U')
				mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, 24 * game->map->tile_size, 17 * game->map->tile_size);
		}
	}
}

void	*get_ghost_current_img(t_game *game, t_ghost *r_ghost)
{
	void	*current_img;

	if ((r_ghost->direction == LEFT || r_ghost->direction == RIGHT) && game->pac_attack_mode == 0)
	{
		current_img = get_ghost_horizontal_animation(game, r_ghost);
	}
	else if ((r_ghost->direction == UP || r_ghost->direction == DOWN) && game->pac_attack_mode == 0)
	{
		current_img = get_ghost_vertical_animation(game, r_ghost);
	}
	else if ((r_ghost->direction == LEFT || r_ghost->direction == RIGHT) && game->pac_attack_mode == 1 && game->pac_attack_mode_delay <= 150)
	{
		current_img = get_ghost_panic_horizontal_animation(game, r_ghost);
	}
	else if ((r_ghost->direction == UP || r_ghost->direction == DOWN) && game->pac_attack_mode == 1 && game->pac_attack_mode_delay <= 150)
	{
		current_img = get_ghost_panic_vertical_animation(game, r_ghost);
	}
	else if ((r_ghost->direction == LEFT || r_ghost->direction == RIGHT) && game->pac_attack_mode == 1 && game->pac_attack_mode_delay >= 150)
	{
		current_img = get_ghost_panic_flashing_horizontal_animation(game, r_ghost);
	}
	else if ((r_ghost->direction == UP || r_ghost->direction == DOWN) && game->pac_attack_mode == 1 && game->pac_attack_mode_delay >= 150)
	{
		current_img = get_ghost_panic_flashing_vertical_animation(game, r_ghost);
	}
	return (current_img);
}

void	*get_pac_current_img(t_game *game, t_player *player)
{
	void	*current_img;

	if (player->direction == LEFT || player->direction == RIGHT)
	{
		current_img = get_pac_horizontal_animation(game, player);
	}
	else if (player->direction == UP || player->direction == DOWN)
	{
		current_img = get_pac_vertical_animation(game, player);
	}
	else
	{
		current_img = player->pac_closed;
	}
	return (current_img);
}

int	game_animation(t_game *game)
{
	t_player	*player;
	t_ghost		*r_ghost;
	void		*pac_current_img;
	void		*ghost_current_img;

	player = game->player;
	r_ghost = game->r_ghost;

	handle_all_animation_timings(game);

	pac_current_img = get_pac_current_img(game, player);
	ghost_current_img = get_ghost_current_img(game, r_ghost);

	update_map(game, game->map->map, game->r_ghost->direction);
	mlx_put_image_to_window(game->mlx, game->win, pac_current_img, game->player->x, game->player->y);
	mlx_put_image_to_window(game->mlx, game->win, ghost_current_img, game->r_ghost->x, game->r_ghost->y);
	return (0);
}
