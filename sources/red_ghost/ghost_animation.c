#include "../../includes/headers/so_long.h"

void	*get_red_ghost_vertical_animation(t_game *game, t_ghost *r_ghost)
{
	void	*current_img;

	if (r_ghost->direction == UP)
	{
		if (game->frame == 0)
			current_img = r_ghost->ghost_up1;
		else if (game->frame == 1 || game->frame == 3)
			current_img = r_ghost->ghost_up2;
		else if (game->frame == 2)
			current_img = r_ghost->ghost_up1;
	}
	else if (r_ghost->direction == DOWN)
	{
		if (game->frame == 0)
			current_img = r_ghost->ghost_down1;
		else if (game->frame == 1 || game->frame == 3)
			current_img = r_ghost->ghost_down2;
		else if (game->frame == 2)
			current_img = r_ghost->ghost_down1;
	}
	return (current_img);
}

void	*get_red_ghost_horizontal_animation(t_game *game, t_ghost *r_ghost)
{
	void	*current_img;

	if (r_ghost->direction == LEFT)
	{
		if (game->frame == 0)
			current_img = r_ghost->ghost_left1;
		else if (game->frame == 1 || game->frame == 3)
			current_img = r_ghost->ghost_left2;
		else if (game->frame == 2)
			current_img = r_ghost->ghost_left1;
	}
	else if (r_ghost->direction == RIGHT)
	{
		if (game->frame == 0)
			current_img = r_ghost->ghost_right1;
		else if (game->frame == 1 || game->frame == 3)
			current_img = r_ghost->ghost_right2;
		else if (game->frame == 2)
			current_img = r_ghost->ghost_right1;
	}
	return (current_img);
}