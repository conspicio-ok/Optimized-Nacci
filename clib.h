#include <stdlib.h>
#include <stdio.h>

#ifndef CLIB_H
# define CLIB_H

typedef struct s_matrix
{
	int	**matrix;
	int	x;
	int	y;
}		t_matrix;


void		free_matrix(t_matrix *mat);
t_matrix	*create_matrix(int x, int y);
t_matrix	*calloc_matrix(int x, int y);
t_matrix	*identity_matrix(int size);
void		print_matrix(t_matrix mat);
void		copy_matrix(t_matrix *to, t_matrix from);
t_matrix	*multiply_matrix(t_matrix *m1, t_matrix *m2);
void		multiply_matrix_into(t_matrix *res, t_matrix *m1, t_matrix *m2);
t_matrix	*power_matrix(t_matrix *mat, int power);
int			nacci(int stop, int degres);

#endif
