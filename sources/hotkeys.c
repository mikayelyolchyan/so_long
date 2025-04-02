#include "../includes/headers/so_long.h"

void	update_direction(t_game *game)
{
	char	**map;
	
	map = game->map->map;
	if (game->player->pending_direction != -1)
	{
		if (game->player->pending_direction == UP && map[(game->player->y - 4) / 32][game->player->x / 32] != '1' && game->player->x % 32 == 0)
		{
			game->player->direction = UP;
			game->player->pending_direction = -1;
		}
		else if (game->player->pending_direction == DOWN && map[(game->player->y + 4) / 32 + 1][game->player->x / 32] != '1' && game->player->x % 32 == 0)
		{
			game->player->direction = DOWN;
			game->player->pending_direction = -1;
		}
		else if (game->player->pending_direction == LEFT && map[game->player->y / 32][(game->player->x - 4) / 32] != '1' && game->player->y % 32 == 0)
		{
			game->player->direction = LEFT;
			game->player->pending_direction = -1;
		}
		else if (game->player->pending_direction == RIGHT && map[game->player->y / 32][(game->player->x + 4) / 32 + 1] != '1' && game->player->y % 32 == 0)
		{
			game->player->direction = RIGHT;
			game->player->pending_direction = -1;
		}
	}
}

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

	game->player->frame_delay = 0;

	return (0);
}
