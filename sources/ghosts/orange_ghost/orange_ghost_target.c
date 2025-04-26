/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orange_ghost_target.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:23:43 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:23:44 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/so_long.h"

void	set_orange_ghost_target(t_game *game, t_ghost *ghost)
{
	int	distance_to_pacman;
	int	eight_tiles_squared;

	distance_to_pacman = 0;
	eight_tiles_squared = 256 * 256;
	if (ghost->is_eaten == 0 && game->pac_attack_mode == 0)
	{
		distance_to_pacman = distance_calculator(ghost->x, game->player->x, \
			ghost->y, game->player->y);
		if (distance_to_pacman > eight_tiles_squared)
		{
			ghost->targ_x = game->player->x;
			ghost->targ_y = game->player->y;
		}
		else
		{
			ghost->targ_x = 0;
			ghost->targ_y = game->map->height * 32;
		}
	}
}
