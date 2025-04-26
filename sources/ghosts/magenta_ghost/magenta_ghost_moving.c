/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magenta_ghost_moving.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:19:45 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:19:59 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/so_long.h"

void	magenta_ghost_moving(t_game *game)
{
	magenta_ghost_direction(game);
	detect_collision_with_speed(game, game->m_ghost, game->map->map);
	if (game->m_ghost->is_eaten == 0)
	{
		ghost_move(game, game->m_ghost);
	}
	else if (game->m_ghost->is_eaten == 1)
	{
		ghost_is_eaten_move(game, game->m_ghost);
	}
}
