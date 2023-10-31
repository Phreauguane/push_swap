/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:37:54 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 03:29:14 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->val < a->next->val)
			return (false);
		a = a->next;
	}
	return (true);
}

void	free_stack(t_stack **s)
{
	t_stack	*tmp;
	
	while (*s)
	{
		tmp = pop(s);
		ft_bzero(tmp, sizeof(t_stack));
		free(tmp);
	}
}

bool	is_biggest(t_stack *e, t_stack *a)
{
	return (e == get_biggest(a));
}

bool	is_smallest(t_stack *e, t_stack *a)
{
	return (e == get_smallest(a));
}

t_stack	*get_smallest_bigger(t_stack *s, int val)
{
	t_stack	*smallest;
	t_stack	*sv;

	smallest = NULL;
	sv = s;
	while (sv)
	{
		if ((!smallest || sv->val < smallest->val) && sv->val > val)
			smallest = sv;
		sv = sv->next;
	}
	if (smallest == NULL)
		smallest = get_smallest(s);
	return (smallest);
}
