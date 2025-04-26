/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orange_ghost_direction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:22:23 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:22:24 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/so_long.h"

static void	movement_logic(t_game *game, t_dist dist)
{
	set_dist_struct_variables(&dist);
	if (game->o_ghost->is_eaten)
	{
		game->o_ghost->is_respawned = 0;
		calculating_to_start(game, &dist, game->o_ghost);
		direction_when_ghost_eated(game->o_ghost, &dist);
		orange_ghost_respawned(game, game->o_ghost);
	}
	else if (game->pac_attack_mode == 1)
	{
		if (game->last_pac_attack_mode == 0 && game->pac_attack_mode == 1)
			game->o_ghost->is_respawned = 0;
		calculating_to_target(game, &dist, game->o_ghost);
		direction_when_ghost_in_panic(game->o_ghost, &dist);
	}
	else
	{
		calculating_to_target(game, &dist, game->o_ghost);
		ghost_direction(game->o_ghost, &dist);
		if (game->o_ghost->is_respawned == 1 && \
			(game->o_ghost->x != game->o_ghost->start_x || \
			game->o_ghost->y != game->o_ghost->start_y))
			game->o_ghost->is_respawned = 0;
	}
}

void	orange_ghost_direction(t_game *game)
{
	t_dist	dist;

	set_dist_struct_variables(&dist);
	when_pac_eated_ghost(game, game->o_ghost);
	when_ghost_eated_pac(game, game->o_ghost);
	set_orange_ghost_target(game, game->o_ghost);
	movement_logic(game, dist);
	game->last_pac_attack_mode = game->pac_attack_mode;
}
