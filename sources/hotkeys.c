#include "../includes/headers/so_long.h"

int	ft_hotkey(int keycode, t_game *game)
{
	if (keycode == W && game->map->map[(game->player->y - 32) / 32][(game->player->x) / 32] != '1')
	{
		game->player->direction = UP;
		//pac_moving(game);
	}
	else if (keycode == S && game->map->map[(game->player->y + 32) / 32][(game->player->x) / 32] != '1')
	{
		game->player->direction = DOWN;
		//pac_moving(game);
	}
	else if (keycode == A && game->map->map[(game->player->y) / 32][(game->player->x - 32) / 32] != '1')
	{
		game->player->direction = LEFT;
		//pac_moving(game);
	}
	else if (keycode == D && game->map->map[(game->player->y) / 32][(game->player->x + 32) / 32] != '1')
	{
		game->player->direction = RIGHT;
		//pac_moving(game);
	}
	else if (keycode == ESC)
	{
		ft_exit(game);
	}
	
	game->player->frame_delay = 0;

    return (0);
}
