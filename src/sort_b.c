/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:52:27 by vlepille          #+#    #+#             */
/*   Updated: 2023/02/13 16:52:27 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_to_b(t_stack_pair *stacks, int offset, t_printer *printer)
{
	int	i;

	if (offset < stacks->size - stacks->len_a - offset)
		i = 0;
	else
		i = stacks->size - stacks->len_a;
	while (i < offset)
	{
		rotate(stacks, STACK_B, printer);
		i++;
	}
	while (i > offset)
	{
		reverse_rotate(stacks, STACK_B, printer);
		i--;
	}
}

void	insert_to_a(t_stack_pair *stacks, int count, t_printer *printer)
{
	int	next;

	while (count > 0)
	{
		next = get_max_offset(stacks, STACK_B);
		go_to_b(stacks, next, printer);
		push(stacks, STACK_A, printer);
		count--;
	}
}

int	insert_to_a_strategy(t_stack_pair *stacks, int count, t_printer *printer)
{
	insert_to_a(stacks, count, printer);
	return (count);
}

int	split_strategy(t_stack_pair *stacks, int count, t_printer *printer)
{
	int	already_reinsert;

	split(stacks, STACK_B, count, printer);
	sort(stacks, STACK_A, count / 2 + count % 2, printer);
	already_reinsert = sort(stacks, STACK_B, count / 2, printer);
	return (count / 2 + count % 2 + already_reinsert);
}

// optional @TODO add a brute force algorithm and compare it
int	sort_b(t_stack_pair *stacks, int count, t_printer *printer)
{
	if (is_sort(stacks, STACK_B, count))
		return (0);
	if (simulate(stacks, count, insert_to_a_strategy)
		< simulate(stacks, count, split_strategy))
		return (insert_to_a_strategy(stacks, count, printer));
	return (split_strategy(stacks, count, printer));
}
