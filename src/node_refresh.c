/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_refresh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:26:38 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 03:42:40 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	calc_price(t_stack *s, char stack)
{
	int	len;
	int	i;

	len = get_stack_len(s);
	i = len;
	while (--i >= 0)
	{
		s->pos = i;
		s->top_price = min(i, len - i);
		if (len - i < i)
			s->to_rev = true;
		if (s->targ != NULL && stack == 'b')
			s->push_price = s->targ->top_price + s->top_price;
		s = s->next;
		i--;
	}
}

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
		ft_printf("Price of %d : %d\n", b->val, b->top_price);
		ft_printf("Targ for %d : ", b->val);
		if (b->targ)
			ft_printf("%d !\n", b->targ->val);
		else
			ft_printf("\n");
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
	ft_printf("A %p B %p", a, b);
	get_targets(a, b);
	calc_price(a, 'a');
	calc_price(b, 'b');
	calc_cheapest(b);
}
