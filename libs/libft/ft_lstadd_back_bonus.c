/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:48:57 by miyolchy          #+#    #+#             */
/*   Updated: 2025/01/29 23:07:46 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_list)
{
	if (!*lst)
	{
		*lst = new_list;
		return ;
	}
	(ft_lstlast(*lst))->next = new_list;
}
