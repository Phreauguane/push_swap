/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:59:17 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 20:29:42 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sa(t_stack **a, bool print)
{
	t_stack	*top;
	t_stack	*top2;
	
	if (print)
		ft_putendl_fd("sa", 1);
	top = get_top(*a);
	top2 = get_top2(*a);
	if (a == NULL || *a == top || top2 == NULL)
		return ;
	top->next = top2;
	top->prev = top2->prev;
	if (top2->prev != NULL)
		top2->prev->next = top;
	top2->next = NULL;
	top2->prev = top;
	if (*a == top2)
		*a = top;
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	if (print)
		ft_putendl_fd("pa", 1);
	push_node(a, pop(b));
	//node_refresh(*a, *b);
}

void	ra(t_stack **a, bool print)
{
	t_stack	*last;
	
	if (print)
		ft_putendl_fd("ra", 1);
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	if ((*a)->next->next == NULL)
	{
		sa(a, 0);
		return ;
	}
	last = pop(a);
	last->next = *a;
	(*a)->prev = last;
	*a = last;
}

void	rra(t_stack **a, bool print)
{
	t_stack	*first;

	if (print)
		ft_putendl_fd("rra", 1);
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	if ((*a)->next->next == NULL)
	{
		sa(a, false);
		return ;
	}
	first = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	first->next = NULL;
	push_node(a, first);
}
