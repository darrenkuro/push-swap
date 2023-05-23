/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:00:54 by dlu               #+#    #+#             */
/*   Updated: 2023/05/20 22:47:12 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute command ra and write the command to op if write isn't 0. */
void	op_exec_ra(t_data *data, int write)
{
	int	i;

	data->a[data->size_a - 1] = data->a[0];
	i = -1;
	while (++i < data->size_a - 1)
		data->a[i] = data->a[i + 1];
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("ra"));
}

/* Execute command rb and write the command to op if write isn't 0. */
void	op_exec_rb(t_data *data, int write)
{
	int	i;

	data->b[data->size_b - 1] = data->b[0];
	i = -1;
	while (++i < data->size_b - 1)
		data->b[i] = data->b[i + 1];
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("rb"));
}

/* Execute command rr and write the command to op if write isn't 0. */
void	op_exec_rr(t_data *data, int write)
{
	op_exec_ra(data, 0);
	op_exec_rb(data, 0);
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("rb"));
}
