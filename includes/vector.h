#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	int	*tab;
	int	len;
	int	msize;
}	t_vector;

void	init_vector(t_vector *vector);
int		add_vector(t_vector *vector, int elem)
		__attribute__ ((warn_unused_result));
void	destroy_vector(t_vector *vector);

#endif
