#include "../../includes/headers/so_long.h"

static void	handle_power_up(t_game *game)
{
	game->pac_attack_mode = 1;
	if (game->map->ghost_count == 4)
	{
		game->r_ghost->is_respawned = 0;
		game->o_ghost->is_respawned = 0;
		game->m_ghost->is_respawned = 0;
		game->b_ghost->is_respawned = 0;
	}
	game->pac_attack_mode_delay = 0;
	game->score += 50;
}

void	handle_pac_portal(t_game *game, int portal_index)
{
	mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img,
		game->player->x, game->player->y);
	if (portal_index == 1)
	{
		game->player->x = (game->portal[1].x - 1) * 32;
		game->player->y = game->portal[1].y * 32;
	}
	else
	{
		game->player->x = (game->portal[0].x + 1) * 32;
		game->player->y = game->portal[0].y * 32;
	}
}

void	handle_collectibles(t_game *game)
{
	int	x;
	int	y;

	if (game->player->y % 32 != 0 || game->player->x % 32 != 0)
		return ;
	x = game->player->x / 32;
	y = game->player->y / 32;
	if (game->map->map[y][x] == 'U')
		handle_power_up(game);
	else if (game->map->map[y][x] == 'C')
	{
		game->score += 10;
		game->eated_dots++;
	}
	if (game->map->map[y][x] != 'T' && game->map->map[y][x] != 'E')
		game->map->map[y][x] = '0';
}
