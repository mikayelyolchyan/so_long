#include "../../includes/headers/so_long.h"

static void	render_tile(t_game *game, int x, int y, char tile)
{
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->food_img, x, y);
	else if (tile == 'U')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->power_up_img, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->black_wall_img, x, y);
}


static void	get_ghost_coords(t_ghost *ghost, int *x, int *y)
{
	*x = ghost->prev_x;
	*y = ghost->prev_y;
}
//static void	get_pac_coords(t_player *player, int *x, int *y)
//{
//	*x = player->prev_x;
//	*y = player->prev_y;
//}

//void	update_player(t_game *game, char **map, t_player *player)
//{
//	int		x;
//	int		y;
//	char	tile;
//	int direction;

//	direction = player->direction;
//	get_pac_coords(player, &x, &y);
//	if (direction == UP || direction == DOWN)
//		tile = map[y / 32][x / 32];
//	else
//		tile = map[y / 32][x / 32];
//	render_tile(game, x, y, tile);
//}

void	update_ghost(t_game *game, char **map, int direction, t_ghost *ghost)
{
	int		x;
	int		y;
	char	tile;

	get_ghost_coords(ghost, &x, &y);
	if (direction == UP || direction == DOWN)
		tile = map[y / 32][x / 32];
	else
		tile = map[y / 32][x / 32];
	render_tile(game, x, y, tile);
}
