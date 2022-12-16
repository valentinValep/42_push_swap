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
void	print_stack(t_stack *stack);

#endif
