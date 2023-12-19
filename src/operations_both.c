/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:46:17 by jde-meo           #+#    #+#             */
/*   Updated: 2023/12/19 16:23:04 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ss(t_stack **a, t_stack **b, t_bool print)
{
	sa(a, FALSE);
	sb(b, FALSE);
	if (print)
		ft_putendl_fd("ss", 1);
}

void	rr(t_stack **a, t_stack **b, t_bool print)
{
	ra(a, FALSE);
	rb(b, FALSE);
	if (print)
		ft_putendl_fd("rr", 1);
}

void	rrr(t_stack **a, t_stack **b, t_bool print)
{
	rra(a, FALSE);
	rrb(b, FALSE);
	if (print)
		ft_putendl_fd("rrr", 1);
}
