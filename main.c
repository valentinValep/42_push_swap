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

int	get(t_stack_pair *stacks, int flag, int rank)
{
	if (flag == STACK_A)
		return (stacks->tab[stacks->len_a - 1 - rank]);
	if (flag == STACK_B)
		return (stacks->tab[stacks->len_a + rank]);
	return (0);
}

void	sort_3len_stack_a(t_stack_pair *stacks, int flag)
{
	if (flag == STACK_A)
	{
		// 0 1 2
		if (get(stacks, flag, 0) < get(stacks, flag, 1) && get(stacks, flag, 1) < get(stacks, flag, 2) && get(stacks, flag, 0) < get(stacks, flag, 2))
			return ; // ok
		// 0 2 1
		if (get(stacks, flag, 0) < get(stacks, flag, 1) && get(stacks, flag, 1) > get(stacks, flag, 2) && get(stacks, flag, 0) < get(stacks, flag, 2))
		{
			push(stacks, flag);
			swap(stacks, flag);
			push(stacks, STACK_B);
			return ; // p s pi
		}
		// 1 2 0
		if (get(stacks, flag, 0) < get(stacks, flag, 1) && get(stacks, flag, 1) > get(stacks, flag, 2) && get(stacks, flag, 0) > get(stacks, flag, 2))
		{
			push(stacks, flag);
			swap(stacks, flag);
			push(stacks, STACK_B);
			swap(stacks, flag);
			return ; // p s pi s
		}
		// 1 0 2
		if (get(stacks, flag, 0) > get(stacks, flag, 1) && get(stacks, flag, 1) < get(stacks, flag, 2) && get(stacks, flag, 0) < get(stacks, flag, 2))
		{
			swap(stacks, flag);
			return ; // s
		}
		// 2 1 0
		if (get(stacks, flag, 0) > get(stacks, flag, 1) && get(stacks, flag, 1) > get(stacks, flag, 2) && get(stacks, flag, 0) > get(stacks, flag, 2))
		{
			push(stacks, STACK_B);
			swap(stacks, flag);
			push(stacks, STACK_B);
			swap(stacks, STACK_B);
			push(stacks, flag);
			swap(stacks, flag);
			push(stacks, flag);
			return ; // p s p si pi s pi
		}
		// 2 0 1
		if (get(stacks, flag, 0) > get(stacks, flag, 1) && get(stacks, flag, 1) < get(stacks, flag, 2) && get(stacks, flag, 0) > get(stacks, flag, 2))
		{
			swap(stacks, flag);
			push(stacks, flag);
			swap(stacks, flag);
			push(stacks, STACK_B);
			return ; // s p s pi
		}
	}
}

void	sort_3len_stack_b(t_stack_pair *stacks, int flag)
{
	if (flag == STACK_A)
	{
		// 2 1 0
		if (get(stacks, flag, 0) > get(stacks, flag, 1) && get(stacks, flag, 1) > get(stacks, flag, 2) && get(stacks, flag, 0) > get(stacks, flag, 2))
			return ; // ok
		// 2 0 1
		if (get(stacks, flag, 0) > get(stacks, flag, 1) && get(stacks, flag, 1) < get(stacks, flag, 2) && get(stacks, flag, 0) > get(stacks, flag, 2))
		{
			push(stacks, flag);
			swap(stacks, flag);
			push(stacks, STACK_B);
			return ; // p s pi
		}
		// 1 2 0
		if (get(stacks, flag, 0) > get(stacks, flag, 1) && get(stacks, flag, 1) < get(stacks, flag, 2) && get(stacks, flag, 0) < get(stacks, flag, 2))
		{
			push(stacks, flag);
			swap(stacks, flag);
			push(stacks, STACK_B);
			swap(stacks, flag);
			return ; // p s pi s
		}
		// 1 0 2
		if (get(stacks, flag, 0) < get(stacks, flag, 1) && get(stacks, flag, 1) > get(stacks, flag, 2) && get(stacks, flag, 0) > get(stacks, flag, 2))
		{
			swap(stacks, flag);
			return ; // s
		}
		// 2 1 0
		if (get(stacks, flag, 0) < get(stacks, flag, 1) && get(stacks, flag, 1) < get(stacks, flag, 2) && get(stacks, flag, 0) < get(stacks, flag, 2))
		{
			push(stacks, STACK_B);
			swap(stacks, flag);
			push(stacks, STACK_B);
			swap(stacks, STACK_B);
			push(stacks, flag);
			swap(stacks, flag);
			push(stacks, flag);
			return ; // p s p si pi s pi
		}
		// 2 0 1
		if (get(stacks, flag, 0) < get(stacks, flag, 1) && get(stacks, flag, 1) > get(stacks, flag, 2) && get(stacks, flag, 0) < get(stacks, flag, 2))
		{
			swap(stacks, flag);
			push(stacks, flag);
			swap(stacks, flag);
			push(stacks, STACK_B);
			return ; // s p s pi
		}
	}
}

void	sort_little_stack(t_stack_pair *stacks, int flag, int count)
{
	if (count == 1)
		return ;
	if (count == 2)
	{
		if (flag == STACK_A)
			if (stacks->tab[stacks->len_a - 1] > stacks->tab[stacks->len_a - 2])
				swap(stacks, flag);
		if (flag == STACK_B)
			if (stacks->tab[stacks->len_a] < stacks->tab[stacks->len_a + 1])
				swap(stacks, flag);
	}
	if (count == 3)
	{
		if (flag == STACK_A)
			sort_3len_stack_a(stacks, flag);
		else if (flag == STACK_B)
			sort_3len_stack_b(stacks, flag);
	}
}

int	get_precedent_count(int base_count, int current_count)
{
	while (base_count / 2 > current_count)
		base_count /= 2;
	return (base_count);
}

void	sort_stack(t_stack_pair *stacks, int flag, int count)
{
	int	current_count;

	current_count = count;
	while (current_count > 3)
	{
		push_median(stacks, flag, current_count);
		print_stacks(stacks);
		current_count /= 2;
	}
	sort_little_stack(stacks, flag, current_count);
	print_stacks(stacks);

	//current_count = get_precedent_count(count, current_count);
	//if (current_count == count)
	//printf("current_count<%d>\n", current_count);

	// faire que le tri push en meme temps
	if (current_count != count)
		sort_stack(stacks, (flag == 1) + 1, count - current_count);
	while (current_count < count)
	{
		push(stacks, flag);
		current_count++;
	}
}

/* --------------------------------------------- */

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
	// @TODO rm print_stacks
	print_stacks(&stacks);
	sort_stack(&stacks, STACK_A, stacks.len_a);
	print_stacks(&stacks);
	// @TODO rm print_stacks
	free(stacks.tab);
	return (0);
}
