#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
#include <stdio.h>
void	swap(t_stack_pair *stacks, char flag)
{
	if (flag & STACK_A)
	{
		if (stacks->len_a >= 2)
			ft_swap(stacks->tab + stacks->len_a -1,
				stacks->tab + stacks->len_a -2);
	}
	if (flag & STACK_B)
	{
		if (stacks->size - stacks->len_a < 2)
			return ;
		ft_swap(stacks->tab + stacks->size - stacks->len_a -1,
			stacks->tab + stacks->size - stacks->len_a -2);
	}
}

void	push(t_stack_pair *stacks, char flag)
{
	stacks->len_a += (
			(flag < 3
				&& !(flag == 1 && stacks->len_a == stacks->size)
				&& !(flag == 2 && !stacks->len_a))
			* ((flag + 1) % 3 -1));
}

void	rotate(t_stack_pair *stacks, char flag)
{
	int	tmp;

	if (flag & STACK_A)
	{
		if (stacks->len_a >= 2)
		{
			tmp = stacks->tab[stacks->len_a - 1];
			ft_intmove(stacks->tab + 1, stacks->tab, stacks->len_a - 1);
			stacks->tab[0] = tmp;
		}
	}
	if (flag & STACK_B)
	{
		if (stacks->size - stacks->len_a < 2)
			return ;
		tmp = stacks->tab[stacks->len_a];
		ft_intmove(stacks->tab + stacks->len_a, stacks->tab + stacks->len_a + 1,
			stacks->size - stacks->len_a - 1);
		stacks->tab[stacks->size - 1] = tmp;
	}
}

void	reverse_rotate(t_stack_pair *stacks, char flag)
{
	int	tmp;

	if (flag & STACK_A)
	{
		if (stacks->len_a >= 2)
		{
			tmp = stacks->tab[0];
			ft_intmove(stacks->tab, stacks->tab + 1, stacks->len_a -1);
			stacks->tab[stacks->len_a -1] = tmp;
		}
	}
	if (flag & STACK_B)
	{
		if (stacks->size - stacks->len_a < 2)
			return ;
		tmp = stacks->tab[stacks->size -1];
		ft_intmove(stacks->tab + stacks->len_a + 1, stacks->tab + stacks->len_a,
			stacks->size - stacks->len_a -1);
		stacks->tab[stacks->len_a] = tmp;
	}
}
