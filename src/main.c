#include "push_swap.h"
#include "vector.h"
#include <unistd.h>
#include <stdlib.h>

int	has(int *array, int size, int n)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (array[i] == n)
			return (1);
	}
	return (0);
}

int	*get_stack_as_rank(t_stack_pair *stacks)
{
	int	*res;
	int	i;
	int	j;
	int	count;

	res = malloc(stacks->size * sizeof(int));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < stacks->size)
	{
		count = 0;
		j = -1;
		while (++j < stacks->size)
			count += stacks->tab[j] < stacks->tab[i];
		res[i] = count;
		if (i > 0 && has(res, i -1, count))
			return ((free(res), NULL));
	}
	return (res);
}

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

void	parse(int argc, char **argv, t_stack_pair *stacks)
{
	int			i;
	int			j;
	int			word_start;
	int			current_num;
	t_vector	vector;

	init_vector(&vector);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		word_start = 0;
		while (!++j || argv[i][j - 1])
		{
			if (argv[i][j] == ' ' || !argv[i][j]) // @TODO verif with a '\t' in bash if it's ok
			{
				if (word_start != j)
				{
					if (ft_atoi_borrow(
							argv[i] + word_start, j - word_start,
							&current_num) || add_vector(&vector, current_num))
						error(&vector);
				}
				word_start = j;
			}
		}
	}
	stacks->size = vector.len;
	stacks->len_a = stacks->size;
	stacks->tab = reverse(vector.tab, vector.len);
	destroy_vector(&vector);
}

int	main(int argc, char **argv)
{
	t_stack_pair	stacks;
	t_printer		printer;
	int				*tmp;

	parse(argc, argv, &stacks);
	tmp = stacks.tab;
	stacks.tab = get_stack_as_rank(&stacks);
	free(tmp);
	if (!stacks.tab)
		return (1);
	init_printer(&printer);
	sort(&stacks, STACK_A, stacks.len_a, &printer);
	free(stacks.tab);
	print(&printer);
	return (0);
}
