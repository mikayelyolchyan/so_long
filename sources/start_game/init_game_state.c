/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:38:39 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:38:40 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

void	init_game_state(t_game *game, t_map *map)
{
	game->frame = 0;
	game->frame_delay = 0;
	game->ghost_attack_mode = 0;
	game->ghost_attack_mode_delay = 0;
	game->power_up_img_delay = 0;
	game->pac_attack_mode = 0;
	game->last_pac_attack_mode = 0;
	game->pac_attack_mode_delay = 0;
	game->score = 0;
	game->eated_dots = 0;
	game->game_start = 0;
	game->game_start_delay = 0;
	game->game_win = 0;
	game->map_flashing_frame = 0;
	game->map_flashing_delay = 0;
	game->map_flashing_count = 0;
	game->game_restart = 0;
	map->x = 0;
	map->y = 0;
}
