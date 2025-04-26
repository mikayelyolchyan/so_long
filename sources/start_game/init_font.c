/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:38:37 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:38:38 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

int	init_font(t_game *game, t_map *map)
{
	game->font = malloc(sizeof(t_font));
	if (!game->font)
	{
		free(game->map->power_up_dots_array);
		free(game->player);
		free(game->r_ghost);
		free(game->o_ghost);
		free(game->m_ghost);
		free(game->b_ghost);
		free_map(map);
		free(map);
		ft_printf("Error: t_font memory allocation failed\n");
		return (1);
	}
	font_initialization(game);
	return (0);
}
