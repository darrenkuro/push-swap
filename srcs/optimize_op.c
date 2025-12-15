/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:34:28 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 09:45:30 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checked if stack a is already ordered only with the incorrect first int. */
int	stack_a_isordered(t_data *data)
{
	int	peak;
	int	i;

	peak = 0;
	i = -1;
	while (++i < data->size_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
			++peak;
	}
	if (data->a[i] > data->a[0])
		++peak;
	if (peak == 1)
		return (TRUE);
	else
		return (FALSE);
}

/* For the given list of op, optimize it with combining rr and rrr. */
void	optimize_op(t_list *op)
{
	t_list	*start;
	t_list	*end;

	if (!op)
		return ;
	while (op->next)
	{
		if (ft_strncmp("pb", (char *) op->content, 2) == 0)
		{
			start = op;
			end = op->next;
			while (end && ft_strncmp("pb", (char *) end->content, 2) != 0)
				end = end->next;
			if (end)
			{
				optimize_rr(start, end);
				optimize_rrr(start, end);
			}
		}
		op = op->next;
	}
}
