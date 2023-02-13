#include "push_swap.h"
#include "printer.h"
#include <stdlib.h>

void	duplicate_stacks(t_stack_pair *stacks, t_stack_pair *copy)
{
	int	i;

	copy->len_a = stacks->len_a;
	copy->size = stacks->size;
	copy->tab = malloc(copy->size * sizeof(int));
	if (copy->tab == NULL)
		exit((free(stacks->tab), 1));
	i = 0;
	while (i < copy->size)
	{
		copy->tab[i] = stacks->tab[i];
		i++;
	}
}

int	simulate(t_stack_pair *stacks, int count,
	int (*f)(t_stack_pair *stacks, int count, t_printer *printer)) {
	t_stack_pair	copy;
	t_printer		simulated_printer;
	int				res;

	duplicate_stacks(stacks, &copy);
	init_printer(&simulated_printer);
	f(&copy, count, &simulated_printer);
	res = simulated_printer.len;
	delete(&simulated_printer);
	free(copy.tab);
	return (res);
}
