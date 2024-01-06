#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <wchar.h>

int main()
{
	char	*bit;
	int		zero;
	int		i;

	i = 7;
	zero = 0;
	bit = "11000110";

	// printf("%s", bit);
	// printf("\n");
	// printf("%c", bit[1]);
	// printf("\n");
	// printf("%d", zero);
	// printf("\n");

	// zero = (zero << i) | 1;
	// printf("%d", zero);
	// printf("\n");
	// i++;
	// zero = (zero << i) | 1;
	// printf("%d", zero);
	// printf("\n");
	// i++;
	// zero = (zero << i) | one;
	printf("%d", zero);
	printf("\n");

	while (i >= 0)
	{
		if (bit[i] == '0')
		{
			zero = (zero << 1) | 0;
			i--;
		}
		else if(bit[i] == '1')
		{
			zero = (zero << 1) | 1;
			i--;
		}
	}
	printf("%c", zero);
	printf("\n");
}