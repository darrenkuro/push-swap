/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 07:06:39 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 13:05:09 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Get the shortest rotate steps. */
int	rotate_count(int index_a, int size_a, int index_b, int size_b)
{
	t_ui	min;

	min = -1;
	if (count_rarb(index_a, size_a, index_b, size_b) < min)
		min = count_rarb(index_a, size_a, index_b, size_b);
	if (count_rrarrb(index_a, size_a, index_b, size_b) < min)
		min = count_rrarrb(index_a, size_a, index_b, size_b);
	if (count_rarrb(index_a, size_a, index_b, size_b) < min)
		min = count_rarrb(index_a, size_a, index_b, size_b);
	if (count_rrarb(index_a, size_a, index_b, size_b) < min)
		min = count_rrarb(index_a, size_a, index_b, size_b);	
	return (min);
}

/* Get the shortest rotate type. */
int	rotate_type(int index_a, int size_a, int index_b, int size_b)
{
	t_ui	min;

	min = -1;
	if (count_rarb(index_a, size_a, index_b, size_b) < min)
		min = count_rarb(index_a, size_a, index_b, size_b);
	if (count_rrarrb(index_a, size_a, index_b, size_b) < min)
		min = count_rrarrb(index_a, size_a, index_b, size_b);
	if (count_rarrb(index_a, size_a, index_b, size_b) < min)
		min = count_rarrb(index_a, size_a, index_b, size_b);
	if (count_rrarb(index_a, size_a, index_b, size_b) < min)
		min = count_rrarb(index_a, size_a, index_b, size_b);
	if (min == count_rarb(index_a, size_a, index_b, size_b))
		return (RARB);
	if (min == count_rrarrb(index_a, size_a, index_b, size_b))
		return (RRARRB);
	if (min == count_rrarb(index_a, size_a, index_b, size_b))
		return (RRARB);
	if (min == count_rarrb(index_a, size_a, index_b, size_b))
		return (RARRB);
}
