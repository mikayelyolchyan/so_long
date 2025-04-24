#include "../../includes/headers/so_long.h"

void red_ghost_direction(t_game *game)
{
    int dist_up = INT_MAX;
    int dist_left = INT_MAX;
    int dist_down = INT_MAX;
    int dist_right = INT_MAX;
    char **map = game->map->map;
    int current = game->r_ghost->direction;

    // Проверка на "съедение" призрака
   	if (game->pac_attack_mode == 1 &&
		(game->player->x - game->r_ghost->x <= 16 && game->player->x - game->r_ghost->x >= -16) &&
    	(game->player->y - game->r_ghost->y <= 16 && game->player->y - game->r_ghost->y >= -16) &&
    	game->r_ghost->is_eaten == 0 && game->r_ghost->is_respawned == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->map->black_wall_img, game->r_ghost->x, game->r_ghost->y);
		game->r_ghost->is_eaten = 1;
		game->game_start_delay = GHOST_EATEN_FREEZE;
		game->game_start = 0;
		game->r_ghost->targ_x = game->r_ghost->start_x;
		game->r_ghost->targ_y = game->r_ghost->start_y;

		game->r_ghost->remainder_x = game->r_ghost->x % 32;
        game->r_ghost->remainder_y = game->r_ghost->y % 32;

        if (game->r_ghost->remainder_x != 0)
        {
            if (game->r_ghost->remainder_x < 16)
                game->r_ghost->x -= game->r_ghost->remainder_x;
            else
                game->r_ghost->x += (32 - game->r_ghost->remainder_x);
        }
        if (game->r_ghost->remainder_y != 0)
        {
            if (game->r_ghost->remainder_y < 16)
                game->r_ghost->y -= game->r_ghost->remainder_y;
            else
                game->r_ghost->y += (32 - game->r_ghost->remainder_y);
        }
	}

	// Проверка на "съедение" пакмана
	if (game->pac_attack_mode == 0 &&
		(game->player->x - game->r_ghost->x <= 16 && game->player->x - game->r_ghost->x >= -16) &&
    	(game->player->y - game->r_ghost->y <= 16 && game->player->y - game->r_ghost->y >= -16) &&
    	game->r_ghost->is_eaten == 0 && game->r_ghost->is_respawned == 0)
	{
		game->game_restart = 1;
		game->player->died_count++;
		draw_map(game);
	}

	if (game->pac_attack_mode == 1 &&
		(game->player->x - game->r_ghost->x <= 16 && game->player->x - game->r_ghost->x >= -16) &&
    	(game->player->y - game->r_ghost->y <= 16 && game->player->y - game->r_ghost->y >= -16) &&
    	game->r_ghost->is_respawned == 1) // && game-r_ghost->is_eaten == 0)
	{
		game->game_restart = 1;
		game->player->died_count++;
		draw_map(game);
	}

    if (game->ghost_attack_mode_delay >= GHOST_NEUTRAL_LIMIT \
		&& game->pac_attack_mode == 0)
        game->ghost_attack_mode = 1;
    else if (game->ghost_attack_mode_delay <= GHOST_ATTACK_LIMIT \
		&& game->pac_attack_mode == 0)
        game->ghost_attack_mode = 0;

    // Установка цели для нормального режима
    if (!game->r_ghost->is_eaten)
    {
        if (game->ghost_attack_mode == 1 && game->pac_attack_mode == 0)
        {
            game->r_ghost->targ_x = game->player->x;
            game->r_ghost->targ_y = game->player->y;
        }
        else if (game->ghost_attack_mode == 0 && game->pac_attack_mode == 0)
        {
            game->r_ghost->targ_x = game->map->width * 32;
            game->r_ghost->targ_y = 0;
        }
    }

    // Логика движения в зависимости от состояния
    if (game->r_ghost->is_eaten)
    {
        game->r_ghost->is_respawned = 0;
        if (current != DOWN && map[(game->r_ghost->y - 32) / 32][game->r_ghost->x / 32] != '1')
            dist_up = distance_calculator(game->r_ghost->x, game->r_ghost->start_x, game->r_ghost->y - 32, game->r_ghost->start_y);
        if (current != RIGHT && map[game->r_ghost->y / 32][(game->r_ghost->x - 32) / 32] != '1')
            dist_left = distance_calculator(game->r_ghost->x - 32, game->r_ghost->start_x, game->r_ghost->y, game->r_ghost->start_y);
        if (current != UP && map[(game->r_ghost->y + 32) / 32][game->r_ghost->x / 32] != '1')
            dist_down = distance_calculator(game->r_ghost->x, game->r_ghost->start_x, game->r_ghost->y + 32, game->r_ghost->start_y);
        if (current != LEFT && map[game->r_ghost->y / 32][(game->r_ghost->x + 32) / 32] != '1')
            dist_right = distance_calculator(game->r_ghost->x + 32, game->r_ghost->start_x, game->r_ghost->y, game->r_ghost->start_y);

        int min_dist = INT_MAX;
        game->r_ghost->pending_direction = UP;

        if (dist_up < min_dist)
		{
            min_dist = dist_up;
            game->r_ghost->pending_direction = UP;
        }
        if (dist_left < min_dist)
		{
            min_dist = dist_left;
            game->r_ghost->pending_direction = LEFT;
        }
        if (dist_down < min_dist)
		{
            min_dist = dist_down;
            game->r_ghost->pending_direction = DOWN;
        }
        if (dist_right < min_dist)
		{
            min_dist = dist_right;
            game->r_ghost->pending_direction = RIGHT;
        }

        if (game->r_ghost->x == game->r_ghost->start_x && 
            game->r_ghost->y == game->r_ghost->start_y)
        {
            game->r_ghost->is_eaten = 0;
            game->r_ghost->is_respawned = 1;
            game->r_ghost->targ_x = game->player->x;
            game->r_ghost->targ_y = game->player->y;
        }
    }
    else if (game->pac_attack_mode == 1)
    {
        // Сбрасываем is_respawned при активации pac_attack_mode
        if (game->last_pac_attack_mode == 0 && game->pac_attack_mode == 1)
            game->r_ghost->is_respawned = 0;

        if (current != DOWN && map[(game->r_ghost->y - 32) / 32][game->r_ghost->x / 32] != '1')
            dist_up = distance_calculator(game->r_ghost->x, game->r_ghost->targ_x, game->r_ghost->y - 32, game->r_ghost->targ_y);
        if (current != RIGHT && map[game->r_ghost->y / 32][(game->r_ghost->x - 32) / 32] != '1')
            dist_left = distance_calculator(game->r_ghost->x - 32, game->r_ghost->targ_x, game->r_ghost->y, game->r_ghost->targ_y);
        if (current != UP && map[(game->r_ghost->y + 32) / 32][game->r_ghost->x / 32] != '1')
            dist_down = distance_calculator(game->r_ghost->x, game->r_ghost->targ_x, game->r_ghost->y + 32, game->r_ghost->targ_y);
        if (current != LEFT && map[game->r_ghost->y / 32][(game->r_ghost->x + 32) / 32] != '1')
            dist_right = distance_calculator(game->r_ghost->x + 32, game->r_ghost->targ_x, game->r_ghost->y, game->r_ghost->targ_y);

        int max_dist = -1;
        game->r_ghost->pending_direction = UP;

        if (dist_up != INT_MAX && dist_up > max_dist)
        {
            max_dist = dist_up;
            game->r_ghost->pending_direction = UP;
        }
        if (dist_left != INT_MAX && dist_left > max_dist)
        {
            max_dist = dist_left;
            game->r_ghost->pending_direction = LEFT;
        }
        if (dist_down != INT_MAX && dist_down > max_dist)
        {
            max_dist = dist_down;
            game->r_ghost->pending_direction = DOWN;
        }
        if (dist_right != INT_MAX && dist_right > max_dist)
        {
            max_dist = dist_right;
            game->r_ghost->pending_direction = RIGHT;
        }
    }
    else
    {
        if (current != DOWN && map[(game->r_ghost->y - 32) / 32][game->r_ghost->x / 32] != '1')
            dist_up = distance_calculator(game->r_ghost->x, game->r_ghost->targ_x, game->r_ghost->y - 32, game->r_ghost->targ_y);
        if (current != RIGHT && map[game->r_ghost->y / 32][(game->r_ghost->x - 32) / 32] != '1')
            dist_left = distance_calculator(game->r_ghost->x - 32, game->r_ghost->targ_x, game->r_ghost->y, game->r_ghost->targ_y);
        if (current != UP && map[(game->r_ghost->y + 32) / 32][game->r_ghost->x / 32] != '1')
            dist_down = distance_calculator(game->r_ghost->x, game->r_ghost->targ_x, game->r_ghost->y + 32, game->r_ghost->targ_y);
        if (current != LEFT && map[game->r_ghost->y / 32][(game->r_ghost->x + 32) / 32] != '1')
            dist_right = distance_calculator(game->r_ghost->x + 32, game->r_ghost->targ_x, game->r_ghost->y, game->r_ghost->targ_y);

        int min_dist = INT_MAX;
        game->r_ghost->pending_direction = UP;

        if (dist_up < min_dist)
        {
            min_dist = dist_up;
            game->r_ghost->pending_direction = UP;
        }
        if (dist_left < min_dist)
        {
            min_dist = dist_left;
            game->r_ghost->pending_direction = LEFT;
        }
        if (dist_down < min_dist)
        {
            min_dist = dist_down;
            game->r_ghost->pending_direction = DOWN;
        }
        if (dist_right < min_dist)
        {
            min_dist = dist_right;
            game->r_ghost->pending_direction = RIGHT;
        }

        // Сбрасываем is_respawned после первого шага от точки спавна
        if (game->r_ghost->is_respawned == 1 && 
            (game->r_ghost->x != game->r_ghost->start_x || game->r_ghost->y != game->r_ghost->start_y))
            game->r_ghost->is_respawned = 0;
    }

    game->last_pac_attack_mode = game->pac_attack_mode;
}

