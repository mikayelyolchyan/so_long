#include "../includes/headers/so_long.h"

void	pac_moving_up_down(t_game *game)
{
	game->player->prev_x = game->player->x;
    game->player->prev_y = game->player->y;
	
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
	}
	else if (game->player->direction == RIGHT)
	{
		if (game->map->map[game->player->y / 32][(game->player->x + 4) / 32 + 1] != '1')
			game->player->x += 4;
		else
		 	game->player->x = (game->player->x + 4) / 32 * 32;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
	}
}

void	pac_moving(t_game *game)
{
	pac_moving_up_down(game);
	pac_moving_left_right(game);
}
