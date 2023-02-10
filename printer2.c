#include "printer.h"
#include <stdlib.h>

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

int	fake_add(t_printer *printer, char *str) {
	int	i;
	int	len;

	if ((printer->len - printer->test_start) && alter_ego(str, printer))
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

// @TODO optionnally look for sa and sb = ss (same for rrr and rr)
int	add(t_printer *printer, char *str)
{
	int	i;
	int	len;

	if (printer->test_start != -1)
		return (fake_add(printer, str));
	if (printer->len && alter_ego(str, printer))
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
