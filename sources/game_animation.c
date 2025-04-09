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

void	handle_all_animation_timings(t_game *game)
{
	game->frame_delay++;
	game->ghost_attack_mode_delay++;
	game->power_up_img_delay++;
	if (game->frame_delay >= 768)
	{
		game->frame = (game->frame + 1) % 4;
		game->frame_delay = 0;
		update_pac_direction(game);
		red_ghost_moving(game);
		orange_ghost_moving(game);
		magenta_ghost_moving(game);
		
		if (game->pac_attack_mode == 1)
		{
			pac_fast_moving(game);
			game->pac_attack_mode_delay++;
			if (game->pac_attack_mode_delay >= 256)
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
	}
}

int	game_animation(t_game *game)
{
	void		*pac_current_img;
	void		*red_ghost_current_img;
	void		*orange_ghost_current_img;
	void		*magenta_ghost_current_img;

	handle_all_animation_timings(game);

	pac_current_img = get_pac_current_img(game, game->player);
	red_ghost_current_img = get_red_ghost_current_img(game, game->r_ghost);
	orange_ghost_current_img = get_orange_ghost_current_img(game, game->o_ghost);
	magenta_ghost_current_img = get_magenta_ghost_current_img(game, game->m_ghost);

	update_map(game, game->map->map, game->r_ghost->direction);
	mlx_put_image_to_window(game->mlx, game->win, pac_current_img, game->player->x, game->player->y);
	mlx_put_image_to_window(game->mlx, game->win, red_ghost_current_img, game->r_ghost->x, game->r_ghost->y);
	mlx_put_image_to_window(game->mlx, game->win, orange_ghost_current_img, game->o_ghost->x, game->o_ghost->y);
	mlx_put_image_to_window(game->mlx, game->win, magenta_ghost_current_img, game->m_ghost->x, game->m_ghost->y);
	return (0);
}
