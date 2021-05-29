#include "push_swap.h"

/*
 * Push b, cheapest operations wise, value lower than median value in a;
 * Util func for ft_push_right;
 */
static void ft_pushb_cheapest(t_ps *inst, int mid)
{
	int top;
	int bot;

	top = 0;
	bot = 1;
	while (inst->stk_a[top] >= mid)
		top++;
	while (inst->stk_a[inst->amt_a - bot] >= mid)
		bot++;
	if (top <= bot)
	{
		while (top-- > 0)
			ft_ra(inst);
		ft_pb(inst);
	}
	else
	{
		while (bot-- > 0)
			ft_rra(inst);
		ft_pb(inst);
	}
}

/**
 * Utility func for ft_main_sort, inits main struct
 */
static void	ft_init_struct(t_ps *inst, int *stk_a, int amt)
{
	inst->amt_a = amt;
	inst->amt_b = 0;
	inst->stk_a = stk_a;
	inst->stk_b = malloc(amt * sizeof(int));
	inst->chunks = malloc(100 * sizeof(int));
	inst->chunks_pos = -1;
	inst->sort_str = ft_calloc(99999, sizeof(char));
	inst->sort_str_pos = 0;
	if (!inst->stk_b || !inst->chunks || !inst->sort_str)
		ft_error(1, "ft_init_struct", inst);
}

/*
 *-----Func for presort stack A in chunks and push it to B-----
 * find mid in array on stk_a and push above values to stk_b ->
 * in leftover array on stk_a preform previous operation,    ->
 * repeat until 4 or less values left;
 */
static void	ft_push_right(t_ps *inst, int to_psh)
{
	int mid;
	int	half;

	while (inst->amt_a)
	{
		if (to_psh <= 4)
		{
			ft_asort_for_less_4(inst, to_psh);
			break ;
		}
		inst->chunks_pos++;
		half = to_psh / 2;
		inst->chunks[inst->chunks_pos] = half;
		mid = ft_mid_value(inst->stk_a, to_psh);
		while(half > 0)
		{
			ft_pushb_cheapest(inst, mid);
			half--;
			to_psh--;
		}
	}
}

/**
 *	Func for pushing half of top chunk on stack B to stack A
 */
static int	ft_push_left(t_ps *inst)
{
	int mid;
	int cnt;
	int	pshd;
	int i;

	cnt = 0;
	i = 0;
	pshd = inst->chunks[inst->chunks_pos] - inst->chunks[inst->chunks_pos] / 2;
	mid = ft_mid_value(inst->stk_b, inst->chunks[inst->chunks_pos]);
	while(i < pshd)
	{
		if (inst->stk_b[0] >= mid)
		{
			ft_pa(inst);
			i++;
		}
		else
		{
			ft_rb(inst);
			cnt++;
		}
	}
	while (cnt--)
		ft_rrb(inst);
	inst->chunks[inst->chunks_pos] = inst->chunks[inst->chunks_pos] / 2;
	return (pshd);
}

/**
 * --Main func for calling sort utility func's---
 *stk_a & stk_b - A and B stacks arrays
 * amt_a & amt_b - amount of values in A and B stacks
 * sort_str - string that contains actions performed by my sorting algo
 */
void ft_main_sort(int *stk_a, int amt)
{
	t_ps	inst;
	int 	to_srt;

	ft_init_struct(&inst, stk_a, amt);
	ft_push_right(&inst, amt);
	while (inst.chunks_pos >= 0)
	{
		to_srt = ft_push_left(&inst);
		ft_push_right(&inst, to_srt);
	}
	ft_putstr_fd(inst.sort_str, 1);
	ft_exit(&inst);
}
/*
int main(void)
{
	t_ps	inst;
	int 	stk_a[] = { 111, -1, 3, 4, 5, 123, -123, 11111, 321, -321, 999, 0 };
	int		*stk;
	int		to_srt;
	int		i;

	i = 0;
	stk = malloc(8 * sizeof(int));
	ft_memcpy(stk, stk_a, 8 * sizeof(int));
	ft_init_struct(&inst, stk_a, 12);
	ft_push_right(&inst, 12);
	while (inst.chunks_pos >= 0)
	{
//		if (inst.amt_a == 12 && ft_sort_ch(inst.stk_a, 12))
//			break;
		to_srt = ft_push_left(&inst);
		printf("%d\n", to_srt);
		ft_push_right(&inst, to_srt);
	}

	printf("amt_a %d\n", inst.amt_a);
	printf("amt_b %d\n", inst.amt_b);
	while (i < inst.amt_a)
	{
		printf("%d, ", inst.stk_a[i]);
		i++;
	}
	i = 0;
	printf("\n");
	while (i < inst.amt_b)
	{
		printf("%d, ", inst.stk_b[i]);
		i++;
	}
	printf("\nchunks ");
	printf("%d, ", inst.chunks[0]);
	printf("%d, ", inst.chunks[1]);
	printf("\npos %d\n", inst.chunks_pos);

}
*/