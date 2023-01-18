#ifndef PRINTER_H
# define PRINTER_H

typedef struct s_printer
{
	char	**printer;
	int		len;
	int		msize;
}	t_printer;

int		ft_upscale_printer(t_printer *printer, int size);
void	delete(t_printer *printer);

void	init_printer(t_printer *printer);
int		add(t_printer *printer, char *str);
int		print(t_printer *printer);

#endif
