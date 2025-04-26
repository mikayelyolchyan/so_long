/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue_ghost_target.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:18:02 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:18:03 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/so_long.h"

static void	set_pivot_at_direction(t_game *game, int *pivot_x, int *pivot_y)
{
	if (game->player->direction == RIGHT)
	{
		*pivot_x = game->player->x + 64;
		*pivot_y = game->player->y;
	}
	else if (game->player->direction == LEFT)
	{
		*pivot_x = game->player->x - 64;
		*pivot_y = game->player->y;
	}
	else if (game->player->direction == DOWN)
	{
		*pivot_x = game->player->x;
		*pivot_y = game->player->y + 64;
	}
	else if (game->player->direction == UP)
	{
		*pivot_x = game->player->x - 64;
		*pivot_y = game->player->y - 64;
	}
}

void	set_blue_ghost_target(t_game *game)
{
	int	pivot_x;
	int	pivot_y;
	int	vector_x;
	int	vector_y;

	pivot_x = 0;
	pivot_y = 0;
	vector_x = 0;
	vector_y = 0;
	if (game->b_ghost->is_eaten == 0)
	{
		if (game->ghost_attack_mode == 1 && game->pac_attack_mode == 0)
		{
			set_pivot_at_direction(game, &pivot_x, &pivot_y);
			vector_x = pivot_x - game->r_ghost->x;
			vector_y = pivot_y - game->r_ghost->y;
			game->b_ghost->targ_x = game->r_ghost->x + 2 * vector_x;
			game->b_ghost->targ_y = game->r_ghost->y + 2 * vector_y;
		}
		else if (game->ghost_attack_mode == 0 && game->pac_attack_mode == 0)
		{
			game->b_ghost->targ_x = game->map->width * 32;
			game->b_ghost->targ_y = game->map->height * 32;
		}
	}
}
