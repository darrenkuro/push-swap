/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 07:06:39 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 07:51:55 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* The operations needed for rarb. */
t_ui	count_rarb(int index_a, int index_b)
{
	if (index_a > index_b)
		return (index_b + (index_a - index_b));
	else
		return (index_a + (index_b - index_a));
}

/* The operations needed for rrarrb. */
t_ui	count_rrarrb(int index_a, int size_a, int index_b, int size_b)
{
	if ((size_a - index_a) > (size_b - index_b))
		return ((size_b - index_b) + ((size_a - index_a) - (size_b - index_b)));
	else
		return ((size_a - index_a) + ((size_b - index_b) - (size_a - index_a)));
}

/* The operations needed for rarrb. */
t_ui	count_rarrb(int index_a, int index_b, int size_b)
{
	return (index_a + (size_b - index_b));
}

/* The operations needed for rrarb. */
t_ui	count_rrarb(int index_a, int size_a, int index_b)
{
	return ((size_a - index_a) + index_b);
}

/* Get the shortest rotate steps. */
int	rotate_count(int index_a, int size_a, int index_b, int size_b)
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
	return (min);
}

