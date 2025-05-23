/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_ghost_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:25:34 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:25:35 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/so_long.h"

void	set_red_ghost_target(t_game *game, t_ghost *ghost)
{
	if (!ghost->is_eaten)
	{
		if (game->ghost_attack_mode == 1 && game->pac_attack_mode == 0)
		{
			ghost->targ_x = game->player->x;
			ghost->targ_y = game->player->y;
		}
		else if (game->ghost_attack_mode == 0 && game->pac_attack_mode == 0)
		{
			ghost->targ_x = game->map->width * 32;
			ghost->targ_y = 0;
		}
	}
}
