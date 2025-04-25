#include "../../includes/headers/so_long.h"

void	red_ghost_moving(t_game *game)
{
	red_ghost_direction(game);
	detect_collision_with_speed(game, game->r_ghost, game->map->map);
	if (game->r_ghost->is_eaten == 0)
	{
		ghost_move(game, game->r_ghost);
	}
	else if (game->r_ghost->is_eaten == 1)
	{
		ghost_is_eaten_move(game, game->r_ghost);
	}
}
