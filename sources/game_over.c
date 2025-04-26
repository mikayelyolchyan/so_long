/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:44:02 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:44:45 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/so_long.h"

static void	red_walls(t_game *game, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->map->red_wall_img,
			x * game->map->tile_size, y * game->map->tile_size);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img,
			x * game->map->tile_size, y * game->map->tile_size);
}

static void	red_map(t_map *map, t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			red_walls(game, x, y, game->map->map[y][x]);
			x++;
		}
		y++;
	}
}

void	game_over(t_game *game)
{
	int	time;

	time = 0;
	red_map(game->map, game);
	red_map(game->map, game);
	while (time < INT_MAX / 3)
		time++;
	ft_exit(game);
}
