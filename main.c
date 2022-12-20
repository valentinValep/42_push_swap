#include <stdio.h> // @TODO RM
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
// @TODO Moulinette
// @TODO RM
void	print_stacks(t_stack_pair *stacks)
{
	int			i;
	int			space_count;
	const int	max_len = (int []){stacks->len_a, stacks->size - stacks->len_a}
	[stacks->len_a < stacks->size - stacks->len_a];

	i = max_len - 1;
	write(STDOUT_FILENO, "A            B\n", 15);
	while (i >= 0)
	{
		if (i < stacks->len_a)
			ft_put_nbr(stacks->tab[i]);
		else
			write(STDOUT_FILENO, " ", 1);
		space_count = -1;
		while (++space_count < 13 - ft_int_count(stacks->tab[i]))
			write(STDOUT_FILENO, " ", 1);
		if (i < stacks->size - stacks->len_a)
			ft_put_nbr(stacks->tab[stacks->size - 1 - i]);
		write(STDOUT_FILENO, "\n", 1);
		i--;
	}
	write(STDOUT_FILENO, "\n----------------\n", 18);
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
	print_stacks(&stacks);
	push(&stacks, STACK_B);
	push(&stacks, STACK_B);
	push(&stacks, STACK_B);
	print_stacks(&stacks);
	rotate(&stacks, STACK_A | STACK_B);
	print_stacks(&stacks);
	swap(&stacks, STACK_A);
	print_stacks(&stacks);
	free(stacks.tab);
	return (0);
}
