#include "../../includes/headers/so_long.h"

int orange_ghost_can_move_vertical(t_game *game, char **map, int direction)
{
    if (direction == UP && map[(game->o_ghost->y - 4) / 32][game->o_ghost->x / 32] != '1' && game->o_ghost->x % 32 == 0)
        return (1);
    if (direction == DOWN && map[(game->o_ghost->y + 4) / 32 + 1][game->o_ghost->x / 32] != '1' && game->o_ghost->x % 32 == 0)
        return (1);
    return (0);
}

int orange_ghost_can_move_horizontal(t_game *game, char **map, int direction)
{
    if (direction == LEFT && map[game->o_ghost->y / 32][(game->o_ghost->x - 4) / 32] != '1' && game->o_ghost->y % 32 == 0)
        return (1);
    if (direction == RIGHT && map[game->o_ghost->y / 32][(game->o_ghost->x + 4) / 32 + 1] != '1' && game->o_ghost->y % 32 == 0)
        return (1);
    return (0);
}

int orange_ghost_can_move_fast_vertical(t_game *game, char **map, int direction)
{
    if (direction == UP && map[(game->o_ghost->y - 8) / 32][game->o_ghost->x / 32] != '1' && game->o_ghost->x % 32 == 0)
        return (1);
    if (direction == DOWN && map[(game->o_ghost->y + 8) / 32 + 1][game->o_ghost->x / 32] != '1' && game->o_ghost->x % 32 == 0)
        return (1);
    return (0);
}

int orange_ghost_can_move_fast_horizontal(t_game *game, char **map, int direction)
{
    if (direction == LEFT && map[game->o_ghost->y / 32][(game->o_ghost->x - 8) / 32] != '1' && game->o_ghost->y % 32 == 0)
        return (1);
    if (direction == RIGHT && map[game->o_ghost->y / 32][(game->o_ghost->x + 8) / 32 + 1] != '1' && game->o_ghost->y % 32 == 0)
        return (1);
    return (0);
}

