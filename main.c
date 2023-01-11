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

	i = -1;
	while (++i < size)
	res = malloc(sizeof(int) * size);
	if (!res)
		exit(1);
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		mini = res[j];
		while (++j < size)
			if (res[j] < mini)
				mini = res[j];
		ft_swap(res[i], res[mini]);
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

// function which push @TODO
void	sort_median(t_stack_pair *stacks, int flag, int count)
{
	const int	median = get_median(stacks->tab + (flag - 1) * stacks->len_a,
			stacks->len_a * (flag % 2)
			+ (stacks->size - stacks->len_a) * (flag - 1));

	// @TODO
}

void	sort_stack(t_stack_pair *stacks, int flag, int count)
{
	// if count > 3 else use another things (idk what)
	sort_median(stacks, flag, count);

	// @TODO
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
