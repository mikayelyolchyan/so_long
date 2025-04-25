#include "../../includes/headers/so_long.h"

static void	pac_eat_ghost_utils(t_game *game, t_ghost *ghost)
{
	ghost->is_eaten = 1;
	game->game_start_delay = GHOST_EATEN_FREEZE;
	game->game_start = 0;
	ghost->targ_x = ghost->start_x;
	ghost->targ_y = ghost->start_y;
	ghost->remainder_x = ghost->x % 32;
	ghost->remainder_y = ghost->y % 32;
}

void	when_pac_eated_ghost(t_game *game, t_ghost *ghost)
{
	if (game->pac_attack_mode == 1 &&
		(game->player->x - ghost->x <= 16 && \
		game->player->x - ghost->x >= -16) && \
		(game->player->y - ghost->y <= 16 && \
		game->player->y - ghost->y >= -16) &&
    	ghost->is_eaten == 0 && ghost->is_respawned == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->map->black_wall_img, ghost->x, ghost->y);
		pac_eat_ghost_utils(game, ghost);
        if (ghost->remainder_x != 0)
        {
            if (ghost->remainder_x < 16)
                ghost->x -= ghost->remainder_x;
            else
                ghost->x += (32 - ghost->remainder_x);
        }
        if (ghost->remainder_y != 0)
        {
            if (ghost->remainder_y < 16)
                ghost->y -= ghost->remainder_y;
            else
                ghost->y += (32 - ghost->remainder_y);
        }
	}
}
