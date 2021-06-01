#include "push_swap.h"

/*
 * 		Main function
 */
int main(int argc, char *argv[])
{
	int		amt;
	int		*stk_a;
	char	**strs;

	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		amt = ft_cnt_strs(strs);
		ft_input_check(strs, amt, 0);
		stk_a = ft_input_process_alt(strs, amt);
		ft_free_after_split(strs);

	}
	else
	{
		ft_input_check(argv, argc - 1, 1);
		stk_a = ft_input_process(argv, argc - 1);

	}
	return (0);
}

