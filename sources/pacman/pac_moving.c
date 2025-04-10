#include "../../includes/headers/so_long.h"

void	pac_moving_up_down(t_game *game)
{
	if (game->player->direction == UP)
	{
		if (game->map->map[(game->player->y - 4) / 32][game->player->x / 32] != '1')
			game->player->y -= 4;
	}
	else if (game->player->direction == DOWN)
	{
		if (game->map->map[(game->player->y + 4) / 32 + 1][game->player->x / 32] != '1')
			game->player->y += 4;
		else
		 	game->player->y = (game->player->y + 4) / 32 * 32;
	}
	if (game->player->y % 32 == 0 && game->player->x % 32 == 0 && game->map->map[game->player->y / 32][game->player->x / 32] == 'U')
	{
			game->pac_attack_mode = 1;
			game->r_ghost->is_respawned = 0;
			game->o_ghost->is_respawned = 0;
			game->m_ghost->is_respawned = 0;
			game->b_ghost->is_respawned = 0;
			game->pac_attack_mode_delay = 0;
			game->score += 50;
	}
	if (game->player->y % 32 == 0 && game->player->x % 32 == 0 && game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
		game->score += 10;
	if (game->player->y % 32 == 0 && game->player->x % 32 == 0)
		game->map->map[game->player->y / 32][game->player->x / 32] = '0';
}

void	pac_moving_left_right(t_game *game)
{
	if (game->player->direction == LEFT)
	{
		if (game->map->map[game->player->y / 32][(game->player->x - 4) / 32] != '1')
			game->player->x -= 4;
		if (game->map->map[game->player->y / 32][(game->player->x - 4) / 32] == 'T')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->player->x, game->player->y);
			game->player->x = (game->portal[1].x - 1) * 32;
			game->player->y = game->portal[1].y * 32;
		}
	}
	else if (game->player->direction == RIGHT)
	{
		if (game->map->map[game->player->y / 32][(game->player->x + 4) / 32 + 1] != '1')
		{
			game->player->x += 4;
		}
		else
		 	game->player->x = (game->player->x + 4) / 32 * 32;
		if (game->map->map[game->player->y / 32][(game->player->x + 32) / 32] == 'T')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->player->x, game->player->y);
			game->player->x = (game->portal[0].x + 1) * 32;
			game->player->y = game->portal[0].y * 32;
		}
	}
	if (game->player->y % 32 == 0 && game->player->x % 32 == 0 && game->map->map[game->player->y / 32][game->player->x / 32] == 'U')
	{
			game->pac_attack_mode = 1;
			game->r_ghost->is_respawned = 0;
			game->o_ghost->is_respawned = 0;
			game->m_ghost->is_respawned = 0;
			game->b_ghost->is_respawned = 0;
			game->pac_attack_mode_delay = 0;
			game->score += 50;
	}
	if (game->player->y % 32 == 0 && game->player->x % 32 == 0 && game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
		game->score += 10;
	if (game->player->y % 32 == 0 && game->player->x % 32 == 0)
		game->map->map[game->player->y / 32][game->player->x / 32] = '0';
}

void	pac_fast_moving_up_down(t_game *game)
{
	if (game->player->direction == UP)
	{
		if (game->map->map[(game->player->y - 8) / 32][game->player->x / 32] != '1')
			game->player->y -= 8;
		else
			game->player->y = (game->player->y + 8) / 32 * 32;
	}
	else if (game->player->direction == DOWN)
	{
		if (game->map->map[(game->player->y + 8) / 32 + 1][game->player->x / 32] != '1')
			game->player->y += 8;
		else
		 	game->player->y = (game->player->y + 8) / 32 * 32;
	}
	if (game->player->y % 32 == 0 && game->player->x % 32 == 0 && game->map->map[game->player->y / 32][game->player->x / 32] == 'U')
	{
			game->pac_attack_mode = 1;
			game->r_ghost->is_respawned = 0;
			game->o_ghost->is_respawned = 0;
			game->m_ghost->is_respawned = 0;
			game->b_ghost->is_respawned = 0;
			game->pac_attack_mode_delay = 0;
			game->score += 50;
	}
	if (game->player->y % 32 == 0 && game->player->x % 32 == 0 && game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
		game->score += 10;
	if (game->player->y % 32 == 0 && game->player->x % 32 == 0)
		game->map->map[game->player->y / 32][game->player->x / 32] = '0';
}

void	pac_fast_moving_left_right(t_game *game)
{
	if (game->player->direction == LEFT)
	{
		if (game->map->map[game->player->y / 32][(game->player->x - 8) / 32] != '1')
			game->player->x -= 8;
		if (game->map->map[game->player->y / 32][(game->player->x - 8) / 32] == 'T')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->player->x, game->player->y);
			game->player->x = (game->portal[1].x - 1) * 32;
			game->player->y = game->portal[1].y * 32;
		}
	}
	else if (game->player->direction == RIGHT)
	{
		if (game->map->map[game->player->y / 32][(game->player->x + 8) / 32 + 1] != '1')
		{
			game->player->x += 8;
		}
		else
		 	game->player->x = (game->player->x + 8) / 32 * 32;
		if (game->map->map[game->player->y / 32][(game->player->x + 32) / 32] == 'T')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->player->x, game->player->y);
			game->player->x = (game->portal[0].x + 1) * 32;
			game->player->y = game->portal[0].y * 32;
		}
	}
	if (game->player->y % 32 == 0 && game->player->x % 32 == 0 && game->map->map[game->player->y / 32][game->player->x / 32] == 'U')
	{
			game->pac_attack_mode = 1;
			game->r_ghost->is_respawned = 0;
			game->o_ghost->is_respawned = 0;
			game->m_ghost->is_respawned = 0;
			game->b_ghost->is_respawned = 0;
			game->pac_attack_mode_delay = 0;
			game->score += 50;
	}
	if (game->player->y % 32 == 0 && game->player->x % 32 == 0 && game->map->map[game->player->y / 32][game->player->x / 32] == 'C')
		game->score += 10;
	if (game->player->y % 32 == 0 && game->player->x % 32 == 0)
		game->map->map[game->player->y / 32][game->player->x / 32] = '0';
}

void	pac_moving(t_game *game)
{
	pac_moving_up_down(game);
	pac_moving_left_right(game);
}

void	pac_fast_moving(t_game *game)
{
	game->player->prev_x = game->player->x;
	game->player->prev_y = game->player->y;

	pac_fast_moving_up_down(game);
	pac_fast_moving_left_right(game);
}
