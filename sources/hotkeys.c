#include "../includes/headers/so_long.h"

int	ft_hotkey(int keycode, t_game *game)
{
	if (keycode == W && game->map->map[(game->player->y - 32) / 32][(game->player->x) / 32] != '1')
	{
		if (game->player->x % 32 == 0)
			game->player->direction = UP;
	}
	else if (keycode == S && game->map->map[(game->player->y + 32) / 32][(game->player->x) / 32] != '1')
	{
		if (game->player->x % 32 == 0)
			game->player->direction = DOWN;
	}
	else if (keycode == A && game->map->map[(game->player->y) / 32][(game->player->x - 32) / 32] != '1')
	{
		if (game->player->y % 32 == 0)
			game->player->direction = LEFT;
	}
	else if (keycode == D && game->map->map[(game->player->y) / 32][(game->player->x + 32) / 32] != '1')
	{
		if (game->player->y % 32 == 0)
			game->player->direction = RIGHT;
	}
	else if (keycode == ESC)
	{
		ft_exit(game);
	}
	
	game->player->frame_delay = 0;

    return (0);
}
