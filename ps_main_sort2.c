#include "push_swap.h"

/**
 * Utility func for sorting both stacks when there only 4 values left in a;
 * amt_b_srt - amount of values in stack b to sort;
 */
void ft_asort_for_less_4(t_ps *inst, int to_srt)
{
	if (to_srt == 3)
	{
		ft_sort_a_3(inst);
		if (inst->chunks[inst->chunks_pos] == 2)
		{
			if (inst->stk_b[0] < inst->stk_b[1])
				ft_sb(inst);
			ft_pa(inst);
			ft_pa(inst);
		}
		else if (inst->chunks[inst->chunks_pos] == 3)
			ft_sort_b_3(inst);
	}
	else if (to_srt == 4)
	{
		ft_sort_a_4(inst);
		if (inst->chunks[inst->chunks_pos] == 3)
			ft_sort_b_3(inst);
		else if (inst->chunks[inst->chunks_pos] == 4)
			ft_sort_b_4(inst);
	}
	inst->chunks[inst->chunks_pos] = 0;
	inst->chunks_pos--;
}

/*
 * --Util func for ft_sort_a_3--
 */
static void ft_super_sa(t_ps *inst)
{
	if (inst->amt_b >= 2 && inst->stk_b[0] < inst->stk_b[1])
		ft_ss(inst);
	else
		ft_sa(inst);
}

/*
 * --Util func for ft_sort_a_3--
 */
static void ft_super_rra(t_ps *inst)
{
	if (inst->amt_a == 3)
	{
		if (inst->amt_b == 2 && inst->stk_b[0] < inst->stk_b[1])
			ft_rrr(inst);
		else
			ft_rra(inst);
	}
	else
	{
		ft_ra(inst);
		ft_ra(inst);
		ft_pb(inst);
		ft_rra(inst);
		ft_rra(inst);
		ft_pa(inst);
	}
}

/*
 * --Util func for ft_sort_a_3--
 */
static void ft_super_ra(t_ps *inst)
{
	if (inst->amt_a == 3)
	{
		if (inst->amt_b == 2 && inst->stk_b[0] < inst->stk_b[1])
			ft_rr(inst);
		else
			ft_ra(inst);
	}
	else
	{
		ft_ra(inst);
		ft_pb(inst);
		ft_pb(inst);
		ft_pa(inst);
		ft_pa(inst);
	}
}

/*
 * Func for sorting 3 values on stack A;
 */
void ft_sort_a_3(t_ps *inst)
{
	if (ft_sort_ch(inst->stk_a, 3))
		return;
	if (inst->stk_a[0] > inst->stk_a[1] && inst->stk_a[0] < inst->stk_a[2])
		ft_super_sa(inst);
	if (inst->stk_a[1] > inst->stk_a[2] && inst->stk_a[1] < inst->stk_a[0])
	{
		ft_super_sa(inst);
		ft_super_rra(inst);
	}
	if (inst->stk_a[2] > inst->stk_a[1] && inst->stk_a[2] < inst->stk_a[0])
		ft_super_ra(inst);
	if (inst->stk_a[2] > inst->stk_a[0] && inst->stk_a[2] < inst->stk_a[1])
	{
		ft_super_sa(inst);
		ft_super_ra(inst);
	}
	if (inst->stk_a[0] > inst->stk_a[2] && inst->stk_a[0] < inst->stk_a[1])
		ft_super_rra(inst);
}
