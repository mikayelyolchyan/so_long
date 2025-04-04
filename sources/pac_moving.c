#include "../includes/headers/so_long.h"

void	pac_moving_up_down(t_game *game)
{
	if (game->player->direction == UP)
	{
		if (game->map->map[(game->player->y - 4) / 32][game->player->x / 32] != '1')
			game->player->y -= 4;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
	}
	else if (game->player->direction == DOWN)
	{
		if (game->map->map[(game->player->y + 4) / 32 + 1][game->player->x / 32] != '1')
			game->player->y += 4;
		else
		 	game->player->y = (game->player->y + 4) / 32 * 32;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
	}
}

void	pac_moving_left_right(t_game *game)
{
	if (game->player->direction == LEFT)
	{
		if (game->map->map[game->player->y / 32][(game->player->x - 4) / 32] != '1')
			game->player->x -= 4;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
		if (game->map->map[game->player->y / 32][(game->player->x - 4) / 32] == 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->player->x, game->player->y);
			game->player->x = 23 * 32;
			game->player->y = 11 * 32;
		}
	}
	else if (game->player->direction == RIGHT)
	{
		if (game->map->map[game->player->y / 32][(game->player->x + 4) / 32 + 1] != '1')
		{
			game->player->x += 4;
		}
		else
		 	game->player->x = (game->player->x + 4) / 32 * 32;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
		if (game->map->map[game->player->y / 32][(game->player->x + 32) / 32] == 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->player->x, game->player->y);
			game->player->x = 2 * 32;
			game->player->y = 11 * 32;
		}
	}
}

void	pac_moving(t_game *game)
{
	pac_moving_up_down(game);
	pac_moving_left_right(game);
}
