/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:36:47 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:36:48 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

static void	draw_tile(t_game *game, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->map->wall_img,
			x * game->map->tile_size, y * game->map->tile_size);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img,
			x * game->map->tile_size, y * game->map->tile_size);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->map->food_img,
			x * game->map->tile_size, y * game->map->tile_size);
	else if (tile == 'T')
		mlx_put_image_to_window(game->mlx, game->win, game->map->portal_img,
			x * game->map->tile_size, y * game->map->tile_size);
	else if (tile == 'U')
		mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img,
			x * game->map->tile_size, y * game->map->tile_size);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->map->exit_img,
			x * game->map->tile_size, y * game->map->tile_size);
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;
	t_map	*map;

	map = game->map;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			draw_tile(game, x, y, map->map[y][x]);
			x++;
		}
		y++;
	}
}

void	update_map(t_game *game, char **map)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player->pac_black, \
		game->player->prev_x, game->player->prev_y);
	update_player(game, map, game->player);
	if (game->map->ghost_count == 4)
	{
		update_ghost(game, map, game->r_ghost->direction, game->r_ghost);
		update_ghost(game, map, game->o_ghost->direction, game->o_ghost);
		update_ghost(game, map, game->m_ghost->direction, game->m_ghost);
		update_ghost(game, map, game->b_ghost->direction, game->b_ghost);
	}
}
