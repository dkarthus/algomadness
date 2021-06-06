#include "push_swap.h"

/*
 *	Defrags sa command if needed
 */
int	ft_defr_sa(char *str, int i)
{
	int	len;

	len = ft_strlen(&str[3]);
	if (!ft_strncmp(&str[3], "sa\n", 3))
	{
		ft_memmove(str, &str[6], len);
		str[len - 3] = '\0';
		return (i);
	}
	if (!ft_strncmp(&str[3], "sb\n", 3))
	{
		str[4] = 's';
		ft_memmove(str, &str[3], len);
		str[len] = '\0';
		return (i + 3);
	}
	return (i + 3);
}

/*
 *	Defrags sb command if needed
 */
int	ft_defr_sb(char *str, int i)
{
	int	len;

	len = ft_strlen(&str[3]);
	if (!ft_strncmp(&str[3], "sb\n", 3))
	{
		ft_memmove(str, &str[6], len);
		str[len - 3] = '\0';
		return (i);
	}
	if (!ft_strncmp(&str[3], "sa\n", 3))
	{
		str[4] = 's';
		ft_memmove(str, &str[3], len);
		str[len] = '\0';
		return (i + 3);
	}
	return (i + 3);
}

/*
 *	Defrags pa command if needed
 */
int	ft_defr_pa(char *str, int i)
{
	int	len;

	len = ft_strlen(&str[6]);
	if (!ft_strncmp(&str[3], "pb\n", 3))
	{
		ft_memmove(str, &str[6], len);
		str[len] = '\0';
		return (i);
	}
	return (i + 3);
}

/*
 * 	Utility func for ft_defragment_str
 */
static void	ft_util_def(char *str, int *i)
{
	if (!ft_strncmp(&str[*i], "ss\n", 3) || !ft_strncmp(&str[*i], "rr\n", 3))
		*i += 3;
	if (!ft_strncmp(&str[*i], "rrr", 3))
		*i += 4;
	if (str[*i] == '\n')
		*i = *i + 1;
}

/*
 *		Func fro defragmentation main output str;
 *		deletes and optimizes needless operations;
 */
void	ft_defragment_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strncmp(&str[i], "sa\n", 3))
			i = ft_defr_sa(&str[i], i);
		if (!ft_strncmp(&str[i], "sb\n", 3))
			i = ft_defr_sb(&str[i], i);
		if (!ft_strncmp(&str[i], "pa\n", 3))
			i = ft_defr_pa(&str[i], i);
		if (!ft_strncmp(&str[i], "pb\n", 3))
			i = ft_defr_pb(&str[i], i);
		if (!ft_strncmp(&str[i], "ra\n", 3))
			i = ft_defr_ra(&str[i], i);
		if (!ft_strncmp(&str[i], "rb\n", 3))
			i = ft_defr_rb(&str[i], i);
		if (!ft_strncmp(&str[i], "rra", 3))
			i = ft_defr_rra(&str[i], i);
		if (!ft_strncmp(&str[i], "rrb", 3))
			i = ft_defr_rrb(&str[i], i);
		ft_util_def(str, &i);
	}
}
