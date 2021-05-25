#include "push_swap.h"

/**
 * Utility func for ft_main_sort, inits main struct
 */
static void	ft_init_struct(t_ps *inst, int *stk_a, int amt)
{
	inst->amt_a = amt;
	inst->amt_b = 0;
	inst->stk_a = stk_a;
	inst->stk_b = malloc(amt * sizeof(int));
	if (!inst->stk_b)
		ft_error(1, "ft_init_struct", stk_a);
	inst->sort_str = ft_calloc(99999, sizeof(char));
	inst->sort_str_pos = 0;
	if (!inst->sort_str)
	{
		free(inst->stk_b);
		ft_error(1, "ft_init_struct", stk_a);
	}
}

/*
 *--------Util func for presort stack and push it to b---------
 * find mid in array on stk_a and push above values to stk_b ->
 * in leftover array on stk_a preform previous operation,    ->
 * repeat until 5 or less values left;
 */
static int	ft_push_right(t_ps *inst)
{
	int mid;
	int	half;
	int iter;

	iter = 0;
	while (inst->amt_a)
	{
		if (inst->amt_a <= 4)
		{
			ft_asort_for_less_4(inst, iter);
			break ;
		}
		half = 0;
		mid = ft_mid_value(inst->stk_a, inst->amt_a);
		while(half < inst->amt_a / 2)
		{
			ft_pushb_cheapest(inst, mid);
			half++;
		}
		iter++;
	}
	return (iter);
}

/**
 * --Main func for calling sort utility func's---
 *stk_a & stk_b - A and B stacks arrays
 * amt_a & amt_b - amount of values in A and B stacks
 * sort_str - string that contains actions performed by my sorting algo
 */
char	*ft_main_sort(int *stk_a, int amt)
{
	t_ps	inst;
	int		iter;

	ft_init_struct(&inst, stk_a, amt);
	iter = ft_push_right(&inst);
}

