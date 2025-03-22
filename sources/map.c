#include "../includes/headers/so_long.h"

int	open_map(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error open number = %d \n");
		perror("Program");
		exit(1);
	}
	return (fd);
}

int		read_map(int fd)
{
	int	map_size;
	char	*line;

	map_size = 0;
	while (1)
	{
		line = get_next_line(fd);	
		if (line == NULL)
			break ;
		map_size++;
		free(line);
	}
	return (map_size);
}

void	fill_map(t_map *map, int fd)
{
	int		index;
	char	*line;

	index = 0;
	while (index < map->height)
	{
		line = get_next_line(fd);
		map->width = ft_strlen(line);
		if (line[map->width] == '\n')
			line[map->width] = '\0';
		map->map[index] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!map->map[index])
			free_map(map);
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
	close (fd);
	game->map->map = (char **)malloc(sizeof(char *) * (map->height));
	if (!map->map)
	{
		ft_printf("Map malloc error\n");
		exit(1);
	}
	fd = open_map(filename);
	fill_map(map, fd);
	close (fd);
}
