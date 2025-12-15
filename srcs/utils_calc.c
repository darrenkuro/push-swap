/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:28:24 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 10:21:17 by dlu              ###   ########.fr       */
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

/* Get the correct index for pushing nbr pushing to stack a. */
int	push_index_ab(t_ui *arr, int size, t_ui nbr)
{
	int	i;

	if (nbr > arr[0] && nbr < arr[size - 1])
		return (0);
	else if ((nbr > get_max(arr, size) || nbr < get_min(arr, size)))
		return (get_max_index(arr, size));
	else
	{
		i = 0;
		while (i < size && (arr[i] < nbr || arr[i + 1] > nbr))
			++i;
		if (i == size)
			return (0);
		else
			return (++i);
	}
}

/* Get the correct index for pushing nbr to stack a. */
int	push_index_ba(t_ui *arr, int size, t_ui nbr)
{
	int	i;

	if (nbr < arr[0] && nbr > arr[size - 1])
		return (0);
	else if ((nbr > get_max(arr, size) || nbr < get_min(arr, size)))
		return (get_min_index(arr, size));
	else
	{
		i = 0;
		while (i < size && (arr[i] > nbr || arr[i + 1] < nbr))
			++i;
		if (i == size)
			return (0);
		else
			return (++i);
	}
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
	{
		if (calc_move_ab(data, i) < min)
		{
			min = calc_move_ab(data, i);
			index = i;
		}
	}
	return (index);
}
