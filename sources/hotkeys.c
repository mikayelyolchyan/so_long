/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:45:05 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:45:06 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/so_long.h"

int	ft_hotkey(int keycode, t_game *game)
{
	if (keycode == W)
	{
		game->player->pending_direction = UP;
	}
	else if (keycode == S)
	{
		game->player->pending_direction = DOWN;
	}
	else if (keycode == A)
	{
		game->player->pending_direction = LEFT;
	}
	else if (keycode == D)
	{
		game->player->pending_direction = RIGHT;
	}
	else if (keycode == ESC)
	{
		ft_exit(game);
	}
	game->frame_delay = 0;
	return (0);
}
