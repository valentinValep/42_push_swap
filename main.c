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

int	has(int *array, int size, int n)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (array[i] == n)
			return (1);
	}
	return (0);
}

int	*get_stack_as_rank(t_stack_pair *stacks)
{
	int	*res;
	int	i;
	int	j;
	int	count;

	res = malloc(stacks->size * sizeof(int));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < stacks->size)
	{
		count = 0;
		j = -1;
		while (++j < stacks->size)
			count += stacks->tab[j] < stacks->tab[i];
		res[i] = count;
		if (i > 0 && has(res, i -1, count))
			return ((free(res), NULL));
	}
	return (res);
}

int	main(int argc, char **argv)
{
	t_stack_pair	stacks;
	t_printer		printer;
	int				i;
	int				*tmp;

	stacks.size = argc - 1;
	stacks.len_a = stacks.size;
	stacks.tab = malloc((stacks.size) * sizeof(int));
	if (!stacks.tab)
		return (1);
	i = -1;
	while (++i < stacks.size)
		stacks.tab[stacks.size - i - 1] = ft_atoi(argv[i + 1]);
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
