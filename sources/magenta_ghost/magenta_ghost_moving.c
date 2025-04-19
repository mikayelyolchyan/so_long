#include "../../includes/headers/so_long.h"

void magenta_ghost_direction(t_game *game)
{
    int dist_up = INT_MAX;
    int dist_left = INT_MAX;
    int dist_down = INT_MAX;
    int dist_right = INT_MAX;
    char **map = game->map->map;
    int current = game->m_ghost->direction;

    // Проверка на "съедение" призрака
    if (game->pac_attack_mode == 1 &&
        (game->player->x - game->m_ghost->x <= 16 && game->player->x - game->m_ghost->x >= -16) &&
        (game->player->y - game->m_ghost->y <= 16 && game->player->y - game->m_ghost->y >= -16) &&
        game->m_ghost->is_eaten == 0 && game->m_ghost->is_respawned == 0)
    {
        game->m_ghost->is_eaten = 1;
		game->game_start_delay = 25000;
		game->game_start = 0;
        game->m_ghost->targ_x = game->m_ghost->start_x;
        game->m_ghost->targ_y = game->m_ghost->start_y;

        game->m_ghost->remainder_x = game->m_ghost->x % 32;
        game->m_ghost->remainder_y = game->m_ghost->y % 32;

        if (game->m_ghost->remainder_x != 0)
        {
            if (game->m_ghost->remainder_x < 16)
                game->m_ghost->x -= game->m_ghost->remainder_x; // Округляем вниз
            else
                game->m_ghost->x += (32 - game->m_ghost->remainder_x); // Округляем вверх
        }
        if (game->m_ghost->remainder_y != 0)
        {
            if (game->m_ghost->remainder_y < 16)
                game->m_ghost->y -= game->m_ghost->remainder_y; // Округляем вниз
            else
                game->m_ghost->y += (32 - game->m_ghost->remainder_y); // Округляем вверх
        }
    }

	if (game->pac_attack_mode == 0 &&
		(game->player->x - game->m_ghost->x <= 16 && game->player->x - game->m_ghost->x >= -16) &&
    	(game->player->y - game->m_ghost->y <= 16 && game->player->y - game->m_ghost->y >= -16) &&
    	game->m_ghost->is_eaten == 0 && game->m_ghost->is_respawned == 0)
	{
		//printf("game->game_restart = 1;\n");
		game->game_restart = 1;
		game->player->died_count++;
		draw_map(game);
	}

    // Логика режимов атаки
    if (game->ghost_attack_mode_delay >= 262144 && game->pac_attack_mode == 0)
        game->ghost_attack_mode = 1;
    else if (game->ghost_attack_mode_delay <= 262144 && game->pac_attack_mode == 0)
        game->ghost_attack_mode = 0;

    // Установка цели для нормального режима
    if (!game->m_ghost->is_eaten)
    {
        if (game->ghost_attack_mode == 1 && game->pac_attack_mode == 0)
        {
            // Розовый призрак целится на 4 клетки впереди Пакмана в зависимости от его направления
            if (game->player->direction == RIGHT)
            {
                game->m_ghost->targ_x = game->player->x + 128; // 4 клетки вправо (4 * 32)
                game->m_ghost->targ_y = game->player->y;
            }
            else if (game->player->direction == LEFT)
            {
                game->m_ghost->targ_x = game->player->x - 128; // 4 клетки влево
                game->m_ghost->targ_y = game->player->y;
            }
            else if (game->player->direction == DOWN)
            {
                game->m_ghost->targ_x = game->player->x;
                game->m_ghost->targ_y = game->player->y + 128; // 4 клетки вниз
            }
            else if (game->player->direction == UP)
            {
                game->m_ghost->targ_x = game->player->x - 128; // 4 клетки влево
                game->m_ghost->targ_y = game->player->y - 128; // 4 клетки вверх
            }
        }
        else if (game->ghost_attack_mode == 0 && game->pac_attack_mode == 0)
        {
            // Розовый призрак идет в левый верхний угол (0, 0)
            game->m_ghost->targ_x = 0;
            game->m_ghost->targ_y = 0;
        }
    }

    // Остальная логика движения остается без изменений
    if (game->m_ghost->is_eaten)
    {
        game->m_ghost->is_respawned = 0;
        if (current != DOWN && map[(game->m_ghost->y - 32) / 32][game->m_ghost->x / 32] != '1')
            dist_up = distance_calculator(game->m_ghost->x, game->m_ghost->start_x, game->m_ghost->y - 32, game->m_ghost->start_y);
        if (current != RIGHT && map[game->m_ghost->y / 32][(game->m_ghost->x - 32) / 32] != '1')
            dist_left = distance_calculator(game->m_ghost->x - 32, game->m_ghost->start_x, game->m_ghost->y, game->m_ghost->start_y);
        if (current != UP && map[(game->m_ghost->y + 32) / 32][game->m_ghost->x / 32] != '1')
            dist_down = distance_calculator(game->m_ghost->x, game->m_ghost->start_x, game->m_ghost->y + 32, game->m_ghost->start_y);
        if (current != LEFT && map[game->m_ghost->y / 32][(game->m_ghost->x + 32) / 32] != '1')
            dist_right = distance_calculator(game->m_ghost->x + 32, game->m_ghost->start_x, game->m_ghost->y, game->m_ghost->start_y);

        int min_dist = INT_MAX;
        game->m_ghost->pending_direction = UP;

        if (dist_up < min_dist)
        {
            min_dist = dist_up;
            game->m_ghost->pending_direction = UP;
        }
        if (dist_left < min_dist)
        {
            min_dist = dist_left;
            game->m_ghost->pending_direction = LEFT;
        }
        if (dist_down < min_dist)
        {
            min_dist = dist_down;
            game->m_ghost->pending_direction = DOWN;
        }
        if (dist_right < min_dist)
        {
            min_dist = dist_right;
            game->m_ghost->pending_direction = RIGHT;
        }

        if (game->m_ghost->x == game->m_ghost->start_x && 
            game->m_ghost->y == game->m_ghost->start_y)
        {
            game->m_ghost->is_eaten = 0;
            game->m_ghost->is_respawned = 1;
            // После респавна сразу устанавливаем цель в зависимости от направления Пакмана
            if (game->player->direction == RIGHT)
            {
                game->m_ghost->targ_x = game->player->x + 128;
                game->m_ghost->targ_y = game->player->y;
            }
            else if (game->player->direction == LEFT)
            {
                game->m_ghost->targ_x = game->player->x - 128;
                game->m_ghost->targ_y = game->player->y;
            }
            else if (game->player->direction == DOWN)
            {
                game->m_ghost->targ_x = game->player->x;
                game->m_ghost->targ_y = game->player->y + 128;
            }
            else if (game->player->direction == UP)
            {
                game->m_ghost->targ_x = game->player->x - 128;
                game->m_ghost->targ_y = game->player->y - 128;
            }
        }
    }
    else if (game->pac_attack_mode == 1)
    {
        if (game->last_pac_attack_mode == 0 && game->pac_attack_mode == 1)
            game->m_ghost->is_respawned = 0;

        if (current != DOWN && map[(game->m_ghost->y - 32) / 32][game->m_ghost->x / 32] != '1')
            dist_up = distance_calculator(game->m_ghost->x, game->m_ghost->targ_x, game->m_ghost->y - 32, game->m_ghost->targ_y);
        if (current != RIGHT && map[game->m_ghost->y / 32][(game->m_ghost->x - 32) / 32] != '1')
            dist_left = distance_calculator(game->m_ghost->x - 32, game->m_ghost->targ_x, game->m_ghost->y, game->m_ghost->targ_y);
        if (current != UP && map[(game->m_ghost->y + 32) / 32][game->m_ghost->x / 32] != '1')
            dist_down = distance_calculator(game->m_ghost->x, game->m_ghost->targ_x, game->m_ghost->y + 32, game->m_ghost->targ_y);
        if (current != LEFT && map[game->m_ghost->y / 32][(game->m_ghost->x + 32) / 32] != '1')
            dist_right = distance_calculator(game->m_ghost->x + 32, game->m_ghost->targ_x, game->m_ghost->y, game->m_ghost->targ_y);

        int max_dist = -1;
        game->m_ghost->pending_direction = UP;

        if (dist_up != INT_MAX && dist_up > max_dist)
        {
            max_dist = dist_up;
            game->m_ghost->pending_direction = UP;
        }
        if (dist_left != INT_MAX && dist_left > max_dist)
        {
            max_dist = dist_left;
            game->m_ghost->pending_direction = LEFT;
        }
        if (dist_down != INT_MAX && dist_down > max_dist)
        {
            max_dist = dist_down;
            game->m_ghost->pending_direction = DOWN;
        }
        if (dist_right != INT_MAX && dist_right > max_dist)
        {
            max_dist = dist_right;
            game->m_ghost->pending_direction = RIGHT;
        }
    }
    else
    {
        if (current != DOWN && map[(game->m_ghost->y - 32) / 32][game->m_ghost->x / 32] != '1')
            dist_up = distance_calculator(game->m_ghost->x, game->m_ghost->targ_x, game->m_ghost->y - 32, game->m_ghost->targ_y);
        if (current != RIGHT && map[game->m_ghost->y / 32][(game->m_ghost->x - 32) / 32] != '1')
            dist_left = distance_calculator(game->m_ghost->x - 32, game->m_ghost->targ_x, game->m_ghost->y, game->m_ghost->targ_y);
        if (current != UP && map[(game->m_ghost->y + 32) / 32][game->m_ghost->x / 32] != '1')
            dist_down = distance_calculator(game->m_ghost->x, game->m_ghost->targ_x, game->m_ghost->y + 32, game->m_ghost->targ_y);
        if (current != LEFT && map[game->m_ghost->y / 32][(game->m_ghost->x + 32) / 32] != '1')
            dist_right = distance_calculator(game->m_ghost->x + 32, game->m_ghost->targ_x, game->m_ghost->y, game->m_ghost->targ_y);

        int min_dist = INT_MAX;
        game->m_ghost->pending_direction = UP;

        if (dist_up < min_dist)
        {
            min_dist = dist_up;
            game->m_ghost->pending_direction = UP;
        }
        if (dist_left < min_dist)
        {
            min_dist = dist_left;
            game->m_ghost->pending_direction = LEFT;
        }
        if (dist_down < min_dist)
        {
            min_dist = dist_down;
            game->m_ghost->pending_direction = DOWN;
        }
        if (dist_right < min_dist)
        {
            min_dist = dist_right;
            game->m_ghost->pending_direction = RIGHT;
        }

        if (game->m_ghost->is_respawned == 1 && 
            (game->m_ghost->x != game->m_ghost->start_x || game->m_ghost->y != game->m_ghost->start_y))
            game->m_ghost->is_respawned = 0;
    }

    game->last_pac_attack_mode = game->pac_attack_mode;
}

