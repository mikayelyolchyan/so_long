#include "../../includes/headers/so_long.h"

void	*get_ghost_panic_animation(t_game *game, t_ghost *c_ghost)
{
	void	*current_img;

	if (game->frame == 0 || game->frame == 2)
		current_img = c_ghost->ghost_panic1a;
	else if (game->frame == 1 || game->frame == 3)
		current_img = c_ghost->ghost_panic1b;
	return (current_img);
}

void	*get_ghost_panic_flashing_animation(t_game *game, t_ghost *c_ghost)
{
	void	*current_img;

	if (game->frame == 0)
		current_img = c_ghost->ghost_panic1a;
	else if (game->frame == 1)
		current_img = c_ghost->ghost_panic1b;
	else if (game->frame == 2)
		current_img = c_ghost->ghost_panic2a;
	else if (game->frame == 3)
		current_img = c_ghost->ghost_panic2b;
	return (current_img);
}
