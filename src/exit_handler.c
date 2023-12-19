/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:04:06 by jde-meo           #+#    #+#             */
/*   Updated: 2023/12/19 16:26:43 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	exit_handler(char *msg)
{
	(void)msg;
	ft_putendl_fd("Error", 1);
	exit(-1);
}

int	max(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}

int	min(int i, int j)
{
	if (i < j)
		return (i);
	return (j);
}
