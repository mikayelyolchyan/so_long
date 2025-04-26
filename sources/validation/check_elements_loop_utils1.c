/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_loop_utils1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:03:35 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 23:08:25 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

int	check_player(t_point *start, char c, int i, int j)
{
	if (c == 'P')
	{
		if (start->x != -1)
		{
			ft_putstr_fd("Error: Multiple players\n", 2);
			return (0);
		}
		start->x = j;
		start->y = i;
	}
	return (1);
}

int	check_collectibles(t_check *total, char c)
{
	if (c == 'C')
		total->coins++;
	else if (c == 'U')
		total->power_ups++;
	else if (c == 'E')
		total->exits++;
	return (1);
}

static int	check_elements_portal(t_map *map, t_check_elements_variables *vars)
{
	if (vars->j == 1)
	{
		vars->portals[0]++;
		if ((vars->i > 0 && map->map[vars->i - 1][vars->j] != '1') || \
			(vars->i < map->height - 1 && \
			map->map[vars->i + 1][vars->j] != '1') || \
			map->map[vars->i][vars->j - 1] != '1' || \
			map->map[vars->i][vars->j + 1] == '1' || \
			map->map[vars->i][vars->j + 1] == 'E')
			return (ft_putstr_fd("Error: Invalid Left portal\n", 2), 0);
	}
	else if (vars->j == map->width - 2)
	{
		vars->portals[1]++;
		if ((vars->i > 0 && map->map[vars->i - 1][vars->j] != '1') || \
		(vars->i < map->height - 1 && \
		map->map[vars->i + 1][vars->j] != '1') || \
		map->map[vars->i][vars->j + 1] != '1' || \
		map->map[vars->i][vars->j - 1] == '1' || \
		map->map[vars->i][vars->j - 1] == 'E')
			return (ft_putstr_fd("Error: Invalid right portal\n", 2), 0);
	}
	else
		return (ft_putstr_fd("Error: Portal in invalid position\n", 2), 0);
	return (1);
}

int	check_portals(t_map *map, t_check *total, t_check_elements_variables *vars)
{
	if (map->map[vars->i][vars->j] == 'T')
	{
		total->portals++;
		if (!check_elements_portal(map, vars))
			return (0);
	}
	return (1);
}

int	check_ghosts(t_check *total, char c, int *ghosts)
{
	if (c == 'R')
	{
		ghosts[0]++;
		total->ghost_count++;
	}
	else if (c == 'B')
	{
		ghosts[1]++;
		total->ghost_count++;
	}
	else if (c == 'O')
	{
		ghosts[2]++;
		total->ghost_count++;
	}
	else if (c == 'M')
	{
		ghosts[3]++;
		total->ghost_count++;
	}
	return (1);
}
