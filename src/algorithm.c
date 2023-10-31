/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:42:29 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 03:35:50 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_two(t_stack **a, t_stack **b)
{
	while (get_top(*a) != (*b)->fst_to_push->targ
		&& get_top(*b) != (*b)->fst_to_push)
		rr(a, b, false);
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
		rrr(a, b, false);
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
	ft_printf("here nigga %d %d %d %p\n", fst->val, fst->top_price, fst->push_price, fst->targ);
	final_rot(a, fst->targ, true);
	pa(a, b, true);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	len;

	len = get_stack_len(*a);
	while (len-- > 3)
	{
		pb(b, a, true);
		print_stacks(*a, *b);
	}
	sort_shmol(a);
	print_stacks(*a, *b);
	while (*b)
	{
		node_refresh(*a, *b);
		ft_printf("ici\n");
		push_fst_to_move(a, b);
		ft_printf("la\n");
		print_stacks(*a, *b);
	}
	if (is_sorted(*a))
		return ;
	ft_printf("coucou\n");
	node_refresh(*a, *b);
	final_rot(a, get_smallest(*a), true);
}
