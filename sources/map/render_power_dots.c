/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_power_dots.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:36:49 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:37:27 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

void	render_power_up_dots(t_game *game)
{
	int	index;
	int	x;
	int	y;
	int	map_x;
	int	map_y;

	index = (game->power_up_img_delay / 1024) % game->map->power_up_dots_count;
	x = game->map->power_up_dots_array[index].x;
	y = game->map->power_up_dots_array[index].y;
	map_x = x / game->map->tile_size;
	map_y = y / game->map->tile_size;
	if (game->power_up_img_delay >= 4096 && game->power_up_img_delay < 8192)
	{
		if (game->map->map[map_y][map_x] == 'U')
			mlx_put_image_to_window(game->mlx, \
			game->win, game->map->power_up_img, x, y);
	}
	else if (game->power_up_img_delay >= 8192)
	{
		if (game->map->map[map_y][map_x] == 'U')
			mlx_put_image_to_window(game->mlx, game->win, \
			game->map->black_wall_img, x, y);
		if (game->power_up_img_delay >= 16384)
			game->power_up_img_delay = 0;
	}
}
