/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:23:59 by vlepille          #+#    #+#             */
/*   Updated: 2023/01/18 18:24:02 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int		ft_atoi_borrow(char *start, int len, int *res);
void	*ft_intmove(int *dest, int *src, size_t size);

typedef struct s_stack_pair {
	int		*tab;
	int		size;
	int		len_a;
}	t_stack_pair;

void	swap(t_stack_pair *stacks, int flag, t_printer *printer);
void	push(t_stack_pair *stacks, int flag, t_printer *printer);
void	rotate(t_stack_pair *stacks, int flag, t_printer *printer);
void	reverse_rotate(t_stack_pair *stacks, int flag, t_printer *printer);

int		get_size(t_stack_pair *stacks, int flag);
int		get_stack(t_stack_pair *stacks, int flag, int offset);
int		is_upper(int flag, int a, int b);
int		get_min(t_stack_pair *stacks, int flag, int count);
int		get_max(t_stack_pair *stacks, int flag, int count);
int		get_max_offset(t_stack_pair *stacks, int flag);

void	parse(int argc, char **argv, t_stack_pair *stacks);

void	split(t_stack_pair *st, int flag, int count, t_printer *printer);
int	is_sort(t_stack_pair *stacks, int flag, int count);
int		sort_len_3(t_stack_pair *stacks, int flag, t_printer *printer);
int		sort(t_stack_pair *stacks, int flag, int count, t_printer *printer);
int		sort_b(t_stack_pair *stacks, int count, t_printer *printer);

int		simulate(
			t_stack_pair *stacks, int count,
			int (*f)(t_stack_pair *stacks, int count, t_printer *printer));

#endif
