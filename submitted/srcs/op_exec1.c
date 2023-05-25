/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:00:54 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 12:15:10 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute command pa and write the command to index of op if it's in range. */
int	op_exec_pa(t_data *data, int index)
{
	int	i;

	if (data->size_b < 1)
		return (FALSE);
	i = data->size_a;
	while (--i >= 0)
		data->a[i + 1] = data->a[i];
	data->a[0] = data->b[0];
	i = -1;
	while (++i < data->size_b)
		data->b[i] = data->b[i + 1];
	(data->size_a)++;
	(data->size_b)--;
	if (index >= 0 && index < MAX_SORT)
		ft_lstadd_back(&data->op[index], ft_lstnew("pa"));
	return (TRUE);
}

/* Execute command pb and write the command to index of op if it's in range. */
int	op_exec_pb(t_data *data, int index)
{
	int	i;

	if (data->size_a < 1)
		return (FALSE);
	i = data->size_b;
	while (--i >= 0)
		data->b[i + 1] = data->b[i];
	data->b[0] = data->a[0];
	i = -1;
	while (++i < data->size_a - 1)
		data->a[i] = data->a[i + 1];
	data->a[i] = 0;
	(data->size_b)++;
	(data->size_a)--;
	if (index >= 0 && index < MAX_SORT)
		ft_lstadd_back(&data->op[index], ft_lstnew("pb"));
	return (TRUE);
}

/* Execute command sa and write the command to index of op if it's in range. */
int	op_exec_sa(t_data *data, int index)
{
	t_ui	temp;

	if (data->size_a < 2)
		return (FALSE);
	temp = data->a[0];
	data->a[0] = data->a[1];
	data->a[1] = temp;
	if (index >= 0 && index < MAX_SORT)
		ft_lstadd_back(&data->op[index], ft_lstnew("sa"));
	return (TRUE);
}

/* Execute command sb and write the command to index of op if it's in range. */
int	op_exec_sb(t_data *data, int index)
{
	t_ui	temp;

	if (data->size_b < 2)
		return (FALSE);
	temp = data->b[0];
	data->b[0] = data->b[1];
	data->b[1] = temp;
	if (index >= 0 && index < MAX_SORT)
		ft_lstadd_back(&data->op[index], ft_lstnew("sb"));
	return (TRUE);
}

/* Execute command sb and write the command to index of op if it's in range. */
int	op_exec_ss(t_data *data, int index)
{
	if (data->size_a < 2 || data->size_b < 2)
		return (FALSE);
	op_exec_sa(data, -1);
	op_exec_sb(data, -1);
	if (index >= 0 && index < MAX_SORT)
		ft_lstadd_back(&data->op[index], ft_lstnew("ss"));
	return (TRUE);
}
