#include "../../includes/headers/so_long.h"

static void	fast_move_left(t_game *game)
{
	if (game->map->map[game->player->y / 32][(game->player->x - 8) / 32] != '1')
		game->player->x -= 8;
	if (game->map->map[game->player->y / 32][game->player->x / 32] == 'T')
		handle_portal(game, 1);
}

static void	fast_move_right(t_game *game)
{
	if (game->map->map[game->player->y / 32] \
	[(game->player->x + 8) / 32 + 1] != '1')
		game->player->x += 8;
	else
		game->player->x = (game->player->x + 8) / 32 * 32;
	if (game->map->map[game->player->y / 32][game->player->x / 32] == 'T')
		handle_portal(game, 0);
}

void	pac_fast_moving_left_right(t_game *game)
{
	if (game->player->direction == LEFT)
		fast_move_left(game);
	else if (game->player->direction == RIGHT)
		fast_move_right(game);
	handle_collectibles(game);
}
