/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:27:37 by dlu               #+#    #+#             */
/*   Updated: 2023/05/16 15:42:34 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	print_content(void *content)
{
	ft_printf("%s\n", (char *) content);
}

int	op_print(t_list *op)
{
	ft_lstiter(op, print_content);
	return (ft_lstsize(op));
}
