#include "push_swap.h"

/*
 *	Count string in 2d array
 */
int	ft_cnt_strs(char *strs[])
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

/*
 *	Free 2d array
 */
void	ft_free_after_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs[i]);
	free(strs);
}

/*
 *	Function for performing operations onto stack
 */
static void	ft_perform_operation(t_ps *inst, char *line)
{
	if (!ft_strncmp(line, "pa\0", 3))
		ft_pa(inst);
	else if (!ft_strncmp(line, "rra\0", 4))
		ft_rra(inst);
	else if (!ft_strncmp(line, "rrb\0", 4))
		ft_rrb(inst);
	else if (!ft_strncmp(line, "rrr\0", 4))
		ft_rrr(inst);
	else if (!ft_strncmp(line, "pb\0", 3))
		ft_pb(inst);
	else if (!ft_strncmp(line, "sa\0", 3))
		ft_sa(inst);
	else if (!ft_strncmp(line, "sb\0", 3))
		ft_sb(inst);
	else if (!ft_strncmp(line, "ra\0", 3))
		ft_ra(inst);
	else if (!ft_strncmp(line, "rb\0", 3))
		ft_rb(inst);
	else if (!ft_strncmp(line, "rr\0", 3))
		ft_rr(inst);
	else if (!ft_strncmp(line, "ss\0", 3))
		ft_ss(inst);
	else
		ft_error(2, NULL, inst);
}

/*
 *	 Main sort check func;
 */
static void	ft_main_check(t_ps *inst)
{
	int		ret;
	char	*line;

	while (1)
	{
		ret = ft_get_next_line(0, &line);
		if (ret == -1)
		{
			free(line);
			exit (1);
		}
		if (!ret)
			break ;
		ft_perform_operation(inst, line);
		free(line);
	}
	if (ft_sort_ch(inst->stk_a, inst->amt_a) && !inst->amt_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

/*
 * 		Main function
 */
int	main(int argc, char *argv[])
{
	int		amt;
	int		*stk_a;
	char	**strs;
	t_ps	inst;

	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		amt = ft_cnt_strs(strs);
		ft_input_check(strs, amt, 0);
		stk_a = ft_input_process_alt(strs, amt);
		ft_free_after_split(strs);
		ft_init_struct(&inst, stk_a, amt);
	}
	else
	{
		ft_input_check(argv, argc - 1, 1);
		stk_a = ft_input_process(argv, argc - 1);
		ft_init_struct(&inst, stk_a, argc - 1);
	}
	ft_main_check(&inst);
	ft_exit(&inst);
	return (0);
}
