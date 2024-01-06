/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:20:27 by mkizilde          #+#    #+#             */
/*   Updated: 2023/10/26 17:20:27 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <wchar.h>
# include <signal.h>

int		ft_atoi(const char *str);
void	bit_2_byte(char *bit);
char	*byte_2_bit();
void	bit_2_signal(char *bit, int pid_client);
void	bit_byte(char c);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int	    ft_check_arg(char *av);
char	*send_byte(int c, int server_pid);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
