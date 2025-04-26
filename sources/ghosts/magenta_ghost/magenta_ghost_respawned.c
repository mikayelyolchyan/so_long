/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magenta_ghost_respawned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:20:22 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:20:23 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/so_long.h"

void	magenta_ghost_respawned(t_game *game, t_ghost *ghost)
{
	if (ghost->x == ghost->start_x && ghost->y == ghost->start_y)
	{
		ghost->is_eaten = 0;
		ghost->is_respawned = 1;
		set_magenta_ghost_target(game, ghost);
	}
}
