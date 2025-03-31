#include "../includes/headers/so_long.h"

int	pac_animation(t_game *game)
{
	t_player *player;
	void	*current_img;

	player = game->player;
	player->frame_delay++;
	if (player->frame_delay >= 30)
	{
		player->frame = (player->frame + 1) % 3;
		player->frame_delay = 0;
	}

	if (player->direction == LEFT)
	{
		if (player->frame == 0)
			current_img = player->pac_closed;
		else if (player->frame == 1)
			current_img = player->pac_semi_left;
		else if (player->frame == 2)
			current_img = player->pac_open_left;
	}
	else if (player->direction == RIGHT)
	{
		if (player->frame == 0)
			current_img = player->pac_closed;
		else if (player->frame == 1)
			current_img = player->pac_semi_right;
		else if (player->frame == 2)
			current_img = player->pac_open_right;
	}
	else if (player->direction == UP)
	{
		if (player->frame == 0)
			current_img = player->pac_closed;
		else if (player->frame == 1)
			current_img = player->pac_semi_up;
		else if (player->frame == 2)
			current_img = player->pac_open_up;
	}
	else if (player->direction == DOWN)
	{
		if (player->frame == 0)
			current_img = player->pac_closed;
		else if (player->frame == 1)
			current_img = player->pac_semi_down;
		else if (player->frame == 2)
			current_img = player->pac_open_down;
	}
	else
	{
		current_img = player->pac_closed;
	}

    draw_map(game);
    mlx_put_image_to_window(game->mlx, game->win, current_img, game->player->x, game->player->y);
	return (0);
}