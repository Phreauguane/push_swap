/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_refresh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:26:38 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/06 16:38:16 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	calc_cheapest(t_stack *s)
{
	t_stack	*cheap;
	t_stack	*sv;

	cheap = s;
	sv = s;
	while (s)
	{
		s->fst_to_push = NULL;
		if (s->push_price < cheap->push_price)
			cheap = s;
		s = s->next;
	}
	while (sv)
	{
		sv->fst_to_push = cheap;
		sv = sv->next;
	}
}

void	get_targets(t_stack *a, t_stack *b)
{
	while (b)
	{
		b->targ = get_smallest_bigger(a, b->val);
		b = b->next;
	}
	while (a)
	{
		a->targ = NULL;
		a = a->next;
	}
}

void	node_refresh(t_stack *a, t_stack *b)
{
	get_targets(a, b);
	calc_prices(a, b);
	calc_cheapest(b);
}
