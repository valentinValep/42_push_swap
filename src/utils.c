/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:24:15 by vlepille          #+#    #+#             */
/*   Updated: 2023/01/18 18:24:16 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <limits.h>
#include "push_swap.h"

int	ft_int_count(int n)
{
	int	i;

	i = 0;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_atoi_borrow(char *start, int len, int *res)
{
	int	i;
	int	neg;

	i = 0;
	*res = 0;
	i += ((neg = start[i] == '-') || start[i] == '+');
	while (start[i] >= '0' && start[i] <= '9')
	{
		if (((long)*res) * 10 + start[i] - '0' > (long)INT_MAX + neg)
			return (-2);
		*res = (*res) * 10 + start[i] - '0';
		i++;
	}
	if ((start[i] != 0 && start[i] != ' ')
		|| (start[i -1] == '-' || start[i -1] == '+'))
		return (-1);
	*res = (*res) * (!neg - neg);
	return (i != len);
}

void	*ft_intmove(int *dest, int *src, size_t size)
{
	int	i;

	if (!size || (!dest && !src))
		return (dest);
	i = (size - 1) * (dest >= src);
	while (size)
	{
		dest[i] = src[i];
		size--;
		i += (dest < src) * 2 - 1;
	}
	return (dest);
}
