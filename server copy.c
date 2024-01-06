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

static pid_t	pid_server;

// void sigusr1_handler(int signo)
// {
// 	// if (signo == SIGUSR1)
// 		printf("Signal reached");
// }

int	main(void)
{
	int		live_condition;
	// int		signal_taker = SIGUSR1;

	live_condition = 1;
	pid_server = getpid();

	printf("server pid = %d\n", pid_server);


			// signal(SIGUSR1, sigusr1_handler);
	while (live_condition == 1)
	{
			// signal(signal_taker, sigusr1_handler);
		// if (signal_taker == SIGUSR1)
		// 	// signal(signal_taker, sigusr1_handler);
		// else
			
		sleep (1);
	}
	return 0;
}