#include "../../includes/headers/so_long.h"

static void	movement_logic(t_game *game, t_dist *dist)
{
	set_dist_struct_variables(dist);
	if (game->r_ghost->is_eaten == 1)
    {
        game->r_ghost->is_respawned = 0;
        calculating_to_start(game, dist, game->r_ghost);
		direction_when_ghost_eated(game->r_ghost, dist);
		red_ghost_respawned(game, game->r_ghost);
    }
	else if (game->pac_attack_mode == 1)
    {
		if (game->last_pac_attack_mode == 0 && game->pac_attack_mode == 1)
       		game->r_ghost->is_respawned = 0;
		calculating_to_target(game, dist, game->r_ghost);
		direction_when_ghost_in_panic(game->r_ghost, dist);
    }
	else
    {
        calculating_to_target(game, dist, game->r_ghost);
		ghost_direction(game->r_ghost, dist);
		if (game->r_ghost->is_respawned == 1 && \
			(game->r_ghost->x != game->r_ghost->start_x || \
			game->r_ghost->y != game->r_ghost->start_y))
			game->r_ghost->is_respawned = 0;
    }
}
void	set_dist_struct_variables(t_dist *dist)
{
	dist->dist_up = INT_MAX;
	dist->dist_down = INT_MAX;
	dist->dist_left = INT_MAX;
	dist->dist_right = INT_MAX;
	dist->min_dist = INT_MAX;
	dist->max_dist = INT_MAX;
}

void red_ghost_direction(t_game *game)
{
    t_dist *dist;

	dist = game->dist;
	set_dist_struct_variables(dist);
    // Проверка на "съедение" призрака
	when_pac_eated_ghost(game, game->r_ghost);
	// Проверка на "съедение" пакмана
	when_ghost_eated_pac(game, game->r_ghost);

	check_ghost_attack_mode(game);
    // Установка цели для нормального режима
	set_red_ghost_target(game, game->r_ghost);

    // Логика движения в зависимости от состояния
	movement_logic(game, dist);
    game->last_pac_attack_mode = game->pac_attack_mode;
}
