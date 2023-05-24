/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:13:48 by dlu               #+#    #+#             */
/*   Updated: 2023/05/24 23:10:32 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define TRUE		1
# define SUCCESS	0
# define FALSE		0
# define FAILURE	1
# define INT_MAXLEN	11
# define STDIN		0
# define STDERR		2
# define ERROR_MSG	"Error\n"
# define MAX_SORT	4

typedef struct s_data
{
	t_ui	*a;
	t_ui	*b;
	t_list	*op[MAX_SORT];
	int		size_a;
	int		size_b;
}	t_data;

int		op_exec_pa(t_data *data, int write);
int		op_exec_pb(t_data *data, int write);
int		op_exec_sa(t_data *data, int write);
int		op_exec_sb(t_data *data, int write);
int		op_exec_ss(t_data *data, int write);
int		op_exec_ra(t_data *data, int write);
int		op_exec_rb(t_data *data, int write);
int		op_exec_rr(t_data *data, int write);
int		op_exec_rra(t_data *data, int write);
int		op_exec_rrb(t_data *data, int write);
int		op_exec_rrr(t_data *data, int write);

int		input_issorted(int ac, char **av);
int		input_isnum(int ac, char **av);
int		input_isint(int ac, char **av);
int		input_isunique(int ac, char **av);
void	input_parser(int ac, char **av, t_data *data);
void	sort_three(t_data *data, int write);
void	sort_five(t_data *data, int write);
void	sort_ordered(t_data *data, int write);
void	sort_large(t_data *data, int write);
int		sort_radix(t_data *data, int write);
int		op_print(t_list *op);

void	print_error(const char *msg);
int		data_init(int ac, char **av, t_data *data);
int		get_shortest_op_index(t_data *data);

void	optimize_op(t_list *op);
int		a_isordered(t_data *data);

#endif
