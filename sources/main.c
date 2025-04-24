#include "../includes/headers/so_long.h"

int start_game(t_game *game, char *argv)
{
    t_map *map;

    game->map = malloc(sizeof(t_map));
    if (!game->map)
    {
        ft_printf("Error: t_map memory allocation failed\n");
        return (1);
    }
    map = game->map;
	map->ghost_count = 0;
    map->map = NULL;
    if (!validate_map(argv, map))
    {
        free(map);
        ft_printf("Error: Invalid map\n");
        return (1);
    }
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        free_map(map);
        free(map);
        ft_printf("MiniLibX initialization Error\n");
        return (1);
    }
    map->tile_size = 32;
    game->win = mlx_new_window(game->mlx, map->width * map->tile_size, map->height * map->tile_size + 32, "PACMAN");
    if (!game->win)
    {
        free_map(map);
        free(map);
        ft_printf("Window creating Error\n");
        return (1);
    }
	map_initialization(game, map);
    if (!map->wall_img || !map->black_wall_img || !map->food_img || !map->portal_img || !map->logo_img || !map->power_up_img)
    {
        free_map(map);
        free(map);
        ft_printf("Error: Failed to load Map xpm`s\n");
        return (1);
    }
    game->player = malloc(sizeof(t_player));
    if (!game->player)
    {
        free_map(map);
        free(map);
        ft_printf("Error: t_player memory allocation failed\n");
        return (1);
    }
	if (map->ghost_count == 4)
	{
   		game->r_ghost = malloc(sizeof(t_ghost));
		game->o_ghost = malloc(sizeof(t_ghost));
    	game->m_ghost = malloc(sizeof(t_ghost));
    	game->b_ghost = malloc(sizeof(t_ghost));
    	if (!game->r_ghost || !game->o_ghost || !game->m_ghost || !game->b_ghost)
    	{
    		free(game->player);
    		free_map(map);
    		free(map);
    		ft_printf("Error: t_ghost memory allocation failed\n");
    		return (1);
    	}
	}
    game->map->dots_count = 0;
    game->map->power_up_dots_count = 0;
    count_sprites(game);
    game->map->power_up_dots_array = malloc((sizeof(t_power_up_dot) * game->map->power_up_dots_count));
    if (!game->map->power_up_dots_array)
    {
        free(game->player);
        free(game->r_ghost);
        free(game->o_ghost);
        free(game->m_ghost);
        free(game->b_ghost);
        free_map(map);
        free(map);
        ft_printf("Error: power_up_dots_array memory allocation failed\n");
        return (1);
    }
    find_positions(game);
    pacman_initializations(game, map);
	if (map->ghost_count == 4)
	{
    	red_ghost_initialization(game, map);
    	orange_ghost_initialization(game, map);
    	magenta_ghost_initialization(game, map);
    	blue_ghost_initialization(game, map);
	}
    game->font = malloc(sizeof(t_font));
    if (!game->font)
    {
        free(game->map->power_up_dots_array);
        free(game->player);
        free(game->r_ghost);
        free(game->o_ghost);
        free(game->m_ghost);
        free(game->b_ghost);
        free_map(map);
        free(map);
        ft_printf("Error: t_font memory allocation failed\n");
        return (1);
    }
    font_initialization(game);
    game->frame = 0;
    game->frame_delay = 0;
    game->ghost_attack_mode = 0;
    game->power_up_img_delay = 0;
    game->pac_attack_mode = 0;
    game->last_pac_attack_mode = 0;
    game->pac_attack_mode_delay = 0;
    game->score = 0;
    game->eated_dots = 0;
    game->game_start = 0;
    game->game_start_delay = 0;
    game->game_win = 0;
    game->map_flashing_frame = 0;
    game->map_flashing_delay = 0;
    game->map_flashing_count = 0;
    game->game_restart = 0;
    map->x = 0;
    map->y = 0;
    return (0);
}

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
