#include "../../includes/headers/so_long.h"

static void	render_player_tile(t_game *game, int x, int y, char tile)
{
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->food_img, x, y);
	else if (tile == 'U')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->power_up_img, x, y);
	else if (tile == 'T')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->portal_img, x, y);
	else if (tile == 'T')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->portal_img, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->exit_img, x, y);
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
		tile = map[y / 32][(x + 4) / 32 + 1];
		render_player_tile(game, (x + 4) / 32 * 32 + 32, y / 32 * 32, tile);
	}
}
