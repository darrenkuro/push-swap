/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:24:29 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 09:52:30 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Print the shortest operations and then free everything. */
static void	print_free(t_data *data)
{
	t_list	*temp;
	int		i;

	i = -1;
	optimize_op(data->op);
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

/* Sort the given data and output the commands. */
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
	if (data.size_a == 2)
		op_exec_ra(&data, 0);
	else if (data.size_a == 3)
		sort_three(&data);
	else if (stack_a_isordered(&data))
		sort_ordered(&data);
	else
		sort_algorithm(&data);
	print_free(&data);
	return (SUCCESS);
}
