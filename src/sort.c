/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:35:03 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 10:07:42 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push index ia from stack a to index ib in stack b. */
static void	push_ab(t_data *data, int ia, int ib)
{
	int	rotate_type;

	rotate_type = get_rotate_type(ia, data->size_a, ib, data->size_b);
	if (rotate_type == RARB)
		rotate_rarb(data, ia, ib);
	else if (rotate_type == RARRB)
		rotate_rarrb(data, ia, ib);
	else if (rotate_type == RRARB)
		rotate_rrarb(data, ia, ib);
	else if (rotate_type == RRARRB)
		rotate_rrarrb(data, ia, ib);
	op_exec_pb(data, 0);
}

/* Push from stack b back to stack a. */
static void	push_ba(t_data *data)
{
	int	index_a;
	int	i;

	index_a = push_index_ba(data->a, data->size_a, data->b[0]);
	i = -1;
	while (index_a > data->size_a / 2 && ++i < (data->size_a - index_a))
		op_exec_rra(data, 0);
	while (index_a <= data->size_a / 2 && ++i < index_a)
		op_exec_ra(data, 0);
	op_exec_pa(data, 0);
}

/* Sort stack that's already ordered and only needs rotating. */
void	sort_ordered(t_data *data)
{
	int	i;

	i = 0;
	while (data->a[i] != 0)
		i++;
	if (i < data->size_a / 2)
		while (data->a[0] != 0)
			op_exec_ra(data, 0);
	else
		while (data->a[0] != 0)
			op_exec_rra(data, 0);
}

/* Sort three numbers on stack a. */
void	sort_three(t_data *data)
{
	t_ui	*arr;

	arr = data->a;
	if (arr[2] > arr[0] && arr[0] > arr[1])
		op_exec_sa(data, 0);
	else if (arr[1] > arr[0] && arr[0] > arr[2])
		op_exec_rra(data, 0);
	else if (arr[0] > arr[2] && arr[2] > arr[1])
		op_exec_ra(data, 0);
	else if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		op_exec_sa(data, 0);
		op_exec_rra(data, 0);
	}
	else if (arr[1] > arr[2] && arr[2] > arr[0])
	{
		op_exec_sa(data, 0);
		op_exec_ra(data, 0);
	}
}

/* Sort anything larger than 3. */
void	sort_algorithm(t_data *data)
{
	int	ia;
	int	ib;

	op_exec_pb(data, 0);
	if (data->size_a > 3)
		op_exec_pb(data, 0);
	while (data->size_a > 3)
	{
		ia = cheapest_index_ab(data);
		ib = push_index_ab(data->b, data->size_b, data->a[ia]);
		push_ab(data, ia, ib);
	}
	sort_three(data);
	while (data->size_b)
		push_ba(data);
	sort_ordered(data);
}
