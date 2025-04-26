/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:35:48 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 23:37:11 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

static int	process_line(char *line, int *line_count, int *started)
{
	if (!(*started))
	{
		if (line[0] == '\n' || line[0] == '\0')
			return (0);
		*started = 1;
	}
	if (line[0] == '\n' || line[0] == '\0')
		return (1);
	(*line_count)++;
	return (0);
}

static int	read_map_count_lines(int fd, int *line_count)
{
	char	*line;
	int		started;
	int		stop_reading;

	started = 0;
	*line_count = 0;
	stop_reading = 0;
	while (!stop_reading)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		stop_reading = process_line(line, line_count, &started);
		free(line);
	}
	return (*line_count >= 3);
}

static int	read_map_allocate(int fd, char ***temp_map, int line_count)
{
	*temp_map = malloc(sizeof(char *) * line_count);
	if (!*temp_map)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
		close(fd);
		return (0);
	}
	return (1);
}

int	read_map(char *filename, t_map *map)
{
	int	fd;
	int	line_count;	

	if (!filename || !map)
		return (ft_putstr_fd("Error: Invalid arguments\n", 2), 0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error: Cannot open file\n", 2), 0);
	if (!read_map_count_lines(fd, &line_count))
	{
		close(fd);
		return (ft_putstr_fd("Error: Map must be at least 3x8\n", 2), 0);
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || !read_map_allocate(fd, &map->map, line_count))
	{
		if (fd >= 0)
			close(fd);
		return (0);
	}
	return (read_map_store_lines(fd, map->map, line_count, map));
}
