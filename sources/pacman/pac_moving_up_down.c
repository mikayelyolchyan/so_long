#include "../../includes/headers/so_long.h"

static void	move_up(t_game *game)
{
	if (game->map->map[(game->player->y - 4) / 32][game->player->x / 32] != '1')
		game->player->y -= 4;
}

static void	move_down(t_game *game)
{
	if (game->map->map[(game->player->y + 4) / 32 + 1] \
		[game->player->x / 32] != '1')
		game->player->y += 4;
	else
		game->player->y = (game->player->y + 4) / 32 * 32;
}

void	pac_moving_up_down(t_game *game)
{
	if (game->player->direction == UP)
		move_up(game);
	else if (game->player->direction == DOWN)
		move_down(game);
	handle_collectibles(game);
}
