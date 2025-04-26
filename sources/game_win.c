/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:45:02 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:45:03 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/so_long.h"

void	game_win(t_game *game)
{
	if (game->eated_dots == game->map->dots_count && \
		game->player->y % 32 == 0 && \
		game->player->x % 32 == 0 && \
		game->map->map[game->player->y / 32][game->player->x / 32] == 'E')
	{
		game->game_win = 1;
		game->map_flashing_delay++;
		if (game->map_flashing_delay >= 25000)
		{
			map_flashing(game->map, game);
			game->map_flashing_delay = 0;
			game->map_flashing_count++;
			if (game->map_flashing_count == 16)
				ft_exit(game);
		}
	}
}
