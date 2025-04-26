/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_current_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:31:10 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:31:11 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

static void	*get_ghost_eaten_img(t_ghost *c_ghost)
{
	void	*current_img;

	current_img = NULL;
	if (c_ghost->direction == UP)
		current_img = c_ghost->ghost_is_eaten_up;
	else if (c_ghost->direction == DOWN)
		current_img = c_ghost->ghost_is_eaten_down;
	else if (c_ghost->direction == LEFT)
		current_img = c_ghost->ghost_is_eaten_left;
	else if (c_ghost->direction == RIGHT)
		current_img = c_ghost->ghost_is_eaten_right;
	return (current_img);
}

void	*get_ghost_current_img(t_game *game, t_ghost *c_ghost)
{
	void	*current_img;

	current_img = NULL;
	if (c_ghost->is_eaten == 1)
	{
		current_img = get_ghost_eaten_img(c_ghost);
	}
	else if (game->pac_attack_mode == 1 && \
			c_ghost->is_eaten == 0 && \
			c_ghost->is_respawned == 0)
	{
		if (game->pac_attack_mode_delay <= GHOST_PANIC_LIMIT)
			current_img = get_ghost_panic_animation(game, c_ghost);
		else
			current_img = get_ghost_panic_flashing_animation(game, c_ghost);
	}
	else
	{
		if (c_ghost->direction == LEFT || c_ghost->direction == RIGHT)
			current_img = get_ghost_horizontal_animation(game, c_ghost);
		else if (c_ghost->direction == UP || c_ghost->direction == DOWN)
			current_img = get_ghost_vertical_animation(game, c_ghost);
	}
	return (current_img);
}
