#include "../../includes/headers/so_long.h"

void	init_game_state(t_game *game, t_map *map)
{
	game->frame = 0;
	game->frame_delay = 0;
	game->ghost_attack_mode = 0;
	game->ghost_attack_mode_delay = 0;
	game->power_up_img_delay = 0;
	game->pac_attack_mode = 0;
	game->last_pac_attack_mode = 0;
	game->pac_attack_mode_delay = 0;
	game->score = 0;
	game->eated_dots = 0;
	game->game_start = 0;
	game->game_start_delay = 0;
	game->game_win = 0;
	game->map_flashing_frame = 0;
	game->map_flashing_delay = 0;
	game->map_flashing_count = 0;
	game->game_restart = 0;
	map->x = 0;
	map->y = 0;
}
