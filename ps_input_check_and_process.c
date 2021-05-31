#include "push_swap.h"

/**
 * -------------Function for checking input values.---------------
 * strs - 2d array with digit values;
 * amt - amount of string in strs;
 * on error prints msq and exit.
 */
void	ft_input_check(char *strs[], int amt, int mode)
{
	int	i;
	int j;

	j = 0;
	if (mode)
		j = 1;
	while (j < amt)
	{
		i = 0;
		if (strs[j][0] == '-')
			i++;
		if (!strs[j][i])
			ft_error(2, NULL, NULL);
		while (strs[j][i] != '\0')
		{
			if (!ft_isdigit(strs[j][i]))
				ft_error(2, NULL, NULL);
			i++;
		}
		j++;
	}
}

/**
 *--Static utility function for ft_input_process, checks for duplicates--
 * stk_a - 2d array with our values;
 * i - amount of values;
 * return (1) on ERROR(duplicate found);
 * return (0) on VALID inputs.
 */
static int	ft_chk_dupl(int *stk_a, int i)
{
	int	lst_in;

	lst_in = stk_a[i];
	while ((i - 1) >= 0)
	{
		if (lst_in == stk_a[i - 1])
			return (1);
		i--;
	}
	return (0);
}

/**
 * -----Function for processing input values.(multi-argument)----------
 * strs - 2d array with digit values;
 * amt - amount of string in strs;
 * on error prints msq and exit.
 * returns pointer on stack "A"
 */
int	*ft_input_process(char *strs[], int amt)
{
	int		*stk_a;
	int		i;
	long	tmp;

	stk_a = malloc(sizeof(int) * amt);
	if (!stk_a)
		ft_error(1, "ft_input_process", NULL);
	i = 0;
	while (i < amt)
	{
		tmp = ft_atoi(strs[i + 1]);
		stk_a[i] = (int)tmp;
		if (2147483647 < tmp || tmp < -2147483648 || ft_chk_dupl(stk_a, i))
			ft_error(2, NULL, NULL);
		i++;
	}
	if (ft_sort_ch(stk_a, amt))
	{
		free(stk_a);
		exit (0);
	}
	return (stk_a);
}

/**
 * -------unction for processing input values(1 argument)---------
 * strs - 2d array with digit values;
 * amt - amount of string in strs;
 * on error prints msq and exit.
 * returns pointer on stack "A"
 */
int	*ft_input_process_alt(char *strs[], int amt)
{
	int		*stk_a;
	int		i;
	long	tmp;

	stk_a = malloc(sizeof(int) * amt);
	if (!stk_a)
		ft_error(1, "ft_input_process", NULL);
	i = 0;
	while (i < amt)
	{
		tmp = ft_atoi(strs[i]);
		stk_a[i] = (int)tmp;
		if (2147483647 < tmp || tmp < -2147483648 || ft_chk_dupl(stk_a, i))
			ft_error(2, NULL, NULL);
		i++;
	}
	if (ft_sort_ch(stk_a, amt))
	{
		free(stk_a);
		exit (0);
	}
	return (stk_a);
}

/*
 * ---Ascending sort check---
 * returns(1) - OK (sorted)
 * returns (0) - KO (not sorted)
 */
int ft_sort_ch(const int *arr, int amt)
{
	int	i;

	i = 0;
	while (i < amt - 1)
	{
		if(arr[i] < arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
