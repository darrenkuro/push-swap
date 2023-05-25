/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:34:28 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 13:46:24 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_ra(t_list *start, t_list *end, int rb)
{
	t_list	*temp;
	int		replace;

	replace = rb;
	while (start->next != end && (rb || replace))
	{
		if (ft_strncmp("rb", (char *) start->next->content, 2) == 0 && rb)
		{
			temp = start->next;
			start->next = start->next->next;
			free(temp);
			--rb;
		}	
		else if (ft_strncmp("ra", (char *) start->next->content, 2) == 0 && replace)
		{
			start->next->content = "rr";
			start = start->next;
			--replace;
		}
		else
			start = start->next;
	}
}

void	replace_rb(t_list *start, t_list *end, int ra)
{
	t_list	*temp;
	int		replace;

	replace = ra;
	while (start->next != end && (ra || replace))
	{
		if (ft_strncmp("ra", (char *) start->next->content, 2) == 0 && ra)
		{
			temp = start->next;
			start->next = start->next->next;
			free(temp);
			--ra;
		}	
		else if (ft_strncmp("rb", (char *) start->next->content, 2) == 0 && replace)
		{
			start->next->content = "rr";
			start = start->next;
			--replace;
		}
		else
			start = start->next;
	}
}

/* Check if the range has both ra and rb. */ 
void	optimize_rr(t_list *start, t_list *end)
{
	t_list	*temp;
	int		ra;
	int		rb;

	ra = 0;
	rb = 0;
	temp = start;
	while (temp != end)
	{
		temp = temp->next;
		if (ft_strncmp("ra", (char *) temp->content, 2) == 0)
			++ra;
		if (ft_strncmp("rb", (char *) temp->content, 2) == 0)
			++rb;
	}
	if (!ra || !rb)
		return ;
	if (ra >= rb)
		replace_ra(start, end, rb);
	else
		replace_rb(start, end, ra);
}

void	optimize_op(t_list *op)
{
	t_list	*start;
	t_list	*end;

	if (!op)
		return ;
	while (op->next)
	{
		if (ft_strncmp("pb", (char *) op->content, 2) == 0)
		{
			start = op;
			end = op->next;
			while (end && ft_strncmp("pb", (char *) end->content, 2) != 0)
				end = end->next;
			if (end)
				optimize_rr(start, end);
		}
		op = op->next;
	}
}
