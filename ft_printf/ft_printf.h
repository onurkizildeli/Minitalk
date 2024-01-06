/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 03:25:11 by mkizilde          #+#    #+#             */
/*   Updated: 2023/10/03 17:39:36 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
int		ft_putnbr(int nb);
size_t	ft_puthex(unsigned int nb);
size_t	ft_puthex_c(unsigned int nb);
size_t	ft_putunsigned(unsigned int nb);
size_t	ft_putptr(void *p);

#endif