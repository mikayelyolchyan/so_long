#include "../includes/headers/so_long.h"

int	ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map);
	exit(0);
}
