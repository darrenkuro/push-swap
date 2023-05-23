/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:00:54 by dlu               #+#    #+#             */
/*   Updated: 2023/05/23 14:38:23 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute command rra and write the command to op if write isn't 0. */
int	op_exec_rra(t_data *data, int write)
{
	int		i;
	t_ui	tmp;

	if (data->size_a < 1)
		return (0);
	tmp = data->a[data->size_a - 1];
	i = data->size_a;
	while (--i > 0)
		data->a[i] = data->a[i - 1];
	data->a[0] = tmp;
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("rra"));
	return (1);
}

/* Execute command rrb and write the command to op if write isn't 0. */
int	op_exec_rrb(t_data *data, int write)
{
	int		i;
	t_ui	tmp;

	if (data->size_b < 1)
		return (0);
	tmp = data->b[data->size_b - 1];
	i = data->size_b;
	while (--i > 0)
		data->b[i] = data->b[i - 1];
	data->b[0] = tmp;
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("rrb"));
	return (1);
}

/* Execute command rrr and write the command to op if write isn't 0. */
int	op_exec_rrr(t_data *data, int write)
{
	if (data->size_a < 1 || data->size_b < 1)
		return (0);
	op_exec_rra(data, 0);
	op_exec_rrb(data, 0);
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("rrr"));
	return (1);
}
