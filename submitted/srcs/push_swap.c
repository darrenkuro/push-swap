/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:24:29 by dlu               #+#    #+#             */
/*   Updated: 2023/05/24 12:29:09 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Print the shortest operations and then free everything. */
static void	print_free(t_data *data)
{
	t_list	*temp;
	int		i;
	int		min;
	int		index;

	i = -1;
	min = 0;
	index = -1;
	while (++i < MAX_SORT)
	{
		ft_printf("i: %d, size: %d\n", i, ft_lstsize(data->op[i]));
		if (min && ft_lstsize(data->op[i]) < min)
		{
			min = ft_lstsize(data->op[i]);
			index = i;
		}
	}
	ft_printf("index is %d.\n", index);
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
}

static void	sort(t_data *data)
{
	if (data->size_a == 2 && data->a[0] > data->a[1])
		op_exec_ra(data, TRUE);
	else if (data->size_a == 3)
		sort_three(data, TRUE);
	else if (data->size_a == 4)
		sort_radix(data, TRUE);
	//	sort_four(data, TRUE);
	//else if (data->size_a == 5)
	//	sort_five(data, TRUE);
	else
		sort_radix(data, TRUE);
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
