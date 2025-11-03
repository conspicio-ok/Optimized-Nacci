#include "clib.h"

void	init_nacci(t_matrix *fibo, t_matrix *nacci)
{
	int	x;
	int	y;

	fibo->matrix[0][0] = 1;
	y = -1;
	while (++y < nacci->y)
	{
		x = -1;
		while (++x < nacci->x)
		{
			if (y == 0 || y - 1 == x)
				nacci->matrix[y][x] = 1;
		}
	}
}

// A mon plus grand regred, je ne pourrais faire moins que 32 lignes...
int	nacci(int stop, int degres)
{
	t_matrix	*fibo;
	t_matrix	*nacci;
	t_matrix	*result;
	t_matrix	*tmp;
	int			res;

	res = -1;
	if (stop < 0)
		return res;
	fibo = calloc_matrix(1, degres);
	if (fibo)
	{
		nacci = calloc_matrix(degres, degres);
		if (nacci)
		{
			init_nacci(fibo, nacci);
			tmp = power_matrix(nacci, stop);
			if (tmp)
			{
				result = multiply_matrix(tmp, fibo);
				if (result)
				{
					res = result->matrix[degres-1][0];
					free_matrix(result);
				}
				free_matrix(tmp);
			}
			free_matrix(nacci);
		}
		free_matrix(fibo);
	}
	return res;
}
