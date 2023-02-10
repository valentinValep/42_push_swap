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
	printer->test_start = -1;
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
