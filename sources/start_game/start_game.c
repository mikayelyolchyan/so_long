/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:38:56 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:38:57 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

int	start_game(t_game *game, char *argv)
{
	t_map	*map;

	game->map = NULL;
	if (init_map(argv, &map))
		return (1);
	game->map = map;
	if (init_mlx(game, map))
		return (1);
	if (init_map_images(game, map))
		return (1);
	if (init_player(game, map))
		return (1);
	if (init_ghosts(game, map))
		return (1);
	if (init_power_up_dots(game, map))
		return (1);
	find_positions(game);
	pacman_initializations(game, map);
	if (init_ghost_positions_textures(game, map))
		return (1);
	if (init_font(game, map))
		return (1);
	init_game_state(game, map);
	return (0);
}
