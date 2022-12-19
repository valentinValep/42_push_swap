#include "push_swap.h"

void	swap_a(t_stack *a, t_stack *b)
{
	(void) b;
	swap(a);
}

void	swap_b(t_stack *a, t_stack *b)
{
	(void) a;
	swap(b);
}

void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	push_a(t_stack *a, t_stack *b)
{
	if (b->count >= 1)
		push(a, pop(b));
}

void	push_b(t_stack *a, t_stack *b)
{
	if (a->count >= 1)
		push(b, pop(a));
}
