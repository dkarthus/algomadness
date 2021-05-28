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
		while (pos > 0)
		{
			ft_rb(inst);
			pos--;
		}
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
	i = 0;
	while (i < pos)
	{
		ft_rb(inst);
		i++;
	}
	ft_pa(inst);
	while (i > 0)
	{
		ft_rrb(inst);
		i--;
	}
	ft_sort_b_3(inst);
}

/*
 * Func for sorting 4 values chunk on stack B;
 */
void ft_sort_b_4(t_ps *inst)
{
	if (inst->amt_b == 4)
		ft_util1(inst);
	else
		ft_util2(inst);
}
