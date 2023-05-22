/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:00:54 by dlu               #+#    #+#             */
/*   Updated: 2023/05/20 22:50:59 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute command rra and write the command to op if write isn't 0. */
void	op_exec_rra(t_data *data, int write)
{
	int	i;

	data->a[0] = data->a[data->size_a - 1];
	i = size_a;
	while (--i > 0)
		data->a[i] = data->a[i - 1];
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("rra"));
}

/* Execute command rrb and write the command to op if write isn't 0. */
void	op_exec_rrb(t_data *data, int write)
{
	int	i;

	data->b[0] = data->b[data->size_b - 1];
	i = size_b;
	while (--i > 0)
		data->b[i] = data->b[i - 1];
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("rrb"));
}

/* Execute command rrr and write the command to op if write isn't 0. */
void	op_exec_rrr(t_data *data, int write)
{
	op_exec_rra(data, 0);
	op_exec_rrb(data, 0);
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("rrr"));
}
