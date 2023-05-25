/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 07:06:39 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 07:38:15 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* The operations needed for rarb. */
int	count_rarb(int index_a, int size_a, int index_b, int size_b)
{
	if (index_a > index_b)
		return (index_b + (index_a - index_b));
	else
		return (index_a + (index_b - index_a));
}

/* The operations needed for rrarrb. */
int	count_rrarrb(int index_a, int size_a, int index_b, int size_b)
{
	if ((size_a - index_a) > (size_b - index_b))
		return ((size_b - index_b) + ((size_a - index_a) - (size_b - index_b)));
	else
		return ((size_a - index_a) + ((size_b - index_b) - (size_a - index_a)));
}

/* The operations needed for rarrb. */
int	count_rarrb(int index_a, int size_a, int index_b, int size_b)
{
	return (index_a + (size_b - index_b));
}

/* The operations needed for rrarb. */
int	count_rrarb(int index_a, int size_a, int index_b, int size_b)
{
	return ((size_a - index_a) + index_b);
}
