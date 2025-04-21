#include "../../includes/headers/so_long.h"

static void	render_ghost_tile(t_game *game, int x, int y, char tile)
{
	if (tile == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->food_img, x, y);
	}
	else if (tile == 'U')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->power_up_img, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->black_wall_img, x, y);
}

static void	render_player_tile(t_game *game, int x, int y, char tile)
{
	if (tile == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->food_img, x, y);
	}
	else if (tile == 'U')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->power_up_img, x, y);
}


static void	get_ghost_coords(t_ghost *ghost, int *x, int *y)
{
	*x = ghost->prev_x;
	*y = ghost->prev_y;
}
static void	get_pac_coords(t_player *player, int *x, int *y)
{
	*x = player->x;
	*y = player->y;
}

void	update_player(t_game *game, char **map, t_player *player)
{
	int		x;
	int		y;
	char	tile;

	get_pac_coords(player, &x, &y);
	if (player->direction == UP)
	{
		tile = map[(y + 4) / 32 + 1][x / 32];
		render_player_tile(game, x / 32 * 32, (y + 4) / 32 * 32 + 32, tile);
	}
	else if (player->direction == DOWN)
	{
		tile = map[(y - 4) / 32][x / 32];
		render_player_tile(game, x / 32 * 32, (y - 4) / 32 * 32, tile);
	}
	else if (player->direction == RIGHT)
	{
		tile = map[y / 32][(x - 4) / 32];
		render_player_tile(game, (x - 4) / 32 * 32, y / 32 * 32, tile);
	}
	else if (player->direction == LEFT)
	{
		tile = map[y / 32][(x + 4)/ 32 + 1];
		render_player_tile(game, (x + 4) / 32 * 32 + 32, y / 32 * 32, tile);
	}
}

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
	render_ghost_tile(game, x, y, tile);
}
