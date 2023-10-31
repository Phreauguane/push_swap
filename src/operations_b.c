/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:24:54 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 02:20:25 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


void	sb(t_stack **b, bool print)
{
	if (print)
		ft_putendl_fd("sb", 1);
	sa(b, false);
}

void	pb(t_stack **b, t_stack **a, bool print)
{
	if (print)
		ft_putendl_fd("pb", 1);
	push_node(b, pop(a));
	node_refresh(*a, *b);
}

void	rb(t_stack **b, bool print)
{
	if (print)
		ft_putendl_fd("rb", 1);
	ra(b, false);
}

void	rrb(t_stack **b, bool print)
{
	if (print)
		ft_putendl_fd("rrb", 1);
	rra(b, false);
}
