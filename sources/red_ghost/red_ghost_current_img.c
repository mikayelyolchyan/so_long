#include "../../includes/headers/so_long.h"

void *get_red_ghost_current_img(t_game *game, t_ghost *r_ghost)
{
    void *current_img;

    // Если призрак "съеден" и движется к спавну
    if (r_ghost->is_eaten == 1)
    {
		if (r_ghost->direction == UP)
        	current_img = game->r_ghost->ghost_is_eaten_up;
		else if (r_ghost->direction == DOWN)
        	current_img = game->r_ghost->ghost_is_eaten_down;
		else if (r_ghost->direction == LEFT)
        	current_img = game->r_ghost->ghost_is_eaten_left;
		else if (r_ghost->direction == RIGHT)
        	current_img = game->r_ghost->ghost_is_eaten_right;
    }
    // Режим паники применяется только к несъеденным призракам при pac_attack_mode == 1
    else if (game->pac_attack_mode == 1 && r_ghost->is_eaten == 0 && r_ghost->is_respawned == 0)
    {
        if (r_ghost->direction == LEFT || r_ghost->direction == RIGHT)
        {
            if (game->pac_attack_mode_delay <= 128)
                current_img = get_red_ghost_panic_horizontal_animation(game, r_ghost);
            else
                current_img = get_red_ghost_panic_flashing_horizontal_animation(game, r_ghost);
        }
        else if (r_ghost->direction == UP || r_ghost->direction == DOWN)
        {
            if (game->pac_attack_mode_delay <= 128)
                current_img = get_red_ghost_panic_vertical_animation(game, r_ghost);
            else
                current_img = get_red_ghost_panic_flashing_vertical_animation(game, r_ghost);
        }
    }
    // По умолчанию (на всякий случай)
    else
    {
		if (r_ghost->direction == LEFT || r_ghost->direction == RIGHT)
        {
            current_img = get_red_ghost_horizontal_animation(game, r_ghost);
        }
		else if (r_ghost->direction == UP || r_ghost->direction == DOWN)
        {
            current_img = get_red_ghost_vertical_animation(game, r_ghost);
        }
    }

    return (current_img);
}