/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:35:39 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 00:00:06 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX_OP_CHAR	4

/* 1 for successful operation; 0 for failed or incorrect operation. */
static int	op_exec(t_data *data, char *op)
{
	if (ft_strncmp(op, "pa", MAX_OP_CHAR) == 0)
		return (op_exec_pa(data, FALSE));
	else if (ft_strncmp(op, "pb", MAX_OP_CHAR) == 0)
		return (op_exec_pb(data, FALSE));
	else if (ft_strncmp(op, "sa", MAX_OP_CHAR) == 0)
		return (op_exec_sa(data, FALSE));
	else if (ft_strncmp(op, "sb", MAX_OP_CHAR) == 0)
		return (op_exec_sb(data, FALSE));
	else if (ft_strncmp(op, "ss", MAX_OP_CHAR) == 0)
		return (op_exec_ss(data, FALSE));
	else if (ft_strncmp(op, "ra", MAX_OP_CHAR) == 0)
		return (op_exec_ra(data, FALSE));
	else if (ft_strncmp(op, "rb", MAX_OP_CHAR) == 0)
		return (op_exec_rb(data, FALSE));
	else if (ft_strncmp(op, "rr", MAX_OP_CHAR) == 0)
		return (op_exec_rr(data, FALSE));
	else if (ft_strncmp(op, "rra", MAX_OP_CHAR) == 0)
		return (op_exec_rra(data, FALSE));
	else if (ft_strncmp(op, "rrb", MAX_OP_CHAR) == 0)
		return (op_exec_rrb(data, FALSE));
	else if (ft_strncmp(op, "rrr", MAX_OP_CHAR) == 0)
		return (op_exec_rrr(data, FALSE));
	else
		return (FALSE);
}

static void	load_args(int ac, char **av, t_data *data)
{
	if (ac == 1)
		exit(FAILURE);
	if (!input_isnum(ac, av) || !input_isint(ac, av) || !input_isunique(ac, av))
		print_error(ERROR_MSG);
	if (!data_init(ac, av, data))
		print_error(ERROR_MSG);
}

/* Check whether data is successfully sorted. 1 if sorted, 0 if it's not. */
static int	check_sorted(t_data *data)
{
	int	i;

	if (data->size_b)
		return (0);
	i = -1;
	while (++i < data->size_a - 1)
		if (data->a[i] > data->a[i + 1])
			return (FALSE);
	return (TRUE);
}

int	main(int ac, char **av)
{
	int		i;
	t_data	data;
	char	op[MAX_OP_CHAR];

	load_args(ac, av, &data);
	i = 0;
	while (read(STDIN, &op[i], 1))
	{
		if (i > 3)
			return (print_error(ERROR_MSG), FAILURE);
		if (op[i] == '\n')
		{
			op[i] = '\0';
			if (!op_exec(&data, op))
				return (print_error(ERROR_MSG), FAILURE);
			i = 0;
		}
		else
			++i;
	}
	if (!check_sorted(&data))
		return (ft_printf("KO\n"), SUCCESS);
	else
		return (ft_printf("OK\n"), SUCCESS);
}
