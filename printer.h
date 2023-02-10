#ifndef PRINTER_H
# define PRINTER_H

typedef struct s_printer
{
	char	**printer;
	int		len;
	int		msize;
	int		test_start;
}	t_printer;

// Intern functions
int		ft_upscale_printer(t_printer *printer, int size)
		__attribute__ ((warn_unused_result));
void	delete(t_printer *printer);
char	*get(t_printer *printer, int offset);

// Public functions
void	init_printer(t_printer *printer);
int		add(t_printer *printer, char *str) __attribute__ ((warn_unused_result));
int		print(t_printer *printer);
int		is_in_test_mode(t_printer *printer);
char	**get_tests_start(t_printer *printer);
int		get_tests_len(t_printer *printer);
int		printer_switch_test_mode(t_printer *printer);

#endif
