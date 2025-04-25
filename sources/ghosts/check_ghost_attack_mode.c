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
