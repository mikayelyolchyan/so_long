#include "../../includes/headers/so_long.h"

void	ghost_move(t_game *game, t_ghost *ghost)
{
	if (ghost->direction == UP)
		ghost->y -= 4;
	else if (ghost->direction == DOWN)
		ghost->y += 4;
	else if (ghost->direction == LEFT)
	{
		ghost->x -= 4;
		if (ghost->x % 32 == 0 && \
			game->map->map[ghost->y / 32][(ghost->x - 32) / 32] == 'T')
			handle_ghost_portal(game, ghost, 1);
	}
	else if (ghost->direction == RIGHT)
	{
		ghost->x += 4;
		if (ghost->x % 32 == 0 && \
			game->map->map[ghost->y / 32][(ghost->x + 32) / 32] == 'T')
			handle_ghost_portal(game, game->r_ghost, 0);
	}
}

void	ghost_is_eaten_move(t_game *game, t_ghost *ghost)
{
	if (ghost->direction == UP)
		ghost->y -= 16;
	else if (ghost->direction == DOWN)
		ghost->y += 16;
	else if (ghost->direction == LEFT)
	{
		ghost->x -= 16;
		if (game->map->map[ghost->y / 32][(ghost->x - 32) / 32] == 'T')
			handle_ghost_portal(game, ghost, 1);
	}
	else if (ghost->direction == RIGHT)
	{   
		ghost->x += 16;
		if (game->map->map[ghost->y / 32][(ghost->x + 32) / 32] == 'T')
			handle_ghost_portal(game, ghost, 0);
	}
}
