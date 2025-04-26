#include "../../includes/headers/so_long.h"

typedef struct s_map_finalize
{
    int		fd;
    char	**temp_map;
    t_map	*map;
    int		height;
    int		width;
}	t_map_finalize;

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || \
		c == '\r' || c == '\v' || c == '\f');
}

int check_extension(char *filename)
{
    int len;

    if (!filename)
    {
        ft_putstr_fd("Error: Filename is NULL\n", 2);
        return (0);
    }
    len = ft_strlen(filename);
    if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
    {
        ft_putstr_fd("Error: File must have .ber extension\n", 2);
        return (0);
    }
    return (1);
}

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

//static int read_map_count_lines(int fd, int *line_count)
//{
//    char	*line;
//    int	started;

//	started = 0;
//    *line_count = 0;
//    while (1)
//    {
//        line = get_next_line(fd);
//        if (!line)
//            break ;
//        if (!started)
//        {
//            if (line[0] == '\n' || line[0] == '\0')
//            {
//                free(line);
//                continue ;
//            }
//            started = 1;
//        }
//        if (line[0] == '\n' || line[0] == '\0')
//        {
//            free(line);
//            break ;
//        }
//        (*line_count)++;
//        free(line);
//    }
//    return (*line_count >= 3);
//}


static int read_map_allocate(int fd, char ***temp_map, int line_count)
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

static int	read_map_store_lines(int fd, char **temp_map, int line_count, t_map *map)
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

int	read_map(char *filename, t_map *map)
{
    int fd;
    int line_count;

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

int	check_structure(t_map *map)
{
    int i;

    if (!map || !map->map)
        return (ft_putstr_fd("Error: Invalid map structure\n", 2), 0);
    i = 0;
    while (i < map->width)
    {
        if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
            return (ft_putstr_fd("Error: Map not surrounded by walls\n", 2), 0);
        i++;
    }
    i = 0;
    while (i < map->height)
    {
        if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
            return (ft_putstr_fd("Error: Map not surrounded by walls\n", 2), 0);
        i++;
    }
    return (1);
}

static int	check_elements_init(t_map *map, t_point *start, t_check *total, int *ghosts)
{
    int i;

    if (!map || !map->map || !start || !total)
    {
        ft_putstr_fd("Error: Invalid arguments\n", 2);
        return (0);
    }
    i = 0;
    while (i < 4)
        ghosts[i++] = 0;
    total->coins = 0;
    total->power_ups = 0;
    total->exits = 0;
    total->portals = 0;
    total->ghost_count = 0;
    start->x = -1;
    return (1);
}

static int check_elements_portal(t_map *map, int i, int j, int *portals)
{
    if (j == 1)
    {
        portals[0]++;
        if ((i > 0 && map->map[i - 1][j] != '1') ||
            (i < map->height - 1 && map->map[i + 1][j] != '1') ||
            map->map[i][j - 1] != '1' || map->map[i][j + 1] == '1' ||
            map->map[i][j + 1] == 'E')
            return (ft_putstr_fd(\
				"Error: Left portal invalid surroundings\n", 2), 0);
    }
    else if (j == map->width - 2)
    {
        portals[1]++;
        if ((i > 0 && map->map[i - 1][j] != '1') ||
            (i < map->height - 1 && map->map[i + 1][j] != '1') ||
            map->map[i][j + 1] != '1' || map->map[i][j - 1] == '1' ||
            map->map[i][j - 1] == 'E')
            return (ft_putstr_fd(\
				"Error: Right portal invalid surroundings\n", 2), 0);
    }
    else
        return (ft_putstr_fd("Error: Portal in invalid position\n", 2), 0);
    return (1);
}

static int check_elements_validate_util(int *ghosts)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (ghosts[i] != 1)
			return (ft_putstr_fd("Error: Exactly one of each ghost required\n", 2), 0);
	}
	return (1);
}

static int	check_elements_validate(t_check *total, t_point *start, int *ghosts, int *portals)
{
    if (start->x == -1)
        return (ft_putstr_fd("Error: No player\n", 2), 0);
    if (total->coins < 1)
        return (ft_putstr_fd("Error: At least one coin required\n", 2), 0);
    if (total->power_ups != 0 && total->power_ups != 4)
        return (ft_putstr_fd("Error: Powerups must be 0 or exactly 4\n", 2), 0);
    if (total->exits != 1)
        return (ft_putstr_fd("Error: Exactly one exit required\n", 2), 0);
    if (total->portals != 0 && (total->portals != 2 || \
		portals[0] != 1 || portals[1] != 1))
        return (ft_putstr_fd("Error: Portals must be 0 or exactly \
			two at x=1 and x=width-2\n", 2), 0);
    if (total->ghost_count != 0 && total->ghost_count != 4)
        return (ft_putstr_fd("Error: Ghosts must be 0 or exactly 4\n", 2), 0);
    if (total->ghost_count == 4)
    {
		if (check_elements_validate_util(ghosts) == 0)
			return (0);
    }
    return (1);
}

static int	check_player(t_point *start, char c, int i, int j)
{
	if (c == 'P')
	{
		if (start->x != -1)
		{
			ft_putstr_fd("Error: Multiple players\n", 2);
			return (0);
		}
		start->x = j;
		start->y = i;
	}
	return (1);
}

static int	check_collectibles(t_check *total, char c)
{
	if (c == 'C')
		total->coins++;
	else if (c == 'U')
		total->power_ups++;
	else if (c == 'E')
		total->exits++;
	return (1);
}

static int	check_portals(t_map *map, t_check *total, int i, int j, int *portals)
{
	if (map->map[i][j] == 'T')
	{
		total->portals++;
		if (!check_elements_portal(map, i, j, portals))
			return (0);
	}
	return (1);
}

