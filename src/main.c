/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:23:50 by vlepille          #+#    #+#             */
/*   Updated: 2023/01/18 18:23:51 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack_pair	stacks;
	t_printer		printer;
	int				*tmp;

	parse(argc, argv, &stacks);
	tmp = stacks.tab;
	stacks.tab = get_stack_as_rank(&stacks);
	free(tmp);
	if (!stacks.tab)
		return (1);
	init_printer(&printer);
	sort(&stacks, STACK_A, stacks.len_a, &printer);
	free(stacks.tab);
	print(&printer);
	return (0);
}
