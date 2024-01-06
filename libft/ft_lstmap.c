/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:50:02 by mkizilde          #+#    #+#             */
/*   Updated: 2023/12/01 19:50:02 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*iter;
	// t_list	*node;

	while (iter -> next != NULL)
	{
		newlist = f(lst);
		newlist -> next = newlist;
		iter = iter -> next;
	}
	return (newlist);
}
