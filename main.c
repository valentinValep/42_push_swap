#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
// @TODO RM bellow include
#include <stdio.h>
// @TODO Moulinette
// @TODO RM
void	print_stacks(t_stack_pair *stacks)
{
	int			i;
	int			space_count;
	const int	max_len = (int []){stacks->len_a, stacks->size - stacks->len_a}
	[stacks->len_a < stacks->size - stacks->len_a];

	// print tab
	i = -1;
	while (++i < stacks->size - 1)
	{
		printf("%d_", stacks->tab[i]);
	}
	printf("%d -> size<%d> len_a<%d>\n", stacks->tab[i], stacks->size, stacks->len_a);
	//
	i = max_len - 1;
	printf("A            B\n");
	while (i >= 0)
	{
		if (i < stacks->len_a)
			printf("%d", stacks->tab[i]);
		else
			printf(" ");
		space_count = -1;
		while (++space_count < 13 - ft_int_count(stacks->tab[i]))
			printf(" ");
		if (i < stacks->size - stacks->len_a)
			printf("%d", stacks->tab[stacks->size - 1 - i]);
		printf("\n");
		i--;
	}
	write(STDOUT_FILENO, "----------------\n", 18);
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

void	push_median(t_stack_pair *stacks, int flag, int count)
{
	int const	median = (get_max(stacks, flag, count) - get_min(stacks, flag, count)) / 2 + get_min(stacks, flag, count);
	int			i;
	int			rotate_count;
	int			pushed_count;
	int			is_totally_unsort;

	i = -1;
	rotate_count = 0;
	pushed_count = 0;
	is_totally_unsort = count != get_size(stacks, flag);
	while (++i < count && pushed_count < count / 2 + count % 2)
	{
		if (is_upper(flag, get_stack(stacks, flag, 0), median + (flag == STACK_A) - (flag == STACK_B && count % 2)))
		{
			push(stacks, (flag == STACK_A) + 1);
			pushed_count++;
		}
		else
		{
			rotate(stacks, flag);
			rotate_count += is_totally_unsort;
		}
	}
	while (rotate_count--)
		reverse_rotate(stacks, flag);
}

void	sort(t_stack_pair *stacks, int flag, int count)
{
	if (count <= 2)
	{
		if (count == 2)
			if (is_upper(flag, get_stack(stacks, flag, 1), get_stack(stacks, flag, 0)))
				swap(stacks, flag);
		return ;
	}
	push_median(stacks, flag, count);
	sort(stacks, flag, count / 2);
	sort(stacks, (flag == STACK_A) + 1, count / 2 + count % 2);
	count = count / 2 + count % 2;
	while (count--)
		push(stacks, flag);
}

/* --------------------------------------------- */

int	is_in(int *array, int size, int n)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (array[i] == n)
			return (1);
	}
	return (0);
}

int	*get_stack_as_rank(t_stack_pair *stacks)
{
	int	*res;
	int	i;
	int	j;
	int	count;

	res = malloc(stacks->size * sizeof(int));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < stacks->size)
	{
		count = 0;
		j = -1;
		while (++j < stacks->size)
			count += stacks->tab[j] < stacks->tab[i];
		res[i] = count;
		if (i > 0 && is_in(res, i -1, count))
			return ((free(res), NULL));
	}
	return (res);
}

int	main(int argc, char **argv)
{
	t_stack_pair	stacks;
	int				i;

	stacks.size = argc - 1;
	stacks.len_a = stacks.size;
	stacks.tab = malloc((stacks.size) * sizeof(int));
	if (!stacks.tab)
		return (1);
	i = -1;
	while (++i < stacks.size)
		stacks.tab[stacks.size - i - 1] = ft_atoi(argv[i + 1]);
	// @TODO verify parsing
	stacks.tab = get_stack_as_rank(&stacks);
	if (!stacks.tab)
		return (1);
	// @TODO rm print_stacks
	//print_stacks(&stacks);
	sort(&stacks, STACK_A, stacks.len_a);
	//print_stacks(&stacks);
	// @TODO rm print_stacks
	free(stacks.tab);
	return (0);
}
