#include "../../includes/headers/so_long.h"

void	direction_when_ghost_eated(t_ghost *ghost, t_dist *dist)
{
	
	dist->min_dist = INT_MAX;
	ghost->pending_direction = UP;	
	if (dist->dist_up < dist->min_dist)
	{
		dist->min_dist = dist->dist_up;
		ghost->pending_direction = UP;
	}
	if (dist->dist_left < dist->min_dist)
	{
		dist->min_dist = dist->dist_left;
		ghost->pending_direction = LEFT;
	}
	if (dist->dist_down < dist->min_dist)
	{
		dist->min_dist = dist->dist_down;
		ghost->pending_direction = DOWN;
	}
	if (dist->dist_right < dist->min_dist)
	{
		dist->min_dist = dist->dist_right;
		ghost->pending_direction = RIGHT;
	}
}
