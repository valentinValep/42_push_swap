#include "vector.h"
#include <stdlib.h>

void	init_vector(t_vector *vector)
{
	vector->len = 0;
	vector->msize = 0;
	vector->tab = NULL;
}

int	add_vector(t_vector *vector, int elem)
{
	int	*new_tab;
	int	i;

	if (vector->len + 1 > vector->msize)
	{
		vector->msize = (vector->msize << 1) + !vector->msize;
		new_tab = malloc(vector->msize * sizeof(int));
		if (!new_tab)
		{
			free(vector->tab);
			return (-1);
		}
		i = -1;
		while (++i < vector->len)
			new_tab[i] = vector->tab[i];
		free(vector->tab);
		vector->tab = new_tab;
	}
	vector->tab[vector->len] = elem;
	vector->len++;
	return (0);
}

void	destroy_vector(t_vector *vector)
{
	if (vector->msize > 0)
		free(vector->tab);
}
