/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:30:08 by dlu               #+#    #+#             */
/*   Updated: 2023/05/17 14:28:27 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_ui *arr, t_list **op)
{
	if (arr[1] < arr[0])
		ft_lstadd_back(op, ft_lstnew("sa"));
}

/* */
void	sort_three(t_ui *arr, t_list **op)
{
	if (arr[2] > arr[0] && arr[0] > arr[1])
		ft_lstadd_back(op, ft_lstnew("sa"));
	else if (arr[1] > arr[0] && arr[0] > arr[2])
		ft_lstadd_back(op, ft_lstnew("rra"));
	else if (arr[0] > arr[2] && arr[2] > arr[1])
		ft_lstadd_back(op, ft_lstnew("ra"));
	else if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		ft_lstadd_back(op, ft_lstnew("sa"));
		ft_lstadd_back(op, ft_lstnew("rra"));
	}
	else if (arr[1] > arr[2] && arr[2] > arr[0])
	{
		ft_lstadd_back(op, ft_lstnew("sa"));
		ft_lstadd_back(op, ft_lstnew("ra"));
	}
}

/* */
void	sort_five(t_ui *arr, t_list **op)
{
	ft_lstadd_back(op, ft_lstnew("pb"));
	ft_lstadd_back(op, ft_lstnew("pb"));
	if (arr[0] > arr[1])
		ft_lstadd_back(op, ft_lstnew("rb"));
	arr += 2;
	ft_printf("arr: %u\n", *arr);
	sort_three(arr, op);
	ft_lstadd_back(op, ft_lstnew("pa"));
	ft_lstadd_back(op, ft_lstnew("pa"));
}
