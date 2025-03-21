#include "../includes/headers/so_long.h"

void	free_map(t_data *data)
{
	int	index;

	index = 0;
	while (data->map[index])
	{
		free(data->map[index]);
		index++;
	}
	free(data->map);
	ft_printf("Error malloc map[index]\n");
	exit(1);
}

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
	int		map_size;
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

void	create_map(char *filename, t_data *data)
{
	int		fd;
	char	*line;
	int		map_size;
	int		index;
	size_t		line_size;

	fd = open_map(filename);
	map_size = read_map(fd);
	close (fd);
	data->map = (char **)malloc(sizeof(char *) * (map_size));
	if (!data->map)
	{
		ft_printf("Map malloc error\n");
		exit(1);
	}
	fd = open_map(filename);
	
	index = 0;
	while (index < map_size)
	{
		line = get_next_line(fd);
		line_size = ft_strlen(line);
		if (line[line_size] == '\n')
			line[line_size] = '\0';
		data->map[index] = (char *)malloc(sizeof(char) * (line_size + 1));
		if (!data->map[index])
			free_map(data);
		ft_strlcpy(data->map[index], line, line_size + 1);
		index++;
		free(line);
	}
}
