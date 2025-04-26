#include "../../includes/headers/so_long.h"

static void movement_logic(t_game *game, t_dist dist)
{
	set_dist_struct_variables(&dist);
	if (game->m_ghost->is_eaten == 1)
    {
        game->m_ghost->is_respawned = 0;
        calculating_to_start(game, &dist, game->m_ghost);
        direction_when_ghost_eated(game->m_ghost, &dist);
		magenta_ghost_respawned(game, game->m_ghost);
    }
	else if (game->pac_attack_mode == 1)
    {
        if (game->last_pac_attack_mode == 0 && game->pac_attack_mode == 1)
            game->m_ghost->is_respawned = 0;
        calculating_to_target(game, &dist, game->m_ghost);
		direction_when_ghost_in_panic(game->m_ghost, &dist);
    }
	else
    {
        calculating_to_target(game, &dist, game->m_ghost);
        ghost_direction(game->m_ghost, &dist);
        if (game->m_ghost->is_respawned == 1 && 
            (game->m_ghost->x != game->m_ghost->start_x || \
			game->m_ghost->y != game->m_ghost->start_y))
            game->m_ghost->is_respawned = 0;
    }
}

void magenta_ghost_direction(t_game *game)
{
	t_dist dist;

	set_dist_struct_variables(&dist);
	when_pac_eated_ghost(game, game->m_ghost);
	when_ghost_eated_pac(game, game->m_ghost);
    check_ghost_attack_mode(game);

    // Установка цели для нормального режима
	set_magenta_ghost_target(game, game->m_ghost);

    // Остальная логика движения остается без изменений
	movement_logic(game, dist);

    game->last_pac_attack_mode = game->pac_attack_mode;
}
