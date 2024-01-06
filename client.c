/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:29:16 by mkizilde          #+#    #+#             */
/*   Updated: 2023/10/01 20:29:16 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <wchar.h>
#include "minitalk.h"
// #include "ft_printf/ft_printf.h"

static pid_t	g_pid_client;

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	nbr;
	int	result;

	sign = 1;
	i = 0;
	nbr = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	result = sign * nbr;
	return (result);
}

int	ft_check_arg(char *av)
{
	size_t	i;

	i = 0;
	if (!av[0] || !av || ft_atoi(av) <= 0 || av[0] == 48)
		return (0);
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

    //a = 01100001
char	*send_byte(int c, int server_pid)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		if (1 & (c >> i))
		{
			bit = 1 & (c >> i);
			// printf("%d", bit);
			kill(server_pid, SIGUSR1);
			// printf("SIGUSR1 sended\n");
		}
		else
		{
			bit = 1 & (c >> i);
			// printf("%d", bit);
			kill(server_pid, SIGUSR2);
			// printf("SIGUSR2 sended\n");
		}
		i++;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	size_t	i;

	i = 0;
	if (ac == 3)
	{
		if (!ft_check_arg(av[1]))
		{
			ft_putstr_fd("Invalid argumant", 1);
			return (0);
		}
		server_pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			send_byte(av[2][i], server_pid);
			i++;
		}
	}
	else
		ft_putstr_fd("Invalid number of argumant", 1);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	int		pid_client;
// 	int		sigusr;
// 	char	*str;
// 	char	*bit;
// 	int		i;

// 	i = 0;
// 	str = argv[2];
// 	sigusr = SIGUSR1;
// 	pid_client = ft_atoi(argv[1]);
// 	// if (argc != 3)
// 	// 	return (0);
// 	if (kill(pid_client, sigusr) == 0)
// 		printf("Signal sended");
// 	else
// 		printf("Signal not sended!");

// 	printf("\n");
// 	while (argv[2][i])
// 	{
// 		bit = byte_2_bit(argv[2][i]);
// 		printf("\n");
// 		printf("%s", bit);
// 		printf("\n");
// 		bit_2_signal(bit, pid_client);
// 		i++;
// 	}

// 	return (0);
// }



void	bit_2_signal(char *bit, int pid_client)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (bit[i] == '0')
		{
			kill(pid_client, SIGUSR2);
			printf("SIGUSR2 sended\n");
		}
		else if (bit[i] == '1')
		{
			kill(pid_client, SIGUSR1);
			printf("SIGUSR1 sended\n");
		}
		else
			printf("Bit Error!!\n");
		usleep(500);
		i++;
	}

}

void	bit_byte(char c)
{
	int	bit;

	bit = 0;
	if ((c >> bit) == 0)
		printf("0");
	else
		printf("1");
}

// char	*byte_2_bit(int c)
// {
// 	int		i;
// 	char	*bit;

// 	bit = (char *)malloc(sizeof(char) * 9);
// 	i = 0;

// 	while (i < 8)
// 	{
// 		bit[i] = (c % 2) + '0';
// 		c = c / 2;
// 		i++;
// 	}
// 	bit[i] = '\0';
// 	printf("%s", bit);
// 	return (bit);
// }