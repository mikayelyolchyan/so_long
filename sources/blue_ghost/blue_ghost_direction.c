#include "../../includes/headers/so_long.h"

static void	movement_logic(t_game *game, t_dist dist)
{
	set_dist_struct_variables(&dist);
	if (game->b_ghost->is_eaten == 1)
    {
        game->b_ghost->is_respawned = 0;
		calculating_to_start(game, &dist, game->b_ghost);
		direction_when_ghost_eated(game->b_ghost, &dist);
        blue_ghost_respawned(game, game->b_ghost);
    }
	else if (game->pac_attack_mode == 1)
    {
        if (game->last_pac_attack_mode == 0 && game->pac_attack_mode == 1)
            game->b_ghost->is_respawned = 0;
        calculating_to_target(game, &dist, game->b_ghost);
		direction_when_ghost_in_panic(game->b_ghost, &dist);
    }
	else
    {
		calculating_to_target(game, &dist, game->b_ghost);
        ghost_direction(game->b_ghost, &dist);
        if (game->b_ghost->is_respawned == 1 && 
            (game->b_ghost->x != game->b_ghost->start_x || \
			game->b_ghost->y != game->b_ghost->start_y))
            game->b_ghost->is_respawned = 0;
    }
}

void	blue_ghost_direction(t_game *game)
{
	t_dist dist;

	set_dist_struct_variables(&dist);
    when_pac_eated_ghost(game, game->b_ghost);
	when_ghost_eated_pac(game, game->b_ghost);
	check_ghost_attack_mode(game);
	set_blue_ghost_target(game);
	movement_logic(game, dist);
    game->last_pac_attack_mode = game->pac_attack_mode;
}
