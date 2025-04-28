/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_deadlock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:16:28 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/28 19:16:31 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

int	total_deadlock(t_game *game, t_ghost *ghost)
{
	char	**map;

	map = game->map->map;
	if (ghost->start_x % 32 == 0 && ghost->start_y % 32 == 0 && \
		map[(ghost->start_y - 32) / 32][ghost->start_x / 32] == '1' && \
		map[(ghost->start_y + 32) / 32][ghost->start_x / 32] == '1' && \
		map[ghost->start_y / 32][(ghost->start_x + 32) / 32] == '1' && \
		map[ghost->start_y / 32][(ghost->start_x - 32) / 32] == '1')
	{
		return (1);
	}
	return (0);
}
