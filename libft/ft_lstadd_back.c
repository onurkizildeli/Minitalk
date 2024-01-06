/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:50:35 by mkizilde          #+#    #+#             */
/*   Updated: 2023/12/01 19:50:35 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == NULL && *lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	if (new == NULL)
		return ;	
	t_list	*iter;

	iter = *lst;
	while (iter -> next != NULL)
	{
		iter = iter -> next;
	}
	iter -> next = new;
	iter -> next -> next = NULL;
}