#include "../includes/headers/so_long.h"

int	ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->map->wall_img);
	mlx_destroy_image(game->mlx, game->map->black_wall_img);
	mlx_destroy_image(game->mlx, game->map->food_img);
	mlx_destroy_image(game->mlx, game->map->portal_img);
	mlx_destroy_image(game->mlx, game->map->logo_img);
	mlx_destroy_display(game->mlx);
	free_map(game->map);
	free(game->mlx);
	exit(0);
}
