/**
 * -------------Function for checking input values.---------------
 * strs - 2d array with digit values;
 * amt - amount of string in strs;
 * on error prints msq and exit.
 */

#include "push_swap.h"

void	ft_input_check(char *strs[], int amt)
{
	int i;

	while (amt > 0)
	{
		i = 0;
		while (strs[amt][i] != '\0')
		{
			if (!ft_isdigit(strs[amt][i]))
			{
				ft_putstr_fd("Error!\nWrong type of input values.\n", 1);
				exit (1);
			}
			i++;
		}
		amt--;
	}
}

/**
 * -------------Function for processing input values.---------------
 * strs - 2d array with digit values;
 * amt - amount of string in strs;
 * on error prints msq and exit.
 * returns pointer on stack "A"
 */

int	*ft_input_process(char *strs[], int amt)
{
	int		stk[amt - 1];
	int		*stk_a;
	int		i;
	long	tmp;

	i = 0;
	while (i < amt)
	{
		tmp = ft_atoi(strs[i + 1]);
		if (2147483647 < tmp || tmp < -2147483648)
		{
			ft_putstr_fd("Error!\nValues aren't in integer range.\n", 1);
			exit (1);
		}
		stk[i] = (int)tmp;
		i++;
	}
	stk_a = malloc(sizeof(int) * amt);
	if (!stk_a)
	{
		ft_putstr_fd("Error!\nMalloc error in ft_input_proc.\n", 1);
		exit (1);
	}
	return (ft_memcpy(stk_a, stk, amt * sizeof(int)));
}
