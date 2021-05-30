#include "push_swap.h"

/**
 * reverse rotate a - shift down all elements of stack a by 1;
 * The last element becomes the first one;
 */
void	ft_rra(t_ps *inst)
{
	int	tmp;
	int i;

	if (inst->amt_a < 2)
		ft_putstr_fd("RRA - WRONG OPERATION CALL\n", 1);
	tmp = inst->stk_a[inst->amt_a - 1];
	i = inst->amt_a - 1;
	while (i > 0)
	{
		inst->stk_a[i] = inst->stk_a[i - 1];
		i--;
	}
	inst->stk_a[0] = tmp;
	ft_memcpy(&inst->sort_str[inst->sort_str_pos], "rra\n", 4);
	inst->sort_str_pos += 4;
}

/*
 * reverse rotate b - shift down all elements of stack b by 1;
 * The last element becomes the first one;
 */
void	ft_rrb(t_ps *inst)
{
	int	tmp;
	int i;

	if (inst->amt_b < 2)
		ft_putstr_fd("RRB - WRONG OPERATION CALL\n", 1);
	tmp = inst->stk_b[inst->amt_b - 1];
	i = inst->amt_b - 1;
	while (i > 0)
	{
		inst->stk_b[i] = inst->stk_b[i - 1];
		i--;
	}
	inst->stk_b[0] = tmp;
	ft_memcpy(&inst->sort_str[inst->sort_str_pos], "rrb\n", 4);
	inst->sort_str_pos += 4;
}

/*
 * rra and rrb at the same time;
 */
void	ft_rrr(t_ps *inst)
{
	int	tmp;

	tmp = inst->sort_str_pos;
	ft_rra(inst);
	ft_rrb(inst);
	ft_memcpy(&inst->sort_str[tmp], "rrr\n\0", 5);
	inst->sort_str_pos = tmp + 4;
}
