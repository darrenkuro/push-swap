/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:34:28 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 09:12:22 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Replace ra wirh rr and remove and free corresponding rb. */
static void	replace_ra(t_list *start, t_list *end, int rb)
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

/* Replace rb wirh rr and remove and free corresponding ra. */
static void	replace_rb(t_list *start, t_list *end, int ra)
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

/* Check if the range has both ra and rb and optimize it with rr. */ 
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
