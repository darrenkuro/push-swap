/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:35:03 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 12:22:52 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static void	sort_to_b(t_data *data)
{
	int	index_a;
	int	index_b;
	int	rotate_type;

	op_exec_pb(data, LARGE_I);
	op_exec_pb(data, LARGE_I);
	while (data->size_a > 3 && !array_issorted(data->a, data->size_a))
	{
		index_a = cheapest_index_ab(data);
		index_b = push_index_ab(data->b, data->size_b);
		rotate_type = rotate_type(index_a, data->size_a, index_b, data->size_b);

	}
}
*/
void	push_ab(t_data *data)
{
	int	index_b;
	int	i;

	index_b = push_index_ab(data->b, data->size_b, data->a[0]);
	i = -1;
	while (index_b > data->size_b / 3 * 2 && ++i < (data->size_b - index_b))
		op_exec_rrb(data, LARGE_I);
	while (index_b <= data->size_b / 3 * 2 && ++i < index_b)
		op_exec_rb(data, LARGE_I);
	op_exec_pb(data, LARGE_I);
}

void	push_ba(t_data *data)
{
	int	index_a;
	int	i;

	index_a = push_index_ba(data->a, data->size_a, data->b[0]);
	i = -1;
	while (index_a > data->size_a / 2 - 1 && ++i < (data->size_a - index_a))
		op_exec_rra(data, LARGE_I);
	while (index_a <= data->size_a / 2 - 1 && ++i < index_a)
		op_exec_ra(data, LARGE_I);
	op_exec_pa(data, LARGE_I);
}

#include <stdio.h>
void	sort_large(t_data *data, int n, int f)
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
				push_ab(data);
			else
				op_exec_ra(data, LARGE_I);
			if (data->size_a <= 3)
				break ;
		}
		n += f;
	}
	sort_three(data, LARGE_I);
	while (data->size_b)
		push_ba(data);
	sort_ordered(data, LARGE_I);
}
