#include "push_swap.h"

/*
 *	Defrags ra command if needed
 */
int ft_defr_ra(char *str, int i)
{
	int len;

	len = ft_strlen(&str[3]);
	if (!ft_strncmp(&str[3], "rra", 3))
	{
		ft_memmove(str, &str[7], len);
		str[len - 4] = '\0';
		return (i);
	}
	if (!ft_strncmp(&str[3], "rb\n", 3))
	{
		str[4] = 'r';
		ft_memmove(str, &str[3], len);
		str[len] = '\0';
		return (i + 3);
	}
	return (i + 3);
}

/*
 *	Defrags rb command if needed
 */
int ft_defr_rb(char *str, int i)
{
	int len;

	len = ft_strlen(&str[3]);
	if (!ft_strncmp(&str[3], "rrb", 3))
	{
		ft_memmove(str, &str[7], len);
		str[len - 4] = '\0';
		return (i);
	}
	if (!ft_strncmp(&str[3], "ra\n", 3))
	{
		str[4] = 'r';
		ft_memmove(str, &str[3], len);
		str[len] = '\0';
		return (i + 3);
	}
	return (i + 3);
}

/*
 *	Defrags rra command if needed
 */
int ft_defr_rra(char *str, int i)
{
	int len;

	len = ft_strlen(&str[4]);
	if (!ft_strncmp(&str[4], "ra\n", 3))
	{
		ft_memmove(str, &str[7], len);
		str[len - 4] = '\0';
		return (i);
	}
	if (!ft_strncmp(&str[4], "rrb\n", 3))
	{
		str[6] = 'r';
		ft_memmove(str, &str[4], len);
		str[len] = '\0';
		return (i + 4);
	}
	return (i + 4);
}

/*
 *	Defrags rrb command if needed
 */
int ft_defr_rrb(char *str, int i)
{
	int len;

	len = ft_strlen(&str[4]);
	if (!ft_strncmp(&str[4], "rb\n", 3))
	{
		ft_memmove(str, &str[7], len);
		str[len - 4] = '\0';
		return (i);
	}
	if (!ft_strncmp(&str[4], "rra\n", 3))
	{
		str[6] = 'r';
		ft_memmove(str, &str[4], len);
		str[len] = '\0';
		return (i + 4);
	}
	return (i + 4);
}
