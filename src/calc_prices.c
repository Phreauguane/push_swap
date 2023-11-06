/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_prices.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:19:13 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/06 16:09:42 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*rev(t_stack *e)
{
	e->to_rev = true;
	if (e->rev_pos > e->pos)
		e->to_rev = false;
	return (e);
}

int	get_minimal_total(t_stack *e)
{
	int	out;
	
	out = max(e->targ->rev_pos, e->rev_pos);
	e->targ->to_rev = true;
	e->to_rev = true;
	if (max(e->pos, e->targ->pos) < out)
		e->targ->to_rev = false;
	if (max(e->pos, e->targ->pos) < out)
		e->to_rev = false;
	out = min(out, max(e->pos, e->targ->pos));
	if (e->pos + e->targ->rev_pos < out)
		e->to_rev = false;
	if (e->pos + e->targ->rev_pos < out)
		e->targ->to_rev = true;
	out = min(out, e->pos + e->targ->rev_pos);
	if (e->rev_pos + e->targ->pos < out)
		e->to_rev = true;
	if (e->rev_pos + e->targ->pos < out)
		e->targ->to_rev = false;
	return (min(out, e->rev_pos + e->targ->pos));
}

void	calc_prices(t_stack *a, t_stack *b)
{
	t_stack	*sva;
	t_stack	*svb;
	int	i;

	sva = a;
	i = get_stack_len(a);
	while (--i >= 0)
	{
		sva->pos = i;
		sva->rev_pos = get_stack_len(a) - i;
		sva = rev(sva);
		sva = sva->next;
	}
	svb = b;
	i = get_stack_len(b);
	while (--i >= 0)
	{
		svb->pos = i;
		svb->rev_pos = get_stack_len(b) - i;
		svb->push_price = get_minimal_total(svb);
		svb = svb->next;
	}
}
