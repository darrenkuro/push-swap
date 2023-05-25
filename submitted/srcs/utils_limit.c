/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_limit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:12:34 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 13:11:07 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Get the max value of a given array. */
t_ui	get_max(t_ui *arr, int size)
{
	t_ui	max;

	max = 0;
	while (--size >= 0)
		if (arr[size] > max)
			max = arr[size];
	return (max);
}

/* Get the min value of a given array. */
t_ui	get_min(t_ui *arr, int size)
{
	t_ui	min;

	min = -1;
	while (--size >= 0)
		if (arr[size] < min)
			min = arr[size];
	return (min);
}

/* Get the index of the max from a given array. */
int	get_max_index(t_ui *arr, int size)
{
	t_ui	max;

	max = get_max(arr, size);
	while (--size >= 0)
		if (arr[size] == max)
			return (size);
	return (-1);
}

/* Get the index of the min from a given array. */
int	get_min_index(t_ui *arr, int size)
{
	t_ui	min;

	min = get_min(arr, size);
	while (--size >= 0)
		if (arr[size] == min)
			return (size);
	return (-1);
}
