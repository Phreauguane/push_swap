/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:04:06 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 22:25:13 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	exit_handler(char *msg)
{
	(void)msg;
	ft_putendl_fd("Error", 2);
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
