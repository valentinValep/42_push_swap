#include <stddef.h>
#include <unistd.h>
#include "push_swap.h"

void	push(t_stack *stack, t_elem *elem)
{
	stack->ceil->next = elem;
	elem->next = NULL;
	elem->before = stack->ceil;
	stack->ceil = elem;
	stack->count++;
}

t_elem	*pop(t_stack *stack)
{
	t_elem	*res;

	if (stack->count == 0)
		return (NULL);
	res = stack->ceil;
	stack->ceil = res->before;
	stack->ceil->next = NULL;
	stack->count--;
	return (res);
}

void	swap(t_stack *stack)
{
	t_elem	*tmp;

	if (stack->count < 2)
		return ;
	tmp = stack->ceil;
	stack->ceil = stack->ceil->before;
	stack->ceil->before = tmp;
	stack->ceil->next = NULL;
	tmp->next = stack->ceil;
	tmp->before = stack->ceil->before;
}

void	rotate(t_stack *stack)
{
	t_elem	*ex_ceil;

	if (stack->count == 0)
		return ;
	if (stack->count == 1)
	{
		swap(stack);
		return ;
	}
	ex_ceil = stack->ceil;
	stack->ceil = stack->floor;
	stack->floor = stack->floor->next;
	stack->floor->before = NULL;
	stack->ceil->before = ex_ceil;
	stack->ceil->next = NULL;
	ex_ceil->next = stack->ceil;
}

void	print_stack(t_stack *stack)
{
	t_elem	*elem;

	elem = stack->floor;
	write(STDOUT_FILENO, "[", 1);
	while (elem && elem->next)
	{
		ft_put_nbr(elem->data);
		elem = elem->next;
		write(STDOUT_FILENO, ", ", 1);
	}
	if (elem)
	{
		ft_put_nbr(elem->data);
		write(STDOUT_FILENO, ", ", 1);
	}
	write(STDOUT_FILENO, "]", 1);
}
