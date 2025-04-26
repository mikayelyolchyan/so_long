#include "../../includes/headers/so_long.h"

void free_map(t_map *map)
{
    int i;

    if (!map || !map->map)
        return;
    i = 0;
    while (map->map[i])
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
    map->map = NULL;
}
