/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:24:29 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 01:34:48 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Print the shortest operations and then free everything. */
static void	print_free(t_data *data)
{
	t_list	*temp;
	int		i;
	int		index;

	index = get_shortest_op_index(data);
	i = -1;
	optimize_op(data->op[index]);
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
}

static void	sort(t_data *data)
{
	if (a_isordered(data))
		sort_ordered(data, 0);
	else if (data->size_a == 2)
		op_exec_ra(data, SMALL_I);
	else if (data->size_a == 3)
		sort_three(data, SMALL_I);
	//else if (data->size_a == 5)
	//	sort_five(data, TRUE);
	else if (data->size_a <= 31)
		sort_radix(data, RADIX_I);
	//else
	//	sort_large(data, )
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
