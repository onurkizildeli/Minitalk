/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 03:05:01 by mkizilde          #+#    #+#             */
/*   Updated: 2023/10/16 19:05:15 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int		n;
	int		i;
	char	s[16];
	long	num;

	num = (long)nb;
	n = 0;
	i = 0;
	if (num == 0)
		n = ft_putchar('0');
	if (num < 0)
	{
		n += write(1, "-", 1);
		num = -num;
	}
	while (num > 0)
	{
		s[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i--)
		n += write(1, &s[i], 1);
	return (n);
}

size_t	ft_putunsigned(unsigned int nb)
{
	int		n;
	int		i;
	char	s[16];

	n = 0;
	i = 0;
	if (nb == 0)
		n = ft_putchar('0');
	while (nb != 0)
	{
		s[i] = (nb % 10) + '0';
		nb /= 10;
		n++;
		i++;
	}
	while (i--)
		write(1, &s[i], 1);
	return (n);
}

size_t	ft_puthex(unsigned int nb)
{
	int		n;
	int		i;
	char	s[16];
	char	*hex;

	n = 0;
	i = 0;
	hex = "0123456789abcdef";
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nb != 0)
	{
		s[i++] = hex[nb % 16];
		nb /= 16;
		n++;
	}
	while (i--)
		write(1, &s[i], 1);
	return (n);
}

size_t	ft_puthex_c(unsigned int nb)
{
	int		n;
	int		i;
	char	s[16];
	char	*hex;

	n = 0;
	i = 0;
	hex = "0123456789ABCDEF";
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nb != 0)
	{
		s[i++] = hex[nb % 16];
		nb /= 16;
		n++;
	}
	while (i--)
		write(1, &s[i], 1);
	return (n);
}

size_t	ft_putptr(void *ptr)
{
	int					n;
	int					i;
	unsigned long int	temp;
	char				s[16];
	char				*hex;

	n = 0;
	i = 0;
	temp = (unsigned long int)ptr;
	hex = "0123456789abcdef";
	if (!temp)
		return (write(1, "0x0", 3));
	while (temp != 0)
	{
		s[i++] = hex[temp % 16];
		temp /= 16;
	}
	n += write(1, "0x", 2);
	while (i--)
		n += write(1, &s[i], 1);
	return (n);
}
