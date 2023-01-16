#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

# define STACK_A 1 // never change
# define STACK_B 2 // never change
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

typedef struct s_stack_group
{
	int	*tab;
	int	size;
}	t_stack_group;

void	print_stacks(t_stack_pair *stacks);

void	swap(t_stack_pair *stacks, char flag);
void	push(t_stack_pair *stacks, char flag);
void	rotate(t_stack_pair *stacks, char flag);
void	reverse_rotate(t_stack_pair *stacks, char flag);
int		get_first(t_stack_pair *stacks, char flag);

void	fill_group(t_stack_pair *stacks, char flag, t_stack_group *group);
void	pull_up_according_med(t_stack_pair *stacks, char flag, int median);

#endif
