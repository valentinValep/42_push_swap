#include <unistd.h>
#include <stddef.h>
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

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	i += ((neg = str[i] == '-') || str[i] == '+');
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * (!neg - neg));
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

