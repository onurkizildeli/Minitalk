/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:52:42 by mkizilde          #+#    #+#             */
/*   Updated: 2023/12/01 19:52:42 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*iter;

	iter = lst;
	if (lst == NULL)
		return (iter);
	if (iter -> next == NULL)
		return (iter);
	while (iter -> next != NULL)
		iter = iter -> next;
	return (iter);
}
