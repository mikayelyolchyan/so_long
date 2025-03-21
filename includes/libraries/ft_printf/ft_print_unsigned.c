/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:19:41 by miyolchy          #+#    #+#             */
/*   Updated: 2025/02/01 01:37:27 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits_count(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		++i;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	print_nbr(unsigned int n, int fd)
{
	char	c;

	if (n >= 10)
		print_nbr(n / 10, fd);
	c = (n % 10) + '0';
	ft_putchar_fd(c, fd);
}

int	print_unsigned(unsigned int number, int fd)
{
	print_nbr(number, fd);
	return (digits_count(number));
}
