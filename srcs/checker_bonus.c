/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:35:39 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 09:39:27 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX_OP_CHAR	4

/* Execute the command, return 1 if successful, 0 if failed or incorrect op. */
static int	op_exec(t_data *data, char *op)
{
	if (ft_strncmp(op, "pa", MAX_OP_CHAR) == 0)
		return (op_exec_pa(data, -1));
	else if (ft_strncmp(op, "pb", MAX_OP_CHAR) == 0)
		return (op_exec_pb(data, -1));
	else if (ft_strncmp(op, "sa", MAX_OP_CHAR) == 0)
		return (op_exec_sa(data, -1));
	else if (ft_strncmp(op, "sb", MAX_OP_CHAR) == 0)
		return (op_exec_sb(data, -1));
	else if (ft_strncmp(op, "ss", MAX_OP_CHAR) == 0)
		return (op_exec_ss(data, -1));
	else if (ft_strncmp(op, "ra", MAX_OP_CHAR) == 0)
		return (op_exec_ra(data, -1));
	else if (ft_strncmp(op, "rb", MAX_OP_CHAR) == 0)
		return (op_exec_rb(data, -1));
	else if (ft_strncmp(op, "rr", MAX_OP_CHAR) == 0)
		return (op_exec_rr(data, -1));
	else if (ft_strncmp(op, "rra", MAX_OP_CHAR) == 0)
		return (op_exec_rra(data, -1));
	else if (ft_strncmp(op, "rrb", MAX_OP_CHAR) == 0)
		return (op_exec_rrb(data, -1));
	else if (ft_strncmp(op, "rrr", MAX_OP_CHAR) == 0)
		return (op_exec_rrr(data, -1));
	else
		return (FALSE);
}

/* Check the validity of the arguments, load stack if valid, exit if invalid. */
static void	load_args(int ac, char **av, t_data *data)
{
	if (ac == 1)
		exit(FAILURE);
	if (!input_isnum(ac, av) || !input_isint(ac, av) || !input_isunique(ac, av))
		print_error_exit(ERROR_MSG);
	if (!data_init(ac, av, data))
		print_error_exit(ERROR_MSG);
}

/* Check the operations on stdin succesfully sort the data. */
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
			print_error_exit(ERROR_MSG);
		if (op[i] == '\n')
		{
			op[i] = '\0';
			if (!op_exec(&data, op))
				print_error_exit(ERROR_MSG);
			i = 0;
		}
		else
			++i;
	}
	if (array_issorted(data.a, data.size_a) && !data.size_b)
		return (ft_printf("OK\n"), SUCCESS);
	else
		return (ft_printf("KO\n"), SUCCESS);
}
