#include "../../includes/headers/so_long.h"

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	t_map *map;

	map = game->map;
	y = 0;
	while(map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, map->wall_img, x * map->tile_size, y * map->tile_size);
			else if (map->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, map->black_wall_img, x * map->tile_size, y * map->tile_size);
			else if (map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, map->food_img, x * map->tile_size, y * map->tile_size);
			x++;
		}
		y++;
	}
}

void	update_map(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->map->wall_img, game->player->x * 32, game->player->y / 32);
}