void orange_ghost_direction(t_game *game)
{
    int dist_up = INT_MAX;
    int dist_left = INT_MAX;
    int dist_down = INT_MAX;
    int dist_right = INT_MAX;
    char **map = game->map->map;
    int current = game->o_ghost->direction;

    // Проверка на "съедение" призрака
   	if (game->pac_attack_mode == 1 &&
		(game->player->x - game->o_ghost->x <= 16 && game->player->x - game->o_ghost->x >= -16) &&
    	(game->player->y - game->o_ghost->y <= 16 && game->player->y - game->o_ghost->y >= -16) &&
    	game->o_ghost->is_eaten == 0 && game->o_ghost->is_respawned == 0)
	{
		game->o_ghost->is_eaten = 1;
		game->o_ghost->targ_x = game->o_ghost->start_x;
		game->o_ghost->targ_y = game->o_ghost->start_y;

		game->o_ghost->remainder_x = game->o_ghost->x % 32;
        game->o_ghost->remainder_y = game->o_ghost->y % 32;

        if (game->o_ghost->remainder_x != 0)
        {
            if (game->o_ghost->remainder_x < 16)
                game->o_ghost->x -= game->o_ghost->remainder_x; // Округляем вниз
            else
                game->o_ghost->x += (32 - game->o_ghost->remainder_x); // Округляем вверх
        }
        if (game->o_ghost->remainder_y != 0)
        {
            if (game->o_ghost->remainder_y < 16)
                game->o_ghost->y -= game->o_ghost->remainder_y; // Округляем вниз
            else
                game->o_ghost->y += (32 - game->o_ghost->remainder_y); // Округляем вверх
        }
	}

    // Логика режимов атаки
    if (game->ghost_attack_mode_delay >= 262144 && game->pac_attack_mode == 0)
        game->ghost_attack_mode = 1;
    else if (game->ghost_attack_mode_delay <= 262144 && game->pac_attack_mode == 0)
        game->ghost_attack_mode = 0;

    // Установка цели для нормального режима
    if (!game->o_ghost->is_eaten)
    {
        if (game->ghost_attack_mode == 1 && game->pac_attack_mode == 0)
        {
            game->o_ghost->targ_x = game->player->x;
            game->o_ghost->targ_y = game->player->y;
        }
        else if (game->ghost_attack_mode == 0 && game->pac_attack_mode == 0)
        {
            game->o_ghost->targ_x = game->map->width * 32;
            game->o_ghost->targ_y = 0;
        }
    }

    // Логика движения в зависимости от состояния
    if (game->o_ghost->is_eaten)
    {
        game->o_ghost->is_respawned = 0;
        if (current != DOWN && map[(game->o_ghost->y - 32) / 32][game->o_ghost->x / 32] != '1')
            dist_up = distance_calculator(game->o_ghost->x, game->o_ghost->start_x, game->o_ghost->y - 32, game->o_ghost->start_y);
        if (current != RIGHT && map[game->o_ghost->y / 32][(game->o_ghost->x - 32) / 32] != '1')
            dist_left = distance_calculator(game->o_ghost->x - 32, game->o_ghost->start_x, game->o_ghost->y, game->o_ghost->start_y);
        if (current != UP && map[(game->o_ghost->y + 32) / 32][game->o_ghost->x / 32] != '1')
            dist_down = distance_calculator(game->o_ghost->x, game->o_ghost->start_x, game->o_ghost->y + 32, game->o_ghost->start_y);
        if (current != LEFT && map[game->o_ghost->y / 32][(game->o_ghost->x + 32) / 32] != '1')
            dist_right = distance_calculator(game->o_ghost->x + 32, game->o_ghost->start_x, game->o_ghost->y, game->o_ghost->start_y);

        int min_dist = INT_MAX;
        game->o_ghost->pending_direction = UP;

        if (dist_up < min_dist)
		{
            min_dist = dist_up;
            game->o_ghost->pending_direction = UP;
        }
        if (dist_left < min_dist)
		{
            min_dist = dist_left;
            game->o_ghost->pending_direction = LEFT;
        }
        if (dist_down < min_dist)
		{
            min_dist = dist_down;
            game->o_ghost->pending_direction = DOWN;
        }
        if (dist_right < min_dist)
		{
            min_dist = dist_right;
            game->o_ghost->pending_direction = RIGHT;
        }

        if (game->o_ghost->x == game->o_ghost->start_x && 
            game->o_ghost->y == game->o_ghost->start_y)
        {
            game->o_ghost->is_eaten = 0;
            game->o_ghost->is_respawned = 1;
            game->o_ghost->targ_x = game->player->x;
            game->o_ghost->targ_y = game->player->y;
        }
    }
    else if (game->pac_attack_mode == 1)
    {
        // Сбрасываем is_respawned при активации pac_attack_mode
        if (game->last_pac_attack_mode == 0 && game->pac_attack_mode == 1)
            game->o_ghost->is_respawned = 0;

        if (current != DOWN && map[(game->o_ghost->y - 32) / 32][game->o_ghost->x / 32] != '1')
            dist_up = distance_calculator(game->o_ghost->x, game->o_ghost->targ_x, game->o_ghost->y - 32, game->o_ghost->targ_y);
        if (current != RIGHT && map[game->o_ghost->y / 32][(game->o_ghost->x - 32) / 32] != '1')
            dist_left = distance_calculator(game->o_ghost->x - 32, game->o_ghost->targ_x, game->o_ghost->y, game->o_ghost->targ_y);
        if (current != UP && map[(game->o_ghost->y + 32) / 32][game->o_ghost->x / 32] != '1')
            dist_down = distance_calculator(game->o_ghost->x, game->o_ghost->targ_x, game->o_ghost->y + 32, game->o_ghost->targ_y);
        if (current != LEFT && map[game->o_ghost->y / 32][(game->o_ghost->x + 32) / 32] != '1')
            dist_right = distance_calculator(game->o_ghost->x + 32, game->o_ghost->targ_x, game->o_ghost->y, game->o_ghost->targ_y);

        int max_dist = -1;
        game->o_ghost->pending_direction = UP;

        if (dist_up != INT_MAX && dist_up > max_dist)
        {
            max_dist = dist_up;
            game->o_ghost->pending_direction = UP;
        }
        if (dist_left != INT_MAX && dist_left > max_dist)
        {
            max_dist = dist_left;
            game->o_ghost->pending_direction = LEFT;
        }
        if (dist_down != INT_MAX && dist_down > max_dist)
        {
            max_dist = dist_down;
            game->o_ghost->pending_direction = DOWN;
        }
        if (dist_right != INT_MAX && dist_right > max_dist)
        {
            max_dist = dist_right;
            game->o_ghost->pending_direction = RIGHT;
        }
    }
    else
    {
        if (current != DOWN && map[(game->o_ghost->y - 32) / 32][game->o_ghost->x / 32] != '1')
            dist_up = distance_calculator(game->o_ghost->x, game->o_ghost->targ_x, game->o_ghost->y - 32, game->o_ghost->targ_y);
        if (current != RIGHT && map[game->o_ghost->y / 32][(game->o_ghost->x - 32) / 32] != '1')
            dist_left = distance_calculator(game->o_ghost->x - 32, game->o_ghost->targ_x, game->o_ghost->y, game->o_ghost->targ_y);
        if (current != UP && map[(game->o_ghost->y + 32) / 32][game->o_ghost->x / 32] != '1')
            dist_down = distance_calculator(game->o_ghost->x, game->o_ghost->targ_x, game->o_ghost->y + 32, game->o_ghost->targ_y);
        if (current != LEFT && map[game->o_ghost->y / 32][(game->o_ghost->x + 32) / 32] != '1')
            dist_right = distance_calculator(game->o_ghost->x + 32, game->o_ghost->targ_x, game->o_ghost->y, game->o_ghost->targ_y);

        int min_dist = INT_MAX;
        game->o_ghost->pending_direction = UP;

        if (dist_up < min_dist)
        {
            min_dist = dist_up;
            game->o_ghost->pending_direction = UP;
        }
        if (dist_left < min_dist)
        {
            min_dist = dist_left;
            game->o_ghost->pending_direction = LEFT;
        }
        if (dist_down < min_dist)
        {
            min_dist = dist_down;
            game->o_ghost->pending_direction = DOWN;
        }
        if (dist_right < min_dist)
        {
            min_dist = dist_right;
            game->o_ghost->pending_direction = RIGHT;
        }

        // Сбрасываем is_respawned после первого шага от точки спавна
        if (game->o_ghost->is_respawned == 1 && 
            (game->o_ghost->x != game->o_ghost->start_x || game->o_ghost->y != game->o_ghost->start_y))
            game->o_ghost->is_respawned = 0;
    }

    game->last_pac_attack_mode = game->pac_attack_mode;
}

