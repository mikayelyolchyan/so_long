#include "../includes/headers/so_long.h"

void render_power_up_dots(t_game *game)
{
	int index = (game->power_up_img_delay / 1024) % game->map->power_up_dots_count;
	int x = game->map->power_up_dots_array[index].x;
	int y = game->map->power_up_dots_array[index].y;
	int map_x = x / game->map->tile_size;
	int map_y = y / game->map->tile_size;
	
	if (game->power_up_img_delay >= 4096 && game->power_up_img_delay < 8192)
	{
	    if (game->map->map[map_y][map_x] == 'U')
	    {
	        mlx_put_image_to_window(game->mlx, game->win, game->map->power_up_img, x, y);
	    }
	}
	else if (game->power_up_img_delay >= 8192)
	{
	    if (game->map->map[map_y][map_x] == 'U')
	    {
	        mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, x, y);
	    }
	    if (game->power_up_img_delay >= 16384)
	    {
	        game->power_up_img_delay = 0;
	    }
	}
}

void display_score(t_game *game, t_font *font, void *mlx, void *win)
{
    int x = 1 * 32;
    int digit;
    int i = 0;
    game->score_str = ft_itoa(game->score);
    while (game->score_str[i] != '\0')
    {
        digit = game->score_str[i] - '0';
        if (digit == 0)
            mlx_put_image_to_window(mlx, win, font->zero, x, (game->map->height) * 32 + 8);
        else if (digit == 1)
            mlx_put_image_to_window(mlx, win, font->one, x, (game->map->height) * 32 + 8);
        else if (digit == 2)
            mlx_put_image_to_window(mlx, win, font->two, x, (game->map->height) * 32 + 8);
        else if (digit == 3)
            mlx_put_image_to_window(mlx, win, font->three, x, (game->map->height) * 32 + 8);
        else if (digit == 4)
            mlx_put_image_to_window(mlx, win, font->four, x, (game->map->height) * 32 + 8);
        else if (digit == 5)
            mlx_put_image_to_window(mlx, win, font->five, x, (game->map->height) * 32 + 8);
        else if (digit == 6)
            mlx_put_image_to_window(mlx, win, font->six, x, (game->map->height) * 32 + 8);
        else if (digit == 7)
            mlx_put_image_to_window(mlx, win, font->seven, x, (game->map->height) * 32 + 8);
        else if (digit == 8)
            mlx_put_image_to_window(mlx, win, font->eight, x, (game->map->height) * 32 + 8);
        else if (digit == 9)
            mlx_put_image_to_window(mlx, win, font->nine, x, (game->map->height) * 32 + 8);
        x += 16; 
        i++;
    }
    free(game->score_str);
}

void	handle_all_animation_timings(t_game *game)
{
	game->frame_delay++;
	game->ghost_attack_mode_delay++;
	game->power_up_img_delay++;
	if (game->frame_delay >= 512)
	{
		game->frame = (game->frame + 1) % 4;
		game->frame_delay = 0;
		update_pac_direction(game);
		red_ghost_moving(game);
		orange_ghost_moving(game);
		magenta_ghost_moving(game);
		blue_ghost_moving(game);
		if (game->pac_attack_mode == 1)
		{
			pac_fast_moving(game);
			game->pac_attack_mode_delay++;
			if (game->pac_attack_mode_delay >= 192)
			{
				game->pac_attack_mode = 0;
				game->pac_attack_mode_delay = 0;
			}
		}
		else
			pac_moving(game);
		if (game->ghost_attack_mode_delay >= 1048576)
			game->ghost_attack_mode_delay = 0;
		render_power_up_dots(game);
		
		display_score(game, game->font, game->mlx, game->win);
	}
}

int	game_animation(t_game *game)
{
	void		*pac_current_img;
	void		*red_ghost_current_img;
	void		*orange_ghost_current_img;
	void		*magenta_ghost_current_img;
	void		*blue_ghost_current_img;

	handle_all_animation_timings(game);
	pac_current_img = get_pac_current_img(game, game->player);
	red_ghost_current_img = get_red_ghost_current_img(game, game->r_ghost);
	orange_ghost_current_img = get_orange_ghost_current_img(game, game->o_ghost);
	magenta_ghost_current_img = get_magenta_ghost_current_img(game, game->m_ghost);
	blue_ghost_current_img = get_blue_ghost_current_img(game, game->b_ghost);
	
	update_map(game, game->map->map, game->r_ghost->direction);

	mlx_put_image_to_window(game->mlx, game->win, pac_current_img, game->player->x, game->player->y);
	mlx_put_image_to_window(game->mlx, game->win, red_ghost_current_img, game->r_ghost->x, game->r_ghost->y);
	mlx_put_image_to_window(game->mlx, game->win, orange_ghost_current_img, game->o_ghost->x, game->o_ghost->y);
	mlx_put_image_to_window(game->mlx, game->win, magenta_ghost_current_img, game->m_ghost->x, game->m_ghost->y);
	mlx_put_image_to_window(game->mlx, game->win, blue_ghost_current_img, game->b_ghost->x, game->b_ghost->y);
	return (0);
}
