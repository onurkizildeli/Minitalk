/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:23:06 by mkizilde          #+#    #+#             */
/*   Updated: 2023/09/30 23:23:06 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <wchar.h>
#include "minitalk.h"

/*

Executable dosyalarınızı client ve server. olarak adlandırın .
•Hataları iyice ele almalısınız. Programınız hiçbir şekilde beklenmedik şekilde ka-
panmamalıdır (segmentation fault, bus error, double free vb.).
•Programınızda memory leaks olmamalıdır.
•Program başına bir global değişkeniniz olabilir (biri client , diğeri server için),
ancak gerekli yerlerde kullanmanız gerekecektir.
•Zorunlu kısmı tamamlamak için aşağıdaki işlevleri kullanmanıza izin verilir:
◦write
◦ft_printf ve sizin kodladığınız herhangi bir eşdeğer kod
◦signal
◦sigemptyset
◦sigaddset
◦sigaction
◦kill
◦getpid
◦malloc
◦free
◦pause
◦sleep
◦usleep
◦exit


Client ve server şeklinde bir iletişim program oluşturmalısınız.
•İlk olarak server başlatılmalıdır. Başlatıldıktan sonra PID’sini. yazdırması gerekir.
•The client takes two parameters:
◦Server PID.
◦Gönderilecek string.
•Client, parametre olarak iletilen String’i server’a göndermelidir.
String alındıktan sonra server’in onu yazdırması gerekir.
•Server’in string’i oldukça hızlı bir şekilde görüntülemesi gerekir. Çok uzun sürdüğünü
düşünüyorsanız muhtemelen çok uzundur.
100 karakter görüntülemek için 1 saniye çok fazla!
•Server, yeniden başlatmaya gerek kalmadan arka arkaya birkaç client’dan dizeler
alabilmelidir.
•Client ve server arasındaki iletişim yalnızca UNIX sinyalleri kullanılarak yapıl-
malıdır.
•Yalnızca bu iki sinyali kullanabilirsin: SIGUSR1 ve SIGUSR2.
Halihazırda bu türden bekleyen sinyalleriniz olduğunda, Linux sistemi
sinyalleri kuyruğa KOYMAZ! Bonus zaman?
6
Bölüm V
Bonus bölüm
Bonus liste:
•Server, client’a bir sinyal göndererek alınan her mesajı onaylar.
•Unicode karakter desteği!
Bonus kısım, yalnızca zorunlu kısım MÜKEMMEL ise
değerlendirilecektir.Mükemmel, zorunlu kısmın entegre
olarak yapıldığı ve arızasız çalıştığı anlamına gelir. TÜM
zorunlu gereksinimleri geçmediyseniz, bonus bölümünüz hiç
değerlendirilmeyecektir. */

static char		g_char = 0;
static char		bit = 0;

// void	ft_putnbr_fd(int n, int fd)
// {
// 	if (n == -2147483648)
// 		ft_putstr_fd("-2147483648", fd);
// 	else if (n < 0)
// 	{
// 		ft_putchar_fd('-', fd);
// 		ft_putnbr_fd(-n, fd);
// 	}
// 	else if (n >= 10)
// 	{
// 		ft_putnbr_fd((n) / 10, fd);
// 		ft_putnbr_fd((n) % 10, fd);
// 	}
// 	else
// 	{
// 		n = n + 48;
// 		write(fd, &n, 1);
// 	}
// }

// void	bit_2_byte(char *bit);
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

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

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd((n) / 10, fd);
		ft_putnbr_fd((n) % 10, fd);
	}
	else
	{
		n = n + 48;
		write(fd, &n, 1);
	}
}

void	sigusr1_handler(int signo)
{
	// static char	bit;
	static char	i;
	static char	j;

	// bit = 0;
	i = '0';
	j = 0;

	if (signo == SIGUSR1)
	{
		bit = 1 & bit << 1;
		i++;
		j++;
		g_char++;
		// write(1, &g_char, 1);
		// write(1, &i, 1);
	}
	g_char++;
	i++;
	j++;
	// bit = bit << 1;
	// if (signo == SIGUSR2)
	// {
	// 	bit = bit << 1;
	// 	i++;
	// 	j++;
	// 	// write(1, &bit, 1);
	// 	// write(1, &i, 1);
	// 	// write(1, "b", 1);
	// }

	if (g_char == 8)
	{
		// write(1, "if state", 9);
		// g_char = g_char - 8 + 'a';
		// write(1, &g_char, 1);
		write(1, &bit, 1);
		g_char = 0;
		// write(1, "H", 1);
		// write(1, &i, 1);
		// write(1, &j, 1);
		// i = 0;
		bit = 0;
	}
	// if (j == 2)
	// {
	// 	write(1, "E", 1);
	// 	write(1, &i, 1);
	// 	write(1, &j, 1);
	// 	// i = 0;
	// 	// bit = 0;
	// }
}

int	main(void)
{
	pid_t	server_pid;
	int 	live;

	live = 1;
	server_pid = getpid();
	ft_putnbr_fd(server_pid, 1);
	write(1, "\n", 1);
	// printf("PID = %d\n", server_pid);
		signal(SIGUSR1, sigusr1_handler);
		signal(SIGUSR2, sigusr1_handler);


	while (live == 1)
	{

		// sleep(4);
	}

	return (0);
}

// void	bit_2_byte(char *bit)
// {
// 	int		zero;
// 	int		i;

// 	i = 7;
// 	zero = 0;
// 	while (i >= 0)
// 	{
// 		if (bit[i] == '0')
// 			zero = (zero << 1) | 0;
// 		else if (bit[i] == '1')
// 			zero = (zero << 1) | 1;
// 		i--;
// 	}
// 	printf("%c", zero);
// 	printf("\n");
// }


// void	sigusr1_handler(int signo)
// {
// 	static int	bit;
// 	static int	i;

// 	bit = 0;
// 	i = 0;

// 	if (signo == SIGUSR1)
// 	{
// 		bit = 1 | bit << 1;
// 		i++;
// 		write(1, &i, 1);
// 	}
// 	else if (signo == SIGUSR2)
// 	{
// 		bit = bit << 1;
// 		// write(1, "0", 1);
// 		i++;
// 		write(1, &i, 1);
// 	}
// 	if ( i == 8)
// 	{
// 		write(1, &bit, 1);
// 		bit = 0;
// 	}
// 	// else
// 	// printf("signal1 reached\n");
// }