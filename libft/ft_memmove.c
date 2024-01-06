/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 00:25:06 by mkizilde          #+#    #+#             */
/*   Updated: 2023/07/26 00:25:06 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dst1;
	char			*src1;

	dst1 = (char *)dst;
	src1 = (char *)src;
	if (dst > src)
	{
		while (len--)
		{
			dst1[len] = src1[len];
		}
	}
	else
		ft_memcpy(dst1, src1, len);
	return (dst);
}
