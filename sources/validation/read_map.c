/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:35:48 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/28 17:43:14 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

static int	process_line(char *line, int *line_count, \
	int *started, int *found_empty)
{
	if (!(*started))
	{
		if (line[0] == '\n' || line[0] == '\0')
			return (0);
		*started = 1;
	}
	if (line[0] == '\n' || line[0] == '\0')
	{
		*found_empty = 1;
		return (0);
	}
	if (*found_empty)
	{
		return (-1);
	}
	(*line_count)++;
	return (0);
}

static int	read_map_count_lines(int fd, int *line_count)
{
	char	*line;
	int		started;
	int		found_empty;
	int		result;

	started = 0;
	found_empty = 0;
	*line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		result = process_line(line, line_count, &started, &found_empty);
		free(line);
		if (result == -1)
			return (ft_printf(\
				"Error: Unexpected non-empty line after empty line\n", 2), 0);
	}
	if (found_empty)
		return (ft_printf("Error: Empty line(s) after map\n", 2), 0);
	return (*line_count >= 3);
}

static int	read_map_allocate(int fd, char ***temp_map, int line_count)
{
	*temp_map = ft_calloc(sizeof(char *), line_count);
	if (!*temp_map)
	{
		ft_printf("Error: Memory allocation failed\n", 2);
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
		return (ft_printf("Error: Invalid arguments\n", 2), 0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: Cannot open file\n", 2), 0);
	if (!read_map_count_lines(fd, &line_count))
	{
		close(fd);
		return (ft_printf("Error: Map must be at least 3x5\n", 2), 0);
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
