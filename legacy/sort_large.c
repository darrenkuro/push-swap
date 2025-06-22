/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:35:03 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 07:19:04 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_ab(t_data *data, int index)
{
	int	index_b;
	int	i;

	index_b = push_index_ab(data->b, data->size_b, data->a[0]);
	i = -1;
	while (index_b > data->size_b / 3 * 2 && ++i < (data->size_b - index_b))
		op_exec_rrb(data, index);
	while (index_b <= data->size_b / 3 * 2 && ++i < index_b)
		op_exec_rb(data, index);
	op_exec_pb(data, index);
}

static void	push_ba(t_data *data, int index)
{
	int	index_a;
	int	i;

	index_a = push_index_ba(data->a, data->size_a, data->b[0]);
	i = -1;
	while (index_a > data->size_a / 2 - 1 && ++i < (data->size_a - index_a))
		op_exec_rra(data, index);
	while (index_a <= data->size_a / 2 - 1 && ++i < index_a)
		op_exec_ra(data, index);
	op_exec_pa(data, index);
}

void	sort_large(t_data *data, int n, int f, int index)
{
	int	size;
	int	i;
	int	median;

	median = data->size_a / 2;
	while (data->size_a > 3)
	{
		size = data->size_a;
		i = -1;
		while (++i < size)
		{
			if ((int) data->a[0] > (median - n) && (int) data->a[0] < (median + n))
				push_ab(data, index);
			else
				op_exec_ra(data, index);
			if (data->size_a <= 3)
				break ;
		}
		n += f;
	}
	sort_three(data, index);
	while (data->size_b)
		push_ba(data, index);
	sort_ordered(data, index);
}
