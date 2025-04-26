/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ghost_attack_mode.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:29:06 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:29:25 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

void	check_ghost_attack_mode(t_game *game)
{
	if (game->ghost_attack_mode_delay >= GHOST_NEUTRAL_LIMIT \
		&& game->pac_attack_mode == 0)
		game->ghost_attack_mode = 1;
	else if (game->ghost_attack_mode_delay <= GHOST_ATTACK_LIMIT \
		&& game->pac_attack_mode == 0)
		game->ghost_attack_mode = 0;
}
