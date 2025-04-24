#include "../../includes/headers/so_long.h"

int	init_map_images(t_game *game, t_map *map)
{
	map_initialization(game, map);
	if (!map->wall_img || !map->black_wall_img || !map->food_img
		|| !map->portal_img || !map->logo_img || !map->power_up_img)
	{
		free_map(map);
		free(map);
		ft_printf("Error: Failed to load Map xpm`s\n");
		return (1);
	}
	return (0);
}
