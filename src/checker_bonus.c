/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:21:34 by vlepille          #+#    #+#             */
/*   Updated: 2023/02/14 15:21:36 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h> // for STDIN_FILENO

int	get_index(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int	parse_command(char const *command)
{
	int	action;
	int	target;

	action = -1;
	if (command[0] && command[1] && (!command[2] || command[2] == '\n'))
	{
		action = get_index(command[0], "spr");
		if (action < 0)
			return (-1);
		action = (int []){SWAP, PUSH, ROTATE}[action];
		target = get_index(command[1], "absr");
		if (target < 0 || (target == 2 && action != SWAP)
			|| (target == 3 && action != ROTATE))
			return (-1);
		target = (int []){STACK_A, STACK_B,
			STACK_A | STACK_B, STACK_A | STACK_B}[target];
	}
	if (command[0] && command[1] && command[2] && (!command[3]
			|| command[3] == '\n') && command[0] == 'r' && command[1] == 'r')
	{
		action = REVERSE_ROTATE;
		target = get_index(command[2], "abr");
		target = (int []){STACK_A, STACK_B, STACK_A | STACK_B}[target];
	}
	return (action | target);
}

int	execute(t_stack_pair *stacks, char const *command)
{
	int const	result = parse_command(command);

	if (result < 0)
		return (-1);
	if (result & SWAP)
		swap(stacks, result & 3, NULL);
	if (result & PUSH)
		push(stacks, result & 3, NULL);
	if (result & ROTATE)
		rotate(stacks, result & 3, NULL);
	if (result & REVERSE_ROTATE)
		reverse_rotate(stacks, result & 3, NULL);
	return (0);
}

void	check_sort(t_stack_pair *stacks)
{
	if (stacks->len_a == stacks->size && is_sort(stacks, STACK_A, stacks->size))
		write(STDIN_FILENO, "OK\n", 3);
	else
		write(STDIN_FILENO, "KO\n", 3);
}


int	main(int argc, char **argv)
{
	t_stack_pair	stacks;
	int				*tmp;
	char			*command;

	parse(argc, argv, &stacks);
	tmp = stacks.tab;
	stacks.tab = get_stack_as_rank(&stacks);
	free(tmp);
	if (!stacks.tab)
		return (1);
	command = get_next_line(STDIN_FILENO);
	while (command)
	{
		if (execute(&stacks, command) < 0)
		{
			free((gnl_close(STDIN_FILENO), free(stacks.tab), command));
			write(STDERR_FILENO, "Error\n", 6);
			exit(2);
		}
		free(command);
		command = get_next_line(STDIN_FILENO);
	}
	free(stacks.tab);
	check_sort(&stacks);
	return (0);
}
