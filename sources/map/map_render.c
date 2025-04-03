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

void	update_map(t_game *game, char **map, int direction)
{
	if (direction == UP && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == '0' && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == DOWN && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == '0' && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == LEFT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == '0' && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == RIGHT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == '0' && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	
	if (direction == UP && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'C' && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == DOWN && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'C' && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == LEFT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'C' && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == RIGHT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'C' && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	
}