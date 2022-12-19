#include "push_swap.h"

void	rotate_a(t_stack *a, t_stack *b)
{
	(void) b;
	rotate(a);
}

void	rotate_b(t_stack *a, t_stack *b)
{
	(void) a;
	rotate(b);
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate_a(t_stack *a, t_stack *b)
{
	(void) b;
	reverse_rotate(a);
}

void	reverse_rotate_b(t_stack *a, t_stack *b)
{
	(void) a;
	reverse_rotate(b);
}
