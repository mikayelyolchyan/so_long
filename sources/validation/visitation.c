/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:50:18 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 23:52:02 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

int	**create_visited(int height, int width, int i)
{
	int	**visited;
	int	j;

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
			return (free(visited), NULL);
		}
	}
	i = -1;
	while (++i < height)
	{
		j = 0;
		while (j < width)
			visited[i][j++] = 0;
	}
	return (visited);
}

void	free_visited(int **visited, int height)
{
	int	i;

	if (!visited)
		return ;
	i = 0;
	while (i < height)
		free(visited[i++]);
	free(visited);
}
