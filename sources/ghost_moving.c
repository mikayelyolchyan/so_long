#include "../includes/headers/so_long.h"

int distance_calculator(int x1, int x2, int y1, int y2)
{
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int ghost_can_move_vertical(t_game *game, char **map, int direction)
{
    if (direction == UP && 
        map[(game->r_ghost->y - 4) / 32][game->r_ghost->x / 32] != '1' && 
        game->r_ghost->x % 32 == 0)
        return (1);
    if (direction == DOWN && 
        map[(game->r_ghost->y + 4) / 32 + 1][game->r_ghost->x / 32] != '1' && 
        game->r_ghost->x % 32 == 0)
        return (1);
    return (0);
}

int ghost_can_move_horizontal(t_game *game, char **map, int direction)
{
    if (direction == LEFT && 
        map[game->r_ghost->y / 32][(game->r_ghost->x - 4) / 32] != '1' && 
        game->r_ghost->y % 32 == 0)
        return (1);
    if (direction == RIGHT && 
        map[game->r_ghost->y / 32][(game->r_ghost->x + 4) / 32 + 1] != '1' && 
        game->r_ghost->y % 32 == 0)
        return (1);
    return (0);
}

void ghost_direction(t_game *game)
{
    int dist_up = INT_MAX;
    int dist_left = INT_MAX;
    int dist_down = INT_MAX;
    int dist_right = INT_MAX;
    char **map = game->map->map;
    int current = game->r_ghost->direction;
	
	if (game->player->x / 32 >= game->map->width / 2 && game->player->y / 32 <= game->map->height / 2)
	{
		game->r_ghost->in_zone = 1;
	}
	else
	{
		game->r_ghost->in_zone = 0;
	}

	if (game->r_ghost->in_zone == 1)
	{
		game->r_ghost->targ_x = game->player->x;
		game->r_ghost->targ_y = game->player->y;
	}
	else
	{
		game->r_ghost->targ_x = game->map->width * 32;
		game->r_ghost->targ_y = 0;
	}

    if (current != DOWN && map[(game->r_ghost->y - 32) / 32][game->r_ghost->x / 32] != '1')
        dist_up = distance_calculator(game->r_ghost->x, game->r_ghost->targ_x, game->r_ghost->y - 32, game->r_ghost->targ_y);
    if (current != RIGHT && map[game->r_ghost->y / 32][(game->r_ghost->x - 32) / 32] != '1')
        dist_left = distance_calculator(game->r_ghost->x - 32, game->r_ghost->targ_x, game->r_ghost->y, game->r_ghost->targ_y);
    if (current != UP && map[(game->r_ghost->y + 32) / 32][game->r_ghost->x / 32] != '1')
        dist_down = distance_calculator(game->r_ghost->x, game->r_ghost->targ_x, game->r_ghost->y + 32, game->r_ghost->targ_y);
    if (current != LEFT && map[game->r_ghost->y / 32][(game->r_ghost->x + 32) / 32] != '1')
        dist_right = distance_calculator(game->r_ghost->x + 32, game->r_ghost->targ_x, game->r_ghost->y, game->r_ghost->targ_y);

    int min_dist = dist_up;
    game->r_ghost->pending_direction = UP;
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
}

void ghost_moving(t_game *game)
{
    char **map;
	
	map = game->map->map;
    ghost_direction(game);

    if ((game->r_ghost->x % 32 == 0 && game->r_ghost->y % 32 == 0) || 
        (game->r_ghost->direction == UP && map[(game->r_ghost->y - 4) / 32][game->r_ghost->x / 32] == '1') ||
        (game->r_ghost->direction == DOWN && map[(game->r_ghost->y + 4) / 32 + 1][game->r_ghost->x / 32] == '1') ||
        (game->r_ghost->direction == LEFT && map[game->r_ghost->y / 32][(game->r_ghost->x - 4) / 32] == '1') ||
        (game->r_ghost->direction == RIGHT && map[game->r_ghost->y / 32][(game->r_ghost->x + 4) / 32 + 1] == '1'))
    {
        if (ghost_can_move_vertical(game, map, game->r_ghost->pending_direction) || 
            ghost_can_move_horizontal(game, map, game->r_ghost->pending_direction))
		{
            game->r_ghost->direction = game->r_ghost->pending_direction;
		}
		if (game->r_ghost->direction == RIGHT && \
			map[game->r_ghost->y / 32][(game->r_ghost->x + 32) / 32] == '1' && \
			map[(game->r_ghost->y + 32) / 32][(game->r_ghost->x) / 32] == '1' && \
			map[(game->r_ghost->y - 32) / 32][(game->r_ghost->x) / 32] == '1')
		{
			game->r_ghost->direction = LEFT;
		}
		else if (game->r_ghost->direction == LEFT && \
			map[game->r_ghost->y / 32][(game->r_ghost->x - 32) / 32] == '1' && \
			map[(game->r_ghost->y + 32) / 32][(game->r_ghost->x) / 32] == '1' && \
			map[(game->r_ghost->y - 32) / 32][(game->r_ghost->x) / 32] == '1')
		{
			game->r_ghost->direction = RIGHT;
		}
		else if (game->r_ghost->direction == UP && \
			map[game->r_ghost->y / 32][(game->r_ghost->x + 32) / 32] == '1' && \
			map[game->r_ghost->y / 32][(game->r_ghost->x - 32) / 32] == '1' && \
			map[(game->r_ghost->y - 32) / 32][(game->r_ghost->x) / 32] == '1')
		{
			game->r_ghost->direction = DOWN;
		}
		else if (game->r_ghost->direction == DOWN && \
			map[game->r_ghost->y / 32][(game->r_ghost->x + 32) / 32] == '1' && \
			map[game->r_ghost->y / 32][(game->r_ghost->x - 32) / 32] == '1' && \
			map[(game->r_ghost->y + 32) / 32][(game->r_ghost->x) / 32] == '1')
		{
			game->r_ghost->direction = UP;
		}
		game->r_ghost->prev_x = game->r_ghost->x;
    	game->r_ghost->prev_y = game->r_ghost->y;
    }
	if (game->r_ghost->direction == UP)
		game->r_ghost->y -= 4;
	else if (game->r_ghost->direction == DOWN)
		game->r_ghost->y += 4;
	else if (game->r_ghost->direction == LEFT)
	{
		game->r_ghost->x -= 4;
		if (map[game->r_ghost->y / 32][(game->r_ghost->x - 4) / 32] == 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->x, game->r_ghost->y);
			game->r_ghost->x = 23 * 32;
			game->r_ghost->y = 11 * 32;
		}
	}
	else if (game->r_ghost->direction == RIGHT)
	{
		game->r_ghost->x += 4;
		if (map[game->r_ghost->y / 32][(game->r_ghost->x + 32) / 32] == 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->map->black_wall_img, game->r_ghost->x, game->r_ghost->y);
			game->r_ghost->x = 2 * 32;
			game->r_ghost->y = 11 * 32;
		}
	}
}
