/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:16:09 by mkizilde          #+#    #+#             */
/*   Updated: 2023/11/09 19:16:09 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <wchar.h>

int	g_t;

// g_t = 0;
bit_2_byte(int sig)
{

}

void signal_handler(int sigusr)
{

	static int	bit;

	bit = 0;
	if (sigusr == SIGUSR1)
	{
		g_t = 1 | g_t << 1;
		bit++;
	}
	else if (sigusr == SIGUSR2)
	{
		g_t = 0 | g_t << 1;
		bit++;
	}
	if (bit == 8)
	{
		printf("before update g_t = %d\n", g_t);
		bit = 0;
	}
	// g_t = 1;
	printf("after update g_t = %d\n", g_t);
}



int	main(void)
{
	printf("%d\n", getpid());
	signal_handler(3);
	printf("main before update g_t = %d\n", g_t);
	g_t = 2;
	printf("main after update g_t = %d\n", g_t);
	// signal(SIGUSR1, signal_handler);
	// signal(SIGUSR2, signal_handler);

	// while (1)
	// {
		
	// }
	
}