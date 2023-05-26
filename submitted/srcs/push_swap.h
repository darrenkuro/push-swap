/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:13:48 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 09:49:51 by dlu              ###   ########.fr       */
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
# define RARB		1
# define RARRB		2
# define RRARB		3
# define RRARRB		4
# define ERROR_MSG	"Error\n"

typedef struct s_data
{
	t_ui	*a;
	t_ui	*b;
	t_list	*op;
	int		size_a;
	int		size_b;
}	t_data;

int		op_exec_pa(t_data *data, int index);
int		op_exec_pb(t_data *data, int index);
int		op_exec_sa(t_data *data, int index);
int		op_exec_sb(t_data *data, int index);
int		op_exec_ss(t_data *data, int index);
int		op_exec_ra(t_data *data, int index);
int		op_exec_rb(t_data *data, int index);
int		op_exec_rr(t_data *data, int index);
int		op_exec_rra(t_data *data, int index);
int		op_exec_rrb(t_data *data, int index);
int		op_exec_rrr(t_data *data, int index);

int		input_isnum(int ac, char **av);
int		input_isint(int ac, char **av);
int		input_isunique(int ac, char **av);
void	input_parser(int ac, char **av, t_data *data);
void	sort_three(t_data *data);
void	sort_ordered(t_data *data);
void	sort_algorithm(t_data *data);

void	print_error_exit(const char *msg);
int		data_init(int ac, char **av, t_data *data);

void	optimize_op(t_list *op);
void	optimize_rr(t_list *start, t_list *end);
void	optimize_rrr(t_list *start, t_list *end);
int		array_issorted(t_ui *arr, int size);
int		stack_a_isordered(t_data *data);

t_ui	get_max(t_ui *arr, int size);
t_ui	get_min(t_ui *arr, int size);
int		get_max_index(t_ui *arr, int size);
int		get_min_index(t_ui *arr, int size);

int		push_index_ab(t_ui *arr, int size, t_ui nbr);
int		push_index_ba(t_ui *arr, int size, t_ui nbr);

void	rotate_rarb(t_data *data, int ia, int ib);
void	rotate_rarrb(t_data *data, int ia, int ib);
void	rotate_rrarb(t_data *data, int ia, int ib);
void	rotate_rrarrb(t_data *data, int ia, int ib);

int		cheapest_index_ab(t_data *data);
int		get_rotate_type(int index_a, int size_a, int index_b, int size_b);
int		rotate_count(int ia, int sa, int ib, int sb);

t_ui	count_rarb(int ia, int ib);
t_ui	count_rarrb(int ia, int ib, int sb);
t_ui	count_rrarb(int ia, int sa, int ib);
t_ui	count_rrarrb(int ia, int sa, int ib, int sb);

#endif
