/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:29:51 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 20:33:12 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <push_swap.h>

t_stack	*create_node(int value)
{
	t_stack	*out;

	out = malloc(sizeof(t_stack));
	ft_bzero(out, sizeof(t_stack));
	out->val = value;
	out->next = NULL;
	out->prev = NULL;
	return (out);
}

void	push_node(t_stack **a, t_stack *node)
{
	t_stack	*n;

	if (node == NULL)
		return ;
	if (*a == NULL)
	{
		*a = node;
		node->prev = NULL;
		node->next = NULL;
		return ;
	}
	n = *a;
	while (n->next != NULL)
		n = n->next;
	n->next = node;
	node->next = NULL;
	node->prev = n;
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int	ac;
	int	bc;
	int	i;

	ac = get_stack_len(a);
	bc = get_stack_len(b);
	i = max(ac, bc) - 1;
	while (i >= 0)
	{
		ft_printf("\n");
		if (get_i(a, i) != NULL)
			ft_printf("%7d", get_i(a, i)->val);
		else
			ft_printf("      _");
		ft_printf(" | ");
		if (get_i(b, i) != NULL)
			ft_printf("%7d", get_i(b, i)->val);
		else
			ft_printf("      _");
		i--;
	}
	ft_printf("\n______a | ______b\n");
}

t_stack	*get_biggest(t_stack *stack)
{
	t_stack	*biggest;
	
	biggest = stack;
	while (stack != NULL)
	{
		if (biggest->val < stack->val)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_stack	*get_top(t_stack *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next != NULL)
		a = a->next;
	return (a);
}
