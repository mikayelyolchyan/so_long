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

static int check_elements_portal(t_map *map, int i, int j, int *portals)
{
    if (j == 1)
    {
        portals[0]++;
        if ((i > 0 && map->map[i - 1][j] != '1') ||
            (i < map->height - 1 && map->map[i + 1][j] != '1') ||
            map->map[i][j - 1] != '1' || map->map[i][j + 1] == '1' ||
            map->map[i][j + 1] == 'E')
            return (ft_putstr_fd(\
				"Error: Left portal invalid surroundings\n", 2), 0);
    }
    else if (j == map->width - 2)
    {
        portals[1]++;
        if ((i > 0 && map->map[i - 1][j] != '1') ||
            (i < map->height - 1 && map->map[i + 1][j] != '1') ||
            map->map[i][j + 1] != '1' || map->map[i][j - 1] == '1' ||
            map->map[i][j - 1] == 'E')
            return (ft_putstr_fd(\
				"Error: Right portal invalid surroundings\n", 2), 0);
    }
    else
        return (ft_putstr_fd("Error: Portal in invalid position\n", 2), 0);
    return (1);
}

int	check_portals(t_map *map, \
	t_check *total, int i, int j, int *portals)
{
	if (map->map[i][j] == 'T')
	{
		total->portals++;
		if (!check_elements_portal(map, i, j, portals))
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
