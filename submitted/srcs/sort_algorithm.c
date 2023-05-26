/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:35:03 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 07:44:32 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_ab(t_data *data, int ia, int ib, int index)
{
	int	rotate_type;

	rotate_type = get_rotate_type(ia, data->size_a, ib, data->size_b);
	if (rotate_type == RARB)
		rotate_rarb(data, ia, ib, index);
	else if (rotate_type == RARRB)
		rotate_rarrb(data, ia, ib, index);
	else if (rotate_type == RRARB)
		rotate_rrarb(data, ia, ib, index);
	else if (rotate_type == RRARRB)
		rotate_rrarrb(data, ia, ib, index);
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

void	sort_algorithm(t_data *data, int index)
{
	int	ia;
	int	ib;

	op_exec_pb(data, index);
	op_exec_pb(data, index);
	while (data->size_a > 3)
	{
		ia = cheapest_index_ab(data);
		ib = push_index_ab(data->b, data->size_b, data->a[ia]);
		push_ab(data, ia, ib, index);
	}
	sort_three(data, index);
	while (data->size_b)
		push_ba(data, index);
	sort_ordered(data, index);
}
