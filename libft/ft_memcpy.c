/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 00:24:25 by mkizilde          #+#    #+#             */
/*   Updated: 2023/07/26 00:24:25 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*d1;

	i = 0;
	s1 = (unsigned char *)src;
	d1 = (unsigned char *)dest;
	if (!src && !dest)
		return (dest);
	while (i < n)
	{
		d1[i] = s1[i];
		i++;
	}
	return (dest);
}
