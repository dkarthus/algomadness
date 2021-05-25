#include "push_swap.h"

/**
 * Utility func for sorting both stacks when there only 4 values left in a;
 * amt_b_srt - amount of values in stack b to sort;
 */
void ft_asort_for_less_4(t_ps *inst, int iter)
{
	int lst_psh_amt;

	lst_psh_amt = (inst->amt_a + inst->amt_b) / (2 * (iter - 1));
	if (inst->amt_a == 3)
	{
		if (lst_psh_amt == 6)
		{

		}
		if (lst_psh_amt == 5)
		{

		}
	}
	if (inst->amt_a == 4)
	{
		if (lst_psh_amt == 7)
		{

		}
		if (lst_psh_amt == 8)
		{

		}
	}
}

/*
 * Push b, cheapest operations wise, value lower than median value in a;
 */
void ft_pushb_cheapest(t_ps *inst, int mid)
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
