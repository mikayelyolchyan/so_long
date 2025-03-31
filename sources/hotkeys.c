#include "../includes/headers/so_long.h"

int	ft_hotkey(int keycode, t_game *game)
{
	int	count;

	count = 0;
	if (keycode == W && game->map->map[(game->player->y - 32) / 32][(game->player->x) / 32] != '1')
	{
		game->player->y -= 32;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
		{
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
			count++;
		}
	}
	else if (keycode == S && game->map->map[(game->player->y + 32) / 32][(game->player->x) / 32] != '1')
	{
		game->player->y += 32;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
		{
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
			count++;
		}
	}
	else if (keycode == A && game->map->map[(game->player->y) / 32][(game->player->x - 32) / 32] != '1')
	{
		game->player->x -= 32;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
		{
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
			count++;
		}
	}
	else if (keycode == D && game->map->map[(game->player->y) / 32][(game->player->x + 32) / 32] != '1')
	{
		game->player->x += 32;
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
	mlx_clear_window(game->mlx, game->win);
    draw_map(game);
    mlx_put_image_to_window(game->mlx, game->win, game->player->pac_semi_right, game->player->x, game->player->y);
    return (0);
}
