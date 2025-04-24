#include "../includes/headers/so_long.h"

static void	display_put_image(t_game *game, int x, int y, int digit)
{
	if (digit == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->font->zero, x, y);
	else if (digit == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->font->one, x, y);
	else if (digit == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->font->two, x, y);
	else if (digit == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->font->three, x, y);
	else if (digit == 4)
		mlx_put_image_to_window(game->mlx, game->win, game->font->four, x, y);
	else if (digit == 5)
		mlx_put_image_to_window(game->mlx, game->win, game->font->five, x, y);
	else if (digit == 6)
		mlx_put_image_to_window(game->mlx, game->win, game->font->six, x, y);
	else if (digit == 7)
		mlx_put_image_to_window(game->mlx, game->win, game->font->seven, x, y);
	else if (digit == 8)
		mlx_put_image_to_window(game->mlx, game->win, game->font->eight, x, y);
	else if (digit == 9)
		mlx_put_image_to_window(game->mlx, game->win, game->font->nine, x, y);
}

void	display_score(t_game *game)
{
	int		x;
	int		digit;
	int		i;

	x = 1 * 32;
	i = 0;
	game->score_str = ft_itoa(game->score);
	while (game->score_str[i] != '\0')
	{
		digit = game->score_str[i] - '0';
		display_put_image(game, x, (game->map->height) * 32 + 8, digit);
		x += 16;
		i++;
	}
	free(game->score_str);
}

void	display_move(t_game *game)
{
	int		x;
	int		digit;
	int		i;

	x = (game->map->width - 2) * 32;
	i = 0;
	game->player->move_str = ft_itoa(game->player->move_count);
	while (game->player->move_str[i] != '\0')
	{
		digit = game->player->move_str[i] - '0';
		display_put_image(game, x, (game->map->height) * 32 + 8, digit);
		x += 16;
		i++;
	}
	free(game->player->move_str);
}
