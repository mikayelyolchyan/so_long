/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_loop_utils2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:29:40 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 23:31:47 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

int	check_invalid_char(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'U'
		&& c != 'E' && c != 'T' && c != 'R' && c != 'B' && c != 'O' && c != 'M')
		return (ft_putstr_fd("Error: Invalid character\n", 2), 0);
	return (1);
}

int	check_structure(t_map *map)
{
	int	i;

	if (!map || !map->map)
		return (ft_putstr_fd("Error: Invalid map structure\n", 2), 0);
	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (ft_putstr_fd("Error: Map not surrounded by walls\n", 2), 0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (ft_putstr_fd("Error: Map not surrounded by walls\n", 2), 0);
		i++;
	}
	return (1);
}

static int	check_elements_validate_util(int *ghosts)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (ghosts[i] != 1)
			return (ft_putstr_fd(\
				"Error: Exactly one of each ghost required\n", 2), 0);
	}
	return (1);
}

int	check_elements_validate(t_check *total, \
	t_point *start, int *ghosts, int *portals)
{
	if (start->x == -1)
		return (ft_putstr_fd("Error: No player\n", 2), 0);
	if (total->coins < 1)
		return (ft_putstr_fd("Error: At least one coin required\n", 2), 0);
	if (total->power_ups != 0 && total->power_ups != 4)
		return (ft_putstr_fd("Error: Powerups must be 0 or exactly 4\n", 2), 0);
	if (total->exits != 1)
		return (ft_putstr_fd("Error: Exactly one exit required\n", 2), 0);
	if (total->portals != 0 && (total->portals != 2 || \
		portals[0] != 1 || portals[1] != 1))
		return (ft_putstr_fd("Error: Portals must be 0 or exactly \
			two at x=1 and x=width-2\n", 2), 0);
	if (total->ghost_count != 0 && total->ghost_count != 4)
		return (ft_putstr_fd("Error: Ghosts must be 0 or exactly 4\n", 2), 0);
	if (total->ghost_count == 4)
	{
		if (check_elements_validate_util(ghosts) == 0)
			return (0);
	}
	return (1);
}
