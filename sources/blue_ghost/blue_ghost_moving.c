#include "../../includes/headers/so_long.h"

void blue_ghost_moving(t_game *game)
{
    char **map;
	
	map = game->map->map;
    blue_ghost_direction(game);
    // Проверка столкновения с учётом скорости
    detect_collision_with_speed(game, game->b_ghost, map);
    if (game->b_ghost->is_eaten == 0)
    {
        ghost_move(game, game->b_ghost);
    }
    else if (game->b_ghost->is_eaten == 1)
    {
        ghost_is_eaten_move(game, game->b_ghost);
    }
}
