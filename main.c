#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_elem	*elem;

	while (elem && elem->next)
	{
		free(elem);
	}
	if (elem)
		free(elem);
}

void	init_stack(t_stack *stack)
{
	stack->ceil = NULL;
	stack->floor = NULL;
	stack->count = 0;
}

static int	ft_atoi(char *str)
{
	return (0); // @TODO
}

int	init_a(t_stack *a, int argc, char **argv)
{
	int		i;
	t_elem	*current_elem;

	init_stack(a);
	i = 1;
	while (i < argc)
	{
		current_elem = malloc(sizeof(t_elem));
		if (!current_elem)
			return (1);
		current_elem->data = ft_atoi(argv[i]);
		if (i == 1)
		{
			a->floor = current_elem;
			a->ceil = current_elem;
			current_elem->before = NULL;
			current_elem->next = NULL;
		}
		else
		{
			current_elem->before = a->ceil;
			current_elem->next = NULL;
			a->ceil->next = current_elem;
			a->ceil = current_elem;
		}
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
	free_stack(&a);
}
