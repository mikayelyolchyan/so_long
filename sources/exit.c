#include "../includes/headers/so_long.h"

void free_pacman_images(t_game *game)
{
    mlx_destroy_image(game->mlx, game->player->pac_open_right);
    mlx_destroy_image(game->mlx, game->player->pac_open_left);
    mlx_destroy_image(game->mlx, game->player->pac_open_up);
    mlx_destroy_image(game->mlx, game->player->pac_open_down);
    mlx_destroy_image(game->mlx, game->player->pac_semi_left);
    mlx_destroy_image(game->mlx, game->player->pac_semi_right);
    mlx_destroy_image(game->mlx, game->player->pac_semi_up);
    mlx_destroy_image(game->mlx, game->player->pac_semi_down);
    mlx_destroy_image(game->mlx, game->player->pac_closed);
    mlx_destroy_image(game->mlx, game->player->pac_black);
    mlx_destroy_image(game->mlx, game->player->dying1);
    mlx_destroy_image(game->mlx, game->player->dying2);
    mlx_destroy_image(game->mlx, game->player->dying3);
    mlx_destroy_image(game->mlx, game->player->dying4);
    mlx_destroy_image(game->mlx, game->player->dying5);
    mlx_destroy_image(game->mlx, game->player->dying6);
    mlx_destroy_image(game->mlx, game->player->dying7);
    mlx_destroy_image(game->mlx, game->player->dying8);
    mlx_destroy_image(game->mlx, game->player->dying9);
    mlx_destroy_image(game->mlx, game->player->dying10);
    mlx_destroy_image(game->mlx, game->player->woosh);
}

void free_ghost_images(t_game *game, t_ghost *ghost)
{
    mlx_destroy_image(game->mlx, ghost->ghost_down1);
    mlx_destroy_image(game->mlx, ghost->ghost_down2);
    mlx_destroy_image(game->mlx, ghost->ghost_up1);
    mlx_destroy_image(game->mlx, ghost->ghost_up2);
    mlx_destroy_image(game->mlx, ghost->ghost_left1);
    mlx_destroy_image(game->mlx, ghost->ghost_left2);
    mlx_destroy_image(game->mlx, ghost->ghost_right1);
    mlx_destroy_image(game->mlx, ghost->ghost_right2);
    mlx_destroy_image(game->mlx, ghost->ghost_is_eaten_right);
    mlx_destroy_image(game->mlx, ghost->ghost_is_eaten_left);
    mlx_destroy_image(game->mlx, ghost->ghost_is_eaten_up);
    mlx_destroy_image(game->mlx, ghost->ghost_is_eaten_down);
    mlx_destroy_image(game->mlx, ghost->ghost_panic1a);
    mlx_destroy_image(game->mlx, ghost->ghost_panic1b);
    mlx_destroy_image(game->mlx, ghost->ghost_panic2a);
    mlx_destroy_image(game->mlx, ghost->ghost_panic2b);
}

void free_font_images(t_game *game)
{
    mlx_destroy_image(game->mlx, game->font->zero);
    mlx_destroy_image(game->mlx, game->font->one);
    mlx_destroy_image(game->mlx, game->font->two);
    mlx_destroy_image(game->mlx, game->font->three);
    mlx_destroy_image(game->mlx, game->font->four);
    mlx_destroy_image(game->mlx, game->font->five);
    mlx_destroy_image(game->mlx, game->font->six);
    mlx_destroy_image(game->mlx, game->font->seven);
    mlx_destroy_image(game->mlx, game->font->eight);
    mlx_destroy_image(game->mlx, game->font->nine);
}

int ft_exit(t_game *game)
{
    // Освобождение окна
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    // Освобождение изображений карты
    if (game->map->wall_img)
        mlx_destroy_image(game->mlx, game->map->wall_img);
    if (game->map->black_wall_img)
        mlx_destroy_image(game->mlx, game->map->black_wall_img);
    if (game->map->food_img)
        mlx_destroy_image(game->mlx, game->map->food_img);
    if (game->map->portal_img)
        mlx_destroy_image(game->mlx, game->map->portal_img);
    if (game->map->logo_img)
        mlx_destroy_image(game->mlx, game->map->logo_img);
    if (game->map->power_up_img)
        mlx_destroy_image(game->mlx, game->map->power_up_img);
    if (game->map->white_wall_img)
        mlx_destroy_image(game->mlx, game->map->white_wall_img);
    if (game->map->red_wall_img)
        mlx_destroy_image(game->mlx, game->map->red_wall_img);
    // Освобождение остальных изображений
    free_pacman_images(game);
	if (game->map->ghost_count == 4)
	{
    	free_ghost_images(game, game->r_ghost);
    	free_ghost_images(game, game->o_ghost);
    	free_ghost_images(game, game->m_ghost);
    	free_ghost_images(game, game->b_ghost);
	}
    free_font_images(game);
    // Освобождение дисплея
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    // Освобождение структур
    if (game->map)
    {
        if (game->map->power_up_dots_array)
            free(game->map->power_up_dots_array);
        free_map(game->map);
        free(game->map);
    }
    if (game->player)
        free(game->player);
    // Освобождение призраков (всегда, так как malloc без условия)
    if (game->r_ghost)
        free(game->r_ghost);
    if (game->o_ghost)
        free(game->o_ghost);
    if (game->m_ghost)
        free(game->m_ghost);
    if (game->b_ghost)
        free(game->b_ghost);
    if (game->font)
        free(game->font);
    exit(0);
}