void red_ghost_moving(t_game *game)
{
    char **map = game->map->map;
    red_ghost_direction(game);

    // Проверка столкновения с учётом скорости
    if ((game->r_ghost->x % 32 == 0 && game->r_ghost->y % 32 == 0) || 
        (game->r_ghost->direction == UP && map[(game->r_ghost->y - (game->r_ghost->is_eaten ? 8 : 4)) / 32][game->r_ghost->x / 32] == '1') ||
        (game->r_ghost->direction == DOWN && map[(game->r_ghost->y + (game->r_ghost->is_eaten ? 8 : 4)) / 32 + 1][game->r_ghost->x / 32] == '1') ||
        (game->r_ghost->direction == LEFT && map[game->r_ghost->y / 32][(game->r_ghost->x - (game->r_ghost->is_eaten ? 8 : 4)) / 32] == '1') ||
        (game->r_ghost->direction == RIGHT && map[game->r_ghost->y / 32][(game->r_ghost->x + (game->r_ghost->is_eaten ? 8 : 4)) / 32 + 1] == '1'))
    {
        if (game->r_ghost->is_eaten == 0 &&
            (can_move_vertical(game->r_ghost, map, game->r_ghost->pending_direction) || 
             can_move_horizontal(game->r_ghost, map, game->r_ghost->pending_direction)))
        {
            game->r_ghost->direction = game->r_ghost->pending_direction;
        }
        else if (game->r_ghost->is_eaten == 1 && 
                 (can_move_fast_vertical(game->r_ghost, map, game->r_ghost->pending_direction) || 
                  can_move_fast_horizontal(game->r_ghost, map, game->r_ghost->pending_direction)))
        {
            game->r_ghost->direction = game->r_ghost->pending_direction;
        }

        // Логика разворота при тупике
        if (game->r_ghost->direction == RIGHT &&
            map[game->r_ghost->y / 32][(game->r_ghost->x + 32) / 32] == '1' && 
            map[(game->r_ghost->y + 32) / 32][(game->r_ghost->x) / 32] == '1' && 
            map[(game->r_ghost->y - 32) / 32][(game->r_ghost->x) / 32] == '1')
            game->r_ghost->direction = LEFT;
        else if (game->r_ghost->direction == LEFT && 
                 map[game->r_ghost->y / 32][(game->r_ghost->x - 32) / 32] == '1' && 
                 map[(game->r_ghost->y + 32) / 32][(game->r_ghost->x) / 32] == '1' && 
                 map[(game->r_ghost->y - 32) / 32][(game->r_ghost->x) / 32] == '1')
            game->r_ghost->direction = RIGHT;
        else if (game->r_ghost->direction == UP && 
                 map[game->r_ghost->y / 32][(game->r_ghost->x + 32) / 32] == '1' && 
                 map[game->r_ghost->y / 32][(game->r_ghost->x - 32) / 32] == '1' && 
                 map[(game->r_ghost->y - 32) / 32][(game->r_ghost->x) / 32] == '1')
            game->r_ghost->direction = DOWN;
        else if (game->r_ghost->direction == DOWN && 
                 map[game->r_ghost->y / 32][(game->r_ghost->x + 32) / 32] == '1' && 
                 map[game->r_ghost->y / 32][(game->r_ghost->x - 32) / 32] == '1' && 
                 map[(game->r_ghost->y + 32) / 32][(game->r_ghost->x) / 32] == '1')
            game->r_ghost->direction = UP;

        game->r_ghost->prev_x = game->r_ghost->x;
        game->r_ghost->prev_y = game->r_ghost->y;
    }

    if (game->r_ghost->is_eaten == 0)
    {
        if (game->r_ghost->direction == UP)
            game->r_ghost->y -= 4;
        else if (game->r_ghost->direction == DOWN)
            game->r_ghost->y += 4;
        else if (game->r_ghost->direction == LEFT)
        {
            game->r_ghost->x -= 4;
            if (game->r_ghost->x % 32 == 0 && \
				map[game->r_ghost->y / 32][(game->r_ghost->x - 32) / 32] == 'T')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->x, game->r_ghost->y);
                handle_ghost_portal(game, game->r_ghost, 1);
            }
        }
        else if (game->r_ghost->direction == RIGHT)
        {
            game->r_ghost->x += 4;
            if (game->r_ghost->x % 32 == 0 && \
				map[game->r_ghost->y / 32][(game->r_ghost->x + 32) / 32] == 'T')
            {
            	mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->x, game->r_ghost->y);
            	handle_ghost_portal(game, game->r_ghost, 0);
            }
        }
    }
    else if (game->r_ghost->is_eaten == 1)
    {
        if (game->r_ghost->direction == UP)
            game->r_ghost->y -= 16;
        else if (game->r_ghost->direction == DOWN)
            game->r_ghost->y += 16;
        else if (game->r_ghost->direction == LEFT)
        {
            game->r_ghost->x -= 16;
            if (map[game->r_ghost->y / 32][(game->r_ghost->x - 32) / 32] == 'T')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->x, game->r_ghost->y);
               	handle_ghost_portal(game, game->r_ghost, 1);
            }
        }
        else if (game->r_ghost->direction == RIGHT)
        {   
            game->r_ghost->x += 16;
            if (map[game->r_ghost->y / 32][(game->r_ghost->x + 32) / 32] == 'T')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->x, game->r_ghost->y);
                handle_ghost_portal(game, game->r_ghost, 0);
            }
        }
    }
}