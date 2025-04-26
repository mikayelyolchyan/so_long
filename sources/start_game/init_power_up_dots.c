/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_power_up_dots.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:38:54 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:38:55 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

int	init_power_up_dots(t_game *game, t_map *map)
{
	game->map->dots_count = 0;
	game->map->power_up_dots_count = 0;
	count_sprites(game);
	game->map->power_up_dots_array = malloc(sizeof(t_power_up_dot)
			* game->map->power_up_dots_count);
	if (!game->map->power_up_dots_array)
	{
		free(game->player);
		free(game->r_ghost);
		free(game->o_ghost);
		free(game->m_ghost);
		free(game->b_ghost);
		free_map(map);
		free(map);
		ft_printf("Error: power_up_dots_array memory allocation failed\n");
		return (1);
	}
	return (0);
}
