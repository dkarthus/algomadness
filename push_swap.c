/**
 * --------MAIN FUNCTION-----------
 */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*stk_a;

	ft_input_check(argv, argc - 1);
	stk_a = ft_input_process(argv, argc - 1);
	ft_main_sort(stk_a, argc - 1);
	return (0);
}
