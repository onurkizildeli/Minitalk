#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <wchar.h>

void	byte_2_bit(int c)
{
	int		i;
	char	bit[9];

	i = 0;

	while (i < 8)
	{
		bit[i] = (c % 2) + '0';
		c = c / 2;
		i++;
	}
	bit[i] = '\0';
	printf("%s", bit);
}

void	bit_2_byte(char *bit)
{
	int		zero;
	int		i;

	i = 7;
	zero = 0;
	while (i >= 0)
	{
		if (bit[i] == '0')
			zero = (zero << 1) | 0;
		else if (bit[i] == '1')
			zero = (zero << 1) | 1;
		i--;
	}
	printf("%c", zero);
	printf("\n");
}

int main(int argc, char **argv)
{
	bit_2_byte("11000110");
}