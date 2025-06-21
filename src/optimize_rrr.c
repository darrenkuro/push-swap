/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:34:28 by dlu               #+#    #+#             */
/*   Updated: 2023/05/26 10:21:51 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Replace rra wirh rrr and remove and free corresponding rrb. */
static void	replace_rra(t_list *start, t_list *end, int rrb)
{
	t_list	*temp;
	int		replace;

	replace = rrb;
	while (start->next != end && (rrb || replace))
	{
		if (ft_strncmp("rrb", (char *) start->next->content, 3) == 0 && rrb)
		{
			temp = start->next;
			start->next = start->next->next;
			free(temp);
			--rrb;
		}	
		else if (ft_strncmp("rra", (char *) start->next->content, 3) == 0
			&& replace)
		{
			start->next->content = "rrr";
			start = start->next;
			--replace;
		}
		else
			start = start->next;
	}
}

/* Replace rrb wirh rrr and remove and free corresponding rra. */
static void	replace_rrb(t_list *start, t_list *end, int rra)
{
	t_list	*temp;
	int		replace;

	replace = rra;
	while (start->next != end && (rra || replace))
	{
		if (ft_strncmp("rra", (char *) start->next->content, 3) == 0 && rra)
		{
			temp = start->next;
			start->next = start->next->next;
			free(temp);
			--rra;
		}	
		else if (ft_strncmp("rrb", (char *) start->next->content, 3) == 0
			&& replace)
		{
			start->next->content = "rrr";
			start = start->next;
			--replace;
		}
		else
			start = start->next;
	}
}

/* Check if the range has both rra and rrb and optimize it with rrr. */
void	optimize_rrr(t_list *start, t_list *end)
{
	t_list	*temp;
	int		rra;
	int		rrb;

	rra = 0;
	rrb = 0;
	temp = start;
	while (temp != end)
	{
		temp = temp->next;
		if (ft_strncmp("rra", (char *) temp->content, 3) == 0)
			++rra;
		if (ft_strncmp("rrb", (char *) temp->content, 3) == 0)
			++rrb;
	}
	if (!rra || !rrb)
		return ;
	if (rra >= rrb)
		replace_rra(start, end, rrb);
	else
		replace_rrb(start, end, rra);
}
