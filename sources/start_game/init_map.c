#include "../../includes/headers/so_long.h"

int	init_map(char *argv, t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (!*map)
	{
		ft_printf("Error: t_map memory allocation failed\n");
		return (1);
	}
	(*map)->ghost_count = 0;
	(*map)->map = NULL;
	if (!validate_map(argv, *map))
	{
		free(*map);
		*map = NULL;
		ft_printf("Error: Invalid map\n");
		return (1);
	}
	return (0);
}
