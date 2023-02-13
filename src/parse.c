#include "vector.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	error(t_vector *vector)
{
	destroy_vector(vector);
	write(STDERR_FILENO, "Error\n", 6);
	exit(2);
}

int	*reverse(int *tab, int len)
{
	int *const	res = malloc(len * sizeof(int));
	int			i;

	if (!res)
	{
		free(tab);
		exit(-1);
	}
	i = -1;
	while (++i < len)
		res[i] = tab[len - i -1];
	return (res);
}

int	check_double(t_vector const *vector)
{
	int	i;
	int	j;

	i = 0;
	while (i < vector->len - 1)
	{
		j = i + 1;
		while (j < vector->len)
		{
			if (vector->tab[i] == vector->tab[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	add_number_to_vec(t_vector *vector, char *word, int *start, int end)
{
	int			current_num;

	if (word[end] == ' ' || !word[end])
	{
		if (*start != end)
		{
			if (ft_atoi_borrow(
					word + *start, end - *start,
					&current_num) || add_vector(vector, current_num))
				error(vector);
		}
		*start = end + 1;
	}
}

void	parse(int argc, char **argv, t_stack_pair *stacks)
{
	int			i;
	int			j;
	int			word_start;
	t_vector	vector;

	init_vector(&vector);
	i = 0;
	while (++i < argc)
	{
		if (!argv[i][0])
			error(&vector);
		j = -1;
		word_start = 0;
		while (!++j || argv[i][j - 1])
		{
			add_number_to_vec(&vector, argv[i], &word_start, j);
		}
	}
	if (!vector.len || check_double(&vector))
		error(&vector);
	stacks->size = vector.len;
	stacks->len_a = stacks->size;
	stacks->tab = reverse(vector.tab, vector.len);
	destroy_vector(&vector);
}
