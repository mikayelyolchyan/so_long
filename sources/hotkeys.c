#include "../includes/headers/so_long.h"

int	ft_hotkey(int keycode, t_game *game)
{
	if (keycode == W)
	{
		game->player->pending_direction = UP;
	}
	else if (keycode == S)
	{
		game->player->pending_direction = DOWN;
	}
	else if (keycode == A)
	{
		game->player->pending_direction = LEFT;
	}
	else if (keycode == D)
	{
		game->player->pending_direction = RIGHT;
	}
	else if (keycode == ESC)
	{
		ft_exit(game);
	}
	game->frame_delay = 0;
	return (0);
}
