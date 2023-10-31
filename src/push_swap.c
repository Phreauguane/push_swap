/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:35:57 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 03:05:50 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = init_stack(ac, av);
	ft_putstr_fd(BOLD_CYAN, 1);
	print_stacks(a, b);
	ft_putstr_fd(BOLD_YELLOW, 1);
	// SORT STACK ============= //
	push_swap(&a, &b);
	// PRINT RESULT =========== //
	ft_putstr_fd(BOLD_GREEN, 1);
	if (!is_sorted(a))
		ft_putstr_fd(BOLD_RED, 1);
	print_stacks(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
