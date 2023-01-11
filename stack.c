#include "push_swap.h"
// @TODO rm bellow includes
#include <stdio.h>
char	*swap(t_stack_pair *stacks, char flag)
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
			return (NULL);
		ft_swap(stacks->tab + stacks->size - stacks->len_a,
			stacks->tab + stacks->size - stacks->len_a -1);
	}
	return ((char []){'s', (char []){'a', 'b', 's'}[flag - 1], 0});
}

char	*push(t_stack_pair *stacks, char flag)
{
	stacks->len_a += (
			(flag < 3
				&& !(flag == 1 && stacks->len_a == stacks->size)
				&& !(flag == 2 && !stacks->len_a))
			* ((flag + 1) % 3 -1));
	return ((char []){'p', 'a' + flag - 1, 0});
}

char	*rotate(t_stack_pair *stacks, char flag)
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
			return (NULL);
		tmp = stacks->tab[stacks->len_a];
		ft_intmove(stacks->tab + stacks->len_a, stacks->tab + stacks->len_a + 1,
			stacks->size - stacks->len_a - 1);
		stacks->tab[stacks->size - 1] = tmp;
	}
	return ((char []){'r', (char []){'a', 'b', 'r'}[flag - 1], 0});
}

char	*reverse_rotate(t_stack_pair *stacks, char flag)
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
			return (NULL);
		tmp = stacks->tab[stacks->size -1];
		ft_intmove(stacks->tab + stacks->len_a + 1, stacks->tab + stacks->len_a,
			stacks->size - stacks->len_a -1);
		stacks->tab[stacks->len_a] = tmp;
	}
	return ((char []){'r', 'r', (char []){'a', 'b', 'r'}[flag - 1], 0});
}
