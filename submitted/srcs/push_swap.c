/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:24:29 by dlu               #+#    #+#             */
/*   Updated: 2023/05/23 16:52:27 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Print the operations and then free everything. */
static void	print_free(t_data *data)
{
	t_list	*temp;

	while (data->op)
	{
		ft_printf("%s\n", (char *) data->op->content);
		temp = data->op;
		data->op = data->op->next;
		free(temp);
	}
	free(data->a);
	free(data->b);
}

static void	sort(t_data *data)
{
	if (data->size_a == 2 && data->a[0] > data->a[1])
		op_exec_ra(data, TRUE);
	else if (data->size_a == 3)
		sort_three(data, TRUE);
	//else if (data->size_a == 4)
	//	sort_four(data, TRUE);
	//else if (data->size_a == 5)
	//	sort_five(data, TRUE);
	//else
	//	sort_large(data, TRUE);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		return (FAILURE);
	if (!input_isnum(ac, av) || !input_isint(ac, av) || !input_isunique(ac, av))
		return (print_error(ERROR_MSG), FAILURE);
	if (input_issorted(ac, av))
		return (SUCCESS);
	if (!data_init(ac, av, &data))
		return (print_error(ERROR_MSG), FAILURE);
	sort(&data);
	print_free(&data);
	return (SUCCESS);
}
