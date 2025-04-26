/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ghost_position_textures.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:38:41 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:38:42 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

int	init_ghost_positions_textures(t_game *game, t_map *map)
{
	if (map->ghost_count == 4)
	{
		red_ghost_initialization(game, map);
		orange_ghost_initialization(game, map);
		magenta_ghost_initialization(game, map);
		blue_ghost_initialization(game, map);
	}
	return (0);
}
