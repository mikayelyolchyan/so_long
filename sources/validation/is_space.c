/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:34:43 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/26 23:34:55 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
		c == '\r' || c == '\v' || c == '\f');
}
