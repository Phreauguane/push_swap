/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:46:17 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 22:57:04 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ss(t_stack **a, t_stack **b, bool print)
{
	sa(a, false);
	sb(b, false);
	if (print)
		ft_putendl_fd("ss", 1);
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	ra(a, false);
	rb(b, false);
	if (print)
		ft_putendl_fd("rr", 1);
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	rra(a, false);
	rrb(b, false);
	if (print)
		ft_putendl_fd("rrr", 1);
}
