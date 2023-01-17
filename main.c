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

/* --------------------------------------------- */

int	*sorted(int tab[], int size)
{
	int	*res;
	int	i;
	int	j;
	int	mini;

	res = malloc(sizeof(int) * size);
	if (!res)
		exit(1);
	i = -1;
	while (++i < size)
		res[i] = tab[i];
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		mini = j;
		while (++j < size)
			if (res[j] < res[mini])
				mini = j;
		ft_swap(res + i, res + mini);
	}
	return (res);
}

int	get_median(int tab[], int size)
{
	int	*sorted_tab;
	int	res;

	sorted_tab = sorted(tab, size);
	res = sorted_tab[size / 2 - (size + 1) % 2];
	return (res);
}

// function which push every int of a stack bellow median to the other stack
void	push_median(t_stack_pair *stacks, int flag, int count)
{
	t_stack_group	group;
	int				median;

	group.size = count;
	fill_group(stacks, flag, &group);
	median = get_median(group.tab, group.size);
	pull_up_according_med(stacks, flag, median);
}

int	is_final_ceil(t_stack_pair *stacks, int flag, int n)
{
	return (n == (stacks->size -1) * (flag == STACK_B));
}

int	get_sorted_end_count(t_stack_pair *stacks, int flag)
{
	int	i;

	i = 0;
	while (i < get_size(stacks, flag) && get_stack(stacks, flag, -i -1)
		== get_stack(stacks, flag, -i -2) + (flag == STACK_A) * 2 - 1)
		i++;
	if (is_final_ceil(stacks, flag, get_stack(stacks, flag, -i -1)))
		return (i + 1);
	return (0);
}

int	is_under_next_ceil_bottom(t_stack_pair *stacks, int flag, int n)
{
	return (get_sorted_end_count(stacks, flag)
		&& (n == get_stack(stacks, flag, -1) + (flag == STACK_A) * 2 - 1));
}

void	sort_stack(t_stack_pair *stacks, int flag)
{
	int	count;

	count = get_size(stacks, flag) - get_sorted_end_count(stacks, flag);
	//printf("count<%d>\n", count);
	while (count > 0)
	{
		if (is_final_ceil(stacks, flag, get_stack(stacks, flag, 0))
			|| is_under_next_ceil_bottom(stacks,
				flag, get_stack(stacks, flag, 0)))
			rotate(stacks, flag);
		else
		{
			flag = (flag == STACK_A) + 1;
			push(stacks, flag);
			while (get_size(stacks, flag) > 1
				&& ((is_final_ceil(stacks, flag, get_stack(stacks, flag, 0)) && get_sorted_end_count(stacks, flag) != get_size(stacks, flag))
					|| is_under_next_ceil_bottom(
						stacks, flag, get_stack(stacks, flag, 0))))
				rotate(stacks, flag);
			flag = (flag == STACK_A) + 1;
		}
		count--;
	}
	//print_stacks(stacks);
	flag = (flag == STACK_A) + 1;
	if (get_sorted_end_count(stacks, flag) != get_size(stacks, flag))
		sort_stack(stacks, flag);
}

void	sort(t_stack_pair *stacks)
{
	sort_stack(stacks, STACK_A);
	while (get_size(stacks, STACK_B))
		push(stacks, STACK_A);
	while (get_sorted_end_count(stacks, STACK_A) != stacks->size)
		rotate(stacks, STACK_A);
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
	sort(&stacks);
	//print_stacks(&stacks);
	// @TODO rm print_stacks
	free(stacks.tab);
	return (0);
}
