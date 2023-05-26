/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 07:06:39 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 07:53:11 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Get the shortest rotate type. */
int	get_rotate_type(int index_a, int size_a, int index_b, int size_b)
{
	t_ui	min;

	min = -1;
	if (count_rarb(index_a, index_b) < min)
		min = count_rarb(index_a, index_b);
	if (count_rrarrb(index_a, size_a, index_b, size_b) < min)
		min = count_rrarrb(index_a, size_a, index_b, size_b);
	if (count_rarrb(index_a, index_b, size_b) < min)
		min = count_rarrb(index_a, index_b, size_b);
	if (count_rrarb(index_a, size_a, index_b) < min)
		min = count_rrarb(index_a, size_a, index_b);
	if (min == count_rarb(index_a, index_b))
		return (RARB);
	if (min == count_rrarrb(index_a, size_a, index_b, size_b))
		return (RRARRB);
	if (min == count_rrarb(index_a, size_a, index_b))
		return (RRARB);
	if (min == count_rarrb(index_a, index_b, size_b))
		return (RARRB);
	return (-1);
}

void	rotate_rarb(t_data *data, int ia, int ib, int index)
{
	int	i;

	i = -1;
	while (++i < ia)
		op_exec_ra(data, index);
	i = -1;
	while (++i < ib)
		op_exec_rb(data, index);
}

void	rotate_rarrb(t_data *data, int ia, int ib, int index)
{
	int	i;

	i = -1;
	while (++i < ia)
		op_exec_ra(data, index);
	i = -1;
	while (++i < data->size_b - ib)
		op_exec_rrb(data, index);
}

void	rotate_rrarb(t_data *data, int ia, int ib, int index)
{
	int	i;

	i = -1;
	while (++i < data->size_a - ia)
		op_exec_rra(data, index);
	i = -1;
	while (++i < ib)
		op_exec_rb(data, index);
}

void	rotate_rrarrb(t_data *data, int ia, int ib, int index)
{
	int	i;

	i = -1;
	while (++i < data->size_a - ia)
		op_exec_rra(data, index);
	i = -1;
	while (++i < data->size_b - ib)
		op_exec_rrb(data, index);
}
