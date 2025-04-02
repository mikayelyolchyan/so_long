#include "../includes/headers/so_long.h"

int	pac_moving(t_game *game)
{

	if (game->player->direction == UP && game->map->map[(game->player->y - 32) / 32][(game->player->x) / 32] != '1')
	{
		game->player->y -= 32;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
	}
	else if (game->player->direction == DOWN && game->map->map[(game->player->y + 32) / 32][(game->player->x) / 32] != '1')
	{
		game->player->y += 32;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
	}
	else if (game->player->direction == LEFT && game->map->map[(game->player->y) / 32][(game->player->x - 32) / 32] != '1')
	{
		game->player->x -= 32;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
	}
	else if (game->player->direction == RIGHT && game->map->map[(game->player->y) / 32][(game->player->x + 32) / 32] != '1')
	{
		game->player->x += 32;
		if (game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
			game->map->map[game->player->y / 32][game->player->x / 32] = '0';
	}

    return (0);
}
