/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:00:54 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 12:15:26 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute command rra and write the command to index of op if it's in range. */
int	op_exec_rra(t_data *data, int index)
{
	int		i;
	t_ui	tmp;

	if (data->size_a < 1)
		return (FALSE);
	tmp = data->a[data->size_a - 1];
	i = data->size_a;
	while (--i > 0)
		data->a[i] = data->a[i - 1];
	data->a[0] = tmp;
	if (index >= 0 && index < MAX_SORT)
		ft_lstadd_back(&data->op[index], ft_lstnew("rra"));
	return (TRUE);
}

/* Execute command rrb and write the command to index of op if it's in rnage. */
int	op_exec_rrb(t_data *data, int index)
{
	int		i;
	t_ui	tmp;

	if (data->size_b < 1)
		return (FALSE);
	tmp = data->b[data->size_b - 1];
	i = data->size_b;
	while (--i > 0)
		data->b[i] = data->b[i - 1];
	data->b[0] = tmp;
	if (index >= 0 && index < MAX_SORT)
		ft_lstadd_back(&data->op[index], ft_lstnew("rrb"));
	return (TRUE);
}

/* Execute command rrr and write the command to index of op if it's in range. */
int	op_exec_rrr(t_data *data, int index)
{
	if (data->size_a < 1 || data->size_b < 1)
		return (FALSE);
	op_exec_rra(data, -1);
	op_exec_rrb(data, -1);
	if (index >= 0 && index < MAX_SORT)
		ft_lstadd_back(&data->op[index], ft_lstnew("rrr"));
	return (TRUE);
}
