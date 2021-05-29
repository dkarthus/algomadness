#include "push_swap.h"

/*
 * ---Utility func for ft_sort_b_3---
 */
static void ft_util1(t_ps *inst)
{
	if (inst->amt_b == 3)
	{
		ft_rrb(inst);
		ft_pa(inst);
		ft_pa(inst);
		ft_pa(inst);
	}
	else
	{
		ft_rb(inst);
		ft_rb(inst);
		ft_pa(inst);
		ft_rrb(inst);
		ft_rrb(inst);
		ft_pa(inst);
		ft_pa(inst);
	}
}

/*
 * ---Utility func for ft_sort_b_3---
 */
static void ft_util2(t_ps *inst)
{
	if (inst->amt_b == 3)
	{
		ft_rb(inst);
		ft_pa(inst);
		ft_pa(inst);
		ft_pa(inst);
	}
	else
	{
		ft_sb(inst);
		ft_pa(inst);
		ft_sb(inst);
		ft_pa(inst);
		ft_pa(inst);
	}
}

/*
 * ---Utility func for ft_sort_b_3---
 */
static void ft_util3(t_ps *inst)
{
	if (inst->amt_b == 3)
	{
		ft_rrb(inst);
		ft_pa(inst);
		ft_sb(inst);
		ft_pa(inst);
		ft_pa(inst);
	}
	else
	{
		ft_rb(inst);
		ft_rb(inst);
		ft_pa(inst);
		ft_rrb(inst);
		ft_pa(inst);
		ft_rrb(inst);
		ft_pa(inst);
	}
}

/*
 * Func for sorting 3 values on stack B;
 */
void ft_sort_b_3(t_ps *inst)
{
	if (inst->stk_b[1] > inst->stk_b[0] && inst->stk_b[1] < inst->stk_b[2])
		ft_util3(inst);
	if (inst->stk_b[0] > inst->stk_b[1] && inst->stk_b[0] < inst->stk_b[2])
		ft_util1(inst);
	if (inst->stk_b[1] > inst->stk_b[2] && inst->stk_b[1] < inst->stk_b[0])
	{
		ft_pa(inst);
		ft_pa(inst);
		ft_pa(inst);
	}
	if (inst->stk_b[2] > inst->stk_b[1] && inst->stk_b[2] < inst->stk_b[0])
	{
		ft_pa(inst);
		ft_sb(inst);
		ft_pa(inst);
		ft_pa(inst);
	}
	if (inst->stk_b[2] > inst->stk_b[0] && inst->stk_b[2] < inst->stk_b[1])
		ft_util2(inst);
	if (inst->stk_b[0] > inst->stk_b[2] && inst->stk_b[0] < inst->stk_b[1])
	{
		ft_sb(inst);
		ft_pa(inst);
		ft_pa(inst);
		ft_pa(inst);
	}
}
