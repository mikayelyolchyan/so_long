/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pac_moving_left_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:37:53 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:37:54 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

static void	move_left(t_game *game)
{
	if (game->map->map[game->player->y / 32][(game->player->x - 4) / 32] != '1')
		game->player->x -= 4;
	if (game->player->x % 32 == 0 && \
		game->map->map[game->player->y / 32] \
		[(game->player->x - 32) / 32] == 'T')
	{
		handle_collectibles(game);
		handle_pac_portal(game, 1);
	}
}

static void	move_right(t_game *game)
{
	if (game->map->map[game->player->y / 32] \
		[(game->player->x + 4) / 32 + 1] != '1')
		game->player->x += 4;
	else
		game->player->x = (game->player->x + 4) / 32 * 32;
	if (game->player->x % 32 == 0 && \
		game->map->map[game->player->y / 32] \
		[(game->player->x + 32) / 32] == 'T')
	{
		handle_collectibles(game);
		handle_pac_portal(game, 0);
	}
}

void	pac_moving_left_right(t_game *game)
{
	if (game->player->direction == LEFT)
		move_left(game);
	else if (game->player->direction == RIGHT)
		move_right(game);
	handle_collectibles(game);
}
