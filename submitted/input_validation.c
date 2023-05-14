/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:19:40 by dlu               #+#    #+#             */
/*   Updated: 2023/05/14 21:44:30 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Check whether input is already sorted, return 1 if it is, 0 if it isn't. */
int	input_sorted(int *arr, int size)
{
	if (size < 3)
		return (1);
	while (--size > 0)
		if (arr[size] < arr[size - 1])
			return (0);
	return (1);
}
#include <stdlib.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	int *test;

	test = (int *) malloc(sizeof(int) * (ac - 1));
	for (int i = 0; i < ac - 1; i++)
		test[i] = atoi(av[i + 1]);
	printf("size: %d\n", ac - 1);
	printf("result: %d\n", input_sorted(test, ac - 1));
	return (0);
}
