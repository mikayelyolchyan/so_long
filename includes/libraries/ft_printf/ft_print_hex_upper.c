/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:41:21 by miyolchy          #+#    #+#             */
/*   Updated: 2025/02/01 01:59:04 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unsigned_to_hex(unsigned int number, const char *base, int fd)
{
	int		size;

	size = 0;
	if (number >= 16)
		size = size + unsigned_to_hex(number / 16, base, fd);
	ft_putchar_fd(base[number % 16], fd);
	return (++size);
}

int	print_hex_upper(unsigned int number, int fd)
{
	return (unsigned_to_hex(number, "0123456789ABCDEF", fd));
}
