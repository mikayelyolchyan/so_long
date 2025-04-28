/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_main_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:37:43 by miyolchy          #+#    #+#             */
/*   Updated: 2025/04/28 17:43:50 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/so_long.h"

int	check_extension(char *filename)
{
	int	len;

	if (!filename)
	{
		ft_printf("Error: Filename is NULL\n");
		return (0);
	}
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error: File must have .ber extension\n");
		return (0);
	}
	return (1);
}
