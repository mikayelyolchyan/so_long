#include "../../includes/headers/so_long.h"

static int validate_map_init(t_check *total, t_check *reached)
{
    total->coins = 0;
    total->power_ups = 0;
    total->exits = 0;
    total->portals = 0;
    total->ghost_count = 0;
    reached->coins = 0;
    reached->power_ups = 0;
    reached->exits = 0;
    reached->portals = 0;
    reached->ghost_count = 0;
    return (1);
}

static int validate_map_check(char *filename, \
	t_map *map, t_point *start, t_check *total)
{
    if (!filename || !map)
    {
        ft_putstr_fd("Error: Invalid arguments\n", 2);
        return (0);
    }
    if (!check_extension(filename) || !read_map(filename, map))
        return (0);
    if (!check_structure(map) || !check_elements(map, start, total))
    {
        free_map(map);
        return (0);
    }
    return (1);
}

int validate_map(char *filename, t_map *map)
{
    t_point start;
    t_check total;
    t_check reached;
    int **visited;

    if (!validate_map_init(&total, &reached))
        return (0);
    if (!validate_map_check(filename, map, &start, &total))
        return (0);
    visited = create_visited(map->height, map->width, 0);
    if (!visited)
    {
        free_map(map);
        ft_putstr_fd("Error: Memory allocation failed\n", 2);
        return (0);
    }
    flood_fill(map, start, &reached, visited);
    free_visited(visited, map->height);
    if (reached.coins != total.coins || reached.power_ups != total.power_ups ||
        reached.exits != total.exits || reached.portals != total.portals)
        return (free_map(map), \
			ft_putstr_fd("Error: Not all elements reachable\n", 2), 0);
    map->ghost_count = total.ghost_count;
    return (1);
}