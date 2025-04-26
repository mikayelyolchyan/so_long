/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_can_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:31:01 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:31:02 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

int	can_move_vertical(t_ghost *c_ghost, char **map, int direction)
{
	if (direction == UP && map[(c_ghost->y - 4) / 32] \
		[c_ghost->x / 32] != '1' && c_ghost->x % 32 == 0)
		return (1);
	if (direction == DOWN && map[(c_ghost->y + 4) / 32 + 1] \
		[c_ghost->x / 32] != '1' && c_ghost->x % 32 == 0)
		return (1);
	return (0);
}

int	can_move_horizontal(t_ghost *c_ghost, char **map, int direction)
{
	if (direction == LEFT && map[c_ghost->y / 32] \
		[(c_ghost->x - 4) / 32] != '1' && c_ghost->y % 32 == 0)
		return (1);
	if (direction == RIGHT && map[c_ghost->y / 32] \
		[(c_ghost->x + 4) / 32 + 1] != '1' && c_ghost->y % 32 == 0)
		return (1);
	return (0);
}

int	can_move_fast_vertical(t_ghost *c_ghost, char **map, int direction)
{
	if (direction == UP && map[(c_ghost->y - 16) / 32] \
		[c_ghost->x / 32] != '1' && c_ghost->x % 32 == 0)
		return (1);
	if (direction == DOWN && map[(c_ghost->y + 16) / 32 + 1] \
		[c_ghost->x / 32] != '1' && c_ghost->x % 32 == 0)
		return (1);
	return (0);
}

int	can_move_fast_horizontal(t_ghost *c_ghost, char **map, int direction)
{
	if (direction == LEFT && map[c_ghost->y / 32] \
		[(c_ghost->x - 16) / 32] != '1' && c_ghost->y % 32 == 0)
		return (1);
	if (direction == RIGHT && map[c_ghost->y / 32] \
		[(c_ghost->x + 16) / 32 + 1] != '1' && c_ghost->y % 32 == 0)
		return (1);
	return (0);
}
