#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# 						include <stdio.h>

typedef struct	s_ps
{
	int		*stk_a;
	int		*stk_b;
	int		amt_a;
	int		amt_b;
	int 	*chunks;
	int 	chunks_pos;
	char	*sort_str;
	int 	sort_str_pos;
}				t_ps;

void	ft_input_check(char *strs[], int amount);
int		*ft_input_process(char *strs[], int amt);
int		ft_sort_ch(const int *arr, int amt);
void	ft_error(int err, char *location, t_ps *inst);

char	*ft_main_sort(int *stk_a, int amt);
int		ft_minmax(int *arr, int n, int minmax);
int		ft_mid_value(int *stk_a, int amt);
void	ft_asort_for_less_4(t_ps *inst);
void	ft_sort_a_3(t_ps *inst);
void	ft_sort_a_4(t_ps *inst);
void	ft_sort_b_3(t_ps *inst);
void	ft_sort_b_4(t_ps *inst);


void	ft_pa(t_ps *inst);
void	ft_pb(t_ps *inst);
void	ft_sa(t_ps *inst);
void	ft_sb(t_ps *inst);
void	ft_ss(t_ps *inst);
void	ft_ra(t_ps *inst);
void	ft_rb(t_ps *inst);
void	ft_rr(t_ps *inst);
void	ft_rra(t_ps *inst);
void	ft_rrb(t_ps *inst);
void	ft_rrr(t_ps *inst);

#endif
