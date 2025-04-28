/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orange_ghost_moving.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:22:31 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/28 19:08:13 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/so_long.h"

void	orange_ghost_moving(t_game *game)
{
	orange_ghost_direction(game);
	detect_collision_with_speed(game, game->o_ghost, game->map->map);
	if (total_deadlock(game, game->o_ghost) == 1)
		return ;
	if (game->o_ghost->is_eaten == 0)
	{
		ghost_move(game, game->o_ghost);
	}
	else if (game->o_ghost->is_eaten == 1)
	{
		ghost_is_eaten_move(game, game->o_ghost);
	}
}
