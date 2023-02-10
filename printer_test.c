#include "printer.h"

int	is_in_test_mode(t_printer *printer)
{
	return (printer->test_start != -1);
}

char	**get_tests_start(t_printer *printer)
{
	return (printer->printer + printer->test_start);
}

int	get_tests_len(t_printer *printer)
{
	return (printer->len - printer->test_start);
}

int	printer_switch_test_mode(t_printer *printer)
{
	int	res;

	if (!is_in_test_mode(printer))
	{
		printer->test_start = printer->len;
		return (-1);
	}
	res = printer->len - printer->test_start;
	while (printer->len > printer->test_start)
	{
		free(printer->printer[printer->len - 1]);
		printer->len--;
	}
	printer->test_start = -1;
	return (res);
}
