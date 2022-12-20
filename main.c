#include <stdio.h> // @TODO RM
#include <stdlib.h>
#include "push_swap.h"
// @TODO Moulinette
void	free_stack(t_stack *stack)
{
	t_elem	*elem;

	if (!stack->count)
		return ;
	elem = stack->ceil;
	while (elem && elem->before)
	{
		free(elem);
		elem = elem->before;
		stack->count--;
	}
	if (elem)
		free((stack->count--, elem));
}

void	init_stack(t_stack *stack)
{
	stack->ceil = NULL;
	stack->floor = NULL;
	stack->count = 0;
}

static int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	i += ((neg = str[i] == '-') || str[i] == '+');
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * (!neg - neg));
}

int	init_a(t_stack *a, int argc, char **argv)
{
	int		i;
	t_elem	*current_elem;

	init_stack((i = 0, a));
	while (++i < argc)
	{
		current_elem = malloc(sizeof(t_elem));
		if (!current_elem)
			return (1);
		current_elem->data = ft_atoi(argv[i]);
		if (i == 1)
		{
			a->ceil = current_elem;
			current_elem->next = NULL;
		}
		else
		{
			current_elem->next = a->floor;
			a->floor->before = current_elem;
		}
		a->floor = current_elem;
		current_elem->before = NULL;
	}
	a->count = argc - 1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (init_a(&a, argc, argv))
	{
		free_stack(&a);
		return (1);
	}
	init_stack(&b);

	print_stack(&a);
	print_stack(&b);
	swap_a(&a, &b);
	push_b(&a, &b);
	print_stack(&a);
	print_stack(&b);

	free_stack(&a);
	free_stack(&b);
}
