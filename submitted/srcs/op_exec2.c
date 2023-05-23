/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:00:54 by dlu               #+#    #+#             */
/*   Updated: 2023/05/23 14:33:35 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute command ra and write the command to op if write isn't 0. */
int	op_exec_ra(t_data *data, int write)
{
	int		i;
	t_ui	tmp;

	if (data->size_a < 1)
		return (0);
	tmp = data->a[0];
	i = -1;
	while (++i < data->size_a - 1)
		data->a[i] = data->a[i + 1];
	data->a[data->size_a - 1] = tmp;
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("ra"));
	return (1);
}

/* Execute command rb and write the command to op if write isn't 0. */
int	op_exec_rb(t_data *data, int write)
{
	int		i;
	t_ui	tmp;

	if (data->size_b < 1)
		return (0);
	tmp = data->b[0];
	i = -1;
	while (++i < data->size_b - 1)
		data->b[i] = data->b[i + 1];
	data->b[data->size_b - 1] = tmp;
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("rb"));
	return (1);
}

/* Execute command rr and write the command to op if write isn't 0. */
int	op_exec_rr(t_data *data, int write)
{
	if (data->size_a < 1 || data->size_b < 1)
		return (0);
	op_exec_ra(data, 0);
	op_exec_rb(data, 0);
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("rb"));
	return (1);
}
