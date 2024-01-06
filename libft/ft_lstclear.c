/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:51:29 by mkizilde          #+#    #+#             */
/*   Updated: 2023/12/01 19:51:29 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*iter;
	t_list	*last;

	iter = *lst;
	while (iter -> next != NULL)
	{
		last = ft_lstlast(*lst);
		ft_lstdelone(last, del);
		free(last);
		last = NULL;
	}
	lst = NULL;
}
