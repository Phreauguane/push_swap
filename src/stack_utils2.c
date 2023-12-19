/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:56:18 by jde-meo           #+#    #+#             */
/*   Updated: 2023/12/19 16:16:21 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*get_smallest(t_stack *a)
{
	t_stack	*smallest;

	smallest = a;
	while (a != NULL)
	{
		if (smallest->val > a->val)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}

t_stack	*get_top2(t_stack *a)
{
	if (a == NULL || a->next == NULL)
		return (NULL);
	return (get_top(a)->prev);
}

t_stack	*pop(t_stack **a)
{
	t_stack	*last;

	last = get_top(*a);
	if (last == NULL)
		return (NULL);
	if (last->prev == NULL)
		*a = NULL;
	if (last->prev == NULL)
		return (last);
	last->prev->next = NULL;
	last->prev = NULL;
	if (last == *a)
		*a = NULL;
	return (last);
}

int	get_stack_len(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}

t_stack	*get_i(t_stack *s, int i)
{
	int	j;

	j = 0;
	while (s)
	{
		if (i == j)
			return (s);
		s = s->next;
		j++;
	}
	return (NULL);
}
