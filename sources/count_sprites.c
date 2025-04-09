#include "../includes/headers/so_long.h"

void	count_sprites(t_game *game)
{
	int	x;
	int	y;
	t_map *map;

	map = game->map;
	y = 0;
	while(map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'U')
			{
				map->power_up_dots_count++;
				//printf("Found 'U' at map_x=%d, map_y=%d\n", x, y); // Отладка
			}
			if (map->map[y][x] == 'C')
			{
				map->dots_count++;
			}
			x++;
		}
		y++;
	}
	//printf("Total power-up dots: %d\n", map->power_up_dots_count);
}