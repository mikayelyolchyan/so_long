#include "../includes/headers/so_long.h"

void	free_map(t_map *map)
{
	int	index;

	index = 0;
	while (map->map[index])
	{
		free(map->map[index]);
		index++;
	}
	free(map->map);
	free(map);
}
