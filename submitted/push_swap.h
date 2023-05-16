/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:13:48 by dlu               #+#    #+#             */
/*   Updated: 2023/05/17 00:20:44 by dlu              ###   ########.fr       */
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
	t_list	*a;
	t_list	*b;
	t_list	*op;
	int		size_a;
	int		size_b;
	int		size_op;
}	t_data;

int		input_issorted(int ac, char **av);
int		input_isnum(int ac, char **av);
int		input_isint(int ac, char **av);
int		input_isunique(int ac, char **av);
t_list	*input_parser(int ac, char **av, t_list **stack);
void	sort_three(unsigned int *arr, t_list **op);
void	sort_five(unsigned int *arr, t_list **op);
int		op_print(t_list *op);

#endif
