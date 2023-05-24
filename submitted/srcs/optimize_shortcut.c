/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_shortcut.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:00:41 by dlu               #+#    #+#             */
/*   Updated: 2023/05/24 23:07:58 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checked if stack a is already ordered only with the incorrect first int. */
int	a_isordered(t_data *data)
{
	int	peak;
	int	i;

	peak = 0;
	i = -1;
	while (++i < data->size_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
			++peak;
	}
	if (data->a[i] > data->a[0])
		++peak;
	if (peak == 1)
		return (TRUE);
	else
		return (FALSE);
}