void magenta_ghost_moving(t_game *game)
{
    char **map = game->map->map;
    magenta_ghost_direction(game);

    // Проверка столкновения с учётом скорости
    if ((game->m_ghost->x % 32 == 0 && game->m_ghost->y % 32 == 0) || 
        (game->m_ghost->direction == UP && map[(game->m_ghost->y - (game->m_ghost->is_eaten ? 8 : 4)) / 32][game->m_ghost->x / 32] == '1') ||
        (game->m_ghost->direction == DOWN && map[(game->m_ghost->y + (game->m_ghost->is_eaten ? 8 : 4)) / 32 + 1][game->m_ghost->x / 32] == '1') ||
        (game->m_ghost->direction == LEFT && map[game->m_ghost->y / 32][(game->m_ghost->x - (game->m_ghost->is_eaten ? 8 : 4)) / 32] == '1') ||
        (game->m_ghost->direction == RIGHT && map[game->m_ghost->y / 32][(game->m_ghost->x + (game->m_ghost->is_eaten ? 8 : 4)) / 32 + 1] == '1'))
    {
        if (game->m_ghost->is_eaten == 0 &&
            (can_move_vertical(game->m_ghost, map, game->m_ghost->pending_direction) || 
             can_move_horizontal(game->m_ghost, map, game->m_ghost->pending_direction)))
        {
            game->m_ghost->direction = game->m_ghost->pending_direction;
        }
        else if (game->m_ghost->is_eaten == 1 && 
                 (can_move_fast_vertical(game->m_ghost, map, game->m_ghost->pending_direction) || 
                  can_move_fast_horizontal(game->m_ghost, map, game->m_ghost->pending_direction)))
        {
            game->m_ghost->direction = game->m_ghost->pending_direction;
        }

        // Логика разворота при тупике
        if (game->m_ghost->direction == RIGHT && 
            map[game->m_ghost->y / 32][(game->m_ghost->x + 32) / 32] == '1' && 
            map[(game->m_ghost->y + 32) / 32][(game->m_ghost->x) / 32] == '1' && 
            map[(game->m_ghost->y - 32) / 32][(game->m_ghost->x) / 32] == '1')
            game->m_ghost->direction = LEFT;
        else if (game->m_ghost->direction == LEFT && 
                 map[game->m_ghost->y / 32][(game->m_ghost->x - 32) / 32] == '1' && 
                 map[(game->m_ghost->y + 32) / 32][(game->m_ghost->x) / 32] == '1' && 
                 map[(game->m_ghost->y - 32) / 32][(game->m_ghost->x) / 32] == '1')
            game->m_ghost->direction = RIGHT;
        else if (game->m_ghost->direction == UP && 
                 map[game->m_ghost->y / 32][(game->m_ghost->x + 32) / 32] == '1' && 
                 map[game->m_ghost->y / 32][(game->m_ghost->x - 32) / 32] == '1' && 
                 map[(game->m_ghost->y - 32) / 32][(game->m_ghost->x) / 32] == '1')
            game->m_ghost->direction = DOWN;
        else if (game->m_ghost->direction == DOWN && 
                 map[game->m_ghost->y / 32][(game->m_ghost->x + 32) / 32] == '1' && 
                 map[game->m_ghost->y / 32][(game->m_ghost->x - 32) / 32] == '1' && 
                 map[(game->m_ghost->y + 32) / 32][(game->m_ghost->x) / 32] == '1')
            game->m_ghost->direction = UP;

        game->m_ghost->prev_x = game->m_ghost->x;
        game->m_ghost->prev_y = game->m_ghost->y;
    }

    if (game->m_ghost->is_eaten == 0)
    {
        if (game->m_ghost->direction == UP)
            game->m_ghost->y -= 4;
        else if (game->m_ghost->direction == DOWN)
            game->m_ghost->y += 4;
        else if (game->m_ghost->direction == LEFT)
        {
            game->m_ghost->x -= 4;
            if (map[game->m_ghost->y / 32][(game->m_ghost->x - 4) / 32] == 'T')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->x, game->m_ghost->y);
                handle_ghost_portal(game, game->m_ghost, 1);
            }
        }
        else if (game->m_ghost->direction == RIGHT)
        {
            game->m_ghost->x += 4;
            if (map[game->m_ghost->y / 32][(game->m_ghost->x + 32) / 32] == 'T')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->x, game->m_ghost->y);
                handle_ghost_portal(game, game->m_ghost, 0);
            }
        }
    }
    else if (game->m_ghost->is_eaten == 1)
    {
        if (game->m_ghost->direction == UP)
            game->m_ghost->y -= 16;
        else if (game->m_ghost->direction == DOWN)
            game->m_ghost->y += 16;
        else if (game->m_ghost->direction == LEFT)
        {
            game->m_ghost->x -= 16;
            if (map[game->m_ghost->y / 32][(game->m_ghost->x - 16) / 32] == 'T')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->x, game->m_ghost->y);
                handle_ghost_portal(game, game->m_ghost, 1);
            }
        }
        else if (game->m_ghost->direction == RIGHT)
        {   
            game->m_ghost->x += 16;
            if (map[game->m_ghost->y / 32][(game->m_ghost->x + 32) / 32] == 'T')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->m_ghost->x, game->m_ghost->y);
                handle_ghost_portal(game, game->m_ghost, 0);
            }
        }
    }
}