#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

void	ft_put_nbr(int nbr);

typedef struct s_elem
{
	int				data;
	struct s_elem	*next;
	struct s_elem	*before;
}	t_elem;

typedef struct s_stack {
	t_elem	*floor;
	t_elem	*ceil;
	int		count;
}	t_stack;

void	push(t_stack *stack, t_elem *elem);
t_elem	*pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	print_stack(t_stack *stack); // @TODO RM

void	push_swap_fun(t_stack *a, t_stack *b);
void	swap_a(t_stack *a, t_stack *b);
void	swap_b(t_stack *a, t_stack *b);
void	swap_ab(t_stack *a, t_stack *b);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a, t_stack *b);
void	rotate_b(t_stack *a, t_stack *b);
void	rotate_ab(t_stack *a, t_stack *b);
void	reverse_rotate_a(t_stack *a, t_stack *b);
void	reverse_rotate_b(t_stack *a, t_stack *b);
void	reverse_rotate_ab(t_stack *a, t_stack *b);

#endif
