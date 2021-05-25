#include "push_swap.h"

/*
 * Push b, cheapest operations wise, value lower than median value in a;
 * Util func for ft_push_right;
 */
static void ft_pushb_cheapest(t_ps *inst, int mid)
{
	int top;
	int bot;

	top = 0;
	bot = 1;
	while (inst->stk_a[top] >= mid)
		top++;
	while (inst->stk_a[inst->amt_a - bot] >= mid)
		bot++;
	if (top <= bot)
	{
		while (top-- > 0)
			ft_ra(inst);
		ft_pb(inst);
	}
	if (top > bot)
	{
		while (bot-- > 0)
			ft_rra(inst);
		ft_pb(inst);
	}
}

/**
 * Utility func for ft_main_sort, inits main struct
 */
static void	ft_init_struct(t_ps *inst, int *stk_a, int amt)
{
	inst->amt_a = amt;
	inst->amt_b = 0;
	inst->stk_a = stk_a;
	inst->stk_b = malloc(amt * sizeof(int));
	inst->chunks = malloc(100 * sizeof(int));
	inst->sort_str = ft_calloc(99999, sizeof(char));
	inst->sort_str_pos = 0;
	if (!inst->stk_b || !inst->chunks || !inst->sort_str)
		ft_error(1, "ft_init_struct", inst);
}

/*
 *-----Func for presort stack A in chunks and push it to B-----
 * find mid in array on stk_a and push above values to stk_b ->
 * in leftover array on stk_a preform previous operation,    ->
 * repeat until 4 or less values left;
 */
static void	ft_push_right(t_ps *inst)
{
	int mid;
	int	half;
	int iter;

	iter = 0;
	while (inst->amt_a)
	{
		if (inst->amt_a <= 4)
		{
			inst->chunks_pos = iter - 1;
			ft_asort_for_less_4(inst);
			break ;
		}
		half = 0;
		mid = ft_mid_value(inst->stk_a, inst->amt_a);
		while(half < inst->amt_a / 2)
		{
			ft_pushb_cheapest(inst, mid);
			half++;
		}
		inst->chunks[iter] = half;
		iter++;
	}
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

	ft_init_struct(&inst, stk_a, amt);
	ft_push_right(&inst);
}

