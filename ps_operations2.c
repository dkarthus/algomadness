#include "push_swap.h"

/*
 * rotate a - shift up all elements of stack a by 1;
 * The first element becomes the last one;
 */
void	ft_ra(t_ps *inst)
{
	int	tmp;
	int	i;

	if (inst->amt_a < 2)
		ft_putstr_fd("RA - WRONG OPERATION CALL\n", 1);
	tmp = inst->stk_a[0];
	i = 1;
	while (i < inst->amt_a)
	{
		inst->stk_a[i - 1] = inst->stk_a[i];
		i++;
	}
	inst->stk_a[i - 1] = tmp;
	ft_memcpy(&inst->sort_str[inst->sort_str_pos], "ra\n", 3);
	inst->sort_str_pos += 3;
}

/*
 * rotate b - shift up all elements of stack b by 1;
 * The first element becomes the last one;
 */
void	ft_rb(t_ps *inst)
{
	int	tmp;
	int	i;

	if (inst->amt_b < 2)
		ft_putstr_fd("RB - WRONG OPERATION CALL\n", 1);
	tmp = inst->stk_b[0];
	i = 1;
	while (i < inst->amt_b)
	{
		inst->stk_b[i - 1] = inst->stk_b[i];
		i++;
	}
	inst->stk_b[i - 1] = tmp;
	ft_memcpy(&inst->sort_str[inst->sort_str_pos], "rb\n", 3);
	inst->sort_str_pos += 3;
}

/*
 * ra and rb at the same time;
 */
void	ft_rr(t_ps *inst)
{
	int	tmp;

	tmp = inst->sort_str_pos;
	ft_ra(inst);
	ft_rb(inst);
	ft_memcpy(&inst->sort_str[tmp], "rr\n\0", 4);
	inst->sort_str_pos = tmp + 3;
}
