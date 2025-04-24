#include "../../includes/headers/so_long.h"

int	init_mlx(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(map);
		free(map);
		ft_printf("MiniLibX initialization Error\n");
		return (1);
	}
	map->tile_size = 32;
	game->win = mlx_new_window(game->mlx, map->width * map->tile_size,
			map->height * map->tile_size + 32, "PACMAN");
	if (!game->win)
	{
		free_map(map);
		free(map);
		ft_printf("Window creating Error\n");
		return (1);
	}
	return (0);
}
