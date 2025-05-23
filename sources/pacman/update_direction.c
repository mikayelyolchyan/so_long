/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:38:01 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:38:02 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

int	pac_can_move_vertical(t_game *game, char **map)
{
	if (game->player->pending_direction == UP && \
		map[(game->player->y - 4) / 32][game->player->x / 32] != '1' && \
		game->player->x % 32 == 0 && game->player->direction != UP)
		return (1);
	if (game->player->pending_direction == DOWN && \
		map[(game->player->y + 4) / 32 + 1][game->player->x / 32] != '1' && \
		game->player->x % 32 == 0 && game->player->direction != DOWN)
		return (1);
	return (0);
}

int	pac_can_move_horizontal(t_game *game, char **map)
{
	if (game->player->pending_direction == LEFT && \
		map[game->player->y / 32][(game->player->x - 4) / 32] != '1' && \
		game->player->y % 32 == 0 && game->player->direction != LEFT)
		return (1);
	if (game->player->pending_direction == RIGHT && \
		map[game->player->y / 32][(game->player->x + 4) / 32 + 1] != '1' && \
		game->player->y % 32 == 0 && game->player->direction != RIGHT)
		return (1);
	return (0);
}

void	update_pac_direction(t_game *game)
{
	char	**map;

	map = game->map->map;
	if (game->player->pending_direction == -1)
		return ;
	if (pac_can_move_vertical(game, map))
	{
		game->player->direction = game->player->pending_direction;
		game->player->pending_direction = -1;
		game->player->move_count++;
	}
	else if (pac_can_move_horizontal(game, map))
	{
		game->player->direction = game->player->pending_direction;
		game->player->pending_direction = -1;
		game->player->move_count++;
	}
}
