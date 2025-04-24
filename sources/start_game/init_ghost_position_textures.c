#include "../../includes/headers/so_long.h"

int	init_ghost_positions_textures(t_game *game, t_map *map)
{
	if (map->ghost_count == 4)
	{
		red_ghost_initialization(game, map);
		orange_ghost_initialization(game, map);
		magenta_ghost_initialization(game, map);
		blue_ghost_initialization(game, map);
	}
	return (0);
}