void orange_ghost_moving(t_game *game)
{
    char **map = game->map->map;
    orange_ghost_direction(game);

    // Проверка столкновения с учётом скорости
    if ((game->o_ghost->x % 32 == 0 && game->o_ghost->y % 32 == 0) || 
        (game->o_ghost->direction == UP && map[(game->o_ghost->y - (game->o_ghost->is_eaten ? 8 : 4)) / 32][game->o_ghost->x / 32] == '1') ||
        (game->o_ghost->direction == DOWN && map[(game->o_ghost->y + (game->o_ghost->is_eaten ? 8 : 4)) / 32 + 1][game->o_ghost->x / 32] == '1') ||
        (game->o_ghost->direction == LEFT && map[game->o_ghost->y / 32][(game->o_ghost->x - (game->o_ghost->is_eaten ? 8 : 4)) / 32] == '1') ||
        (game->o_ghost->direction == RIGHT && map[game->o_ghost->y / 32][(game->o_ghost->x + (game->o_ghost->is_eaten ? 8 : 4)) / 32 + 1] == '1'))
    {
        if (game->o_ghost->is_eaten == 0 &&
            (orange_ghost_can_move_vertical(game, map, game->o_ghost->pending_direction) || 
             orange_ghost_can_move_horizontal(game, map, game->o_ghost->pending_direction)))
        {
            game->o_ghost->direction = game->o_ghost->pending_direction;
        }
        else if (game->o_ghost->is_eaten == 1 && 
                 (orange_ghost_can_move_fast_vertical(game, map, game->o_ghost->pending_direction) || 
                  orange_ghost_can_move_fast_horizontal(game, map, game->o_ghost->pending_direction)))
        {
            game->o_ghost->direction = game->o_ghost->pending_direction;
        }

        // Логика разворота при тупике
        if (game->o_ghost->direction == RIGHT && 
            map[game->o_ghost->y / 32][(game->o_ghost->x + 32) / 32] == '1' && 
            map[(game->o_ghost->y + 32) / 32][(game->o_ghost->x) / 32] == '1' && 
            map[(game->o_ghost->y - 32) / 32][(game->o_ghost->x) / 32] == '1')
            game->o_ghost->direction = LEFT;
        else if (game->o_ghost->direction == LEFT && 
                 map[game->o_ghost->y / 32][(game->o_ghost->x - 32) / 32] == '1' && 
                 map[(game->o_ghost->y + 32) / 32][(game->o_ghost->x) / 32] == '1' && 
                 map[(game->o_ghost->y - 32) / 32][(game->o_ghost->x) / 32] == '1')
            game->o_ghost->direction = RIGHT;
        else if (game->o_ghost->direction == UP && 
                 map[game->o_ghost->y / 32][(game->o_ghost->x + 32) / 32] == '1' && 
                 map[game->o_ghost->y / 32][(game->o_ghost->x - 32) / 32] == '1' && 
                 map[(game->o_ghost->y - 32) / 32][(game->o_ghost->x) / 32] == '1')
            game->o_ghost->direction = DOWN;
        else if (game->o_ghost->direction == DOWN && 
                 map[game->o_ghost->y / 32][(game->o_ghost->x + 32) / 32] == '1' && 
                 map[game->o_ghost->y / 32][(game->o_ghost->x - 32) / 32] == '1' && 
                 map[(game->o_ghost->y + 32) / 32][(game->o_ghost->x) / 32] == '1')
            game->o_ghost->direction = UP;

        game->o_ghost->prev_x = game->o_ghost->x;
        game->o_ghost->prev_y = game->o_ghost->y;
    }

    if (game->o_ghost->is_eaten == 0)
    {
        if (game->o_ghost->direction == UP)
            game->o_ghost->y -= 4;
        else if (game->o_ghost->direction == DOWN)
            game->o_ghost->y += 4;
        else if (game->o_ghost->direction == LEFT)
        {
            game->o_ghost->x -= 4;
            if (map[game->o_ghost->y / 32][(game->o_ghost->x - 4) / 32] == 'E')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->x, game->o_ghost->y);
                game->o_ghost->x = 23 * 32;
                game->o_ghost->y = 11 * 32;
            }
        }
        else if (game->o_ghost->direction == RIGHT)
        {
            game->o_ghost->x += 4;
            if (map[game->o_ghost->y / 32][(game->o_ghost->x + 32) / 32] == 'E')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->x, game->o_ghost->y);
                game->o_ghost->x = 2 * 32;
                game->o_ghost->y = 11 * 32;
            }
        }
    }
    else if (game->o_ghost->is_eaten == 1)
    {
        if (game->o_ghost->direction == UP)
            game->o_ghost->y -= 8;
        else if (game->o_ghost->direction == DOWN)
            game->o_ghost->y += 8;
        else if (game->o_ghost->direction == LEFT)
        {
            game->o_ghost->x -= 8;
            if (map[game->o_ghost->y / 32][(game->o_ghost->x - 8) / 32] == 'E')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->x, game->o_ghost->y);
                game->o_ghost->x = 23 * 32;
                game->o_ghost->y = 11 * 32;
            }
        }
        else if (game->o_ghost->direction == RIGHT)
        {   
            game->o_ghost->x += 8;
            if (map[game->o_ghost->y / 32][(game->o_ghost->x + 32) / 32] == 'E')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->o_ghost->x, game->o_ghost->y);
                game->o_ghost->x = 2 * 32;
                game->o_ghost->y = 11 * 32;
            }
        }
    }
}