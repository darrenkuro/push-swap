/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:00:54 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 09:44:46 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute command ra and write the command to index of op if it's in range. */
int	op_exec_ra(t_data *data, int index)
{
	int		i;
	t_ui	tmp;

	if (data->size_a < 1)
		return (FALSE);
	tmp = data->a[0];
	i = -1;
	while (++i < data->size_a - 1)
		data->a[i] = data->a[i + 1];
	data->a[data->size_a - 1] = tmp;
	if (index >= 0)
		ft_lstadd_back(&data->op, ft_lstnew("ra"));
	return (TRUE);
}

/* Execute command rb and write the command to index of op if it's in range. */
int	op_exec_rb(t_data *data, int index)
{
	int		i;
	t_ui	tmp;

	if (data->size_b < 1)
		return (FALSE);
	tmp = data->b[0];
	i = -1;
	while (++i < data->size_b - 1)
		data->b[i] = data->b[i + 1];
	data->b[data->size_b - 1] = tmp;
	if (index >= 0)
		ft_lstadd_back(&data->op, ft_lstnew("rb"));
	return (TRUE);
}

/* Execute command rr and write the command to index of op if it's in range. */
int	op_exec_rr(t_data *data, int index)
{
	if (data->size_a < 1 || data->size_b < 1)
		return (FALSE);
	op_exec_ra(data, -1);
	op_exec_rb(data, -1);
	if (index >= 0)
		ft_lstadd_back(&data->op, ft_lstnew("rr"));
	return (TRUE);
}
