#include "../../includes/headers/so_long.h"

void	detect_collision_with_speed(t_game *game, t_ghost *ghost, char **map)
{
	int	speed;

	speed = 4;
	if (ghost->is_eaten == 1)
		speed = 8;
	if ((ghost->x % 32 == 0 && ghost->y % 32 == 0) || \
	(ghost->direction == UP && \
	map[(ghost->y - speed) / 32][ghost->x / 32] == '1') || \
	(ghost->direction == DOWN && \
	map[(ghost->y + speed) / 32 + 1][ghost->x / 32] == '1') || \
	(ghost->direction == LEFT && \
	map[ghost->y / 32][(ghost->x - speed) / 32] == '1') || \
	(ghost->direction == RIGHT && \
	map[ghost->y / 32][(ghost->x + speed) / 32 + 1] == '1'))
	{
		set_ghost_direction(game, ghost);
		handle_dead_end_turn(game, ghost);
		ghost->prev_x = ghost->x;
		ghost->prev_y = ghost->y;
	}
}
