#include "../../includes/headers/so_long.h"

void	pac_move_mode(t_game *game)
{
	if (game->pac_attack_mode == 1)
	{
		pac_fast_moving(game);
		game->pac_attack_mode_delay++;
		if (game->pac_attack_mode_delay >= GHOST_PANIC_FLASHING_LIMIT)
		{
			game->pac_attack_mode = 0;
			game->pac_attack_mode_delay = 0;
		}
	}
	else
		pac_moving(game);
}

void	pac_moving(t_game *game)
{
	update_pac_direction(game);
	game->player->prev_x = game->player->x;
	game->player->prev_y = game->player->y;
	pac_moving_up_down(game);
	pac_moving_left_right(game);
}
