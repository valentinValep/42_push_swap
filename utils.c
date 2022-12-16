#include <unistd.h>
#include "push_swap.h"

void	ft_put_nbr(int nbr)
{
	if (nbr / 10)
		ft_put_nbr(nbr / 10);
	else
		write(STDOUT_FILENO, "-", nbr < 0);
	write(STDOUT_FILENO, &(char){nbr % 10 *~-((nbr > 0) * 2) + 48}, 1);
}
