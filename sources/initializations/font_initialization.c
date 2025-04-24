#include "../../includes/headers/so_long.h"

void	font_initialization(t_game *game)
{
	int	i;
	int	j;

	i = 15;
	j = 8;
	game->font->zero = mlx_xpm_file_to_image(game->mlx, \
		"textures/Fonts/0.xpm", &i, &j);
	game->font->one = mlx_xpm_file_to_image(game->mlx, \
		"textures/Fonts/1.xpm", &i, &j);
	game->font->two = mlx_xpm_file_to_image(game->mlx, \
		"textures/Fonts/2.xpm", &i, &j);
	game->font->three = mlx_xpm_file_to_image(game->mlx, \
		"textures/Fonts/3.xpm", &i, &j);
	game->font->four = mlx_xpm_file_to_image(game->mlx, \
		"textures/Fonts/4.xpm", &i, &j);
	game->font->five = mlx_xpm_file_to_image(game->mlx, \
		"textures/Fonts/5.xpm", &i, &j);
	game->font->six = mlx_xpm_file_to_image(game->mlx, \
		"textures/Fonts/6.xpm", &i, &j);
	game->font->seven = mlx_xpm_file_to_image(game->mlx, \
		"textures/Fonts/7.xpm", &i, &j);
	game->font->eight = mlx_xpm_file_to_image(game->mlx, \
		"textures/Fonts/8.xpm", &i, &j);
	game->font->nine = mlx_xpm_file_to_image(game->mlx, \
		"textures/Fonts/9.xpm", &i, &j);
}
