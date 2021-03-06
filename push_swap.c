#include "push_swap.h"

/*
 *
 */
int	ft_cnt_strs(char *strs[])
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

/*
 *
 */
void	ft_free_after_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs[i]);
	free(strs);
}

/**
 * --------MAIN FUNCTION-----------
 */
int	main(int argc, char *argv[])
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
		ft_main_sort(stk_a, amt);
	}
	else
	{
		ft_input_check(argv, argc - 1, 1);
		stk_a = ft_input_process(argv, argc - 1);
		ft_main_sort(stk_a, argc - 1);
	}
	return (0);
}
