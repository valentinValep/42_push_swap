#include "printer.h"

char	*get(t_printer *printer, int offset)
{
	if (offset > 0)
		return (printer->printer[offset]);
	return (printer->printer[printer->len + offset]);
}
