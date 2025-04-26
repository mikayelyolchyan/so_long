/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dead_end_turn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:31:57 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:31:58 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

void	handle_dead_end_turn(t_game *game, t_ghost *ghost)
{
	char	**map;

	map = game->map->map;
	if (ghost->direction == RIGHT && \
		map[ghost->y / 32][(ghost->x + 32) / 32] == '1' && \
		map[(ghost->y + 32) / 32][(ghost->x) / 32] == '1' && \
		map[(ghost->y - 32) / 32][(ghost->x) / 32] == '1')
		ghost->direction = LEFT;
	else if (ghost->direction == LEFT && \
			map[ghost->y / 32][(ghost->x - 32) / 32] == '1' && \
			map[(ghost->y + 32) / 32][(ghost->x) / 32] == '1' && \
			map[(ghost->y - 32) / 32][(ghost->x) / 32] == '1')
		ghost->direction = RIGHT;
	else if (ghost->direction == UP && \
			map[ghost->y / 32][(ghost->x + 32) / 32] == '1' && \
			map[ghost->y / 32][(ghost->x - 32) / 32] == '1' && \
			map[(ghost->y - 32) / 32][(ghost->x) / 32] == '1')
		ghost->direction = DOWN;
	else if (ghost->direction == DOWN && \
			map[ghost->y / 32][(ghost->x + 32) / 32] == '1' && \
			map[ghost->y / 32][(ghost->x - 32) / 32] == '1' && \
			map[(ghost->y + 32) / 32][(ghost->x) / 32] == '1')
		ghost->direction = UP;
}
