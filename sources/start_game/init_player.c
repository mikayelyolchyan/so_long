#include "../../includes/headers/so_long.h"

int	init_player(t_game *game, t_map *map)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		free_map(map);
		free(map);
		ft_printf("Error: t_player memory allocation failed\n");
		return (1);
	}
	return (0);
}
