#include "../../includes/headers/so_long.h"

static	void	target_to_pac(t_game *game, t_ghost *ghost)
{
	if (game->player->direction == RIGHT)
	{
		ghost->targ_x = game->player->x + 128;
		ghost->targ_y = game->player->y;
	}
	else if (game->player->direction == LEFT)
	{
		ghost->targ_x = game->player->x - 128;
		ghost->targ_y = game->player->y;
	}
	else if (game->player->direction == DOWN)
	{
		ghost->targ_x = game->player->x;
		ghost->targ_y = game->player->y + 128;
	}
	else if (game->player->direction == UP)
	{
		ghost->targ_x = game->player->x - 128;
		ghost->targ_y = game->player->y - 128;
	}
}

void	set_magenta_ghost_target(t_game *game, t_ghost *ghost)
{
	if (ghost->is_eaten == 0)
    {
        if (game->ghost_attack_mode == 1 && game->pac_attack_mode == 0)
        {
			target_to_pac(game, ghost);
        }
        else if (game->ghost_attack_mode == 0 && game->pac_attack_mode == 0)
        {
            ghost->targ_x = 0;
            ghost->targ_y = 0;
        }
    }
}
