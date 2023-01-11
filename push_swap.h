#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

# define STACK_A 1
# define STACK_B 2
# define STACKS_AB 3 // = STACK_A | STACK_B

void	ft_swap(int *a, int *b)
int		ft_int_count(int n);
int		ft_atoi(char *str);
void	*ft_intmove(int *dest, int *src, size_t size);

typedef struct s_stack_pair {
	int		*tab;
	int		size;
	int		len_a;
}	t_stack_pair;

void	print_stacks(t_stack_pair *stacks);

char	*swap(t_stack_pair *stacks, char flag);
char	*push(t_stack_pair *stacks, char flag);
char	*rotate(t_stack_pair *stacks, char flag);
char	*reverse_rotate(t_stack_pair *stacks, char flag);

#endif
