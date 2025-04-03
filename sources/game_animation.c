#include "../includes/headers/so_long.h"

void	handle_pac_ghost_animation_moving_timings(t_game *game)
{
	game->frame_delay++;
	if (game->frame_delay >= 1024)
	{
		game->frame = (game->frame + 1) % 4;
		game->frame_delay = 0;
		update_direction(game);
		pac_moving(game);
		ghost_moving(game);
	}
}

void	*get_ghost_current_img(t_game *game, t_ghost *r_ghost)
{
	void	*current_img;

	if (r_ghost->direction == LEFT || r_ghost->direction == RIGHT)
	{
		current_img = get_ghost_horizontal_animation(game, r_ghost);
	}
	else if (r_ghost->direction == UP || r_ghost->direction == DOWN)
	{
		current_img = get_ghost_vertical_animation(game, r_ghost);
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

	handle_pac_ghost_animation_moving_timings(game);

	pac_current_img = get_pac_current_img(game, player);
	ghost_current_img = get_ghost_current_img(game, r_ghost);

	// mlx_clear_window(game->mlx, game->win);
	//draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, pac_current_img, game->player->x, game->player->y);
	mlx_put_image_to_window(game->mlx, game->win, ghost_current_img, game->r_ghost->x, game->r_ghost->y);
	//update_map(game, game->map->map, game->r_ghost->direction);
	return (0);
}
