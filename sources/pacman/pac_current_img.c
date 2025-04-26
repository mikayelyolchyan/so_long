/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pac_current_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:37:42 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:37:43 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

void	*get_pac_current_img(t_game *game, t_player *player)
{
	void	*current_img;

	current_img = NULL;
	if (player->direction == LEFT || player->direction == RIGHT)
	{
		current_img = get_pac_horizontal_animation(game, player);
	}
	else if (player->direction == UP || player->direction == DOWN)
	{
		current_img = get_pac_vertical_animation(game, player);
	}
	else
	{
		current_img = player->pac_closed;
	}
	return (current_img);
}
