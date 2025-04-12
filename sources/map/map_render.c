/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <ваш_логин> <ваш_email>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 by <ваш_логин>             #+#    #+#             */
/*   Updated: 2025/04/11 by <ваш_логин>             ###   ########.fr       */
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

void	update_map(t_game *game, char **map, int direction)
{
	update_player_position(game);
	update_ghost(game, map, direction, game->r_ghost);
	update_ghost(game, map, direction, game->o_ghost);
	update_ghost(game, map, direction, game->m_ghost);
	update_ghost(game, map, direction, game->b_ghost);
}
