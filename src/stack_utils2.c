/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:52:36 by vlepille          #+#    #+#             */
/*   Updated: 2023/02/13 16:52:37 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_offset(t_stack_pair *stacks, int flag)
{
	int	i;
	int	max;
	int	max_i;

	i = 0;
	max_i = 0;
	max = get_stack(stacks, flag, i);
	while (++i < stacks->size - stacks->len_a)
	{
		if (max < get_stack(stacks, flag, i))
		{
			max = get_stack(stacks, flag, i);
			max_i = i;
		}
	}
	return (max_i);
}
