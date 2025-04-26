/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ghost_direction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:32:30 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:32:43 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

void	set_ghost_direction(t_game *game, t_ghost *ghost)
{
	char	**map;

	map = game->map->map;
	if (ghost->is_eaten == 0 && \
		(can_move_vertical(ghost, map, ghost->pending_direction) || \
			can_move_horizontal(ghost, map, ghost->pending_direction)))
	{
		ghost->direction = ghost->pending_direction;
	}
	else if (ghost->is_eaten == 1 && \
		(can_move_fast_vertical(ghost, map, ghost->pending_direction) || \
			can_move_fast_horizontal(ghost, map, ghost->pending_direction)))
	{
		ghost->direction = ghost->pending_direction;
	}
}
