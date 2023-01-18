#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printer.h"
# include <stddef.h>

# define STACK_A 1 // don't change
# define STACK_B 2 // don't change
# define STACKS_AB 3 // = STACK_A | STACK_B

# define PRINT_STACK_OPERATION 1

void	ft_swap(int *a, int *b);
int		ft_int_count(int n);
int		ft_atoi(char *str);
void	*ft_intmove(int *dest, int *src, size_t size);

typedef struct s_stack_pair {
	int		*tab;
	int		size;
	int		len_a;
}	t_stack_pair;

// @TODO rm
void	print_stacks(t_stack_pair *stacks);

void	swap(t_stack_pair *stacks, int flag, t_printer *printer);
void	push(t_stack_pair *stacks, int flag, t_printer *printer);
void	rotate(t_stack_pair *stacks, int flag, t_printer *printer);
void	reverse_rotate(t_stack_pair *stacks, int flag, t_printer *printer);

int		get_size(t_stack_pair *stacks, int flag);
int		get_stack(t_stack_pair *stacks, int flag, int offset);

#endif
