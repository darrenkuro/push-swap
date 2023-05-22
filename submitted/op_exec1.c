/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:00:54 by dlu               #+#    #+#             */
/*   Updated: 2023/05/20 22:42:41 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute command pa and write the command to op if write isn't 0. */
void	op_exec_pa(t_data *data, int write)
{
	int	i;

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
}

/* Execute command pb and write the command to op if write isn't 0. */
void	op_exec_pb(t_data *data, int write)
{
	int	i;

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
}

/* Execute command sa and write the command to op if write isn't 0. */
void	op_exec_sa(t_data *data, int write)
{
	t_ui temp;

	temp = data->a[0];
	data->a[0] = data->a[1];
	data->a[1] = temp;
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("sa"));
}

/* Execute command sb and write the command to op if write isn't 0. */
void	op_exec_sb(t_data *data, int write)
{
	t_ui temp;

	temp = data->b[0];
	data->b[0] = data->b[1];
	data->b[1] = temp;
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("sb"));
}

/* Execute command sb and write the command to op if write isn't 0. */
void	op_exec_ss(t_data *data, int write)
{
	op_exec_sa(data, 0);
	op_exec_sb(data, 0);
	if (write)
		ft_lstadd_back(&data->op, ft_lstnew("ss"));
}
