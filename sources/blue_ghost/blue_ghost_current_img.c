#include "../../includes/headers/so_long.h"

void *get_blue_ghost_current_img(t_game *game, t_ghost *b_ghost)
{
    void *current_img;

    // Если призрак "съеден" и движется к спавну
    if (b_ghost->is_eaten == 1)
    {
		if (b_ghost->direction == UP)
        	current_img = game->b_ghost->ghost_is_eaten_up;
		else if (b_ghost->direction == DOWN)
        	current_img = game->b_ghost->ghost_is_eaten_down;
		else if (b_ghost->direction == LEFT)
        	current_img = game->b_ghost->ghost_is_eaten_left;
		else if (b_ghost->direction == RIGHT)
        	current_img = game->b_ghost->ghost_is_eaten_right;
    }
    // Режим паники применяется только к несъеденным призракам при pac_attack_mode == 1
    else if (game->pac_attack_mode == 1 && b_ghost->is_eaten == 0 && b_ghost->is_respawned == 0)
    {
        if (b_ghost->direction == LEFT || b_ghost->direction == RIGHT)
        {
            if (game->pac_attack_mode_delay <= 128)
                current_img = get_blue_ghost_panic_horizontal_animation(game, b_ghost);
            else
                current_img = get_blue_ghost_panic_flashing_horizontal_animation(game, b_ghost);
        }
        else if (b_ghost->direction == UP || b_ghost->direction == DOWN)
        {
            if (game->pac_attack_mode_delay <= 128)
                current_img = get_blue_ghost_panic_vertical_animation(game, b_ghost);
            else
                current_img = get_blue_ghost_panic_flashing_vertical_animation(game, b_ghost);
        }
    }
    // По умолчанию (на всякий случай)
    else
    {
		if (b_ghost->direction == LEFT || b_ghost->direction == RIGHT)
        {
            current_img = get_blue_ghost_horizontal_animation(game, b_ghost);
        }
		else if (b_ghost->direction == UP || b_ghost->direction == DOWN)
        {
            current_img = get_blue_ghost_vertical_animation(game, b_ghost);
        }
    }

    return (current_img);
}