/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:00:54 by dlu               #+#    #+#             */
/*   Updated: 2023/05/23 14:17:47 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute command pa and write the command to op if write isn't 0. */
int	op_exec_pa(t_data *data, int write)
{
	int	i;

	if (data->size_b < 1)
		return (0);
	i = data->size_a;
	while (--i >= 0)
		data->a[i + 1] = data->a[i];
	data->a[0] = data->b[0];
	i = -1;
	while (++i < data->size_b)
		data->b[i] = data->b[i + 1];
	(data->size_a)++;
	(data->size_b)--;
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("pa"));
	return (1);
}

/* Execute command pb and write the command to op if write isn't 0. */
int	op_exec_pb(t_data *data, int write)
{
	int	i;

	if (data->size_a < 1)
		return (0);
	i = data->size_b;
	while (--i >= 0)
		data->b[i + 1] = data->b[i];
	data->b[0] = data->a[0];
	i = -1;
	while (++i < data->size_a)
		data->a[i] = data->a[i + 1];
	(data->size_b)++;
	(data->size_a)--;
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("pb"));
	return (1);
}

/* Execute command sa and write the command to op if write isn't 0. */
int	op_exec_sa(t_data *data, int write)
{
	t_ui	temp;

	if (data->size_a < 2)
		return (0);
	temp = data->a[0];
	data->a[0] = data->a[1];
	data->a[1] = temp;
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("sa"));
	return (1);
}

/* Execute command sb and write the command to op if write isn't 0. */
int	op_exec_sb(t_data *data, int write)
{
	t_ui	temp;

	if (data->size_b < 2)
		return (0);
	temp = data->b[0];
	data->b[0] = data->b[1];
	data->b[1] = temp;
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("sb"));
	return (1);
}

/* Execute command sb and write the command to op if write isn't 0. */
int	op_exec_ss(t_data *data, int write)
{
	if (data->size_a < 2 || data->size_b < 2)
		return (0);
	op_exec_sa(data, FALSE);
	op_exec_sb(data, FALSE);
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("ss"));
	return (1);
}
