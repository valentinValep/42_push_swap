/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:24:07 by vlepille          #+#    #+#             */
/*   Updated: 2023/01/18 18:24:09 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_upper(int flag, int a, int b)
{
	if (flag == STACK_A)
		return (a < b);
	return (a > b);
}

int	get_min(t_stack_pair *stacks, int flag, int count)
{
	int	i;
	int	min;

	i = 0;
	min = get_stack(stacks, flag, i);
	while (++i < count)
	{
		if (min > get_stack(stacks, flag, i))
			min = get_stack(stacks, flag, i);
	}
	return (min);
}

int	get_max(t_stack_pair *stacks, int flag, int count)
{
	int	i;
	int	max;

	i = 0;
	max = get_stack(stacks, flag, i);
	while (++i < count)
	{
		if (max < get_stack(stacks, flag, i))
			max = get_stack(stacks, flag, i);
	}
	return (max);
}
