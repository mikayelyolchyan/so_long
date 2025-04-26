/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:34:47 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 22:35:32 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

static int	check_elements_init(t_map *map, \
	t_point *start, t_check *total, int *ghosts)
{
    int i;

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
	int		i;
	int		j;
	int		portals[2];
	char	c;

	i = 0;
	portals[0] = 0;
	portals[1] = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			c = map->map[i][j];
			if (!check_player(start, c, i, j) \
				|| !check_collectibles(total, c) \
				|| !check_portals(map, total, i, j, portals) \
				|| !check_ghosts(total, c, ghosts) \
				|| !check_invalid_char(c))
				return (0);
			j++;
		}
		i++;
	}
	return (check_elements_validate(total, start, ghosts, portals));
}

int check_elements(t_map *map, t_point *start, t_check *total)
{
    int ghosts[4];

    if (!check_elements_init(map, start, total, ghosts))
        return (0);
    return (check_elements_loop(map, start, total, ghosts));
}
