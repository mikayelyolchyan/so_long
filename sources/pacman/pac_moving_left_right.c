#include "../../includes/headers/so_long.h"

static void	move_left(t_game *game)
{
	if (game->map->map[game->player->y / 32][(game->player->x - 4) / 32] != '1')
		game->player->x -= 4;
	if (game->map->map[game->player->y / 32][game->player->x / 32] == 'T')
		handle_portal(game, 1);
}

static void	move_right(t_game *game)
{
	if (game->map->map[game->player->y / 32] \
		[(game->player->x + 4) / 32 + 1] != '1')
		game->player->x += 4;
	else
		game->player->x = (game->player->x + 4) / 32 * 32;
	if (game->map->map[game->player->y / 32][game->player->x / 32] == 'T')
		handle_portal(game, 0);
}

void	pac_moving_left_right(t_game *game)
{
	if (game->player->direction == LEFT)
		move_left(game);
	else if (game->player->direction == RIGHT)
		move_right(game);
	handle_collectibles(game);
}
