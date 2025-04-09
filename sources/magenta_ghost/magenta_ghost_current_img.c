#include "../../includes/headers/so_long.h"

void *get_magenta_ghost_current_img(t_game *game, t_ghost *m_ghost)
{
    void *current_img;

    // Если призрак "съеден" и движется к спавну
    if (m_ghost->is_eaten == 1)
    {
        current_img = game->m_ghost->ghost_is_eaten; // Изображение глаз
    }
    // Режим паники применяется только к несъеденным призракам при pac_attack_mode == 1
    else if (game->pac_attack_mode == 1 && m_ghost->is_eaten == 0 && m_ghost->is_respawned == 0)
    {
        if (m_ghost->direction == LEFT || m_ghost->direction == RIGHT)
        {
            if (game->pac_attack_mode_delay <= 128)
                current_img = get_magenta_ghost_panic_horizontal_animation(game, m_ghost);
            else
                current_img = get_magenta_ghost_panic_flashing_horizontal_animation(game, m_ghost);
        }
        else if (m_ghost->direction == UP || m_ghost->direction == DOWN)
        {
            if (game->pac_attack_mode_delay <= 128)
                current_img = get_magenta_ghost_panic_vertical_animation(game, m_ghost);
            else
                current_img = get_magenta_ghost_panic_flashing_vertical_animation(game, m_ghost);
        }
    }
    // По умолчанию (на всякий случай)
    else
    {
		if (m_ghost->direction == LEFT || m_ghost->direction == RIGHT)
        {
            current_img = get_magenta_ghost_horizontal_animation(game, m_ghost);
        }
		else if (m_ghost->direction == UP || m_ghost->direction == DOWN)
        {
            current_img = get_magenta_ghost_vertical_animation(game, m_ghost);
        }
    }

    return (current_img);
}