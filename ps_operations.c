#include "push_swap.h"

/**
 * Swap a - swap the first 2 elements at the top of stack a;
 * Do nothing if there is only one or no elements;
 */
void	ft_sa(t_ps *inst)
{
	int	tmp;

	if (inst->amt_a < 2)
		return ;
	tmp = inst->stk_a[0];
	inst->stk_a[0] = inst->stk_a[1];
	inst->stk_a[1] = tmp;
	ft_memcpy(&inst->sort_str[inst->sort_str_pos], "sa\n", 3);
	inst->sort_str_pos += 3;
}

/**
 * Swap b - swap the first 2 elements at the top of stack b;
 * Do nothing if there is only one or no elements;
 */
void	ft_sb(t_ps *inst)
{
	int	tmp;

	if (inst->amt_b < 2)
		return ;
	tmp = inst->stk_b[0];
	inst->stk_b[0] = inst->stk_b[1];
	inst->stk_b[1] = tmp;
	ft_memcpy(&inst->sort_str[inst->sort_str_pos], "sb\n", 3);
	inst->sort_str_pos += 3;
}

/*
 * SA and SB at the same time;
 */
void	ft_ss(t_ps *inst)
{
	int	tmp;

	tmp = inst->sort_str_pos;
	ft_sa(inst);
	ft_sb(inst);
	ft_memcpy(&inst->sort_str[tmp], "ss\n\0", 4);
	inst->sort_str_pos = tmp + 3;
}

/**
 * push a - take the first element at the top of b and put it at the top of a;
 * Do nothing if b is empty;
 */
void	ft_pa(t_ps *inst)
{
	int	tmp;

	tmp = 0;
	if (inst->amt_b == 0)
		return ;
	while (tmp < inst->amt_a)
	{
		inst->stk_a[inst->amt_a - tmp] = inst->stk_a[inst->amt_a - tmp - 1];
		tmp++;
	}
	inst->stk_a[0] = inst->stk_b[0];
	inst->amt_a++;
	inst->amt_b--;
	tmp = 0;
	while (tmp < inst->amt_b)
	{
		inst->stk_b[tmp] = inst->stk_b[tmp + 1];
		tmp++;
	}
	ft_memcpy(&inst->sort_str[inst->sort_str_pos], "pa\n", 3);
	inst->sort_str_pos += 3;
}

/*
 * push b - take the first element at the top of a and put it at the top of b;
 * Do nothing if a is empty;
 */
void	ft_pb(t_ps *inst)
{
	int	tmp;

	tmp = 0;
	if (inst->amt_a == 0)
		return ;
	while (tmp < inst->amt_b)
	{
		inst->stk_b[inst->amt_b - tmp] = inst->stk_b[inst->amt_b - tmp - 1];
		tmp++;
	}
	inst->stk_b[0] = inst->stk_a[0];
	inst->amt_b++;
	inst->amt_a--;
	tmp = 0;
	while (tmp < inst->amt_a)
	{
		inst->stk_a[tmp] = inst->stk_a[tmp + 1];
		tmp++;
	}
	ft_memcpy(&inst->sort_str[inst->sort_str_pos], "pb\n", 3);
	inst->sort_str_pos += 3;
}
