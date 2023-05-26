/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calc_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:28:24 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 07:46:54 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculate the move needed for index in stack a to the correct position. */
static t_ui	calc_move_ab(t_data *data, int index)
{
	int	index_b;

	index_b = push_index_ab(data->b, data->size_b, data->a[index]);
	return (rotate_count(index, data->size_a, index_b, data->size_b));
}

/* Calculate the move needed for index in stack b to the correct position.
static t_ui calc_move_ba(t_data *data, int index)
{
	int	index_a;

	index_a = push_index_ba(data->a, data->size_a, data->b[index]);
	return (rotate_count(index_a, data->size_a, index, data->size_b));
}
*/
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
		if (calc_move_ab(data, i) < min)
		{
			min = calc_move_ab(data, i);
			index = i;
		}
	return (index);
}
