/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:45:10 by mkizilde          #+#    #+#             */
/*   Updated: 2023/07/26 16:16:36 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	i = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (len > 0)
	{
		sub[i] = s[start];
		i++;
		start++;
		len--;
	}
	sub[i] = '\0';
	return (sub);
}

static int	nwords(const char *s, char c)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			n++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	int				i;
	int				f;
	int				n;
	char			**new;

	i = 0;
	n = 0;
	new = (char **)malloc(sizeof(char *) * (nwords(s, c) + 1));
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		f = i;
		while (s[i] != c && s[i])
			i++;
		if (i > f)
		{
			new[n] = ft_substr2(s, f, i - f);
			n++;
		}
	}
	new[n] = (NULL);
	return (new);
}
