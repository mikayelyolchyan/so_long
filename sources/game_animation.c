/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:40:39 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:41:41 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/so_long.h"

static void	delays_update(t_game *game)
{
	game->frame_delay++;
	game->ghost_attack_mode_delay++;
	game->power_up_img_delay++;
	game->game_start_delay++;
}

static void	ghosts_movings(t_game *game)
{
	red_ghost_moving(game);
	orange_ghost_moving(game);
	magenta_ghost_moving(game);
	blue_ghost_moving(game);
}

static void	handle_all_animation_timings(t_game *game)
{
	delays_update(game);
	if (game->game_start_delay >= GAME_START_LIMIT)
		game->game_start = 1;
	if (game->game_start == 1 && game->game_win == 0 && game->game_restart == 0)
	{
		game->game_start_delay = 0;
		if (game->frame_delay >= GAME_FRAME_LIMIT)
		{
			game->frame = (game->frame + 1) % 4;
			game->frame_delay = 0;
			if (game->map->ghost_count == 4)
				ghosts_movings(game);
			pac_move_mode(game);
			if (game->ghost_attack_mode_delay >= GHOST_ATTACK_LIMIT)
				game->ghost_attack_mode_delay = 0;
			if (game->map->power_up_dots_count == 4)
				render_power_up_dots(game);
			display_score(game);
			display_move(game);
		}
	}
	game_win(game);
}

static void	ghost_current_image_to_window(t_game *game)
{
	void		*red_ghost_current_img;
	void		*orange_ghost_current_img;
	void		*magenta_ghost_current_img;
	void		*blue_ghost_current_img;

	red_ghost_current_img = get_ghost_current_img(game, game->r_ghost);
	orange_ghost_current_img = get_ghost_current_img(game, game->o_ghost);
	magenta_ghost_current_img = get_ghost_current_img(game, game->m_ghost);
	blue_ghost_current_img = get_ghost_current_img(game, game->b_ghost);
	mlx_put_image_to_window(game->mlx, game->win, \
		red_ghost_current_img, game->r_ghost->x, game->r_ghost->y);
	mlx_put_image_to_window(game->mlx, game->win, \
		orange_ghost_current_img, game->o_ghost->x, game->o_ghost->y);
	mlx_put_image_to_window(game->mlx, game->win, \
		magenta_ghost_current_img, game->m_ghost->x, game->m_ghost->y);
	mlx_put_image_to_window(game->mlx, game->win, \
		blue_ghost_current_img, game->b_ghost->x, game->b_ghost->y);
}

int	game_animation(t_game *game)
{
	void		*pac_current_img;

	handle_all_animation_timings(game);
	if (game->game_win == 0 && game->game_restart == 0)
	{
		pac_current_img = get_pac_current_img(game, game->player);
		update_map(game, game->map->map);
		mlx_put_image_to_window(game->mlx, game->win, \
			pac_current_img, game->player->x, game->player->y);
		if (game->map->ghost_count == 4)
			ghost_current_image_to_window(game);
	}
	if (game->game_restart == 1)
		pac_dying_and_restart(game);
	return (0);
}
