/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:34:28 by dlu               #+#    #+#             */
/*   Updated: 2023/05/24 23:26:09 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Optimize a given op list. */
void	optimize_op(t_list *op)
{
	t_list	*temp;

	while (op->next)
	{
		if ((ft_strncmp("ra", (char *) op->content, 2) == 0
				&& ft_strncmp("rb", (char *) op->next->content, 2) == 0)
			|| (ft_strncmp("rb", (char *) op->content, 2) == 0
				&& ft_strncmp("ra", (char *) op->next->content, 2) == 0))
		{
			temp = op->next;
			op->next = op->next->next;
			op->content = "rr";
			free(temp);
		}
		op = op->next;
	}
}
