#include "../../includes/headers/so_long.h"

void *get_orange_ghost_current_img(t_game *game, t_ghost *o_ghost)
{
    void *current_img;

    if (o_ghost->is_eaten == 1)
    {
		if (o_ghost->direction == UP)
        	current_img = game->o_ghost->ghost_is_eaten_up;
		else if (o_ghost->direction == DOWN)
        	current_img = game->o_ghost->ghost_is_eaten_down;
		else if (o_ghost->direction == LEFT)
        	current_img = game->o_ghost->ghost_is_eaten_left;
		else if (o_ghost->direction == RIGHT)
        	current_img = game->o_ghost->ghost_is_eaten_right;
    }
    else if (game->pac_attack_mode == 1 && o_ghost->is_eaten == 0 && o_ghost->is_respawned == 0)
    {
        if (o_ghost->direction == LEFT || o_ghost->direction == RIGHT)
        {
            if (game->pac_attack_mode_delay <= 128)
                current_img = get_orange_ghost_panic_horizontal_animation(game, o_ghost);
            else
                current_img = get_orange_ghost_panic_flashing_horizontal_animation(game, o_ghost);
        }
        else if (o_ghost->direction == UP || o_ghost->direction == DOWN)
        {
            if (game->pac_attack_mode_delay <= 128)
                current_img = get_orange_ghost_panic_vertical_animation(game, o_ghost);
            else
                current_img = get_orange_ghost_panic_flashing_vertical_animation(game, o_ghost);
        }
    }
    else
    {
        if (o_ghost->direction == LEFT || o_ghost->direction == RIGHT)
        {
            current_img = get_orange_ghost_horizontal_animation(game, o_ghost);
        }
        else if (o_ghost->direction == UP || o_ghost->direction == DOWN)
        {
            current_img = get_orange_ghost_vertical_animation(game, o_ghost);
        }
    }

    return (current_img);
}