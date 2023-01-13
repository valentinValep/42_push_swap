#include "push_swap.h"

void	fill_group(t_stack_pair *stacks, char flag, t_stack_group *group)
{
	if (flag & STACK_A)
	{
		if (group->size > stacks->len_a)
			return ;
		group->tab = stacks->tab + stacks->len_a - group->size;
		return ;
	}
	if (flag & STACK_B)
	{
		if (group->size > stacks->size - stacks->len_a)
			return ;
		group->tab = stacks->tab + stacks->len_a;
		return ;
	}
}

int	continue_pull_up(t_stack_pair *stacks, char flag, int median)
{
	int	i;

	if (flag == STACK_A)
	{
		i = 0;
		while (i < stacks->len_a)
		{
			if (stacks->tab[i] <= median)
				return (1);
			i++;
		}
	}
	else
	{
		i = stacks->len_a;
		while (i < stacks->size)
		{
			if (stacks->tab[i] >= median)
				return (1);
			i++;
		}
	}
	return (0);
}

void	pull_up_according_med(t_stack_pair *stacks, char flag, int median)
{
	int	rotated_count;

	rotated_count = 0;
	if (flag == STACK_A)
	{
		while (continue_pull_up(stacks, flag, median))
		{
			rotated_count += (get_first(stacks, STACK_A) > median);
			if (get_first(stacks, STACK_A) > median)
				rotate(stacks, STACK_A);
			else
				push(stacks, STACK_B);
		}
	}
	else if (flag == STACK_B)
	{
		while (continue_pull_up(stacks, flag, median))
		{
			rotated_count += (get_first(stacks, STACK_B) < median);
			if (get_first(stacks, STACK_B) < median)
				rotate(stacks, STACK_B);
			else
				push(stacks, STACK_A);
		}
	}
	while (rotated_count-- > 0)
		reverse_rotate(stacks, flag);
}
