#include "../../includes/headers/so_long.h"

void	magenta_ghost_respawned(t_game *game, t_ghost *ghost)
{
	if (ghost->x == ghost->start_x && ghost->y == ghost->start_y)
	{
		ghost->is_eaten = 0;
		ghost->is_respawned = 1;
		set_magenta_ghost_target(game, ghost);
	}
}
