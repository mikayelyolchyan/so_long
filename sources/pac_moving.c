#include "../includes/headers/so_long.h"

int	pac_moving(t_game *game)
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
	else if (game->player->direction == LEFT)
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

    return (0);
}
