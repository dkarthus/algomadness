#include "push_swap.h"

/**
 * ----Sort func for finding mid value----
 * returns mid value in int
 * all input checks must be done beforehand
 */
int	ft_mid_value(int *stk_a, int amt)
{
	int	i;
	int	j;
	int	key;
	int	*tmp;

	tmp = malloc(amt * sizeof(int));
	if (!tmp)
		ft_error(1, "ft_mid_value", NULL);
	tmp = ft_memcpy(tmp, stk_a, amt * sizeof(int));
	i = 1;
	while (i < amt)
	{
		j = i - 1;
		key = tmp[i];
		while (j >= 0 && tmp[j] > key)
		{
			tmp[j + 1] = tmp[j];
			j--;
		}
		tmp[j + 1] = key;
		i++;
	}
	key = tmp[amt / 2];
	free (tmp);
	return (key);
}

/**
 * Utility func for ft_main_sort, inits main struct
 */
void	ft_init_struct(t_ps *inst, int *stk_a, int amt)
{
	inst->amt_a = amt;
	inst->amt_b = 0;
	inst->stk_a = stk_a;
	inst->stk_b = malloc(amt * sizeof(int));
	inst->chunks = malloc(100 * sizeof(int));
	inst->chunks_pos = -1;
	inst->sort_str = ft_calloc(25000, sizeof(char));
	inst->sort_str_pos = 0;
	if (!inst->stk_b || !inst->chunks || !inst->sort_str)
		ft_error(1, "ft_init_struct", inst);
}
