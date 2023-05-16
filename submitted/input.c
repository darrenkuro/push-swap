/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:19:40 by dlu               #+#    #+#             */
/*   Updated: 2023/05/17 00:20:47 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check whether input is already sorted. */
int	input_issorted(int ac, char **av)
{
	while (--ac > 0)
		if (ft_atoi(av[ac]) < ft_atoi(av[ac - 1]))
			return (FALSE);
	return (TRUE);
}

/* Check whether input is all numbers. */
int	input_isnum(int ac, char **av)
{
	int	i;

	while (--ac > 0)
	{
		i = -1;
		while (av[ac][++i])
		{
			if (i == 0 && av[ac][i] != '+' && av[ac][i] != '-'
					&& !ft_isdigit(av[ac][i]))
				return (FALSE);
			if (i && !ft_isdigit(av[ac][i]))
				return (FALSE);
		}
	}
	return (TRUE);
}

/* Check whether input is within valid range of int. */
int	input_isint(int ac, char **av)
{
	t_ll	num;
	int		i;
	int		neg;

	while (--ac > 0)
	{
		if (ft_strlen(av[ac]) > INT_MAXLEN)
			return (FALSE);
		num = 0;
		neg = 1;
		i = -1;
		while (av[ac][++i])
		{
			if (i == 0 && av[ac][i] == '-')
				neg = -1;
			else if (ft_isdigit(av[ac][i]))
				num = num * 10 + (av[ac][i] - '0');
		}
		num = num * neg;
		if (num > INT_MAX || num < INT_MIN)
			return (FALSE);
	}
	return (TRUE);
}

/* Check whether input is all unique numbers. */
int	input_isunique(int ac, char **av)
{
	int	i;
	int	size;
	int	*input;

	input = (int *) ft_calloc(ac - 1, sizeof(int));
	if (!input)
		return (FALSE);
	size = ac - 1;
	while (--ac > 0)
		input[ac - 1] = ft_atoi(av[ac]);
	while (--size >= 0)
	{
		i = -1;
		while (++i < size)
			if (input[i] == input[size])
				return (free(input), FALSE);
	}
	return (free(input), TRUE);
}

/*  */
t_list	*input_parser(int ac, char **av, t_list **stack)
{
	int		i;
	int		j;
	t_ui	count;
	t_ui	*temp;

	//ret = (t_ui *) ft_calloc(ac - 1, sizeof(t_ui));
	//if (!ret)
	//	return (NULL);
	i = -1;
	while (++i < ac - 1)
	{
		count = 0;
		j = -1;
		while (++j < ac - 1)
			if (ft_atoi(av[i + 1]) > ft_atoi(av[j + 1]))
				++count;
		temp = (t_ui *) malloc(sizeof(t_ui));
		if (!temp)
			// handle free with lstclear
			return (NULL);
		*temp = count;
		ft_lstadd_back(stack, ft_lstnew(temp));
	}
	return (*stack);
}
