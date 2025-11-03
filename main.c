#include "clib.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 4)
	{
		printf("arguments be : ./prog indice_of_fib{int} matrix_degres{int} show_all_occurence{bool}\n");
		return 0;
	}
	if (atoi(argv[3]))
	{
		i = 0;
		printf("[ ");
		while (i < atoi(argv[1]))
		{
			printf("%d", nacci(i, atoi(argv[2])));
			i++;
			if (i < atoi(argv[1]))
			printf(", ");
		}
		printf(" ]\n");
	}
	else
		printf("%d\n", nacci(atoi(argv[1]), atoi(argv[2])));
	return 0;
}
