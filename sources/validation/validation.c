#include "../../includes/headers/so_long.h"

int check_extension(char *filename)
{
    int len;

    len = 0;
    while (filename[len])
        len++;
    if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
    {
        ft_putstr_fd("Error: File must have .ber extension\n", 2);
        return (0);
    }
    return (1);
}
int read_map(char *filename, t_map *map)
{
    int fd;
    char *line;
    int height;
    int width;
    int len;

    // Первая проверка: открытие файла
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("Error: Cannot open file\n", 2);
        return (0);
    }

    // Подсчёт размеров карты и проверка валидности
    height = 0;
    width = 0;
    line = get_next_line(fd);
    if (!line || line[0] == ' ' || line[0] == '\f' || line[0] == '\n' ||
        line[0] == '\r' || line[0] == '\t' || line[0] == '\v')
    {
        ft_putstr_fd("Error: Map must start immediately with valid content\n", 2);
        free(line);
        close(fd);
        return (0);
    }

    while (line && line[0] != '\n')
    {
        len = 0;
        while (line[len] && line[len] != '\n')
            len++;
        if (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\f' ||
                        line[len - 1] == '\r' || line[len - 1] == '\t' ||
                        line[len - 1] == '\v'))
        {
            ft_putstr_fd("Error: Trailing whitespace in map\n", 2);
            free(line);
            close(fd);
            return (0);
        }
        if (!width)
            width = len;
        else if (len != width)
        {
            ft_putstr_fd("Error: Map is not rectangular\n", 2);
            free(line);
            close(fd);
            return (0);
        }
        height++;
        free(line);
        line = get_next_line(fd);
    }

    if (line)
    {
        ft_putstr_fd("Error: Extra content after map\n", 2);
        free(line);
        close(fd);
        return (0);
    }
    close(fd);

    // Проверка минимальных размеров карты
    if (height < 3 || width < 5)
    {
        ft_putstr_fd("Error: Map must be at least 3x5\n", 2);
        return (0);
    }

    // Выделение памяти после всех проверок
    map->map = malloc(sizeof(char *) * (height + 1));
    if (!map->map)
        return (0);
    map->height = height;
    map->width = width;

    // Второе чтение файла для заполнения карты
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("Error: Cannot open file\n", 2);
        free(map->map);
        return (0);
    }

    height = 0;
    while (height < map->height)
    {
        map->map[height] = get_next_line(fd);
        if (!map->map[height])
        {
            ft_putstr_fd("Error: Failed to read map\n", 2);
            while (height > 0)
                free(map->map[--height]);
            free(map->map);
            close(fd);
            return (0);
        }
        len = 0;
        while (map->map[height][len] && map->map[height][len] != '\n')
            len++;
        if (len != width || (len > 0 && (map->map[height][len - 1] == ' ' ||
                                         map->map[height][len - 1] == '\f' ||
                                         map->map[height][len - 1] == '\r' ||
                                         map->map[height][len - 1] == '\t' ||
                                         map->map[height][len - 1] == '\v')))
        {
            ft_putstr_fd("Error: Invalid map format or trailing whitespace\n", 2);
            while (height >= 0)
                free(map->map[height--]);
            free(map->map);
            close(fd);
            return (0);
        }
        height++;
    }
    map->map[height] = NULL;

    // Проверка на лишний контент после карты
    line = get_next_line(fd);
    if (line)
    {
        ft_putstr_fd("Error: Extra content after map\n", 2);
        free(line);
        while (height > 0)
            free(map->map[--height]);
        free(map->map);
        close(fd);
        return (0);
    }

    close(fd);
    return (1);
}

int check_structure(t_map *map)
{
    int i;

    if (!map || !map->map)
    {
        ft_putstr_fd("Error: Invalid map structure\n", 2);
        return (0);
    }
    i = 0;
    while (i < map->width)
    {
        if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
        {
            ft_putstr_fd("Error: Map not surrounded by walls\n", 2);
            return (0);
        }
        i++;
    }
    i = 0;
    while (i < map->height)
    {
        if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
        {
            ft_putstr_fd("Error: Map not surrounded by walls\n", 2);
            return (0);
        }
        i++;
    }
    return (1);
}

