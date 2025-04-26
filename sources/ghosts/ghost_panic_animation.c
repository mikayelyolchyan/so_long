/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_panic_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:31:52 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:31:53 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

void	*get_ghost_panic_animation(t_game *game, t_ghost *c_ghost)
{
	void	*current_img;

	current_img = NULL;
	if (game->frame == 0 || game->frame == 2)
		current_img = c_ghost->ghost_panic1a;
	else if (game->frame == 1 || game->frame == 3)
		current_img = c_ghost->ghost_panic1b;
	return (current_img);
}

void	*get_ghost_panic_flashing_animation(t_game *game, t_ghost *c_ghost)
{
	void	*current_img;

	current_img = NULL;
	if (game->frame == 0)
		current_img = c_ghost->ghost_panic1a;
	else if (game->frame == 1)
		current_img = c_ghost->ghost_panic1b;
	else if (game->frame == 2)
		current_img = c_ghost->ghost_panic2a;
	else if (game->frame == 3)
		current_img = c_ghost->ghost_panic2b;
	return (current_img);
}
