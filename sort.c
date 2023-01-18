#include "push_swap.h"

void	push_median(t_stack_pair *st, int flag, int count, t_printer *printer)
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

void	sort_len_3(t_stack_pair *stacks, int flag, t_printer *printer)
{
	int	tab[3];

	put_rank_len_3(stacks, flag, tab);
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

void	sort(t_stack_pair *stacks, int flag, int count, t_printer *printer)
{
	if (is_sort(stacks, flag, count))
		return ;
	if (count <= 3)
	{
		if (count == 2)
			if (is_upper(flag, get_stack(stacks, flag, 1),
					get_stack(stacks, flag, 0)))
				swap(stacks, flag, printer);
		if (count == 3)
			sort_len_3(stacks, flag, printer);
		return ;
	}
	push_median(stacks, flag, count, printer);
	if (flag == STACK_A)
		sort(stacks, flag, count / 2, printer);
	sort(stacks, (flag == STACK_A) + 1, count / 2 + count % 2, printer);
	if (flag == STACK_B)
		sort(stacks, flag, count / 2, printer);
	count = count / 2 + count % 2;
	while (count--)
		push(stacks, flag, printer);
}
