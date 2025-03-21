#include "../includes/headers/so_long.h"

int	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("MiniLibX initialization Error\n");
		return (1);
	}
	game->win = mlx_new_window(game->mlx, 1024, 1024, "PACMAN");
	if (!game->win)
	{
		ft_printf("Window creating Error\n");
		return (1);
	}
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		ft_printf("t_map memory allocation error\n");
		return (1);
	}
	
	game->map->x = 512;
	game->map->y = 512;
	return (0);
}

int	main(void)
{
	t_game	game;

	if (start_game(&game) == 1)
		return (1);
	
	/* reading map and printing full map in terminal*/
	//int fd = open_map("maps/map.ber");
	//create_map("maps/map.ber", &game);
	//int map_size = read_map(fd);

	//if (game.map->map)
    //{
    //    for (int i = 0; i < map_size; i++)
    //        printf("string %d: %s\n", i, game.map->map[i]);
    //}

	mlx_string_put(game.mlx, game.win, game.map->x, game.map->y, 0xFFFFFF, "PACMAN");
	mlx_hook(game.win, 17, 1L << 2, ft_exit, &game);
	mlx_key_hook(game.win, ft_hotkey, &game);
	mlx_loop(game.mlx);
	return (0);
}
