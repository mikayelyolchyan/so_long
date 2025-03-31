#include "../includes/headers/so_long.h"

int	ft_hotkey(int keycode, t_game *game)
{
	int	count;

	count = 0;
	if (keycode == W && game->map->map[(game->player->y - 32) / 32][(game->player->x) / 32] != '1')
	{
		game->player->y -= 32;
		game->player->direction = UP;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
		{
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
			count++;
		}
	}
	else if (keycode == S && game->map->map[(game->player->y + 32) / 32][(game->player->x) / 32] != '1')
	{
		game->player->y += 32;
		game->player->direction = DOWN;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
		{
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
			count++;
		}
	}
	else if (keycode == A && game->map->map[(game->player->y) / 32][(game->player->x - 32) / 32] != '1')
	{
		game->player->x -= 32;
		game->player->direction = LEFT;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
		{
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
			count++;
		}
	}
	else if (keycode == D && game->map->map[(game->player->y) / 32][(game->player->x + 32) / 32] != '1')
	{
		game->player->x += 32;
		game->player->direction = RIGHT;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
		{
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
			count++;
		}
	}
	else if (keycode == ESC)
	{
		ft_exit(game);
	}
	
	game->player->frame_delay = 0;

    return (0);
}
