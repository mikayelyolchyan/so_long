/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pac_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:37:39 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:37:40 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

void	*get_pac_vertical_animation(t_game *game, t_player *player)
{
	void	*current_img;

	current_img = NULL;
	if (player->direction == UP)
	{
		if (game->frame == 0)
			current_img = player->pac_closed;
		else if (game->frame == 1 || game->frame == 3)
			current_img = player->pac_semi_up;
		else if (game->frame == 2)
			current_img = player->pac_open_up;
	}
	else if (player->direction == DOWN)
	{
		if (game->frame == 0)
			current_img = player->pac_closed;
		else if (game->frame == 1 || game->frame == 3)
			current_img = player->pac_semi_down;
		else if (game->frame == 2)
			current_img = player->pac_open_down;
	}
	return (current_img);
}

void	*get_pac_horizontal_animation(t_game *game, t_player *player)
{
	void	*current_img;

	current_img = NULL;
	if (player->direction == LEFT)
	{
		if (game->frame == 0)
			current_img = player->pac_closed;
		else if (game->frame == 1 || game->frame == 3)
			current_img = player->pac_semi_left;
		else if (game->frame == 2)
			current_img = player->pac_open_left;
	}
	else if (player->direction == RIGHT)
	{
		if (game->frame == 0)
			current_img = player->pac_closed;
		else if (game->frame == 1 || game->frame == 3)
			current_img = player->pac_semi_right;
		else if (game->frame == 2)
			current_img = player->pac_open_right;
	}
	return (current_img);
}
