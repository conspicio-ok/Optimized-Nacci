#include "clib.h"

void	free_matrix(t_matrix *mat)
{
	int	i;

	i = -1;
	while (++i < mat->y)
		free(mat->matrix[i]);
	free(mat->matrix);
	free(mat);
}

t_matrix	*create_matrix(int x, int y)
{
	t_matrix	*mat;

	mat = (t_matrix *)malloc(sizeof(t_matrix));
	if (!mat)
		return NULL;
	mat->x = x;
	mat->y = y;
	mat->matrix = (int **)malloc(sizeof(int *) * y);
	if (!(mat->matrix))
	{
		free(mat);
		return NULL;
	}
	mat->y = 0;
	while (mat->y < y)
	{
		mat->matrix[mat->y] = (int *)malloc(sizeof(int) * x);
		if (!(mat->matrix[mat->y]))
		{
			free_matrix(mat);
			return NULL;
		}
		(mat->y)++;
	}
	return mat;
}

t_matrix	*calloc_matrix(int x, int y)
{
	int	i_x;
	int	i_y;
	t_matrix *mat;

	mat = create_matrix(x, y);
	if (!(mat))
		return NULL;
	i_y = -1;
	while (++i_y < y)
	{
		i_x = -1;
		while (++i_x < x)
			mat->matrix[i_y][i_x] = 0;
	}
	return mat;
}

t_matrix	*identity_matrix(int size)
{
    t_matrix	*mat;
    
    mat = calloc_matrix(size, size);
    if (!mat)
        return NULL;
    while (size--)
        mat->matrix[size][size] = 1;
    return mat;
}

void	print_matrix(t_matrix mat)
{
	int y;
	int	x;

	y = -1;
	while (++y < mat.y)
	{
		x = -1;
		while (++x < mat.x)
			printf("%d ", mat.matrix[y][x]);
		printf("\n");
	}
}

void	copy_matrix(t_matrix *to, t_matrix from)
{
	int	x;
	int	y;

	if (to->x != from.x || to->y != from.y)
		return ;
	y = -1;
	while (++y < from.y)
	{
		x = -1;
		while (++x < from.x)
			to->matrix[y][x] = from.matrix[y][x];
	}
}

t_matrix	*multiply_matrix(t_matrix *m1, t_matrix *m2)
{
	int			result_x;
	int			result_y;
	int			i;
	t_matrix	*result;

	if (m1->x != m2->y)
		return NULL;
	result = calloc_matrix(m2->x, m1->y);
	if (!result)
		return NULL;
	result_y = -1;
	while (++result_y < result->y)
	{
		result_x = -1;
		while (++result_x < result->x)
		{
			i = -1;
			while (++i < m1->x)
				result->matrix[result_y][result_x] += m1->matrix[result_y][i] * m2->matrix[i][result_x];
		}
	}
	return result;
}

void	multiply_matrix_into(t_matrix *res, t_matrix *m1, t_matrix *m2)
{
	int			result_x;
	int			result_y;
	int			i;
	t_matrix	*tmp;

	if (m1->x != m2->y)
		return ;
	tmp = calloc_matrix(m2->x, m1->y);
	if (!tmp)
		return ;
	result_y = -1;
	while (++result_y < tmp->y)
	{
		result_x = -1;
		while (++result_x < tmp->x)
		{
			i = -1;
			while (++i < m1->x)
				tmp->matrix[result_y][result_x] += m1->matrix[result_y][i] * m2->matrix[i][result_x];
		}
	}
	copy_matrix(res, *tmp);
	free_matrix(tmp);
}

t_matrix	*power_matrix(t_matrix *mat, int power)
{
	t_matrix	*result;
	t_matrix	*base;

	if ((mat->x != mat->y) || power < 0)
		return NULL;
	result = identity_matrix(mat->x);
	if (!result)
		return NULL;
	base = create_matrix(mat->x, mat->y);
	if (!base)
	{
		free_matrix(result);
		return NULL;
	}
	copy_matrix(base, *mat);
	while (power)
	{
		if (power % 2)
			multiply_matrix_into(result, result, base);
		power /= 2;
		if (power)
			multiply_matrix_into(base, base, base);
	}
	free_matrix(base);
	return result;
}
