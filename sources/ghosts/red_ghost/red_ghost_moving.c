/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_ghost_moving.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:25:41 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/28 19:00:07 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/so_long.h"

void	red_ghost_moving(t_game *game)
{
	red_ghost_direction(game);
	detect_collision_with_speed(game, game->r_ghost, game->map->map);
	if (total_deadlock(game, game->r_ghost) == 1)
		return ;
	if (game->r_ghost->is_eaten == 0)
	{
		ghost_move(game, game->r_ghost);
	}
	else if (game->r_ghost->is_eaten == 1)
	{
		ghost_is_eaten_move(game, game->r_ghost);
	}
}
