#include "../../includes/headers/so_long.h"

static void handle_fill_error(t_map *map, char *line, int index)
{
	if (!line || !map->map[index])
	{
		ft_printf("Error: Fill map failed\n");
		free_map(map);
		if (line)
			free(line);
		exit (1);
	}
}

void	fill_map(t_map *map, int fd)
{
	int		index;
	char	*line;

	index = 0;
	while (index < map->height)
	{
		line = get_next_line(fd);
		map->width = ft_strlen(line) - 1;
		if (line[map->width] == '\n')
			line[map->width] = '\0';
		map->map[index] = (char *)malloc(sizeof(char) * (map->width + 1));
		handle_fill_error(map, line, index);
		ft_strlcpy(map->map[index], line, map->width + 1);
		index++;
		free(line);
	}
}

void	create_map(char *filename, t_game *game)
{
	int		fd;
	t_map	*map;

	map = game->map;
	fd = open_map(filename);
	map->height = read_map(fd);
	close(fd);
	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
	{
		ft_printf("Map malloc error\n");
		exit(1);
	}
	map->map[map->height] = NULL;
	fd = open_map(filename);
	fill_map(map, fd);
	close (fd);
}