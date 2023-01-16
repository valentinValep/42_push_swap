#include "push_swap.h"

int	get_size(t_stack_pair *stacks, int flag)
{
	if (flag == STACK_A)
		return (stacks->len_a);
	return (stacks->size - stacks->len_a);
}

int	get_stack(t_stack_pair *stacks, int flag, int offset)
{
	if (offset < 0)
	{
		if (flag == STACK_A)
			return (stacks->tab[offset * -1 -1]);
		return (stacks->tab[stacks->size - offset * -1]);
	}
	if (flag == STACK_A)
		return (stacks->tab[stacks->len_a - offset - 1]);
	return (stacks->tab[stacks->len_a + offset]);
}