int check_elements(t_map *map, t_point *start, t_check *total)
{
    int ghosts[4];
    int i;
    int j;
    int left_portal;
    int right_portal;

    ghosts[0] = 0; // R
    ghosts[1] = 0; // B
    ghosts[2] = 0; // O
    ghosts[3] = 0; // M
    total->coins = 0;
    total->power_ups = 0;
    total->exits = 0;
    total->portals = 0;
    total->ghost_count = 0;
    start->x = -1;
    left_portal = 0;
    right_portal = 0;
    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            char c = map->map[i][j];
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
            else if (c == 'C')
                total->coins++;
            else if (c == 'U')
                total->power_ups++;
            else if (c == 'E')
                total->exits++;
            else if (c == 'T')
            {
                total->portals++;
                if (j == 1)
                {
                    left_portal++;
                    if ((i > 0 && map->map[i - 1][j] != '1') ||
                        (i < map->height - 1 && map->map[i + 1][j] != '1') ||
                        map->map[i][j - 1] != '1' || map->map[i][j + 1] == '1' ||
                        map->map[i][j + 1] == 'E')
                    {
                        ft_putstr_fd("Error: Left portal invalid surroundings\n", 2);
                        return (0);
                    }
                }
                else if (j == map->width - 2)
                {
                    right_portal++;
                    if ((i > 0 && map->map[i - 1][j] != '1') ||
                        (i < map->height - 1 && map->map[i + 1][j] != '1') ||
                        map->map[i][j + 1] != '1' || map->map[i][j - 1] == '1' ||
                        map->map[i][j - 1] == 'E')
                    {
                        ft_putstr_fd("Error: Right portal invalid surroundings\n", 2);
                        return (0);
                    }
                }
                else
                {
                    ft_putstr_fd("Error: Portal in invalid position\n", 2);
                    return (0);
                }
            }
            else if (c == 'R')
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
            else if (c != '1' && c != '0')
            {
                ft_putstr_fd("Error: Invalid character\n", 2);
                return (0);
            }
            j++;
        }
        i++;
    }
    if (start->x == -1)
    {
        ft_putstr_fd("Error: No player\n", 2);
        return (0);
    }
    if (total->coins < 1)
    {
        ft_putstr_fd("Error: At least one coin required\n", 2);
        return (0);
    }
    if (total->power_ups != 0 && total->power_ups != 4)
    {
        ft_putstr_fd("Error: Power-ups must be 0 or exactly 4\n", 2);
        return (0);
    }
    if (total->exits != 1)
    {
        ft_putstr_fd("Error: Exactly one exit required\n", 2);
        return (0);
    }
    if (total->portals != 0 && (total->portals != 2 || left_portal != 1 || right_portal != 1))
    {
        ft_putstr_fd("Error: Portals must be 0 or exactly two at x=1 and x=width-2\n", 2);
        return (0);
    }
    if (total->ghost_count != 0 && total->ghost_count != 4)
    {
        ft_putstr_fd("Error: Ghosts l be 0 or exactly 4\n", 2);
        return (0);
    }
    if (total->ghost_count == 4)
    {
        i = 0;
        while (i < 4)
        {
            if (ghosts[i] != 1)
            {
                ft_putstr_fd("Error: Exactly one of each ghost required\n", 2);
                return (0);
            }
            i++;
        }
    }
    return (1);
}

int **create_visited(int height, int width)
{
    int **visited;
    int i;
    int j;

    visited = malloc(sizeof(int *) * height);
    if (!visited)
        return (NULL);
    i = 0;
    while (i < height)
    {
        visited[i] = malloc(sizeof(int) * width);
        if (!visited[i])
        {
            while (i > 0)
            {
                i--;
                free(visited[i]);
            }
            free(visited);
            return (NULL);
        }
        j = 0;
        while (j < width)
        {
            visited[i][j] = 0;
            j++;
        }
        i++;
    }
    return (visited);
}

void free_visited(int **visited, int height)
{
    int i;

    i = 0;
    while (i < height)
    {
        free(visited[i]);
        i++;
    }
    free(visited);
}

void flood_fill(t_map *map, t_point pos, t_check *reached, int **visited)
{
    t_point next;

    if (pos.y < 0 || pos.y >= map->height || pos.x < 0 || pos.x >= map->width)
        return;
    if (visited[pos.y][pos.x] || map->map[pos.y][pos.x] == '1' ||
        map->map[pos.y][pos.x] == 'R' || map->map[pos.y][pos.x] == 'B' ||
        map->map[pos.y][pos.x] == 'O' || map->map[pos.y][pos.x] == 'M')
        return;
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

int validate_map(char *filename, t_map *map)
{
    t_point start;
    t_check total;
    t_check reached;
    int **visited;

    total.coins = 0;
    total.power_ups = 0;
    total.exits = 0;
    total.portals = 0;
    total.ghost_count = 0;
    reached.coins = 0;
    reached.power_ups = 0;
    reached.exits = 0;
    reached.portals = 0;
    reached.ghost_count = 0;
    if (!check_extension(filename) || !read_map(filename, map))
        return (0);
    if (!check_structure(map) || !check_elements(map, &start, &total))
    {
        free_map(map);
        return (0);
    }
    visited = create_visited(map->height, map->width);
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
    {
        free_map(map);
        ft_putstr_fd("Error: Not all elements reachable\n", 2);
        return (0);
    }
    map->ghost_count = total.ghost_count;
    return (1);
}
