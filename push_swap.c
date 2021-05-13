/**
 * --------MAIN FUNCTION-----------
 */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int	*stk_a;
	int	i;

	i = 0;
	ft_input_check(argv, argc - 1);
	stk_a = ft_input_process(argv, argc - 1);
	while (i < argc - 1)
	{
		ft_putnbr_fd(stk_a[i], 1);
		write(1, "\n", 1);
		i++;
	}
	free(stk_a);
	return (0);
}
