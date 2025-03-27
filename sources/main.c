#include "../includes/headers/so_long.h"

int	start_game(t_game *game)
{
	t_map *map;

	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		ft_printf("Error: t_map memory allocation failed\n");
		return (1);
	}
	map = game->map;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("MiniLibX initialization Error\n");
		return (1);
	}
	map->tile_size = 32;
	create_map("maps/google.ber", game);
	game->win = mlx_new_window(game->mlx, map->width * map->tile_size, map->height * map->tile_size, "PACMAN");
	if (!game->win)
	{
		ft_printf("Window creating Error\n");
		return (1);
	}
	map->wall_img = mlx_xpm_file_to_image(game->mlx, "sprites/Walls/wall.xpm", &map->tile_size, &map->tile_size);
	if (!map->wall_img)
	{
		ft_printf("Error: Failed to load walls.xpm\n");
		return (1);
	}
	map->x = map->width * map->tile_size / 2;
	map->y = map->height * map->tile_size / 2;
	return (0);
}

int	main(void)
{
	t_game	game;

	if (start_game(&game) == 1)
		return (1);

	draw_map(&game);	
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
	mlx_key_hook(game.win, &ft_hotkey, &game);
	mlx_loop(game.mlx);
	return (0);
}
