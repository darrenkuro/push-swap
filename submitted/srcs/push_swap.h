/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:13:48 by dlu               #+#    #+#             */
/*   Updated: 2023/05/22 12:32:11 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <limits.h>

# define TRUE		1
# define SUCCESS	0
# define FALSE		0
# define FAILURE	1
# define INT_MAXLEN	11
# define STDERR		2
# define ERROR_MSG	"Error\n"

typedef unsigned int	t_ui;

typedef struct s_data
{
	t_ui	*a;
	t_ui	*b;
	t_list	*op;
	int		size_a;
	int		size_b;
}	t_data;

void	op_exec_pa(t_data *data, int write);
void	op_exec_pb(t_data *data, int write);
void	op_exec_ra(t_data *data, int write);
void	op_exec_rb(t_data *data, int write);
void	op_exec_rr(t_data *data, int write);
void	op_exec_rra(t_data *data, int write);
void	op_exec_rrb(t_data *data, int write);
void	op_exec_rrr(t_data *data, int write);

int		input_issorted(int ac, char **av);
int		input_isnum(int ac, char **av);
int		input_isint(int ac, char **av);
int		input_isunique(int ac, char **av);
void	input_parser(int ac, char **av, t_data *data);
void	sort_three(unsigned int *arr, t_list **op);
void	sort_five(unsigned int *arr, t_list **op);
int		op_print(t_list *op);

#endif
