#include "../../includes/headers/so_long.h"

void	set_positions_in_start(t_game *game)
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

void	set_default_directions(t_game *game)
{
	game->player->direction = RIGHT;
	game->r_ghost->direction = RIGHT;
	game->o_ghost->direction = LEFT;
	game->m_ghost->direction = LEFT;
	game->b_ghost->direction = RIGHT;
}
void	game_restart(t_game *game)
{
	set_positions_in_start(game);
	set_default_directions(game);
	draw_map(game);
	game->player->dying_frame = 0;
	game->game_restart = 0;
	game->game_start = 0;
	game->game_start_delay = 0;
	game->frame_delay = 0;
	game->ghost_attack_mode_delay = 0;
	game->power_up_img_delay = 0;
	if (game->player->died_count == 1)
		mlx_put_image_to_window(game->mlx, game->win, \
	game->map->black_wall_img, 5 * 32, game->map->height * 32);
	else if (game->player->died_count == 2)
		mlx_put_image_to_window(game->mlx, game->win, \
	game->map->black_wall_img, 4 * 32, game->map->height * 32);
	else if (game->player->died_count == 3)
		game_over(game);
}

void	pac_dying(t_game *game, t_player *player)
{
	void	*current_img;

	if (game->player->dying_frame == 0)
		current_img = player->dying1;
	else if (game->player->dying_frame == 1)
			current_img = player->dying2;
	else if (game->player->dying_frame == 2)
		current_img = player->dying3;
	else if (game->player->dying_frame == 3)
		current_img = player->dying4;
	else if (game->player->dying_frame == 4)
		current_img = player->dying5;
	else if (game->player->dying_frame == 5)
		current_img = player->dying6;
	else if (game->player->dying_frame == 6)
		current_img = player->dying7;
	else if (game->player->dying_frame == 7)
		current_img = player->dying8;
	else if (game->player->dying_frame == 8)
		current_img = player->dying9;
	else if (game->player->dying_frame == 9)
		current_img = player->dying10;
	else if (game->player->dying_frame == 10)
		current_img = player->woosh;
	else if (game->player->dying_frame == 11)
		current_img = game->map->black_wall_img;
	else if (game->player->dying_frame == 12)
		current_img = game->map->black_wall_img;
	else if (game->player->dying_frame == 13)
		current_img = game->map->black_wall_img;
	else if (game->player->dying_frame == 14)
	{	
		current_img = game->map->black_wall_img;
		game_restart(game);
	}
	mlx_put_image_to_window(game->mlx, game->win, \
		current_img, game->player->x, game->player->y);
}
