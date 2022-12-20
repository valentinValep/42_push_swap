#include <stddef.h>
#include <unistd.h>
#include "push_swap.h"

void	print_stack(t_stack *stack) // @TODO del
{
	t_elem	*elem;
	int		i;

	elem = stack->ceil;
	i = stack->count - 1;
	write(STDOUT_FILENO, "[", 1);
	while (i >= 0)
	{
		ft_put_nbr(elem->data);
		elem = elem->before;
		write(STDOUT_FILENO, ", ", !!i * 2);
		i--;
	}
	write(STDOUT_FILENO, "]\n", 2);
}

void	push(t_stack *stack, t_elem *elem)
{
	if (!elem)
		return ;
	stack->ceil->next = elem;
	elem->next = NULL;
	elem->before = stack->ceil;
	stack->ceil = elem;
	stack->count++;
}
#include <stdio.h>
t_elem	*pop(t_stack *stack)
{
	t_elem	*res;

	if (stack->count == 0)
		return (NULL);
	res = stack->ceil;
	stack->ceil = res->before;
	res->before = NULL;
	res->next = NULL;
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
	stack->ceil->next = NULL;
	tmp->next = stack->ceil;
	tmp->before = stack->ceil->before;
	tmp->before->next = tmp;
	stack->ceil->before = tmp;
}

void	rotate(t_stack *stack)
{
	t_elem	*ex_floor;

	if (stack->count == 0)
		return ;
	if (stack->count == 1)
	{
		swap(stack);
		return ;
	}
	ex_floor = stack->floor;
	stack->floor = stack->ceil;
	stack->ceil = stack->ceil->before;
	stack->ceil->next = NULL;
	stack->floor->next = ex_floor;
	stack->floor->before = NULL;
	ex_floor->before = stack->floor;
}

void	reverse_rotate(t_stack *stack)
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
