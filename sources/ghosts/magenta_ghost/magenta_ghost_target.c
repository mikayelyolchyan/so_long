/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magenta_ghost_target.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:21:22 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:21:23 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/so_long.h"

static void	target_to_pac(t_game *game, t_ghost *ghost)
{
	if (game->player->direction == RIGHT)
	{
		ghost->targ_x = game->player->x + 128;
		ghost->targ_y = game->player->y;
	}
	else if (game->player->direction == LEFT)
	{
		ghost->targ_x = game->player->x - 128;
		ghost->targ_y = game->player->y;
	}
	else if (game->player->direction == DOWN)
	{
		ghost->targ_x = game->player->x;
		ghost->targ_y = game->player->y + 128;
	}
	else if (game->player->direction == UP)
	{
		ghost->targ_x = game->player->x - 128;
		ghost->targ_y = game->player->y - 128;
	}
}

void	set_magenta_ghost_target(t_game *game, t_ghost *ghost)
{
	if (ghost->is_eaten == 0)
	{
		if (game->ghost_attack_mode == 1 && game->pac_attack_mode == 0)
		{
			target_to_pac(game, ghost);
		}
		else if (game->ghost_attack_mode == 0 && game->pac_attack_mode == 0)
		{
			ghost->targ_x = 0;
			ghost->targ_y = 0;
		}
	}
}
