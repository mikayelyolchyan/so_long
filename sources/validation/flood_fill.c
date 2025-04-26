/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:33:19 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 23:34:00 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

int	flood_fill_util(t_map *map, t_point pos, t_check *reached, int **visited)
{
	if (!map || !map->map || !reached || !visited)
		return (1);
	if (pos.y < 0 || pos.y >= map->height || pos.x < 0 || pos.x >= map->width)
		return (1);
	if (visited[pos.y][pos.x] || map->map[pos.y][pos.x] == '1' ||
		map->map[pos.y][pos.x] == 'R' || map->map[pos.y][pos.x] == 'B' ||
		map->map[pos.y][pos.x] == 'O' || map->map[pos.y][pos.x] == 'M')
		return (1);
	return (0);
}

void	flood_fill(t_map *map, t_point pos, t_check *reached, int **visited)
{
	t_point	next;

	if (flood_fill_util(map, pos, reached, visited) == 1)
		return ;
	visited[pos.y][pos.x] = 1;
	if (map->map[pos.y][pos.x] == 'C')
		reached->coins++;
	else if (map->map[pos.y][pos.x] == 'U')
		reached->power_ups++;
	else if (map->map[pos.y][pos.x] == 'E')
		reached->exits++;
	else if (map->map[pos.y][pos.x] == 'T')
		reached->portals++;
	next.y = pos.y - 1;
	next.x = pos.x;
	flood_fill(map, next, reached, visited);
	next.y = pos.y + 1;
	flood_fill(map, next, reached, visited);
	next.x = pos.x - 1;
	next.y = pos.y;
	flood_fill(map, next, reached, visited);
	next.x = pos.x + 1;
	flood_fill(map, next, reached, visited);
}
