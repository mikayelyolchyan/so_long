#include "../includes/headers/so_long.h"

int	ft_hotkey(int keycode, t_game *game)
{
	if (keycode == W)
	{
		game->map->y -= 10;
	}
	else if (keycode == S)
	{
		game->map->y += 10;
	}
	else if (keycode == A)
	{
		game->map->x -= 10;
	}
	else if (keycode == D)
	{
		game->map->x += 10;
	}
	else if (keycode == ESC)
	{
		exit(0);
	}
	mlx_clear_window(game->mlx, game->win);
	mlx_string_put(game->mlx, game->win, game->map->x, game->map->y, 0xFFFFFF, "C");
	return (0);
}
