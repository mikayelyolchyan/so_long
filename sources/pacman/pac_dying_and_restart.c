/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pac_dying_and_restart.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:42:59 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:43:00 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

void	pac_dying_and_restart(t_game *game)
{
	game->player->dying_frame_delay++;
	if (game->player->dying_frame_delay >= DYING_FRAME_LIMIT)
	{
		game->player->dying_frame_delay = 0;
		game->player->dying_frame = (game->player->dying_frame + 1) % 15;
		pac_dying(game, game->player);
	}
}
