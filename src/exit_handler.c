/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:04:06 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 01:34:10 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	exit_handler(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
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