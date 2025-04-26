#include "../../includes/headers/so_long.h"

void	set_dist_struct_variables(t_dist *dist)
{
	dist->dist_up = INT_MAX;
	dist->dist_down = INT_MAX;
	dist->dist_left = INT_MAX;
	dist->dist_right = INT_MAX;
	dist->min_dist = INT_MAX;
	dist->max_dist = INT_MAX;
}
