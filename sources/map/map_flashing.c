#include "../../includes/headers/so_long.h"

static void	blue_walls(t_game *game, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->map->wall_img,
			x * game->map->tile_size, y * game->map->tile_size);
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img,
			x * game->map->tile_size, y * game->map->tile_size);
	}
}

static void	white_walls(t_game *game, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->map->white_wall_img,
			x * game->map->tile_size, y * game->map->tile_size);
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img,
			x * game->map->tile_size, y * game->map->tile_size);
	}
}

static void	flashing(t_game *game, int x, int y)
{
	if (game->map_flashing_frame == 0)
		blue_walls(game, x, y, game->map->map[y][x]);
	else if (game->map_flashing_frame == 1)
		white_walls(game, x, y, game->map->map[y][x]);
}
void	map_flashing(t_map *map, t_game *game)
{
	int		x;
	int		y;

	y = 0;
	game->map_flashing_frame = (game->map_flashing_frame + 1) % 2;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			flashing(game, x, y);
			x++;
		}
		y++;
	}
}