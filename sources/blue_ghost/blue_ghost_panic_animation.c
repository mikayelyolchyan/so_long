#include "../../includes/headers/so_long.h"

void	*get_blue_ghost_panic_vertical_animation(t_game *game, t_ghost *b_ghost)
{
	void	*current_img;

	if (b_ghost->direction == UP)
	{
		if (game->frame == 0)
			current_img = b_ghost->ghost_panic1a;
		else if (game->frame == 1)
			current_img = b_ghost->ghost_panic1b;
		else if (game->frame == 2)
			current_img = b_ghost->ghost_panic1a;
		else if (game->frame == 3)
			current_img = b_ghost->ghost_panic1b;
	}
	else if (b_ghost->direction == DOWN)
	{
		if (game->frame == 0)
			current_img = b_ghost->ghost_panic1a;
		else if (game->frame == 1)
			current_img = b_ghost->ghost_panic1b;
		else if (game->frame == 2)
			current_img = b_ghost->ghost_panic1a;
		else if (game->frame == 3)
			current_img = b_ghost->ghost_panic1b;
	}
	return (current_img);
}

void	*get_blue_ghost_panic_horizontal_animation(t_game *game, t_ghost *b_ghost)
{
	void	*current_img;

	if (b_ghost->direction == LEFT)
	{
		if (game->frame == 0)
			current_img = b_ghost->ghost_panic1a;
		else if (game->frame == 1)
			current_img = b_ghost->ghost_panic1b;
		else if (game->frame == 2)
			current_img = b_ghost->ghost_panic1a;
		else if (game->frame == 3)
			current_img = b_ghost->ghost_panic1b;
	}
	else if (b_ghost->direction == RIGHT)
	{
		if (game->frame == 0)
			current_img = b_ghost->ghost_panic1a;
		else if (game->frame == 1)
			current_img = b_ghost->ghost_panic1b;
		else if (game->frame == 2)
			current_img = b_ghost->ghost_panic1a;
		else if (game->frame == 3)
			current_img = b_ghost->ghost_panic1b;
	}
	return (current_img);
}

void	*get_blue_ghost_panic_flashing_vertical_animation(t_game *game, t_ghost *b_ghost)
{
	void	*current_img;

	if (b_ghost->direction == UP)
	{
		if (game->frame == 0)
			current_img = b_ghost->ghost_panic1a;
		else if (game->frame == 1)
			current_img = b_ghost->ghost_panic1b;
		else if (game->frame == 2)
			current_img = b_ghost->ghost_panic2a;
		else if (game->frame == 3)
			current_img = b_ghost->ghost_panic2b;
	}
	else if (b_ghost->direction == DOWN)
	{
		if (game->frame == 0)
			current_img = b_ghost->ghost_panic1a;
		else if (game->frame == 1)
			current_img = b_ghost->ghost_panic1b;
		else if (game->frame == 2)
			current_img = b_ghost->ghost_panic2a;
		else if (game->frame == 3)
			current_img = b_ghost->ghost_panic2b;
	}
	return (current_img);
}

void	*get_blue_ghost_panic_flashing_horizontal_animation(t_game *game, t_ghost *b_ghost)
{
	void	*current_img;

	if (b_ghost->direction == LEFT)
	{
		if (game->frame == 0)
			current_img = b_ghost->ghost_panic1a;
		else if (game->frame == 1)
			current_img = b_ghost->ghost_panic1b;
		else if (game->frame == 2)
			current_img = b_ghost->ghost_panic2a;
		else if (game->frame == 3)
			current_img = b_ghost->ghost_panic2b;
	}
	else if (b_ghost->direction == RIGHT)
	{
		if (game->frame == 0)
			current_img = b_ghost->ghost_panic1a;
		else if (game->frame == 1)
			current_img = b_ghost->ghost_panic1b;
		else if (game->frame == 2)
			current_img = b_ghost->ghost_panic2a;
		else if (game->frame == 3)
			current_img = b_ghost->ghost_panic2b;
	}
	return (current_img);
}