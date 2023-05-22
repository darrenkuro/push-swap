/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:24:29 by dlu               #+#    #+#             */
/*   Updated: 2023/05/20 22:25:17 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
{
	write(STDERR, ERROR_MSG, ft_strlen(ERROR_MSG));
}

/* Free all memory allocated before exit. */
//static void	cleanup(t_stack a, t_stack b, t_list op)

/* Initialize the data structure, parse the argument into stack a. */
static int	init(int ac, char **av, t_data *data)
{
	data->a = (t_ui *) ft_calloc(ac - 1, sizeof(t_ui));
	if (!data->a)
		return (FAILURE);
	data->b = (t_ui *) ft_calloc(ac - 1, sizeof(t_ui));
	if (!data->b)
		return (free(data->a), FAILURE);
	data->op = NULL;
	data->size_a = ac - 1;
	data->size_b = 0;
	data->size_op = 0;
	input_parser(ac, av, data);
	return (SUCCESS);
}

static void sort(t_data *data)
{
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		return (FAILURE);
	if (!input_isnum(ac, av) || !input_isint(ac, av) || !input_isunique(ac, av))
		return (print_error(), FAILURE);
	if (input_issorted(ac, av))
		return (SUCCESS);
	if (!init(ac, av, &data))
		return (print_error(), FAILURE);
	sort(&data);
	print(data);
	return (SUCCESS);
}
