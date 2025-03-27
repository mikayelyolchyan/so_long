#include "../includes/headers/so_long.h"

int	ft_exit(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map->wall_img)
		mlx_destroy_image(game->mlx, game->map->wall_img);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free_map(game->map);
	free(game->mlx);
	exit(0);
}
