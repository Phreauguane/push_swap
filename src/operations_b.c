/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:24:54 by jde-meo           #+#    #+#             */
/*   Updated: 2023/12/19 16:23:00 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sb(t_stack **b, t_bool print)
{
	if (print)
		ft_putendl_fd("sb", 1);
	sa(b, FALSE);
}

void	pb(t_stack **b, t_stack **a, t_bool print)
{
	if (print)
		ft_putendl_fd("pb", 1);
	push_node(b, pop(a));
}

void	rb(t_stack **b, t_bool print)
{
	if (print)
		ft_putendl_fd("rb", 1);
	ra(b, FALSE);
}

void	rrb(t_stack **b, t_bool print)
{
	if (print)
		ft_putendl_fd("rrb", 1);
	rra(b, FALSE);
}
