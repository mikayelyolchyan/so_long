/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_utils_ghost.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:36:42 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:36:43 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

static void	render_ghost_tile(t_game *game, int x, int y, char tile)
{
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->food_img, x, y);
	else if (tile == 'U')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->power_up_img, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->exit_img, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map->black_wall_img, x, y);
}

static void	get_ghost_coords(t_ghost *ghost, int *x, int *y)
{
	*x = ghost->prev_x;
	*y = ghost->prev_y;
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
