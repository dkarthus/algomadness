#include "push_swap.h"

/**
 * ---Func for handling ERRORS---
 * err = 1 - malloc error
 * err = 2 - invalid values
 */
void	ft_error(int err, char *location, t_ps *inst)
{
	if (err == 1)
	{
		ft_putstr_fd(location, 1);
		ft_putstr_fd(" - malloc ERROR\n", 1);
	}
	if (err == 2)
		ft_putstr_fd("ERROR!\nInvalid values.\n", 1);
	if (inst)
	{
		if (inst->stk_a)
			free(inst->stk_a);
		if (inst->stk_b)
			free(inst->stk_b);
		if (inst->sort_str)
			free(inst->sort_str);
		if (inst->chunks)
			free(inst->chunks);
	}
	exit (1);
}

/*
 * 		Exit func, frees main struct;
 */
void	ft_exit(t_ps *inst)
{
	if (inst->stk_a)
		free(inst->stk_a);
	if (inst->stk_b)
		free(inst->stk_b);
	if (inst->sort_str)
		free(inst->sort_str);
	if (inst->chunks)
		free(inst->chunks);
}
