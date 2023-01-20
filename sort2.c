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
void	sort_len_3_little(
	t_stack_pair *stacks, int flag, t_printer *printer, int *rank)
{
	if (rank[0] == 0 && rank[1] == 1 && rank[2] == 2)
		swap((ft_swap(rank, rank + 1), stacks), flag, printer);
	if (rank[0] == 2 && rank[1] == 0 && rank[2] == 1)
		reverse_rotate(
			(rank[0] = 1, rank[1] = 2, rank[2] = 0, stacks), flag, printer);
	if (rank[0] == 0 && rank[1] == 2 && rank[2] == 1)
		rotate(stacks, flag, printer);
	if (rank[0] == 1 && rank[1] == 0 && rank[2] == 2)
		reverse_rotate(stacks, flag, printer);
	if (rank[0] == 1 && rank[1] == 2 && rank[2] == 0)
		swap(stacks, flag, printer);
}

void	sort_len_3(t_stack_pair *stacks, int flag, t_printer *printer)
{
	int	tab[3];

	put_rank_len_3(stacks, flag, tab);
	if (get_size(stacks, flag) != 3)
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
	}
	else
		sort_len_3_little(stacks, flag, printer, tab);
}

//void	put_rank(t_stack_pair *stacks, int flag, int *res, int size)
//{
//	int	i;
//	int	j;

//	i = 0;
//	while (i < size)
//	{
//		j = 0;
//		while (j < size)
//		{
//			res[i] = is_upper(flag, get_stack(stacks, flag, i), get_stack(stacks, flag, j));
//			j++;
//		}
//		i++;
//	}
//}

//void	sort_len_4(t_stack_pair *stacks, int flag, t_printer *printer)
//{
//	int	tab[3];

//	put_rank_len_4(stacks, flag, tab, 4);
//	sort_len_3(stacks, flag, printer);
//}
