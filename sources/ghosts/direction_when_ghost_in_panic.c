/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_when_ghost_in_panic.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:30:27 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 17:30:28 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

void	direction_when_ghost_in_panic(t_ghost *ghost, t_dist *dist)
{
	dist->max_dist = -1;
	ghost->pending_direction = UP;
	if (dist->dist_up != INT_MAX && dist->dist_up > dist->max_dist)
	{
		dist->max_dist = dist->dist_up;
		ghost->pending_direction = UP;
	}
	if (dist->dist_left != INT_MAX && dist->dist_left > dist->max_dist)
	{
		dist->max_dist = dist->dist_left;
		ghost->pending_direction = LEFT;
	}
	if (dist->dist_down != INT_MAX && dist->dist_down > dist->max_dist)
	{
		dist->max_dist = dist->dist_down;
		ghost->pending_direction = DOWN;
	}
	if (dist->dist_right != INT_MAX && dist->dist_right > dist->max_dist)
	{
		dist->max_dist = dist->dist_right;
		ghost->pending_direction = RIGHT;
	}
}