static int	check_ghosts(t_check *total, char c, int *ghosts)
{
	if (c == 'R')
	{
		ghosts[0]++;
		total->ghost_count++;
	}
	else if (c == 'B')
	{
		ghosts[1]++;
		total->ghost_count++;
	}
	else if (c == 'O')
	{
		ghosts[2]++;
		total->ghost_count++;
	}
	else if (c == 'M')
	{
		ghosts[3]++;
		total->ghost_count++;
	}
	return (1);
}

static int	check_invalid_char(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'U'
		&& c != 'E' && c != 'T' && c != 'R' && c != 'B' && c != 'O' && c != 'M')
	{
		ft_putstr_fd("Error: Invalid character\n", 2);
		return (0);
	}
	return (1);
}

static int	check_elements_loop(t_map *map, t_point *start, t_check *total, int *ghosts)
{
	int		i;
	int		j;
	int		portals[2];
	char	c;

	i = 0;
	portals[0] = 0;
	portals[1] = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			c = map->map[i][j];
			if (!check_player(start, c, i, j) \
				|| !check_collectibles(total, c) \
				|| !check_portals(map, total, i, j, portals) \
				|| !check_ghosts(total, c, ghosts) \
				|| !check_invalid_char(c))
				return (0);
			j++;
		}
		i++;
	}
	return (check_elements_validate(total, start, ghosts, portals));
}

int check_elements(t_map *map, t_point *start, t_check *total)
{
    int ghosts[4];

    if (!check_elements_init(map, start, total, ghosts))
        return (0);
    return (check_elements_loop(map, start, total, ghosts));
}

int **create_visited(int height, int width, int i)
{
    int **visited;

    visited = malloc(sizeof(int *) * height);
    if (!visited)
        return (NULL);
    i = -1;
    while (++i < height)
    {
        visited[i] = malloc(sizeof(int) * width);
        if (!visited[i])
        {
            while (i > 0)
                free(visited[--i]);
            free(visited);
            return (NULL);
        }
    }
    i = -1;
    while (++i < height)
    {
        int j = 0;
        while (j < width)
            visited[i][j++] = 0;
    }
    return (visited);
}

void free_visited(int **visited, int height)
{
    int i;

    if (!visited)
        return;
    i = 0;
    while (i < height)
        free(visited[i++]);
    free(visited);
}

int flood_fill_util(t_map *map, t_point pos, t_check *reached, int **visited)
{
	if (!map || !map->map || !reached || !visited)
		return (1);
	if (pos.y < 0 || pos.y >= map->height || pos.x < 0 || pos.x >= map->width)
		return (1);
	if (visited[pos.y][pos.x] || map->map[pos.y][pos.x] == '1' ||
		map->map[pos.y][pos.x] == 'R' || map->map[pos.y][pos.x] == 'B' ||
		map->map[pos.y][pos.x] == 'O' || map->map[pos.y][pos.x] == 'M')
		return (1);
	return (0);
}

void flood_fill(t_map *map, t_point pos, t_check *reached, int **visited)
{
    t_point next;

    if (flood_fill_util(map, pos, reached, visited) == 1)
		return ;
    visited[pos.y][pos.x] = 1;
    if (map->map[pos.y][pos.x] == 'C')
        reached->coins++;
    else if (map->map[pos.y][pos.x] == 'U')
        reached->power_ups++;
    else if (map->map[pos.y][pos.x] == 'E')
        reached->exits++;
    else if (map->map[pos.y][pos.x] == 'T')
        reached->portals++;
    next.y = pos.y - 1;
    next.x = pos.x;
    flood_fill(map, next, reached, visited);
    next.y = pos.y + 1;
    flood_fill(map, next, reached, visited);
    next.x = pos.x - 1;
    next.y = pos.y;
    flood_fill(map, next, reached, visited);
    next.x = pos.x + 1;
    flood_fill(map, next, reached, visited);
}

static int validate_map_init(t_check *total, t_check *reached)
{
    total->coins = 0;
    total->power_ups = 0;
    total->exits = 0;
    total->portals = 0;
    total->ghost_count = 0;
    reached->coins = 0;
    reached->power_ups = 0;
    reached->exits = 0;
    reached->portals = 0;
    reached->ghost_count = 0;
    return (1);
}

static int validate_map_check(char *filename, t_map *map, t_point *start, t_check *total)
{
    if (!filename || !map)
    {
        ft_putstr_fd("Error: Invalid arguments\n", 2);
        return (0);
    }
    if (!check_extension(filename) || !read_map(filename, map))
        return (0);
    if (!check_structure(map) || !check_elements(map, start, total))
    {
        free_map(map);
        return (0);
    }
    return (1);
}

int validate_map(char *filename, t_map *map)
{
    t_point start;
    t_check total;
    t_check reached;
    int **visited;

    if (!validate_map_init(&total, &reached))
        return (0);
    if (!validate_map_check(filename, map, &start, &total))
        return (0);
    visited = create_visited(map->height, map->width, 0);
    if (!visited)
    {
        free_map(map);
        ft_putstr_fd("Error: Memory allocation failed\n", 2);
        return (0);
    }
    flood_fill(map, start, &reached, visited);
    free_visited(visited, map->height);
    if (reached.coins != total.coins || reached.power_ups != total.power_ups ||
        reached.exits != total.exits || reached.portals != total.portals)
        return (free_map(map), \
			ft_putstr_fd("Error: Not all elements reachable\n", 2), 0);
    map->ghost_count = total.ghost_count;
    return (1);
}

void free_map(t_map *map)
{
    int i;

    if (!map || !map->map)
        return;
    i = 0;
    while (map->map[i])
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
    map->map = NULL;
}
