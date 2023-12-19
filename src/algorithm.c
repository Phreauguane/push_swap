/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:42:29 by jde-meo           #+#    #+#             */
/*   Updated: 2023/12/19 16:22:36 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_two(t_stack **a, t_stack **b)
{
	while (get_top(*a) != (*b)->fst_to_push->targ
		&& get_top(*b) != (*b)->fst_to_push)
		rr(a, b, TRUE);
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
		rrr(a, b, TRUE);
	node_refresh(*a, *b);
}

void	final_rot(t_stack **stack, t_stack *cheap, t_bool is_stack_a)
{
	while (get_top(*stack) != cheap)
	{
		if (is_stack_a && cheap->to_rev)
			rra(stack, TRUE);
		else if (is_stack_a)
			ra(stack, TRUE);
		else if (cheap->to_rev)
			rrb(stack, TRUE);
		else
			rb(stack, TRUE);
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
	final_rot(b, fst, FALSE);
	final_rot(a, fst->targ, TRUE);
	pa(a, b, TRUE);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	len;

	len = get_stack_len(*a);
	if (is_sorted(*a))
		return ;
	while (len-- > 3)
		pb(b, a, TRUE);
	sort_shmol(a);
	while (*b)
	{
		node_refresh(*a, *b);
		push_fst_to_move(a, b);
	}
	if (is_sorted(*a))
		return ;
	calc_prices(*a, *b);
	final_rot(a, rev(get_smallest(*a)), TRUE);
}
