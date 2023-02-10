#include "push_swap.h"
#include "printer.h"

void	execute(
	void (*f)(t_stack_pair *stacks, int flag, t_printer *printer),
	t_stack_pair *stacks,
	int flag,
	t_printer *printer)
{
	f(stacks, flag, printer);
}

void	invert_input(t_stack_pair *stacks, char const *input)
{
	void	(*f)(t_stack_pair *stacks, int flag, t_printer *printer);

	if (input[0] == 's')
	{
		;
	}

}

int	switch_test_mode(t_stack_pair *stacks, t_printer *printer)
{
	int const	tests_len = get_tests_len(printer);
	char const	**tests_start = get_tests_start(printer);
	int			i;
	char const	*current_word;

	i = 0;
	while (i < tests_len)
	{
		current_word = tests_start[i];
		invert_input(stacks, current_word);
		i++;
	}
	return (tests_len);
}
