#include "../includes/headers/so_long.h"

int	can_move_vertical(t_game *game, char **map)
{
	if (game->player->pending_direction == UP && \
		map[(game->player->y - 4) / 32][game->player->x / 32] != '1' && \
		game->player->x % 32 == 0)
		return (1);
	if (game->player->pending_direction == DOWN && \
		map[(game->player->y + 4) / 32 + 1][game->player->x / 32] != '1' && \
		game->player->x % 32 == 0)
		return (1);
	return (0);
}

int	can_move_horizontal(t_game *game, char **map)
{
	if (game->player->pending_direction == LEFT && \
		map[game->player->y / 32][(game->player->x - 4) / 32] != '1' && \
		game->player->y % 32 == 0)
		return (1);
	if (game->player->pending_direction == RIGHT && \
		map[game->player->y / 32][(game->player->x + 4) / 32 + 1] != '1' && \
		game->player->y % 32 == 0)
		return (1);
	return (0);
}

void	update_direction(t_game *game)
{
	char	**map;

	map = game->map->map;
	if (game->player->pending_direction == -1)
		return ;
	if (can_move_vertical(game, map))
	{
		game->player->direction = game->player->pending_direction;
		game->player->pending_direction = -1;
	}
	else if (can_move_horizontal(game, map))
	{
		game->player->direction = game->player->pending_direction;
		game->player->pending_direction = -1;
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
	game->frame_delay = 0;
	return (0);
}
