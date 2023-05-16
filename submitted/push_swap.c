/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:24:29 by dlu               #+#    #+#             */
/*   Updated: 2023/05/17 00:20:38 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
{
	write(STDERR, ERROR_MSG, ft_strlen(ERROR_MSG));
}

/* Free all memory allocated before exit. */
//static void	cleanup(t_stack a, t_stack b, t_list op)

static void	init(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->op = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->size_op = 0;
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
	init(&data);
	data.a = input_parser(ac, av, &data.a);
	data.size_a = ac - 1;
	ft_printf("%d\n", (t_ui) data.a->content);
	return (SUCCESS);
}
