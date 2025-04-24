#include "../includes/headers/so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
	{
		ft_printf("Error: use second argument .ber map\n");
		return (1);
	}
	if (start_game(&game, argv[1]) == 1)
		return (1);
	draw_map(&game);
	mlx_put_image_to_window(game.mlx, game.win, \
		game.player->pac_open_right, game.player->x, game.player->y);
	mlx_put_image_to_window(game.mlx, game.win, game.map->logo_img, \
		game.map->width / 2 * 32 - 65, game.map->height * 32);
	mlx_put_image_to_window(game.mlx, game.win, \
		game.player->pac_semi_right, 4 * 32, game.map->height * 32);
	mlx_put_image_to_window(game.mlx, game.win, \
		game.player->pac_semi_right, 5 * 32, game.map->height * 32);
	mlx_hook(game.win, 17, 1L << 2, ft_exit, &game);
	mlx_hook(game.win, 2, 1L << 0, &ft_hotkey, &game);
	mlx_loop_hook(game.mlx, &game_animation, &game);
	mlx_loop(game.mlx);
    return (0);
}
