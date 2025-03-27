#include "../includes/headers/so_long.h"

int	ft_hotkey(int keycode, t_game *game)
{
	if (keycode == W)
	{
		game->player->y -= 32;
	}
	else if (keycode == S)
	{
		game->player->y += 32;
	}
	else if (keycode == A)
	{
		game->player->x -= 32;
	}
	else if (keycode == D)
	{
		game->player->x += 32;
	}
	else if (keycode == ESC)
	{
		exit(0);
	}
	mlx_clear_window(game->mlx, game->win);
    draw_map(game);
    mlx_put_image_to_window(game->mlx, game->win, game->player->player_img, game->player->x, game->player->y);
    return (0);
}
