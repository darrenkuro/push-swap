/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:09:02 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 13:05:00 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
