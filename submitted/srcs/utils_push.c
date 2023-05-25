/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:09:02 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 12:25:19 by dlu              ###   ########.fr       */
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

void	rotate_and_push_ab(int rotate_type)
{
	
}
/*
#include <stdio.h>
int	main(void)
{
	t_ui	test[5] = {1, 6, 8};

	printf("%d\n", push_index_btoa(test, 3, 9));
	return (0);
}
*/
