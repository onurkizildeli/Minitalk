/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:53:26 by mkizilde          #+#    #+#             */
/*   Updated: 2023/12/01 19:53:26 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*iter;

	i = 1;
	iter = lst;
	if (!iter)
		return (0);
	while (iter -> next != NULL)
	{
		iter = iter -> next;
		i++;
	}
	return (i);
}
