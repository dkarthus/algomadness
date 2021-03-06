#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_ps
{
	int		*stk_a;
	int		*stk_b;
	int		amt_a;
	int		amt_b;
	int		*chunks;
	int		chunks_pos;
	char	*sort_str;
	int		sort_str_pos;
}				t_ps;

void	ft_defragment_str(char *str);
void	ft_input_check(char *strs[], int amount, int mode);
int		*ft_input_process(char *strs[], int amt);
int		*ft_input_process_alt(char *strs[], int amt);
int		ft_sort_ch(const int *arr, int amt);
void	ft_error(int err, char *location, t_ps *inst);
void	ft_exit(t_ps *inst);

void	ft_main_sort(int *stk_a, int amt);
int		ft_minmax(int *arr, int n, int minmax);
int		ft_mid_value(int *stk_a, int amt);
void	ft_asort_for_less_4(t_ps *inst, int to_srt);
void	ft_sort_a_3(t_ps *inst);
void	ft_sort_a_4(t_ps *inst);
void	ft_sort_b_3(t_ps *inst);
void	ft_sort_b_4(t_ps *inst);

void	ft_free_after_split(char **strs);
int		ft_cnt_strs(char *strs[]);
void	ft_init_struct(t_ps *inst, int *stk_a, int amt);

int		ft_defr_sa(char *str, int i);
int		ft_defr_sb(char *str, int i);
int		ft_defr_pa(char *str, int i);
int		ft_defr_pb(char *str, int i);
int		ft_defr_ra(char *str, int i);
int		ft_defr_rb(char *str, int i);
int		ft_defr_rra(char *str, int i);
int		ft_defr_rrb(char *str, int i);

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
