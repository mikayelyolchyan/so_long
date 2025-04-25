#include "../../includes/headers/so_long.h"

void	red_ghost_respawned(t_game *game, t_ghost *ghost)
{
	if (ghost->x == ghost->start_x && 
		ghost->y == ghost->start_y)
	{
		ghost->is_eaten = 0;
		ghost->is_respawned = 1;
		game->r_ghost->targ_x = game->player->x;
		game->r_ghost->targ_y = game->player->y;
	}
}
