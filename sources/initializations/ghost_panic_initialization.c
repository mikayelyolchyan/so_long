#include "../../includes/headers/so_long.h"

void	ghost_panic_textures(t_game *game, t_map *map, t_ghost *c_ghost)
{
	c_ghost->ghost_panic1a = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/Panic/ghost_panic1a.xpm", \
			&map->tile_size, &map->tile_size);
	c_ghost->ghost_panic1b = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/Panic/ghost_panic1b.xpm", \
			&map->tile_size, &map->tile_size);
	c_ghost->ghost_panic2a = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/Panic/ghost_panic2a.xpm", \
			&map->tile_size, &map->tile_size);
	c_ghost->ghost_panic2b = mlx_xpm_file_to_image(game->mlx, \
		"textures/Ghosts/Panic/ghost_panic2b.xpm", \
			&map->tile_size, &map->tile_size);
}
