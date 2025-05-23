/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   when_ghost_eated_pac.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:32:58 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:33:54 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

void	when_ghost_eated_pac(t_game *game, t_ghost *ghost)
{
	if (game->pac_attack_mode == 0 && \
		(game->player->x - ghost->x <= 16 && \
		game->player->x - ghost->x >= -16) && \
		(game->player->y - ghost->y <= 16 && \
		game->player->y - ghost->y >= -16) && \
		ghost->is_eaten == 0 && ghost->is_respawned == 0)
	{
		game->game_restart = 1;
		game->player->died_count++;
		draw_map(game);
	}
	if (game->pac_attack_mode == 1 && \
		(game->player->x - ghost->x <= 16 && \
		game->player->x - ghost->x >= -16) && \
		(game->player->y - ghost->y <= 16 && \
		game->player->y - ghost->y >= -16) && ghost->is_respawned == 1)
	{
		game->game_restart = 1;
		game->player->died_count++;
		draw_map(game);
	}
}
