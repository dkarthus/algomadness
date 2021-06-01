#include "push_swap.h"

/**
 * --Utility func for ft_sort_b_4--
 */
static void	ft_util1(t_ps *inst)
{
	int	pos;

	pos = ft_minmax(inst->stk_b, 4, 1);
	if (pos == 3)
	{
		ft_rrb(inst);
		ft_pa(inst);
	}
	else
	{
		while (pos--)
			ft_rb(inst);
		ft_pa(inst);
	}
	ft_sort_b_3(inst);
}

/**
 * --Utility func for ft_sort_b_4--
 */
static void	ft_util2(t_ps *inst)
{
	int	pos;
	int	i;

	pos = ft_minmax(inst->stk_b, 4, 1);
	i = pos;
	while (pos--)
		ft_rb(inst);
	ft_pa(inst);
	while (i--)
		ft_rrb(inst);
	ft_sort_b_3(inst);
}

/*
 * Func for sorting 4 values chunk on stack B;
 */
void	ft_sort_b_4(t_ps *inst)
{
	if (inst->amt_b == 4)
		ft_util1(inst);
	else
		ft_util2(inst);
}
