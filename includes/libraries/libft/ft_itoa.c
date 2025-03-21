/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:53:38 by miyolchy          #+#    #+#             */
/*   Updated: 2025/01/24 17:53:39 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits_count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*fill(char *str, int n)
{
	int	i;

	i = digits_count(n);
	str[i] = '\0';
	--i;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		--i;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	digits = digits_count(n);
	str = (char *)malloc((digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = fill(str, n);
	return (str);
}
