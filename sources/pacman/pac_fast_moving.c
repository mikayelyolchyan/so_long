#include "../../includes/headers/so_long.h"

static void	fast_move_up(t_game *game)
{
	if (game->map->map[(game->player->y - 8) / 32] \
		[game->player->x / 32] != '1')
		game->player->y -= 8;
	else
		game->player->y = (game->player->y + 8) / 32 * 32;
}

static void	fast_move_down(t_game *game)
{
	if (game->map->map[(game->player->y + 8) / 32 + 1] \
		[game->player->x / 32] != '1')
		game->player->y += 8;
	else
		game->player->y = (game->player->y + 8) / 32 * 32;
}

void	pac_fast_moving_up_down(t_game *game)
{
	if (game->player->direction == UP)
		fast_move_up(game);
	else if (game->player->direction == DOWN)
		fast_move_down(game);
	handle_collectibles(game);
}

void	pac_fast_moving(t_game *game)
{
	update_pac_direction(game);
	game->player->prev_x = game->player->x;
	game->player->prev_y = game->player->y;
	pac_fast_moving_up_down(game);
	pac_fast_moving_left_right(game);
}
