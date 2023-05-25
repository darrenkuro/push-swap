/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:28:24 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 08:32:46 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculate the move needed for index in stack a to the correct position. */
int	calc_move_ab(t_data *data, int index)
{
	int	index_b;

	index_b = push_index_atob(data->b, data->size_b, data->a[index]);
	return (rotate_count(index, data->size_a, index_b, data->size_b));	
}

/* Get the cheapest index when pushing from a to b. */
int	cheapest_index_ab(t_data *data)
{
	t_ui	min;
	int		i;
	int		index;

	i = -1;
	min = -1;
	index = -1;
	while (++i < data->size_a)
		if (calc_move_atob(data, i) < min)
		{
			min = calc_move_atob(data, i);
			index = i;
		}
	return (index);
}
