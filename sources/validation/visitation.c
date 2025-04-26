#include "../../includes/headers/so_long.h"

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
