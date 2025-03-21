/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 01:12:14 by miyolchy          #+#    #+#             */
/*   Updated: 2025/02/01 20:04:27 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	us_to_hex(unsigned long number, const char *base, int fd)
{
	int		size;

	size = 0;
	if (number >= 16)
		size = size + us_to_hex(number / 16, base, fd);
	ft_putchar_fd(base[number % 16], fd);
	return (++size);
}

int	print_ptr(void *ptr, const char *base, int fd)
{
	return (print_str("0x", fd) + us_to_hex((unsigned long)ptr, base, fd));
}
