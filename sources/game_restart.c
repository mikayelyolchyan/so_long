/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_restart.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:44:53 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:44:54 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/so_long.h"

static void	set_positions_in_start(t_game *game)
{
	game->player->x = game->player->start_x;
	game->player->y = game->player->start_y;
	game->r_ghost->x = game->r_ghost->start_x;
	game->r_ghost->y = game->r_ghost->start_y;
	game->b_ghost->x = game->b_ghost->start_x;
	game->b_ghost->y = game->b_ghost->start_y;
	game->m_ghost->x = game->m_ghost->start_x;
	game->m_ghost->y = game->m_ghost->start_y;
	game->o_ghost->x = game->o_ghost->start_x;
	game->o_ghost->y = game->o_ghost->start_y;
}

static void	set_default_directions(t_game *game)
{
	game->player->direction = RIGHT;
	game->r_ghost->direction = RIGHT;
	game->o_ghost->direction = LEFT;
	game->m_ghost->direction = LEFT;
	game->b_ghost->direction = RIGHT;
}

static void	set_variables_to_zero(t_game *game)
{
	game->player->dying_frame = 0;
	game->game_restart = 0;
	game->game_start = 0;
	game->game_start_delay = 0;
	game->frame_delay = 0;
	game->ghost_attack_mode_delay = 0;
	game->power_up_img_delay = 0;
	game->pac_attack_mode = 0;
	game->r_ghost->is_eaten = 0;
	game->r_ghost->is_respawned = 0;
	game->m_ghost->is_eaten = 0;
	game->m_ghost->is_respawned = 0;
	game->o_ghost->is_eaten = 0;
	game->o_ghost->is_respawned = 0;
	game->b_ghost->is_eaten = 0;
	game->b_ghost->is_respawned = 0;
}

void	game_restart(t_game *game)
{
	set_positions_in_start(game);
	set_default_directions(game);
	draw_map(game);
	set_variables_to_zero(game);
	if (game->player->died_count == 1)
		mlx_put_image_to_window(game->mlx, game->win, \
	game->map->black_wall_img, 5 * 32, game->map->height * 32);
	else if (game->player->died_count == 2)
		mlx_put_image_to_window(game->mlx, game->win, \
	game->map->black_wall_img, 4 * 32, game->map->height * 32);
	else if (game->player->died_count == 3)
		game_over(game);
}
