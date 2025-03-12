/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:54:43 by miyolchy          #+#    #+#             */
/*   Updated: 2025/01/24 22:30:30 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			k;
	size_t			little_len;

	little_len = ft_strlen(little);
	i = 0;
	if (!little[i] || (!big && little_len == 0))
		return ((char *)big);
	while (big[i] && i < len)
	{
		k = 0;
		while (big[i + k] == little[k] && i + k < len && little[k])
			k++;
		if (k == little_len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
