/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:35:03 by dlu               #+#    #+#             */
/*   Updated: 2023/05/25 01:43:45 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_onto_b(t_data *data)
{
	op_exec_pb(data, LARGE_I);
	op_exec_pb(data, LARGE_I);
	while (data->size_a > 3 && !array_issorted(data->a, data->size_a))
	{
		
	}
}

void	sort_large(t_data *data)
{
	
}
