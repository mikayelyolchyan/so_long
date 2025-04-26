/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_ghost_direction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:24:27 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:26:34 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/so_long.h"

static void	movement_logic(t_game *game, t_dist dist)
{
	set_dist_struct_variables(&dist);
	if (game->r_ghost->is_eaten == 1)
	{
		game->r_ghost->is_respawned = 0;
		calculating_to_start(game, &dist, game->r_ghost);
		direction_when_ghost_eated(game->r_ghost, &dist);
		red_ghost_respawned(game, game->r_ghost);
	}
	else if (game->pac_attack_mode == 1)
	{
		if (game->last_pac_attack_mode == 0 && game->pac_attack_mode == 1)
			game->r_ghost->is_respawned = 0;
		calculating_to_target(game, &dist, game->r_ghost);
		direction_when_ghost_in_panic(game->r_ghost, &dist);
	}
	else
	{
		calculating_to_target(game, &dist, game->r_ghost);
		ghost_direction(game->r_ghost, &dist);
		if (game->r_ghost->is_respawned == 1 && \
			(game->r_ghost->x != game->r_ghost->start_x || \
			game->r_ghost->y != game->r_ghost->start_y))
			game->r_ghost->is_respawned = 0;
	}
}

void	red_ghost_direction(t_game *game)
{
	t_dist	dist;

	set_dist_struct_variables(&dist);
	when_pac_eated_ghost(game, game->r_ghost);
	when_ghost_eated_pac(game, game->r_ghost);
	check_ghost_attack_mode(game);
	set_red_ghost_target(game, game->r_ghost);
	movement_logic(game, dist);
	game->last_pac_attack_mode = game->pac_attack_mode;
}
