/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:15:26 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 09:49:40 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Print the given message to stderr and exit the program. */
void	print_error_exit(const char *msg)
{
	write(STDERR, msg, ft_strlen(msg));
	exit(FAILURE);
}

/* Initialize the data structure, parse the argument into stack a. */
int	data_init(int ac, char **av, t_data *data)
{

	data->a = (t_ui *) ft_calloc(ac - 1, sizeof(t_ui));
	if (!data->a)
		return (FALSE);
	data->b = (t_ui *) ft_calloc(ac - 1, sizeof(t_ui));
	if (!data->b)
		return (free(data->a), FALSE);
	data->op = NULL;
	data->size_a = ac - 1;
	data->size_b = 0;
	input_parser(ac, av, data);
	return (TRUE);
}

/* Check if an array is sorted of it's given size. */
int	array_issorted(t_ui *arr, int size)
{
	while (--size > 0)
		if (arr[size] < arr[size - 1])
			return (FALSE);
	return (TRUE);
}
