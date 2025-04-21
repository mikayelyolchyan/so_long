#include "../../includes/headers/so_long.h"

void blue_ghost_direction(t_game *game)
{
    int dist_up = INT_MAX;
    int dist_left = INT_MAX;
    int dist_down = INT_MAX;
    int dist_right = INT_MAX;
    char **map = game->map->map;
    int current = game->b_ghost->direction;

    if (game->pac_attack_mode == 1 &&
        (game->player->x - game->b_ghost->x <= 16 && game->player->x - game->b_ghost->x >= -16) &&
        (game->player->y - game->b_ghost->y <= 16 && game->player->y - game->b_ghost->y >= -16) &&
        game->b_ghost->is_eaten == 0 && game->b_ghost->is_respawned == 0)
    {
		mlx_put_image_to_window(game->mlx, game->win, \
			game->map->black_wall_img, game->b_ghost->x, game->b_ghost->y);
        game->b_ghost->is_eaten = 1;
		game->game_start_delay = GHOST_EATEN_FREEZE;
		game->game_start = 0;
        game->b_ghost->targ_x = game->b_ghost->start_x;
        game->b_ghost->targ_y = game->b_ghost->start_y;

        game->b_ghost->remainder_x = game->b_ghost->x % 32;
        game->b_ghost->remainder_y = game->b_ghost->y % 32;

        if (game->b_ghost->remainder_x != 0)
        {
            if (game->b_ghost->remainder_x < 16)
                game->b_ghost->x -= game->b_ghost->remainder_x; // Округляем вниз
            else
                game->b_ghost->x += (32 - game->b_ghost->remainder_x); // Округляем вверх
        }
        if (game->b_ghost->remainder_y != 0)
        {
            if (game->b_ghost->remainder_y < 16)
                game->b_ghost->y -= game->b_ghost->remainder_y; // Округляем вниз
            else
                game->b_ghost->y += (32 - game->b_ghost->remainder_y); // Округляем вверх
        }
    }

	if (game->pac_attack_mode == 0 &&
		(game->player->x - game->b_ghost->x <= 16 && game->player->x - game->b_ghost->x >= -16) &&
    	(game->player->y - game->b_ghost->y <= 16 && game->player->y - game->b_ghost->y >= -16) &&
    	game->b_ghost->is_eaten == 0 && game->b_ghost->is_respawned == 0)
	{
		//printf("game->game_restart = 1;\n");
		game->game_restart = 1;
		game->player->died_count++;
		draw_map(game);
	}

    // Логика режимов атаки
    if (game->ghost_attack_mode_delay >= GHOST_NEUTRAL_LIMIT && game->pac_attack_mode == 0)
        game->ghost_attack_mode = 1;
    else if (game->ghost_attack_mode_delay <= GHOST_ATTACK_LIMIT && game->pac_attack_mode == 0)
        game->ghost_attack_mode = 0;

    // Установка цели для нормального режима
    if (!game->b_ghost->is_eaten)
    {
        if (game->ghost_attack_mode == 1 && game->pac_attack_mode == 0)
        {
            // Шаг 1: Определяем точку на 2 клетки впереди Пакмана
            int pivot_x, pivot_y;

			pivot_x = 0;
			pivot_y = 0;
            if (game->player->direction == RIGHT)
            {
                pivot_x = game->player->x + 64; // 2 клетки вправо (2 * 32)
                pivot_y = game->player->y;
            }
            else if (game->player->direction == LEFT)
            {
                pivot_x = game->player->x - 64; // 2 клетки влево
                pivot_y = game->player->y;
            }
            else if (game->player->direction == DOWN)
            {
                pivot_x = game->player->x;
                pivot_y = game->player->y + 64; // 2 клетки вниз
            }
            else if (game->player->direction == UP)
            {
                pivot_x = game->player->x - 64; // 2 клетки влево
                pivot_y = game->player->y - 64; // 2 клетки вверх
            }

            // Шаг 2: Вычисляем вектор от Blinky к этой точке
            int vector_x = pivot_x - game->r_ghost->x;
            int vector_y = pivot_y - game->r_ghost->y;

            // Шаг 3: Удваиваем вектор и добавляем к позиции Blinky
            game->b_ghost->targ_x = game->r_ghost->x + 2 * vector_x;
            game->b_ghost->targ_y = game->r_ghost->y + 2 * vector_y;
        }
        else if (game->ghost_attack_mode == 0 && game->pac_attack_mode == 0)
        {
            // Нейтральная позиция Inky — правый нижний угол
            game->b_ghost->targ_x = game->map->width * 32;
            game->b_ghost->targ_y = game->map->height * 32;
        }
    }

    // Логика движения в зависимости от состояния
    if (game->b_ghost->is_eaten)
    {
        game->b_ghost->is_respawned = 0;
        if (current != DOWN && map[(game->b_ghost->y - 32) / 32][game->b_ghost->x / 32] != '1')
            dist_up = distance_calculator(game->b_ghost->x, game->b_ghost->start_x, game->b_ghost->y - 32, game->b_ghost->start_y);
        if (current != RIGHT && map[game->b_ghost->y / 32][(game->b_ghost->x - 32) / 32] != '1')
            dist_left = distance_calculator(game->b_ghost->x - 32, game->b_ghost->start_x, game->b_ghost->y, game->b_ghost->start_y);
        if (current != UP && map[(game->b_ghost->y + 32) / 32][game->b_ghost->x / 32] != '1')
            dist_down = distance_calculator(game->b_ghost->x, game->b_ghost->start_x, game->b_ghost->y + 32, game->b_ghost->start_y);
        if (current != LEFT && map[game->b_ghost->y / 32][(game->b_ghost->x + 32) / 32] != '1')
            dist_right = distance_calculator(game->b_ghost->x + 32, game->b_ghost->start_x, game->b_ghost->y, game->b_ghost->start_y);

        int min_dist = INT_MAX;
        game->b_ghost->pending_direction = UP;

        if (dist_up < min_dist)
        {
            min_dist = dist_up;
            game->b_ghost->pending_direction = UP;
        }
        if (dist_left < min_dist)
        {
            min_dist = dist_left;
            game->b_ghost->pending_direction = LEFT;
        }
        if (dist_down < min_dist)
        {
            min_dist = dist_down;
            game->b_ghost->pending_direction = DOWN;
        }
        if (dist_right < min_dist)
        {
            min_dist = dist_right;
            game->b_ghost->pending_direction = RIGHT;
        }

        if (game->b_ghost->x == game->b_ghost->start_x && 
            game->b_ghost->y == game->b_ghost->start_y)
        {
            game->b_ghost->is_eaten = 0;
            game->b_ghost->is_respawned = 1;
            // После респавна устанавливаем цель в зависимости от поведения Inky
            int pivot_x, pivot_y;

			pivot_x = 0;
			pivot_y = 0;
            if (game->player->direction == RIGHT)
            {
                pivot_x = game->player->x + 64;
                pivot_y = game->player->y;
            }
            else if (game->player->direction == LEFT)
            {
                pivot_x = game->player->x - 64;
                pivot_y = game->player->y;
            }
            else if (game->player->direction == DOWN)
            {
                pivot_x = game->player->x;
                pivot_y = game->player->y + 64;
            }
            else if (game->player->direction == UP)
            {
                pivot_x = game->player->x - 64; // 2 клетки влево
                pivot_y = game->player->y - 64; // 2 клетки вверх
            }
            int vector_x = pivot_x - game->r_ghost->x;
            int vector_y = pivot_y - game->r_ghost->y;
            game->b_ghost->targ_x = game->r_ghost->x + 2 * vector_x;
            game->b_ghost->targ_y = game->r_ghost->y + 2 * vector_y;
        }
    }
    else if (game->pac_attack_mode == 1)
    {
        if (game->last_pac_attack_mode == 0 && game->pac_attack_mode == 1)
            game->b_ghost->is_respawned = 0;

        if (current != DOWN && map[(game->b_ghost->y - 32) / 32][game->b_ghost->x / 32] != '1')
            dist_up = distance_calculator(game->b_ghost->x, game->b_ghost->targ_x, game->b_ghost->y - 32, game->b_ghost->targ_y);
        if (current != RIGHT && map[game->b_ghost->y / 32][(game->b_ghost->x - 32) / 32] != '1')
            dist_left = distance_calculator(game->b_ghost->x - 32, game->b_ghost->targ_x, game->b_ghost->y, game->b_ghost->targ_y);
        if (current != UP && map[(game->b_ghost->y + 32) / 32][game->b_ghost->x / 32] != '1')
            dist_down = distance_calculator(game->b_ghost->x, game->b_ghost->targ_x, game->b_ghost->y + 32, game->b_ghost->targ_y);
        if (current != LEFT && map[game->b_ghost->y / 32][(game->b_ghost->x + 32) / 32] != '1')
            dist_right = distance_calculator(game->b_ghost->x + 32, game->b_ghost->targ_x, game->b_ghost->y, game->b_ghost->targ_y);

        int max_dist = -1;
        game->b_ghost->pending_direction = UP;

        if (dist_up != INT_MAX && dist_up > max_dist)
        {
            max_dist = dist_up;
            game->b_ghost->pending_direction = UP;
        }
        if (dist_left != INT_MAX && dist_left > max_dist)
        {
            max_dist = dist_left;
            game->b_ghost->pending_direction = LEFT;
        }
        if (dist_down != INT_MAX && dist_down > max_dist)
        {
            max_dist = dist_down;
            game->b_ghost->pending_direction = DOWN;
        }
        if (dist_right != INT_MAX && dist_right > max_dist)
        {
            max_dist = dist_right;
            game->b_ghost->pending_direction = RIGHT;
        }
    }
    else
    {
        if (current != DOWN && map[(game->b_ghost->y - 32) / 32][game->b_ghost->x / 32] != '1')
            dist_up = distance_calculator(game->b_ghost->x, game->b_ghost->targ_x, game->b_ghost->y - 32, game->b_ghost->targ_y);
        if (current != RIGHT && map[game->b_ghost->y / 32][(game->b_ghost->x - 32) / 32] != '1')
            dist_left = distance_calculator(game->b_ghost->x - 32, game->b_ghost->targ_x, game->b_ghost->y, game->b_ghost->targ_y);
        if (current != UP && map[(game->b_ghost->y + 32) / 32][game->b_ghost->x / 32] != '1')
            dist_down = distance_calculator(game->b_ghost->x, game->b_ghost->targ_x, game->b_ghost->y + 32, game->b_ghost->targ_y);
        if (current != LEFT && map[game->b_ghost->y / 32][(game->b_ghost->x + 32) / 32] != '1')
            dist_right = distance_calculator(game->b_ghost->x + 32, game->b_ghost->targ_x, game->b_ghost->y, game->b_ghost->targ_y);

        int min_dist = INT_MAX;
        game->b_ghost->pending_direction = UP;

        if (dist_up < min_dist)
        {
            min_dist = dist_up;
            game->b_ghost->pending_direction = UP;
        }
        if (dist_left < min_dist)
        {
            min_dist = dist_left;
            game->b_ghost->pending_direction = LEFT;
        }
        if (dist_down < min_dist)
        {
            min_dist = dist_down;
            game->b_ghost->pending_direction = DOWN;
        }
        if (dist_right < min_dist)
        {
            min_dist = dist_right;
            game->b_ghost->pending_direction = RIGHT;
        }

        if (game->b_ghost->is_respawned == 1 && 
            (game->b_ghost->x != game->b_ghost->start_x || game->b_ghost->y != game->b_ghost->start_y))
            game->b_ghost->is_respawned = 0;
    }

    game->last_pac_attack_mode = game->pac_attack_mode;
}

