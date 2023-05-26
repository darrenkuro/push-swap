/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:24:29 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 07:53:59 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Print the shortest operations and then free everything. */
static void	print_free(t_data *data)
{
	t_list	*temp;
	int		i;
	int		index;

	i = -1;
	while (++i < MAX_SORT)
		optimize_op(data->op[i]);
	index = get_shortest_op_index(data);
	i = -1;
	while (++i < MAX_SORT)
	{
		while (data->op[i])
		{
			if (i == index)
				ft_printf("%s\n", (char *) data->op[i]->content);
			temp = data->op[i];
			data->op[i] = data->op[i]->next;
			free(temp);
		}
	}
	free(data->a);
	free(data->b);
	free(data->og);
}

static void	sort(t_data *data)
{
	if (data->size_a == 2)
		op_exec_ra(data, SMALL_I);
	else if (data->size_a == 3)
		sort_three(data, SMALL_I);
	else if (a_isordered(data))
		sort_ordered(data, 0);
	//else if (data->size_a == 5)
	//	sort_five(data, TRUE);
	//else if (data->size_a <= 31)
	//	sort_radix(data, RADIX_I);
	else if (data->size_a <= 20)
		sort_large(data, 5, 2, 0);
	else if (data->size_a <= 150)
	{
		sort_large(data, 20, 10, 0);
		reset_stack(data);
		sort_large(data, 22, 8, 1);
		reset_stack(data);
		sort_large(data, 25, 12, 2);
	}
	else
	{
		sort_algorithm(data, 0);
		/*
		sort_large(data, 35, 18, 0);
		reset_stack(data);
		sort_large(data, 40, 40, 1);
		reset_stack(data);
		sort_large(data, 20, 30, 2);
		reset_stack(data);
		sort_radix(data, 3);*/
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		return (FAILURE);
	if (!input_isnum(ac, av) || !input_isint(ac, av) || !input_isunique(ac, av))
		print_error_exit(ERROR_MSG);
	if (!data_init(ac, av, &data))
		print_error_exit(ERROR_MSG);
	if (array_issorted(data.a, data.size_a))
		return (SUCCESS);
	sort(&data);
	print_free(&data);
	return (SUCCESS);
}
