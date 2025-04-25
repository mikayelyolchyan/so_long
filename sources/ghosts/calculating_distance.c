#include "../../includes/headers/so_long.h"

void	calculating_to_target(t_game *game, t_dist *dist, t_ghost *ghost)
{
	char 	**map;

	map = game->map->map;
	if (ghost->direction != DOWN && map[(ghost->y - 32) / 32][ghost->x / 32] != '1')
		dist->dist_up = distance_calculator(ghost->x, ghost->targ_x, ghost->y - 32, ghost->targ_y);
	if (ghost->direction != RIGHT && map[ghost->y / 32][(ghost->x - 32) / 32] != '1')
		dist->dist_left = distance_calculator(ghost->x - 32, ghost->targ_x, ghost->y, ghost->targ_y);
	if (ghost->direction != UP && map[(ghost->y + 32) / 32][ghost->x / 32] != '1')
		dist->dist_down = distance_calculator(ghost->x, ghost->targ_x, ghost->y + 32, ghost->targ_y);
	if (ghost->direction != LEFT && map[ghost->y / 32][(ghost->x + 32) / 32] != '1')
		dist->dist_right = distance_calculator(ghost->x + 32, ghost->targ_x, ghost->y, ghost->targ_y);
}

void	calculating_to_start(t_game *game, t_dist *dist, t_ghost *ghost)
{
	char 	**map;

	map = game->map->map;
	if (ghost->direction != DOWN && map[(ghost->y - 32) / 32][ghost->x / 32] != '1')
		dist->dist_up = distance_calculator(ghost->x, ghost->start_x, ghost->y - 32, ghost->start_y);
	if (ghost->direction != RIGHT && map[ghost->y / 32][(ghost->x - 32) / 32] != '1')
		dist->dist_left = distance_calculator(ghost->x - 32, ghost->start_x, ghost->y, ghost->start_y);
	if (ghost->direction != UP && map[(ghost->y + 32) / 32][ghost->x / 32] != '1')
		dist->dist_down = distance_calculator(ghost->x, ghost->start_x, ghost->y + 32, ghost->start_y);
	if (ghost->direction != LEFT && map[ghost->y / 32][(ghost->x + 32) / 32] != '1')
		dist->dist_right = distance_calculator(ghost->x + 32, ghost->start_x, ghost->y, ghost->start_y);
}
