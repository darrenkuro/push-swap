/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:53:43 by dlu               #+#    #+#             */
/*   Updated: 2023/05/24 11:32:56 by dlu              ###   ########.fr       */
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

/* Return an array of indices for 0 at the given digit (from right-most). */
/*static int	*get_indices(t_ui *arr, int size, int digit)
{
	while (--size)
	{
	}
}*/

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
			if ((data->a[0] >> i) & 1)
			{
				op_exec_pb(data, write);
				op_exec_rb(data, write);
			}
			else
				op_exec_ra(data, write);
		}
		while (data->size_b)
		{
			op_exec_pa(data, write);
			op_exec_ra(data, write);
		}
	}
	return (1);
}
/*
int	main(void)
{
	t_ui	test[] = {16, 1, 7, 0, 12};
	ft_printf("%d\n", get_digit(test, 5));
	return (0);
}
*/
