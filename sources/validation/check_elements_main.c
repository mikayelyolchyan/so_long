/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:34:47 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 23:32:59 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

static int	check_elements_init(t_map *map, \
	t_point *start, t_check *total, int *ghosts)
{
	int	i;

	if (!map || !map->map || !start || !total)
	{
		ft_putstr_fd("Error: Invalid arguments\n", 2);
		return (0);
	}
	i = 0;
	while (i < 4)
		ghosts[i++] = 0;
	total->coins = 0;
	total->power_ups = 0;
	total->exits = 0;
	total->portals = 0;
	total->ghost_count = 0;
	start->x = -1;
	return (1);
}

static int	check_elements_loop(t_map *map, \
	t_point *start, t_check *total, int *ghosts)
{
	t_check_elements_variables	vars;
	char						c;

	vars.i = 0;
	vars.portals[0] = 0;
	vars.portals[1] = 0;
	while (vars.i < map->height)
	{
		vars.j = 0;
		while (vars.j < map->width)
		{
			c = map->map[vars.i][vars.j];
			if (!check_player(start, c, vars.i, vars.j) \
				|| !check_collectibles(total, c) \
				|| !check_portals(map, total, &vars) \
				|| !check_ghosts(total, c, ghosts) \
				|| !check_invalid_char(c))
				return (0);
			vars.j++;
		}
		vars.i++;
	}
	return (check_elements_validate(total, start, ghosts, vars.portals));
}

int	check_elements(t_map *map, t_point *start, t_check *total)
{
	int	ghosts[4];

	if (!check_elements_init(map, start, total, ghosts))
		return (0);
	return (check_elements_loop(map, start, total, ghosts));
}
