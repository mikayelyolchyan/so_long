#include "../../includes/headers/so_long.h"

void	handle_ghost_portal(t_game *game, t_ghost *c_ghost, int portal_index)
{
	mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img,
		c_ghost->x, c_ghost->y);
	if (portal_index == 1)
	{
		c_ghost->x = (game->portal[1].x - 1) * 32;
		c_ghost->y = game->portal[1].y * 32;
	}
	else
	{
		c_ghost->x = (game->portal[0].x + 1) * 32;
		c_ghost->y = game->portal[0].y * 32;
	}
}