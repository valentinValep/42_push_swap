#include "printer.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	delete(t_printer *printer)
{
	int		i;

	i = -1;
	while (++i < printer->len)
		free(printer->printer[i]);
	free(printer->printer);
	printer->len = 0;
	printer->msize = 0;
	printer->printer = NULL;
}

int	ft_upscale_printer(t_printer *printer, int size)
{
	char	**new;
	int		i;

	if (printer->msize >= size)
		return (0);
	while (printer->msize < size)
		printer->msize = printer->msize * 2 + (!printer->msize);
	new = malloc((printer->msize) * sizeof(char *));
	if (!new)
	{
		if (printer->printer)
			delete(printer);
		printer->printer = NULL;
		return (1);
	}
	i = -1;
	while (++i < printer->len)
		new[i] = printer->printer[i];
	free(printer->printer);
	printer->printer = new;
	return (0);
}

void	init_printer(t_printer *printer)
{
	printer->msize = 0;
	printer->printer = NULL;
	printer->len = 0;
}

char	*get(t_printer *printer, int offset)
{
	if (offset > 0)
		return (printer->printer[offset]);
	return (printer->printer[printer->len + offset]);
}

int	equal(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == 0 && b[i] == 0);
}

int	versus(char *a, char *b, char *pattern_a, char *pattern_b)
{
	return ((equal(a, pattern_a) && equal(b, pattern_b))
		|| (equal(a, pattern_b) && equal(b, pattern_a)));
}

int	alter_ego(char *str, t_printer *printer)
{
	return (versus(str, get(printer, -1), "pa", "pb")
		|| versus(str, get(printer, -1), "ra", "rra")
		|| versus(str, get(printer, -1), "rb", "rrb")
		|| versus(str, get(printer, -1), "sa", "sa")
		|| versus(str, get(printer, -1), "sb", "sb"));
}

int	add(t_printer *printer, char *str)
{
	int	i;
	int	len;

	if (printer->len && alter_ego(str, printer)) // @TODO look for sa and sb = ss (same for rrr and rr)
	{
		free(printer->printer[printer->len -1]);
		printer->len--;
		return (0);
	}
	if (ft_upscale_printer(printer, printer->len + 1))
		return (1);
	printer->len++;
	len = 0;
	while (str[len])
		len++;
	printer->printer[printer->len -1] = malloc((len + 1) * sizeof(char));
	if (!printer->printer[printer->len -1])
		return ((printer->len--, delete(printer), 1));
	i = -1;
	while (++i < len + 1)
		printer->printer[printer->len -1][i] = str[i];
	return (0);
}

int	print(t_printer *printer)
{
	int	i;
	int	word_len;

	i = -1;
	while (++i < printer->len)
	{
		word_len = 0;
		while (printer->printer[i][word_len])
			word_len++;
		printer->printer[i][word_len] = '\n';
		if (write(STDOUT_FILENO, printer->printer[i], word_len + 1)
			!= word_len + 1)
			return (1);
	}
	delete(printer);
	return (0);
}
