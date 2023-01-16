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

int	get_sorted_end_count(t_stack_pair *stacks, int flag)
{
	int	i;

	i = 0;
	while (get_stack(stacks, flag, -i -1)
		== get_stack(stacks, flag, -i -2) + (flag == STACK_A) * 2 - 1)
		i++;
	if (get_stack(stacks, flag, -i -1) == (stacks->size -1) * (flag == STACK_B))
		return (i + 1);
	return (0);
}

void	sort_stack(t_stack_pair *stacks, int flag)
{
	int	count;

	count = get_size(stacks, flag) - get_sorted_end_count(stacks, flag);
	printf("count<%d>\n", count);
	while (count > 0)
	{
		if (!get_stack(stacks, STACK_A, 0) || (get_stack(stacks, STACK_A, 0)
				== get_stack(stacks, STACK_A, -1) + 1
				&& get_sorted_end_count(stacks, STACK_A)))
			rotate(stacks, STACK_A);
		else
		{
			push(stacks, STACK_B);
			while (get_size(stacks, STACK_B) > 1 && (get_stack(stacks, STACK_B, 0)
					== stacks->size -1 || ((get_stack(stacks, STACK_B, 0)
							== get_stack(stacks, STACK_B, -1) - 1)
						&& get_sorted_end_count(stacks, STACK_B))))
				rotate(stacks, STACK_B);
		}
		count--;
	}
	if (get_sorted_end_count(stacks, STACK_A) != stacks->size)
		sort_stack(stacks, (flag == STACK_A) + 1);
}

/* --------------------------------------------- */

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
	print_stacks(&stacks);
	sort_stack(&stacks, STACK_A);
	print_stacks(&stacks);
	// @TODO rm print_stacks
	free(stacks.tab);
	return (0);
}
