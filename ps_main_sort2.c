#include "push_swap.h"

/**
 * Utility func for sorting both stacks when there only 4 values left in a;
 * amt_b_srt - amount of values in stack b to sort;
 */
void ft_asort_for_less_4(t_ps *inst)
{
	if (inst->amt_a == 3)
	{
		ft_sort_a_3(inst);
		if (inst->chunks[inst->chunks_pos] == 2)
		{

		}
		if (inst->chunks[inst->chunks_pos] == 3)
			ft_sort_b_3(inst);
	}
	if (inst->amt_a == 4)
	{
		ft_sort_a_4(inst);
		if (inst->chunks[inst->chunks_pos] == 3)
			ft_sort_b_3(inst);
		if (inst->chunks[inst->chunks_pos] == 4)
			ft_sort_b_4(inst);
	}
}

/*
 * Func for sorting 3 values on stack A;
 */
void ft_sort_a_3(t_ps *inst)
{
	if (inst->stk_a[0] > inst->stk_a[1] && inst->stk_a[0] < inst->stk_a[2])
	{
		if (inst->amt_b >= 2 && inst->stk_b[0] < inst->stk_b[1])
			ft_ss(inst);
		else
			ft_sa(inst);
	}
	if (inst->stk_a[1] > inst->stk_a[2] && inst->stk_a[1] < inst->stk_a[0])
	{

	}
}

/*
 * Func for sorting 4 values on stack A;
 */
void ft_sort_a_4(t_ps *inst)
{

}
/*
 * Func for sorting 3 values on stack B;
 */
void ft_sort_b_3(t_ps *inst)
{

}

/*
 * Func for sorting 4 values on stack B;
 */
void ft_sort_b_4(t_ps *inst)
{

}