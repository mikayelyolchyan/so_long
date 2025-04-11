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
			else if (map->map[y][x] == 'T')
				mlx_put_image_to_window(game->mlx, game->win, map->portal_img, x * map->tile_size, y * map->tile_size);
			else if (map->map[y][x] == 'U')
				mlx_put_image_to_window(game->mlx, game->win, map->power_up_img, x * map->tile_size, y * map->tile_size);
			x++;
		}
		y++;
	}
}

void	update_map(t_game *game, char **map, int direction)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player->pac_black, game->player->prev_x, game->player->prev_y);

	if (direction == UP && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'C')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == DOWN && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'C')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == LEFT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'C')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == RIGHT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'C')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == UP && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == '0')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == DOWN && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == '0')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == LEFT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == '0')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == RIGHT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == '0')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == UP && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'R')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == DOWN && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'R')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == LEFT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'R')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == RIGHT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'R')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == UP && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'O')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == DOWN && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'O')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == LEFT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'O')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == RIGHT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'O')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == UP && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'M')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == DOWN && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'M')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == LEFT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'M')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == RIGHT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'M')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == UP && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'U')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == DOWN && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'U')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == LEFT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'U')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == RIGHT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'U')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == UP && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'B')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == DOWN && map[(game->r_ghost->prev_y) / 32][game->r_ghost->prev_x / 32] == 'B')// && game->r_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->prev_x, (game->r_ghost->prev_y));
	else if (direction == LEFT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'B')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);
	else if (direction == RIGHT && map[game->r_ghost->prev_y / 32][(game->r_ghost->prev_x) / 32] == 'B')// && game->r_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->r_ghost->prev_x), game->r_ghost->prev_y);

	if (direction == UP && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == 'C')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == DOWN && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == 'C')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == LEFT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == 'C')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);
	else if (direction == RIGHT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == 'C')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);
	else if (direction == UP && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == '0')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == DOWN && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == '0')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == LEFT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == '0')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);
	else if (direction == RIGHT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == '0')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);
	else if (direction == UP && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == 'R')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == DOWN && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == 'R')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == LEFT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == 'R')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);
	else if (direction == RIGHT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == 'R')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);
	else if (direction == UP && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == 'O')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == DOWN && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == 'O')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == LEFT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == 'O')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);
	else if (direction == RIGHT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == 'O')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);
	else if (direction == UP && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == 'M')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == DOWN && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == 'M')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == LEFT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == 'M')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);
	else if (direction == RIGHT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == 'M')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);
	else if (direction == UP && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == 'U')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == DOWN && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == 'U')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == LEFT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == 'U')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);
	else if (direction == RIGHT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == 'U')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);
	else if (direction == UP && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == 'B')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == DOWN && map[(game->o_ghost->prev_y) / 32][game->o_ghost->prev_x / 32] == 'B')// && game->o_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->prev_x, (game->o_ghost->prev_y));
	else if (direction == LEFT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == 'B')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);
	else if (direction == RIGHT && map[game->o_ghost->prev_y / 32][(game->o_ghost->prev_x) / 32] == 'B')// && game->o_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->o_ghost->prev_x), game->o_ghost->prev_y);

	if (direction == UP && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == 'C')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == DOWN && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == 'C')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == LEFT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == 'C')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);
	else if (direction == RIGHT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == 'C')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);
	else if (direction == UP && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == '0')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == DOWN && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == '0')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == LEFT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == '0')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);
	else if (direction == RIGHT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == '0')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);
	else if (direction == UP && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == 'R')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == DOWN && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == 'R')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == LEFT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == 'R')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);
	else if (direction == RIGHT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == 'R')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);
	else if (direction == UP && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == 'O')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == DOWN && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == 'O')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == LEFT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == 'O')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);
	else if (direction == RIGHT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == 'O')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);
	else if (direction == UP && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == 'M')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == DOWN && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == 'M')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == LEFT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == 'M')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);
	else if (direction == RIGHT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == 'M')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);
	else if (direction == UP && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == 'U')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == DOWN && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == 'U')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == LEFT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == 'U')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);
	else if (direction == RIGHT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == 'U')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);
	else if (direction == UP && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == 'B')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == DOWN && map[(game->m_ghost->prev_y) / 32][game->m_ghost->prev_x / 32] == 'B')// && game->m_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->prev_x, (game->m_ghost->prev_y));
	else if (direction == LEFT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == 'B')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);
	else if (direction == RIGHT && map[game->m_ghost->prev_y / 32][(game->m_ghost->prev_x) / 32] == 'B')// && game->m_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->m_ghost->prev_x), game->m_ghost->prev_y);

	if (direction == UP && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == 'C')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == DOWN && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == 'C')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == LEFT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == 'C')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
	else if (direction == RIGHT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == 'C')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
	else if (direction == UP && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == '0')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == DOWN && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == '0')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == LEFT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == '0')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
	else if (direction == RIGHT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == '0')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
	else if (direction == UP && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == 'R')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == DOWN && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == 'R')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == LEFT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == 'R')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
	else if (direction == RIGHT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == 'R')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
	else if (direction == UP && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == 'O')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == DOWN && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == 'O')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == LEFT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == 'O')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
	else if (direction == RIGHT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == 'O')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
	else if (direction == UP && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == 'M')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == DOWN && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == 'M')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == LEFT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == 'M')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
	else if (direction == RIGHT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == 'M')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
	else if (direction == UP && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == 'U')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == DOWN && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == 'U')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == LEFT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == 'U')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
	else if (direction == RIGHT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == 'U')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
	else if (direction == UP && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == 'B')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == DOWN && map[(game->b_ghost->prev_y) / 32][game->b_ghost->prev_x / 32] == 'B')// && game->b_ghost->prev_x % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->prev_x, (game->b_ghost->prev_y));
	else if (direction == LEFT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == 'B')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
	else if (direction == RIGHT && map[game->b_ghost->prev_y / 32][(game->b_ghost->prev_x) / 32] == 'B')// && game->b_ghost->prev_y % 32 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, (game->b_ghost->prev_x), game->b_ghost->prev_y);
}
