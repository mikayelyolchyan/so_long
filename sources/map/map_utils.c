#include "../../includes/headers/so_long.h"

int	open_map(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error open number = %d \n", fd);
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