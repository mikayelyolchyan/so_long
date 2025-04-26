#include "../../includes/headers/so_long.h"

static void cleanup_gnl(int fd, char **temp_map, int height)
{
    char *line;

    while ((line = get_next_line(fd)) != NULL)
        free(line);
    while (height > 0)
        free(temp_map[--height]);
    free(temp_map);
    close(fd);
}

static int read_map_finalize(t_map_finalize *params)
{
    int i;

    cleanup_gnl(params->fd, NULL, 0);
    params->map->map = malloc(sizeof(char *) * (params->height + 1));
    if (!params->map->map)
    {
        cleanup_gnl(params->fd, params->temp_map, params->height);
        ft_putstr_fd("Error: Memory allocation failed\n", 2);
        return (0);
    }
    i = 0;
    while (i < params->height)
    {
        params->map->map[i] = params->temp_map[i];
        if (params->map->map[i][params->width - 1] == '\n')
            params->map->map[i][params->width - 1] = '\0';
        i++;
    }
    params->map->map[params->height] = NULL;
    free(params->temp_map);
    params->map->height = params->height;
    params->map->width = params->width;
    return (1);
}

static int read_map_check_line(char *line, int *width, int *i)
{
    *i = 0;
    while (line[*i] && line[*i] != '\n')
    {
        if (is_space(line[*i]))
            return (0);
        (*i)++;
    }
    if (*i > 0 && is_space(line[*i - 1]))
        return (0);
    if (!*width)
        *width = *i;
    else if (*i != *width)
        return (0);
    return (1);
}

static void util(t_map_finalize *params, int fd, int height, int width)
{
	params->fd = fd;
    params->height = height;
    params->width = width;
}

static int check_map_size(int fd, char **temp_map, int width, int height)
{
	if (width < 8)
		return (cleanup_gnl(fd, temp_map, height), \
			ft_putstr_fd("Error: Map must be at least 3x8\n", 2), 0);
	return (1);
}

int	read_map_store_lines(int fd, \
	char **temp_map, int line_count, t_map *map)
{
    char			*line;
    int				height;
    int 			width;
    int				i;
    t_map_finalize	params;

	height = 0;
	width = 0;
    while (height < line_count)
    {
        line = get_next_line(fd);
        if (!line || line[0] == '\n' || line[0] == '\0')
            return (free(line), cleanup_gnl(fd, temp_map, height), \
                    ft_putstr_fd("Error: Unexpected end of file\n", 2), 0);
        if (is_space(line[0]) || !read_map_check_line(line, &width, &i))
            return (free(line), cleanup_gnl(fd, temp_map, height), \
		ft_putstr_fd("Error: Map have invalid isspace characters\n", 2), 0);
        temp_map[height++] = line;
    }
	if (check_map_size(fd, temp_map, width, height) == 0)
		return (0);
	params.temp_map = temp_map;
	params.map = map;
	util(&params, fd, height, width);
    return (read_map_finalize(&params));
}