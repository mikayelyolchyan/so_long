/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pac_fast_moving_left_right.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:37:46 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:37:47 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

static void	fast_move_left(t_game *game)
{
	if (game->map->map[game->player->y / 32][(game->player->x - 8) / 32] != '1')
		game->player->x -= 8;
	if (game->map->map[game->player->y / 32][game->player->x / 32] == 'T')
	{
		handle_collectibles(game);
		handle_pac_portal(game, 1);
	}
}

static void	fast_move_right(t_game *game)
{
	if (game->map->map[game->player->y / 32] \
	[(game->player->x + 8) / 32 + 1] != '1')
		game->player->x += 8;
	else
		game->player->x = (game->player->x + 8) / 32 * 32;
	if (game->map->map[game->player->y / 32] \
		[(game->player->x + 32) / 32] == 'T')
	{
		handle_collectibles(game);
		handle_pac_portal(game, 0);
	}
}

void	pac_fast_moving_left_right(t_game *game)
{
	if (game->player->direction == LEFT)
		fast_move_left(game);
	else if (game->player->direction == RIGHT)
		fast_move_right(game);
	handle_collectibles(game);
}
