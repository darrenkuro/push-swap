/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:53:43 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 01:17:22 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Get the largest binary digit. */
static int	get_digit(t_ui *arr, int size)
{
	t_ui	max;
	int		digit;

	max = 0;
	while (--size >= 0)
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

/* */
static int	rest_sorted(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->size_a - 1)
		if (data->a[i] > data->a[i + 1])
			return (0);
	return (1);
}

/* returns the number of operations. */
int	sort_radix(t_data *data, int write)
{
	int	digit;
	int	i;
	int	j;
	int	size;

	i = -1;
	digit = get_digit(data->a, data->size_a);
	size = data->size_a;
	while (++i < digit)
	{
		j = -1;
		while (++j < size)
		{
			if (rest_sorted(data))
				break ;
			else if ((data->a[0] >> i) & 1)
				op_exec_ra(data, write);
			else
				op_exec_pb(data, write);
		}
		while (data->size_b)
			op_exec_pa(data, write);
	}
	return (TRUE);
}
