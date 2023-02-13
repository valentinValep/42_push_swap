/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:52:31 by vlepille          #+#    #+#             */
/*   Updated: 2023/02/13 16:52:32 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_rank_len_3(t_stack_pair *stacks, int flag, int *res)
{
	res[0] = is_upper(
			flag, get_stack(stacks, flag, 0), get_stack(stacks, flag, 1))
		+ is_upper(
			flag, get_stack(stacks, flag, 0), get_stack(stacks, flag, 2));
	res[1] = is_upper(
			flag, get_stack(stacks, flag, 1), get_stack(stacks, flag, 0))
		+ is_upper(
			flag, get_stack(stacks, flag, 1), get_stack(stacks, flag, 2));
	res[2] = is_upper(
			flag, get_stack(stacks, flag, 2), get_stack(stacks, flag, 0))
		+ is_upper(
			flag, get_stack(stacks, flag, 2), get_stack(stacks, flag, 1));
}

__attribute__ ((always_inline))
int	sort_len_3_little(
	t_stack_pair *stacks, int flag, t_printer *printer, int *rank)
{
	if (rank[0] == 2 && rank[1] == 0 && rank[2] == 1 && flag == STACK_B)
	{
		push(stacks, (flag == STACK_A) + 1, printer);
		swap(stacks, flag, printer);
		return (1);
	}
	if (rank[0] == 0 && rank[1] == 1 && rank[2] == 2)
		rotate((rank[0] = 1, rank[1] = 2, rank[2] = 0, stacks), flag, printer);
	if (rank[0] == 2 && rank[1] == 0 && rank[2] == 1)
		reverse_rotate(stacks, flag, printer);
	if (rank[0] == 0 && rank[1] == 2 && rank[2] == 1)
		rotate(stacks, flag, printer);
	if (rank[0] == 1 && rank[1] == 0 && rank[2] == 2)
		reverse_rotate(stacks, flag, printer);
	if ((rank[0] == 1 && rank[1] == 2 && rank[2] == 0)
		|| (rank[0] == 2 && rank[1] == 0 && rank[2] == 1))
		swap(stacks, flag, printer);
	return (0);
}

int	sort_len_3_stack_a(
	int *tab, t_stack_pair *stacks, int flag, t_printer *printer)
{
	if (tab[0] == 0 && tab[1] == 1 && tab[2] == 2)
		swap((ft_swap(tab, tab + 1), stacks), flag, printer);
	if (tab[0] == 1 && tab[1] == 0 && tab[2] == 2)
	{
		rotate(stacks, flag, printer);
		swap((ft_swap(tab + 1, tab + 2), stacks), flag, printer);
		reverse_rotate(stacks, flag, printer);
	}
	if ((tab[0] == 1 && tab[1] == 2 && tab[2] == 0)
		|| (tab[0] == 0 && tab[1] == 2 && tab[2] == 1))
		swap((ft_swap(tab, tab + 1), stacks), flag, printer);
	if (tab[0] == 2 && tab[1] == 0 && tab[2] == 1)
	{
		rotate(stacks, flag, printer);
		swap(stacks, flag, printer);
		reverse_rotate(stacks, flag, printer);
	}
	return (0);
}

int	sort_len_3_stack_b(
	int *tab, t_stack_pair *stacks, int flag, t_printer *printer)
{
	if ((tab[0] == 0 && tab[1] == 1 && tab[2] == 2)
		|| (tab[0] == 0 && tab[1] == 2 && tab[2] == 1))
	{
		rotate(stacks, flag, printer);
		push(stacks, (flag == STACK_A) + 1, printer);
		push(stacks, (flag == STACK_A) + 1, printer);
		reverse_rotate(stacks, flag, printer);
		return ((tab[0] == 0 && tab[1] == 1 && tab[2] == 2
				&& (swap(stacks, (flag == STACK_A) + 1, printer), 0)) + 2);
	}
	if (tab[0] == 1 && tab[1] == 0 && tab[2] == 2)
	{
		push(stacks, (flag == STACK_A) + 1, printer);
		swap(stacks, flag, printer);
		push(stacks, (flag == STACK_A) + 1, printer);
		swap(stacks, (flag == STACK_A) + 1, printer);
		return (2);
	}
	if (tab[0] == 2 && tab[1] == 0 && tab[2] == 1)
		return ((push(stacks, (flag == STACK_A) + 1, printer),
				swap(stacks, flag, printer), 1));
	if ((tab[0] == 1 && tab[1] == 2 && tab[2] == 0)
		|| (tab[0] == 0 && tab[1] == 2 && tab[2] == 1))
		swap(stacks, flag, printer);
	return (0);
}

int	sort_len_3(t_stack_pair *stacks, int flag, t_printer *printer)
{
	int	tab[3];

	put_rank_len_3(stacks, flag, tab);
	if (get_size(stacks, flag) != 3 && flag == STACK_A)
	{
		return (sort_len_3_stack_a(tab, stacks, flag, printer));
	}
	else if (get_size(stacks, flag) != 3 && flag == STACK_B)
	{
		return (sort_len_3_stack_b(tab, stacks, flag, printer));
	}
	else
		return (sort_len_3_little(stacks, flag, printer, tab));
}
