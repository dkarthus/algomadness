#include "push_swap.h"

/*
 * Func for finding min/max on first n values in array;
 * minmax: 1 for max, 0 for min;
 * returns pos of this value;
 */
int ft_minmax(int *arr, int n, int minmax)
{
	int	i;
	int tmp;

	i = 0;
	tmp = arr[0];
	while (i < n)
	{
		if (minmax == 1)
		{
			if (tmp < arr[i])
				tmp = arr[i];
		}
		if (minmax == 0)
		{
			if (tmp > arr[i])
				tmp = arr[i];
		}
		i++;
	}
	while (i > 0)
	{
		if (tmp == arr[i - 1])
			return (i - 1);
		i--;
	}
	return (-1);
}

/*
* --Util func for ft_sort_a_4 for sorting final chunk--
*/
static void ft_util_lst_chunk(t_ps *inst, int pos)
{
	if (pos == 3)
			ft_rra(inst);
	else
	{
		while (pos--)
			ft_ra(inst);
	}
	ft_pb(inst);
	ft_sort_a_3(inst);
}

/*
 * --Util func for ft_sort_a_4 for sorting final chunk--
 */
static void ft_util_default(t_ps *inst, int pos)
{
	int	i;

	i = pos;
	while (pos--)
		ft_ra(inst);
	ft_pb(inst);
	while (i--)
		ft_rra(inst);
	ft_sort_a_3(inst);
}

/*
 * Func for sorting 4 values on stack A;
 */
void ft_sort_a_4(t_ps *inst)
{
	int pos;

	if (ft_sort_ch(inst->stk_a, 4))
		return;
	pos = ft_minmax(inst->stk_a, 4, 0);
	if (inst->amt_a == 4)
		ft_util_lst_chunk(inst, pos);
	else
		ft_util_default(inst, pos);
	ft_pa(inst);
}
