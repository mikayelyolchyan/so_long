/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue_ghost_moving.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:16:03 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:16:04 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/so_long.h"

void	blue_ghost_moving(t_game *game)
{
	blue_ghost_direction(game);
	detect_collision_with_speed(game, game->b_ghost, game->map->map);
	if (game->b_ghost->is_eaten == 0)
	{
		ghost_move(game, game->b_ghost);
	}
	else if (game->b_ghost->is_eaten == 1)
	{
		ghost_is_eaten_move(game, game->b_ghost);
	}
}
