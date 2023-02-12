#include "push_swap.h"
#include <stdio.h> // @TODO rm

void	split(t_stack_pair *st, int flag, int count, t_printer *printer)
{
	int const	median = (get_max(st, flag, count) - get_min(st, flag, count))
		/ 2 + get_min(st, flag, count);
	int			i;
	int			rotate_count;
	int			pushed_count;
	int			is_totally_unsort;

	i = -1;
	rotate_count = 0;
	pushed_count = 0;
	is_totally_unsort = count != get_size(st, flag);
	while (++i < count && pushed_count < count / 2 + count % 2)
	{
		if (is_upper(flag, get_stack(st, flag, 0),
				//median + (flag == STACK_A && !(count % 2))
				//- (flag == STACK_B && count % 2)))
				median + (flag == STACK_A) - (flag == STACK_B && count % 2)))
		{
			push(st, (flag == STACK_A) + 1, printer);
			pushed_count++;
		}
		else
			rotate((rotate_count++, st), flag, printer);
	}
	while (is_totally_unsort && rotate_count--)
		reverse_rotate(st, flag, printer);
}

int	is_sort(t_stack_pair *stacks, int flag, int count)
{
	int	i;

	i = -1;
	while (++i < count - 1)
	{
		if (is_upper(flag, get_stack(stacks, flag, i + 1),
				get_stack(stacks, flag, i)))
			return (0);
	}
	return (1);
}

int	sort_a(t_stack_pair *stacks, int count, t_printer *printer)
{
	int	already_reinsert;

	if (is_sort(stacks, STACK_A, count))
		return (0);
	if (count <= 3)
	{
		if (count == 2)
			if (is_upper(STACK_A, get_stack(stacks, STACK_A, 1),
					get_stack(stacks, STACK_A, 0)))
				swap(stacks, STACK_A, printer);
		if (count == 3)
			return (sort_len_3(stacks, STACK_A, printer));
		return (0);
	}
	split(stacks, STACK_A, count, printer);
	sort(stacks, STACK_A, count / 2, printer);
	already_reinsert = sort(stacks, STACK_B, count / 2 + count % 2, printer);
	already_reinsert = (count / 2 + count % 2 - already_reinsert);
	while (already_reinsert-- > 0)
		push(stacks, STACK_A, printer);
	return (0);
}

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

int	sort(t_stack_pair *stacks, int flag, int count, t_printer *printer)
{
	if (flag == STACK_A)
		return (sort_a(stacks, count, printer));
	return (sort_b(stacks, count, printer));
}
