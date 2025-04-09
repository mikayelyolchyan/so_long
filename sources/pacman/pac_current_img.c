#include "../../includes/headers/so_long.h"

void	*get_pac_current_img(t_game *game, t_player *player)
{
	void	*current_img;

	if (player->direction == LEFT || player->direction == RIGHT)
	{
		current_img = get_pac_horizontal_animation(game, player);
	}
	else if (player->direction == UP || player->direction == DOWN)
	{
		current_img = get_pac_vertical_animation(game, player);
	}
	else
	{
		current_img = player->pac_closed;
	}
	return (current_img);
}