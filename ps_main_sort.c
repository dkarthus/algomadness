#include "push_swap.h"

/*
 * Push b, cheapest operations wise, value lower than median value in a;
 * Util func for ft_push_right;
 */
static int	ft_pushb_cheapest(t_ps *inst, int mid)
{
	int	top;
	int	bot;
	int	ra;

	top = 0;
	bot = 1;
	while (inst->stk_a[top] >= mid)
		top++;
	while (inst->stk_a[inst->amt_a - bot] >= mid)
		bot++;
	if (top <= bot)
	{
		ra = top;
		while (top--)
			ft_ra(inst);
		ft_pb(inst);
	}
	else
	{
		ra = 0;
		while (bot--)
			ft_rra(inst);
		ft_pb(inst);
	}
	return (ra);
}

/*
 * 		Utility func for ft_push_right
 */
static void	ft_xcnt_rra(int cnt, t_ps *inst)
{
	while (cnt--)
		ft_rra(inst);
}

/*
 *-----Func for presort stack A in chunks and push it to B-----
 * find mid in array on stk_a and push above values to stk_b ->
 * in leftover array on stk_a preform previous operation,    ->
 * repeat until 4 or less values left;
 */
static void	ft_push_right(t_ps *inst, int to_psh, int mode)
{
	int	pa_cnt;
	int	ra_cnt;
	int	mid;

	while (to_psh)
	{
		if (to_psh <= 4)
		{
			ft_asort_for_less_4(inst, to_psh);
			return ;
		}
		inst->chunks_pos++;
		inst->chunks[inst->chunks_pos] = to_psh / 2;
		pa_cnt = to_psh / 2;
		ra_cnt = 0;
		mid = ft_mid_value(inst->stk_a, to_psh);
		while (pa_cnt > 0)
		{
			ra_cnt = ra_cnt + ft_pushb_cheapest(inst, mid);
			pa_cnt--;
			to_psh--;
		}
		if (mode)
			ft_xcnt_rra(ra_cnt, inst);
	}
}

/**
 *	Func for pushing half of top chunk on stack B to stack A
 */
static int	ft_push_left(t_ps *inst)
{
	int	mid;
	int	pshd;
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	pshd = inst->chunks[inst->chunks_pos] - inst->chunks[inst->chunks_pos] / 2;
	mid = ft_mid_value(inst->stk_b, inst->chunks[inst->chunks_pos]);
	while (i[0] < pshd)
	{
		if (inst->stk_b[0] >= mid)
		{
			ft_pa(inst);
			i[0]++;
		}
		else
		{
			ft_rb(inst);
			i[1]++;
		}
	}
	while (i[1]--)
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
void	ft_main_sort(int *stk_a, int amt)
{
	t_ps	inst;
	int		to_srt;

	ft_init_struct(&inst, stk_a, amt);
	ft_push_right(&inst, amt, 0);
	while (inst.amt_b > 0)
	{
		to_srt = ft_push_left(&inst);
		if (!to_srt)
			break ;
		ft_push_right(&inst, to_srt, 1);
		if (inst.chunks_pos < 0)
			break ;
	}
	ft_defragment_str(inst.sort_str);
	ft_defragment_str(inst.sort_str);
	ft_defragment_str(inst.sort_str);
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