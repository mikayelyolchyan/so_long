#include "../../includes/headers/so_long.h"

static void	*get_dying_image1(t_game *game, int frame)
{
	if (frame == 0)
		return (game->player->dying1);
	else if (frame == 1)
		return (game->player->dying2);
	else if (frame == 2)
		return (game->player->dying3);
	else if (frame == 3)
		return (game->player->dying4);
	else if (frame == 4)
		return (game->player->dying5);
	return (NULL);
}

static void	*get_dying_image2(t_game *game, int frame)
{
	if (frame == 5)
		return (game->player->dying6);
	else if (frame == 6)
		return (game->player->dying7);
	else if (frame == 7)
		return (game->player->dying8);
	else if (frame == 8)
		return (game->player->dying9);
	else if (frame == 9)
		return (game->player->dying10);
	else if (frame == 10)
		return (game->player->woosh);
	else if (frame >= 11 && frame <= 14)
		return (game->map->black_wall_img);
	return (NULL);
}

static void	*select_dying_image(t_game *game, t_player *player)
{
	void	*img;

	img = NULL;
	if (player->dying_frame < 5)
		img = get_dying_image1(game, player->dying_frame);
	else if (player->dying_frame < 14)
		img = get_dying_image2(game, player->dying_frame);
	return (img);
}

static void	render_dying_frame(t_game *game, t_player *player, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, \
		player->x, player->y);
}

void	pac_dying(t_game *game, t_player *player)
{
	void	*current_img;

	current_img = select_dying_image(game, player);
	if (current_img)
		render_dying_frame(game, player, current_img);
	if (player->dying_frame == 14)
		game_restart(game);
}

