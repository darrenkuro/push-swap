/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:15:26 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 12:25:09 by dlu              ###   ########.fr       */
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
	int	i;

	data->a = (t_ui *) ft_calloc(ac - 1, sizeof(t_ui));
	if (!data->a)
		return (FALSE);
	data->b = (t_ui *) ft_calloc(ac - 1, sizeof(t_ui));
	if (!data->b)
		return (free(data->a), FALSE);
	i = -1;
	while (++i < MAX_SORT)
		data->op[i] = NULL;
	data->size_a = ac - 1;
	data->size_b = 0;
	input_parser(ac, av, data);
	return (TRUE);
}

/* Get the shortest op index from data, -1 for error. */
int	get_shortest_op_index(t_data *data)
{
	int	i;
	int	min;
	int	index;

	min = 0;
	index = -1;
	i = -1;
	while (++i < MAX_SORT)
	{
		if (!ft_lstsize(data->op[i]))
			continue ;
		if (ft_lstsize(data->op[i]) < min || !min)
		{
			min = ft_lstsize(data->op[i]);
			index = i;
		}
	}
	return (index);
}

/* Check if an array is sorted of it's given size. */
int	array_issorted(t_ui *arr, int size)
{
	while (--size > 0)
		if (arr[size] < arr[size - 1])
			return (FALSE);
	return (TRUE);
}
