/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:39:38 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:40:09 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/so_long.h"

void	count_sprites(t_game *game)
{
	int		x;
	int		y;
	t_map	*map;

	map = game->map;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'U')
			{
				map->power_up_dots_count++;
			}
			if (map->map[y][x] == 'C')
			{
				map->dots_count++;
			}
			x++;
		}
		y++;
	}
}