void blue_ghost_moving(t_game *game)
{
    char **map = game->map->map;
    blue_ghost_direction(game);

    // Проверка столкновения с учётом скорости
    if ((game->b_ghost->x % 32 == 0 && game->b_ghost->y % 32 == 0) || 
        (game->b_ghost->direction == UP && map[(game->b_ghost->y - (game->b_ghost->is_eaten ? 8 : 4)) / 32][game->b_ghost->x / 32] == '1') ||
        (game->b_ghost->direction == DOWN && map[(game->b_ghost->y + (game->b_ghost->is_eaten ? 8 : 4)) / 32 + 1][game->b_ghost->x / 32] == '1') ||
        (game->b_ghost->direction == LEFT && map[game->b_ghost->y / 32][(game->b_ghost->x - (game->b_ghost->is_eaten ? 8 : 4)) / 32] == '1') ||
        (game->b_ghost->direction == RIGHT && map[game->b_ghost->y / 32][(game->b_ghost->x + (game->b_ghost->is_eaten ? 8 : 4)) / 32 + 1] == '1'))
    {
        if (game->b_ghost->is_eaten == 0 &&
            (can_move_vertical(game->b_ghost, map, game->b_ghost->pending_direction) || 
             can_move_horizontal(game->b_ghost, map, game->b_ghost->pending_direction)))
        {
            game->b_ghost->direction = game->b_ghost->pending_direction;
        }
        else if (game->b_ghost->is_eaten == 1 &&
                 (can_move_fast_vertical(game->b_ghost, map, game->b_ghost->pending_direction) || 
				 can_move_fast_horizontal(game->b_ghost, map, game->b_ghost->pending_direction)))
        {
            game->b_ghost->direction = game->b_ghost->pending_direction;
        }

        // Логика разворота при тупике
        if (game->b_ghost->direction == RIGHT && 
            map[game->b_ghost->y / 32][(game->b_ghost->x + 32) / 32] == '1' && 
            map[(game->b_ghost->y + 32) / 32][(game->b_ghost->x) / 32] == '1' && 
            map[(game->b_ghost->y - 32) / 32][(game->b_ghost->x) / 32] == '1')
            game->b_ghost->direction = LEFT;
        else if (game->b_ghost->direction == LEFT && 
                 map[game->b_ghost->y / 32][(game->b_ghost->x - 32) / 32] == '1' && 
                 map[(game->b_ghost->y + 32) / 32][(game->b_ghost->x) / 32] == '1' && 
                 map[(game->b_ghost->y - 32) / 32][(game->b_ghost->x) / 32] == '1')
            game->b_ghost->direction = RIGHT;
        else if (game->b_ghost->direction == UP && 
                 map[game->b_ghost->y / 32][(game->b_ghost->x + 32) / 32] == '1' && 
                 map[game->b_ghost->y / 32][(game->b_ghost->x - 32) / 32] == '1' && 
                 map[(game->b_ghost->y - 32) / 32][(game->b_ghost->x) / 32] == '1')
            game->b_ghost->direction = DOWN;
        else if (game->b_ghost->direction == DOWN && 
                 map[game->b_ghost->y / 32][(game->b_ghost->x + 32) / 32] == '1' && 
                 map[game->b_ghost->y / 32][(game->b_ghost->x - 32) / 32] == '1' && 
                 map[(game->b_ghost->y + 32) / 32][(game->b_ghost->x) / 32] == '1')
            game->b_ghost->direction = UP;

        game->b_ghost->prev_x = game->b_ghost->x;
        game->b_ghost->prev_y = game->b_ghost->y;
    }

    if (game->b_ghost->is_eaten == 0)
    {
        if (game->b_ghost->direction == UP)
            game->b_ghost->y -= 4;
        else if (game->b_ghost->direction == DOWN)
            game->b_ghost->y += 4;
        else if (game->b_ghost->direction == LEFT)
        {
            game->b_ghost->x -= 4;
            if (map[game->b_ghost->y / 32][(game->b_ghost->x - 4) / 32] == 'T')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->x, game->b_ghost->y);
                handle_ghost_portal(game, game->b_ghost, 1);
            }
        }
        else if (game->b_ghost->direction == RIGHT)
        {
            game->b_ghost->x += 4;
            if (map[game->b_ghost->y / 32][(game->b_ghost->x + 32) / 32] == 'T')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->x, game->b_ghost->y);
                handle_ghost_portal(game, game->b_ghost, 0);
            }
        }
    }
    else if (game->b_ghost->is_eaten == 1)
    {
        if (game->b_ghost->direction == UP)
            game->b_ghost->y -= 16;
        else if (game->b_ghost->direction == DOWN)
            game->b_ghost->y += 16;
        else if (game->b_ghost->direction == LEFT)
        {
            game->b_ghost->x -= 16;
            if (map[game->b_ghost->y / 32][(game->b_ghost->x - 16) / 32] == 'T')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->x, game->b_ghost->y);
                handle_ghost_portal(game, game->b_ghost, 1);
            }
        }
        else if (game->b_ghost->direction == RIGHT)
        {   
            game->b_ghost->x += 16;
            if (map[game->b_ghost->y / 32][(game->b_ghost->x + 32) / 32] == 'T')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->b_ghost->x, game->b_ghost->y);
                handle_ghost_portal(game, game->b_ghost, 0);
            }
        }
    }
}