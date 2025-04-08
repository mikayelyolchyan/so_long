#include "../includes/headers/so_long.h"

void render_power_up_dots(t_game *game)
{
	int index = (game->power_up_img_delay / 1024) % game->map->power_up_dots_count;
	int x = game->map->power_up_dots_array[index].x;
	int y = game->map->power_up_dots_array[index].y;
	int map_x = x / game->map->tile_size;
	int map_y = y / game->map->tile_size;

	printf("game->power_up_img_delay = %d\n", game->power_up_img_delay / 512);

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
	//printf("%llu\n", game->attack_mode_delay);
	if (game->frame_delay >= 1024)
	{
		game->frame = (game->frame + 1) % 4;
		game->frame_delay = 0;
		update_direction(game);
		ghost_moving(game);

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

void *get_ghost_current_img(t_game *game, t_ghost *r_ghost)
{
    void *current_img;

    // Если призрак "съеден" и движется к спавну
    if (r_ghost->is_eaten == 1)
    {
        current_img = game->r_ghost->ghost_is_eaten; // Изображение глаз
    }
    // После респавна (is_eaten == 0) призрак возвращается к нормальному виду
    //else if (game->pac_attack_mode == 0 && r_ghost->is_eaten == 0)
    //{
    //    // Независимо от pac_attack_mode, после респавна он нормальный
    //    if (r_ghost->direction == LEFT || r_ghost->direction == RIGHT)
    //    {
    //        current_img = get_ghost_horizontal_animation(game, r_ghost);
    //    }
    //    else if (r_ghost->direction == UP || r_ghost->direction == DOWN)
    //    {
    //        current_img = get_ghost_vertical_animation(game, r_ghost);
    //    }
    //}
    // Режим паники применяется только к несъеденным призракам при pac_attack_mode == 1
    else if (game->pac_attack_mode == 1 && r_ghost->is_eaten == 0 && r_ghost->is_respawned == 0)
    {
        if (r_ghost->direction == LEFT || r_ghost->direction == RIGHT)
        {
            if (game->pac_attack_mode_delay <= 128)
                current_img = get_ghost_panic_horizontal_animation(game, r_ghost);
            else
                current_img = get_ghost_panic_flashing_horizontal_animation(game, r_ghost);
        }
        else if (r_ghost->direction == UP || r_ghost->direction == DOWN)
        {
            if (game->pac_attack_mode_delay <= 128)
                current_img = get_ghost_panic_vertical_animation(game, r_ghost);
            else
                current_img = get_ghost_panic_flashing_vertical_animation(game, r_ghost);
        }
    }
    // По умолчанию (на всякий случай)
    else
    {
		if (r_ghost->direction == LEFT || r_ghost->direction == RIGHT)
        {
            current_img = get_ghost_horizontal_animation(game, r_ghost);
        }
		else if (r_ghost->direction == UP || r_ghost->direction == DOWN)
        {
            current_img = get_ghost_vertical_animation(game, r_ghost);
        }
    }

    return (current_img);
}

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

int	game_animation(t_game *game)
{
	t_player	*player;
	t_ghost		*r_ghost;
	void		*pac_current_img;
	void		*ghost_current_img;

	player = game->player;
	r_ghost = game->r_ghost;

	handle_all_animation_timings(game);

	pac_current_img = get_pac_current_img(game, player);
	ghost_current_img = get_ghost_current_img(game, r_ghost);

	update_map(game, game->map->map, game->r_ghost->direction);
	mlx_put_image_to_window(game->mlx, game->win, pac_current_img, game->player->x, game->player->y);
	mlx_put_image_to_window(game->mlx, game->win, ghost_current_img, game->r_ghost->x, game->r_ghost->y);
	return (0);
}
