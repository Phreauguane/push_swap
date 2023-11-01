/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:42:29 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/01 18:57:08 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_two(t_stack **a, t_stack **b)
{
	while (get_top(*a) != (*b)->fst_to_push->targ
		&& get_top(*b) != (*b)->fst_to_push)
		rr(a, b, true);
	node_refresh(*a, *b);
}

void	rev_rotate_two(t_stack **a, t_stack **b)
{
	if (!(*b) || !(*b)->fst_to_push || !(*b)->fst_to_push->targ)
	{
		node_refresh(*a, *b);
		return ;
	}
	while (get_top(*a) != (*b)->fst_to_push->targ
		&& get_top(*b) != (*b)->fst_to_push)
		rrr(a, b, true);
	node_refresh(*a, *b);
}

void	final_rot(t_stack **stack, t_stack *cheap, bool is_stack_a)
{
	while (get_top(*stack) != cheap)
	{
		if (is_stack_a && cheap->to_rev)
			rra(stack, true);
		else if (is_stack_a)
			ra(stack, true);
		else if (cheap->to_rev)
			rrb(stack, true);
		else
			rb(stack, true);
	}
}

void	push_fst_to_move(t_stack **a, t_stack **b)
{
	t_stack	*fst;

	if (!b || !*b || !(*b)->fst_to_push)
		return ;
	fst = (*b)->fst_to_push;
	if (fst->to_rev && fst->targ->to_rev)
		rev_rotate_two(a, b);
	else if (!(fst->to_rev) && !(fst->targ->to_rev))
		rotate_two(a, b);
	final_rot(b, fst, false);
	final_rot(a, fst->targ, true);
	pa(a, b, true);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	len;

	len = get_stack_len(*a);
	if (is_sorted(*a))
		return ;
	while (len-- > 3)
		pb(b, a, true);
	sort_shmol(a);
	while (*b)
	{
		node_refresh(*a, *b);
		push_fst_to_move(a, b);
	}
	if (is_sorted(*a))
		return ;
	t_stack *e = get_smallest(*a);
	ft_printf("%d : %d > %d\n", e->to_rev, e->pos, e->rev_pos);
	final_rot(a, rev(get_smallest(*a)), true);
	e = get_smallest(*a);
	ft_printf("%d : %d > %d\n", e->to_rev, e->pos, e->rev_pos);

}
