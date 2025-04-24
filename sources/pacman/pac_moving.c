#include "../../includes/headers/so_long.h"

void	pac_moving(t_game *game)
{
	update_pac_direction(game);
	game->player->prev_x = game->player->x;
	game->player->prev_y = game->player->y;
	pac_moving_up_down(game);
	pac_moving_left_right(game);
}
