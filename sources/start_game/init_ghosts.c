#include "../../includes/headers/so_long.h"

int	init_ghosts(t_game *game, t_map *map)
{
	if (map->ghost_count != 4)
		return (0);
	game->r_ghost = malloc(sizeof(t_ghost));
	game->o_ghost = malloc(sizeof(t_ghost));
	game->m_ghost = malloc(sizeof(t_ghost));
	game->b_ghost = malloc(sizeof(t_ghost));
	if (!game->r_ghost || !game->o_ghost || !game->m_ghost || !game->b_ghost)
	{
		free(game->player);
		free(game->r_ghost);
		free(game->o_ghost);
		free(game->m_ghost);
		free(game->b_ghost);
		free_map(map);
		free(map);
		ft_printf("Error: t_ghost memory allocation failed\n");
		return (1);
	}
	return (0);
}
