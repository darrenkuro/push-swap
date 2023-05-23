/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:53:43 by dlu               #+#    #+#             */
/*   Updated: 2023/05/23 19:57:49 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Get the largest binary digit. */
static int	get_digit(t_ui *arr, int size)
{
	t_ui	max;
	int		digit;

	max = 0;
	while (--size >= 0) // >= 0??
		if (arr[size] > max)
			max = arr[size];
	digit = 1;
	while (max > 1)
	{
		++digit;
		max /= 2;
	}
	return (digit);
}

/* Return an array of indices for 0 at the given digit (from right-most). */
static int	*get_indices(t_ui *arr, int size, int digit)
{
	while (--size)
	{
	}
}

/* returns the number of operations. */
int	sort_radix(t_data *data, int write)
{
	int	digit;
	int	i;
	int	j;

	i = -1;
	digit = get_digit(data->a, data->size_a);
	while (++i <= digit)
	{
		j = -1;
		while (++j < data->size_a)
	}
}

/*
int	main(void)
{
	t_ui	test[] = {2, 1, 7, 0, 12};
	ft_printf("%d\n", get_digit(test, 5));
	return (0);
}
*/
